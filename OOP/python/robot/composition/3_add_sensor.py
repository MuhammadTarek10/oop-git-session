# Stage 3: DistanceSensor becomes a second component.
# Robot now HAS a Motor AND a DistanceSensor -- composition scales by just
# adding another field + delegating another method to it.


class DistanceSensor:
    def __init__(self, max_range, readings):
        self._max_range = max_range         # clamps every reading, like the Part 1 exercise
        self._readings = readings           # a fixed, scripted sequence -- deterministic, not random
        self._next_reading_index = 0

    def get_reading(self):
        raw = self._readings[self._next_reading_index % len(self._readings)]
        self._next_reading_index += 1
        return min(raw, self._max_range)


class Motor:
    def __init__(self):
        self._speed = 0

    def spin(self, speed):
        self._speed = max(0, min(100, speed))
        print(f"Motor spinning at {self._speed}%")


class Robot:
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100
        self.motor = Motor()
        self.front_sensor = DistanceSensor(200, [120, 95, 40, 200])  # Robot HAS-A DistanceSensor too

    def move(self):
        self.motor.spin(70)
        self.battery_level -= 5
        print(f"{self.id} is moving. Battery: {self.battery_level}%")

    def check_front(self):
        distance = self.front_sensor.get_reading()  # delegate reading to the sensor
        print(f"{self.id} front sensor reads {distance}cm")


if __name__ == "__main__":
    robot = Robot("R-1")
    robot.move()
    robot.check_front()
    robot.check_front()
