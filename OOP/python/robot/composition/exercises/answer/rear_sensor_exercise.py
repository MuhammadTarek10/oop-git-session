from enum import Enum


class Direction(Enum):
    FORWARD = "FORWARD"
    BACKWARD = "BACKWARD"
    STOPPED = "STOPPED"


class Motor:
    def __init__(self, label):
        self.label = label
        self._speed = 0
        self._direction = Direction.STOPPED

    def spin(self, direction, speed):
        self._speed = max(0, min(100, speed))
        self._direction = direction
        print(f"{self.label} motor spinning {self._direction.value} at {self._speed}%")


class DistanceSensor:
    def __init__(self, label, max_range, readings):
        self.label = label
        self._max_range = max_range
        self._readings = readings
        self._next_reading_index = 0

    def get_reading(self):
        raw = self._readings[self._next_reading_index % len(self._readings)]
        self._next_reading_index += 1
        distance = min(raw, self._max_range)
        print(f"{self.label} sensor reads {distance}cm")
        return distance


class Robot:
    def __init__(self, robot_id):
        self.id = robot_id
        self.left_motor = Motor("Left wheel")
        self.right_motor = Motor("Right wheel")
        self.front_sensor = DistanceSensor("Front", 200, [120, 95, 40, 200])
        self.rear_sensor = DistanceSensor("Rear", 150, [80, 30, 200])

    def move(self, direction):
        self.front_sensor.get_reading()
        self.left_motor.spin(direction, 70)
        self.right_motor.spin(direction, 70)

    def check_rear(self):
        self.rear_sensor.get_reading()


if __name__ == "__main__":
    robot = Robot("R-1")
    robot.move(Direction.FORWARD)
    robot.check_rear()
