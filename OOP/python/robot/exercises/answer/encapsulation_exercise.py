class Sensor:
    def __init__(self):
        self._max_range = 200

    def set_max_range(self, cm):
        self._max_range = max(10, min(500, cm))

    def get_max_range(self):
        return self._max_range


if __name__ == "__main__":
    sensor = Sensor()
    print(f"Default max range: {sensor.get_max_range()}cm")

    sensor.set_max_range(300)
    print(f"Max range after setting 300: {sensor.get_max_range()}cm")

    sensor.set_max_range(9999)
    print(f"Max range after setting 9999: {sensor.get_max_range()}cm")

    sensor.set_max_range(-50)
    print(f"Max range after setting -50: {sensor.get_max_range()}cm")
