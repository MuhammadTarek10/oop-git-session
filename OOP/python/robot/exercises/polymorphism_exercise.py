from abc import ABC, abstractmethod

"""
Exercise: Polymorphism

TODO:
1. Add a second abstract method to Robot: report_status().
2. Implement report_status() in both DeliveryRobot and CleaningRobot,
   each printing a different status message.
3. Extend the fleet loop in main to also call report_status() on
   every robot, right after perform_task().
"""


class Robot(ABC):
    def __init__(self, robot_id):
        self.id = robot_id

    @abstractmethod
    def perform_task(self):
        ...

    # TODO: declare abstract method report_status()


class DeliveryRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is delivering a package.")

    # TODO: implement report_status()


class CleaningRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is cleaning the warehouse floor.")

    # TODO: implement report_status()


if __name__ == "__main__":
    fleet = [DeliveryRobot("D-1"), CleaningRobot("C-1")]

    for robot in fleet:
        robot.perform_task()
        # TODO: also call robot.report_status()
