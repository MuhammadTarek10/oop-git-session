# Stage 1: a bare Robot. No components yet -- just its own data.
# This is where Part 1 left off. Composition starts in the next stage.


class Robot:
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100

    def move(self):
        self.battery_level -= 5
        print(f"{self.id} is moving. Battery: {self.battery_level}%")


if __name__ == "__main__":
    robot = Robot("R-1")
    robot.move()
    robot.move()
