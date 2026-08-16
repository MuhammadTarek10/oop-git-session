from abc import ABC, abstractmethod


class Robot(ABC):
    def __init__(self, robot_id):
        self.id = robot_id

    @abstractmethod
    def perform_task(self):
        ...

    @abstractmethod
    def report_status(self):
        ...


class DeliveryRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is delivering a package.")

    def report_status(self):
        print(f"{self.id} status: cargo bay operational.")


class CleaningRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is cleaning the warehouse floor.")

    def report_status(self):
        print(f"{self.id} status: bin at 40% capacity.")


if __name__ == "__main__":
    fleet = [DeliveryRobot("D-1"), CleaningRobot("C-1")]

    for robot in fleet:
        robot.perform_task()
        robot.report_status()
