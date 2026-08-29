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


class MovementStrategy(ABC):
    @abstractmethod
    def should_move(self, distance_reading):
        ...


class CautiousStrategy(MovementStrategy):
    def should_move(self, distance_reading):
        return distance_reading >= 80


class AggressiveStrategy(MovementStrategy):
    def should_move(self, distance_reading):
        return distance_reading >= 20


class Robot(ABC):
    def __init__(self, robot_id, strategy):
        self.id = robot_id
        self.battery_level = 100
        self._motor = Motor()
        self._sensor = DistanceSensor(200, [120, 95, 40, 200])
        self._strategy = strategy
        self.obstacle_encountered = False

    def move(self):
        distance = self._sensor.get_reading()
        if not self._strategy.should_move(distance):
            self._motor.stop()
            self.obstacle_encountered = True
            print(f"{self.id} ({distance}cm) says too risky — staying put.")
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


class GuardRobot(Robot):
    def perform_task(self):
        if self.move():
            print(f"{self.id} patrolled its zone.")


def main():
    fleet = [
        DeliveryRobot("D-1", CautiousStrategy()),
        GuardRobot("G-1", AggressiveStrategy()),
    ]

    # Same scripted readings for both: 120, 95, 40, 200 (cycled per robot).
    for _ in range(3):
        for robot in fleet:
            robot.perform_task()

    print("\n--- Fleet Report ---")
    for robot in fleet:
        obstacle = "yes" if robot.obstacle_encountered else "no"
        print(f"{robot.id}: battery {robot.battery_level}%, obstacle encountered: {obstacle}")


if __name__ == "__main__":
    main()
