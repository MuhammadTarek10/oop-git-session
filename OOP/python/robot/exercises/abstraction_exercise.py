from abc import ABC, abstractmethod


class Robot(ABC):
    def __init__(self, robot_id):
        self.id = robot_id

    @abstractmethod
    def perform_task(self):
        ...


"""
Exercise: Abstraction

MaintenanceRobot inherits from Robot but does not yet implement
perform_task(), so instantiating it currently raises a TypeError
(it's still considered abstract).

TODO: implement perform_task() so it prints:
"<id> is running a maintenance check."
"""


class MaintenanceRobot(Robot):
    pass  # TODO: implement perform_task() here


if __name__ == "__main__":
    maintenance = MaintenanceRobot("M-1")
    maintenance.perform_task()
