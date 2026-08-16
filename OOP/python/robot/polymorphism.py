from abc import ABC, abstractmethod


class Robot(ABC):
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100

    @abstractmethod
    def perform_task(self):
        ...


class DeliveryRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is delivering a package.")


class CleaningRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is cleaning the warehouse floor.")


if __name__ == "__main__":
    # The fleet holds objects of the ABSTRACT base type Robot.
    # Each call to perform_task() runs the CORRECT version for the
    # actual (concrete) type of the object, decided at runtime.
    fleet = [
        DeliveryRobot("D-1"),
        CleaningRobot("C-1"),
        DeliveryRobot("D-2"),
    ]

    for robot in fleet:
        robot.perform_task()  # same call, different behavior per type
