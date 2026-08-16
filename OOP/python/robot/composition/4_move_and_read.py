from enum import Enum

# Stage 4: a real two-wheeled robot.
# Robot now HAS-A left_motor, HAS-A right_motor, and HAS-A front_sensor.
# move() coordinates all three components together: it checks the sensor
# first, and only spins both wheel motors if the path ahead is clear.


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

    def stop(self):
        self._speed = 0
        self._direction = Direction.STOPPED
        print(f"{self.label} motor stopped")


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
    SAFE_DISTANCE_CM = 50

    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100
        self.left_motor = Motor("Left wheel")
        self.right_motor = Motor("Right wheel")
        self.front_sensor = DistanceSensor("Front", 200, [120, 95, 40, 200])

    def move(self, direction):
        distance = self.front_sensor.get_reading()
        if direction == Direction.FORWARD and distance < self.SAFE_DISTANCE_CM:
            print(f"{self.id} detects an obstacle {distance}cm ahead — stopping instead of moving.")
            self.left_motor.stop()
            self.right_motor.stop()
            return

        self.left_motor.spin(direction, 70)
        self.right_motor.spin(direction, 70)
        self.battery_level -= 5
        print(f"{self.id} is moving. Battery: {self.battery_level}%")


if __name__ == "__main__":
    robot = Robot("R-1")
    robot.move(Direction.FORWARD)  # reading 120cm -> clear, moves
    robot.move(Direction.FORWARD)  # reading 95cm  -> clear, moves
    robot.move(Direction.FORWARD)  # reading 40cm  -> too close, stops
