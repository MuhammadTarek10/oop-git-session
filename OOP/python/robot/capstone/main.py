from abc import ABC, abstractmethod

# --- Full working robot hierarchy + fleet dispatcher ---
# Your job: add a GuardRobot class below (see TODO) and register an
# instance of it in the fleet in main(). Everything else already works.


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


"""
TODO: Capstone Exercise

Add a GuardRobot class here:
1. It should inherit from Robot.
2. __init__ takes (robot_id, patrol_zone), calls super().__init__(robot_id),
   and stores self.patrol_zone.
3. Implement perform_task() to print:
   "<id> is patrolling zone <patrol_zone>."
"""

# class GuardRobot(Robot):
#     ...


if __name__ == "__main__":
    # This fleet dispatcher already works for any Robot subclass.
    # Once you write GuardRobot above, uncomment the line below to
    # add it to the fleet and see polymorphic dispatch pick it up.
    fleet = [
        DeliveryRobot("D-1", 20),
        CleaningRobot("C-1", 5),
        # GuardRobot("G-1", "North Warehouse"),
    ]

    for robot in fleet:
        robot.perform_task()
