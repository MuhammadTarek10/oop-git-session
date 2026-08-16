class Robot:
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100

    def move(self):
        self.battery_level -= 5
        print(f"{self.id} is moving. Battery: {self.battery_level}%")


"""
Exercise: Inheritance

TODO:
1. Make InspectionRobot inherit from Robot.
2. In __init__, accept (robot_id, camera_count), call super().__init__(robot_id),
   and store self.camera_count.
3. Add a method take_photo() that prints:
   "<id> takes a photo with <camera_count> camera(s)."
"""


class InspectionRobot:  # TODO: inherit from Robot
    def __init__(self, robot_id, camera_count):
        pass  # TODO: call super().__init__ and store camera_count

    def take_photo(self):
        pass  # TODO: print the photo message


if __name__ == "__main__":
    inspector = InspectionRobot("I-1", 2)

    inspector.move()        # inherited from Robot
    inspector.take_photo()  # specific to InspectionRobot
