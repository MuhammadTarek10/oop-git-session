"""
Exercise: Encapsulation

A Sensor measures distance in centimeters, but it should never report
a range below 10cm (too close to be useful) or above 500cm (out of
hardware range).

TODO:
1. In __init__, store a "private" attribute `self._max_range` initialized to 200.
2. Write a method `set_max_range(self, cm)` that clamps the value between
   10 and 500 before storing it.
3. Write a method `get_max_range(self)` that returns self._max_range.
"""


class Sensor:
    def __init__(self):
        pass  # TODO: initialize self._max_range to 200

    def set_max_range(self, cm):
        pass  # TODO: clamp cm between 10 and 500, then store it

    def get_max_range(self):
        pass  # TODO: return self._max_range


if __name__ == "__main__":
    sensor = Sensor()
    print(f"Default max range: {sensor.get_max_range()}cm")

    sensor.set_max_range(300)
    print(f"Max range after setting 300: {sensor.get_max_range()}cm")

    sensor.set_max_range(9999)  # should clamp to 500
    print(f"Max range after setting 9999: {sensor.get_max_range()}cm")

    sensor.set_max_range(-50)  # should clamp to 10
    print(f"Max range after setting -50: {sensor.get_max_range()}cm")
