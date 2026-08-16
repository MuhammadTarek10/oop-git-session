class Robot:
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100

    def move(self):
        self.battery_level -= 5
        print(f"{self.id} is moving. Battery: {self.battery_level}%")


class InspectionRobot(Robot):
    def __init__(self, robot_id, camera_count):
        super().__init__(robot_id)
        self.camera_count = camera_count

    def take_photo(self):
        print(f"{self.id} takes a photo with {self.camera_count} camera(s).")


if __name__ == "__main__":
    inspector = InspectionRobot("I-1", 2)

    inspector.move()
    inspector.take_photo()
