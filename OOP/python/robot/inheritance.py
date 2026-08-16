class Robot:
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100

    def move(self):
        self.battery_level -= 5
        print(f"{self.id} is moving. Battery: {self.battery_level}%")


# DeliveryRobot inherits everything from Robot and adds its own data/behavior
class DeliveryRobot(Robot):
    def __init__(self, robot_id, cargo_capacity):
        super().__init__(robot_id)
        self.cargo_capacity = cargo_capacity

    def load_cargo(self):
        print(f"{self.id} loaded with cargo (capacity {self.cargo_capacity}kg)")


# CleaningRobot also inherits from Robot, but adds different data/behavior
class CleaningRobot(Robot):
    def __init__(self, robot_id, bin_capacity):
        super().__init__(robot_id)
        self.bin_capacity = bin_capacity

    def sweep_floor(self):
        print(f"{self.id} sweeping floor (bin capacity {self.bin_capacity}L)")


if __name__ == "__main__":
    delivery = DeliveryRobot("D-1", 20)
    cleaner = CleaningRobot("C-1", 5)

    delivery.move()        # inherited from Robot
    delivery.load_cargo()  # specific to DeliveryRobot

    cleaner.move()         # inherited from Robot
    cleaner.sweep_floor()  # specific to CleaningRobot
