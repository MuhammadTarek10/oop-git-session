from abc import ABC, abstractmethod


# Robot is now an abstract class: it defines the contract every robot
# must follow, but does not know HOW each robot performs its task.
class Robot(ABC):
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100

    @abstractmethod
    def perform_task(self):
        ...  # no body -> subclasses MUST implement it


class DeliveryRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is delivering a package.")


class CleaningRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is cleaning the warehouse floor.")


if __name__ == "__main__":
    # Robot("X-1")  # TypeError: Can't instantiate abstract class Robot

    delivery = DeliveryRobot("D-1")
    cleaner = CleaningRobot("C-1")

    delivery.perform_task()
    cleaner.perform_task()
