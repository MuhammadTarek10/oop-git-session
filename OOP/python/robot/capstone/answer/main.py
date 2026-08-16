from abc import ABC, abstractmethod


class Robot(ABC):
    def __init__(self, robot_id):
        self.id = robot_id
        self.battery_level = 100

    @abstractmethod
    def perform_task(self):
        ...


class DeliveryRobot(Robot):
    def __init__(self, robot_id, cargo_capacity):
        super().__init__(robot_id)
        self.cargo_capacity = cargo_capacity

    def perform_task(self):
        print(f"{self.id} is delivering a package (capacity {self.cargo_capacity}kg).")


class CleaningRobot(Robot):
    def __init__(self, robot_id, bin_capacity):
        super().__init__(robot_id)
        self.bin_capacity = bin_capacity

    def perform_task(self):
        print(f"{self.id} is cleaning the warehouse floor (bin capacity {self.bin_capacity}L).")


class GuardRobot(Robot):
    def __init__(self, robot_id, patrol_zone):
        super().__init__(robot_id)
        self.patrol_zone = patrol_zone

    def perform_task(self):
        print(f"{self.id} is patrolling zone {self.patrol_zone}.")


if __name__ == "__main__":
    fleet = [
        DeliveryRobot("D-1", 20),
        CleaningRobot("C-1", 5),
        GuardRobot("G-1", "North Warehouse"),
    ]

    for robot in fleet:
        robot.perform_task()
