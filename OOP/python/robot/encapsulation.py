class Motor:
    def __init__(self):
        self._speed = 0  # 0-100, never set directly from outside

    def set_speed(self, new_speed):
        new_speed = max(0, min(100, new_speed))
        self._speed = new_speed
        print(f"Motor speed set to {self._speed}%")

    def get_speed(self):
        return self._speed


class Robot:
    def __init__(self):
        self._battery_level = 100  # 0-100, protected from invalid values

    def consume_battery(self, amount):
        self._battery_level = max(0, self._battery_level - amount)
        print(f"Battery drained to {self._battery_level}%")

    def charge_battery(self, amount):
        self._battery_level = min(100, self._battery_level + amount)
        print(f"Battery charged to {self._battery_level}%")

    def get_battery_level(self):
        return self._battery_level


if __name__ == "__main__":
    motor = Motor()
    motor.set_speed(60)
    motor.set_speed(9999)  # clamped to 100, can't burn out the motor
    print(f"Final motor speed: {motor.get_speed()}%\n")

    robot = Robot()
    robot.consume_battery(30)
    robot.consume_battery(9999)  # clamped to 0, can't go negative
    robot.charge_battery(50)
    print(f"Final battery level: {robot.get_battery_level()}%")
