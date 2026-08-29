from abc import ABC, abstractmethod


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
        distance = min(raw, self._max_range)
        print(f"Sensor reads {distance}cm")
        return distance


class Robot(ABC):
    SAFE_DISTANCE_CM = 50

    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100
        self._motor = Motor()
        self._sensor = DistanceSensor(200, [120, 95, 40, 200])
        self.obstacle_encountered = False

    def check_obstacle(self):
        return self._sensor.get_reading() < self.SAFE_DISTANCE_CM

    def move(self):
        if self.check_obstacle():
            self._motor.stop()
            self.obstacle_encountered = True
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
    def perform_task(self):
        if self.move():
            print(f"{self.id} delivered a package.")


class CleaningRobot(Robot):
    def perform_task(self):
        if self.move():
            print(f"{self.id} cleaned the floor.")


class GuardRobot(Robot):
    def perform_task(self):
        if self.move():
            print(f"{self.id} patrolled its zone.")


def main():
    fleet = [DeliveryRobot("D-1"), CleaningRobot("C-1"), GuardRobot("G-1")]

    commands = [
        ("D-1", "run"),
        ("C-1", "run"),
        ("G-1", "run"),
        ("D-1", "run"),
        ("D-1", "run"),  # 3rd command to D-1 hits its 40cm reading -> blocked
    ]

    for robot_id, _command in commands:
        for robot in fleet:
            if robot.id == robot_id:
                robot.perform_task()  # polymorphic dispatch
                break

    print("\n--- Fleet Report ---")
    for robot in fleet:
        obstacle = "yes" if robot.obstacle_encountered else "no"
        print(f"{robot.id}: battery {robot.battery_level}%, obstacle encountered: {obstacle}")


if __name__ == "__main__":
    main()
