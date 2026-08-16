from enum import Enum

# Stage 2: Motor becomes a real, separate object.
# Robot no longer moves itself -- it HAS a Motor and delegates to it.
# This is composition: Robot is built out of another object, not just data.


class Direction(Enum):
    FORWARD = "FORWARD"
    BACKWARD = "BACKWARD"
    STOPPED = "STOPPED"


class Motor:
    def __init__(self):
        self._speed = 0  # 0-100, clamped -- same validated-setter idea from encapsulation
        self._direction = Direction.STOPPED

    def spin(self, direction, speed):
        self._speed = max(0, min(100, speed))
        self._direction = direction
        print(f"Motor spinning {self._direction.value} at {self._speed}%")


class Robot:
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100
        self.motor = Motor()  # Robot HAS-A Motor

    def move(self):
        self.motor.spin(Direction.FORWARD, 70)  # delegate the actual work to Motor
        self.battery_level -= 5
        print(f"{self.id} is moving. Battery: {self.battery_level}%")


if __name__ == "__main__":
    robot = Robot("R-1")
    robot.move()
