from abc import ABC, abstractmethod

# Robot composes a Motor and a DistanceSensor (Part 2: composition).
# Every subclass inherits these components for free and its perform_task()
# calls the shared move()/check_obstacle() helpers before doing its own job.


class Motor:
    def __init__(self):
        self._speed = 0

    def spin(self, speed):
        self._speed = max(0, min(100, speed))
        print(f"Motor spinning at {self._speed}%")

    def stop(self):
        self._speed = 0


class DistanceSensor:
    def __init__(self, max_range, readings):
        self._max_range = max_range
        self._readings = readings
        self._next_reading_index = 0

    def get_reading(self):
        raw = self._readings[self._next_reading_index % len(self._readings)]
        self._next_reading_index += 1
        return min(raw, self._max_range)


class Robot(ABC):
    SAFE_DISTANCE_CM = 50

    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100
        self._motor = Motor()
        self._front_sensor = DistanceSensor(200, [120, 95, 40, 200])

    def check_obstacle(self):
        distance = self._front_sensor.get_reading()
        print(f"{self.id} front sensor reads {distance}cm")
        return distance < self.SAFE_DISTANCE_CM

    def move(self):
        if self.check_obstacle():
            self._motor.stop()
            print(f"{self.id} sees an obstacle ahead — staying put.")
            return False
        self._motor.spin(70)
        self.battery_level -= 5
        print(f"{self.id} is moving. Battery: {self.battery_level}%")
        return True

    @abstractmethod
    def perform_task(self):
        ...


class DeliveryRobot(Robot):
    def __init__(self, robot_id, cargo_capacity):
        super().__init__(robot_id)
        self.cargo_capacity = cargo_capacity

    def perform_task(self):
        if self.move():
            print(f"{self.id} is delivering a package (capacity {self.cargo_capacity}kg).")


class CleaningRobot(Robot):
    def __init__(self, robot_id, bin_capacity):
        super().__init__(robot_id)
        self.bin_capacity = bin_capacity

    def perform_task(self):
        if self.move():
            print(f"{self.id} is cleaning the warehouse floor (bin capacity {self.bin_capacity}L).")


class GuardRobot(Robot):
    def __init__(self, robot_id, patrol_zone):
        super().__init__(robot_id)
        self.patrol_zone = patrol_zone

    def perform_task(self):
        if self.move():
            print(f"{self.id} is patrolling zone {self.patrol_zone}.")


if __name__ == "__main__":
    fleet = [
        DeliveryRobot("D-1", 20),
        CleaningRobot("C-1", 5),
        GuardRobot("G-1", "North Warehouse"),
    ]

    for robot in fleet:
        robot.perform_task()
