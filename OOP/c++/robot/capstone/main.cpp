#include <iostream>
#include <string>
#include <vector>

// --- Full working robot hierarchy + fleet dispatcher ---
// Your job: add a GuardRobot class below (see TODO) and register an
// instance of it in the fleet in main(). Everything else already works.

class Robot {
   protected:
    std::string id;
    int batteryLevel;

   public:
    Robot(std::string id) : id(id), batteryLevel(100) {}

    virtual void performTask() = 0;

    virtual ~Robot() {}

    std::string getId() const {
        return id;
    }
};

class DeliveryRobot : public Robot {
   private:
    int cargoCapacity;

   public:
    DeliveryRobot(std::string id, int cargoCapacity)
        : Robot(id), cargoCapacity(cargoCapacity) {}

    void performTask() override {
        std::cout << id << " is delivering a package (capacity "
                   << cargoCapacity << "kg).\n";
    }
};

class CleaningRobot : public Robot {
   private:
    int binCapacity;

   public:
    CleaningRobot(std::string id, int binCapacity)
        : Robot(id), binCapacity(binCapacity) {}

    void performTask() override {
        std::cout << id << " is cleaning the warehouse floor (bin capacity "
                   << binCapacity << "L).\n";
    }
};

/*
    TODO: Capstone Exercise

    Add a GuardRobot class here:
    1. It should inherit publicly from Robot.
    2. Give it a private field `patrolZone` (std::string).
    3. Constructor takes (id, patrolZone) and passes id up to Robot.
    4. Implement performTask() to print:
       "<id> is patrolling zone <patrolZone>."
*/

// class GuardRobot : public Robot { ... };

int main() {
    // This fleet dispatcher already works for any Robot subclass.
    // Once you write GuardRobot above, uncomment the line below to
    // add it to the fleet and see polymorphic dispatch pick it up.
    std::vector<Robot*> fleet;
    fleet.push_back(new DeliveryRobot("D-1", 20));
    fleet.push_back(new CleaningRobot("C-1", 5));
    // fleet.push_back(new GuardRobot("G-1", "North Warehouse"));

    for (Robot* robot : fleet) {
        robot->performTask();
    }

    for (Robot* robot : fleet) {
        delete robot;
    }

    return 0;
}
