#include <iostream>
#include <string>
#include <vector>

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

class GuardRobot : public Robot {
   private:
    std::string patrolZone;

   public:
    GuardRobot(std::string id, std::string patrolZone)
        : Robot(id), patrolZone(patrolZone) {}

    void performTask() override {
        std::cout << id << " is patrolling zone " << patrolZone << ".\n";
    }
};

int main() {
    std::vector<Robot*> fleet;
    fleet.push_back(new DeliveryRobot("D-1", 20));
    fleet.push_back(new CleaningRobot("C-1", 5));
    fleet.push_back(new GuardRobot("G-1", "North Warehouse"));

    for (Robot* robot : fleet) {
        robot->performTask();
    }

    for (Robot* robot : fleet) {
        delete robot;
    }

    return 0;
}
