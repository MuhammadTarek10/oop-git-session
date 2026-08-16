from abc import ABC, abstractmethod

# --- Full working robot hierarchy + fleet dispatcher ---
# Your job: add a GuardRobot class below (see TODO) and register an
# instance of it in the fleet in main(). Everything else already works.
#
# Robot now composes a Motor and a DistanceSensor (Part 2: composition).
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
        self._motor = Motor()  # Robot HAS-A Motor
        self._front_sensor = DistanceSensor(200, [120, 95, 40, 200])  # Robot HAS-A DistanceSensor

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


"""
TODO: Capstone Exercise

Add a GuardRobot class here:
1. It should inherit from Robot.
2. __init__ takes (robot_id, patrol_zone), calls super().__init__(robot_id),
   and stores self.patrol_zone.
3. Implement perform_task() so it calls self.move() first (like
   DeliveryRobot and CleaningRobot do), and if it succeeds, prints:
   "<id> is patrolling zone <patrol_zone>."
"""

# class GuardRobot(Robot):
#     ...


if __name__ == "__main__":
    # This fleet dispatcher already works for any Robot subclass.
    # Once you write GuardRobot above, uncomment the line below to
    # add it to the fleet and see polymorphic dispatch pick it up.
    fleet = [
        DeliveryRobot("D-1", 20),
        CleaningRobot("C-1", 5),
        # GuardRobot("G-1", "North Warehouse"),
    ]

    for robot in fleet:
        robot.perform_task()
