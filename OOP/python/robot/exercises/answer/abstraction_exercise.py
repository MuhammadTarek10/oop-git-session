from abc import ABC, abstractmethod


class Robot(ABC):
    def __init__(self, robot_id):
        self.id = robot_id

    @abstractmethod
    def perform_task(self):
        ...


class MaintenanceRobot(Robot):
    def perform_task(self):
        print(f"{self.id} is running a maintenance check.")


if __name__ == "__main__":
    maintenance = MaintenanceRobot("M-1")
    maintenance.perform_task()
