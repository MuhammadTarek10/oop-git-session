#include <iostream>
#include <string>

class Robot {
   protected:
    std::string id;
    int batteryLevel;

   public:
    Robot(std::string id) : id(id), batteryLevel(100) {}

    void move() {
        batteryLevel -= 5;
        std::cout << id << " is moving. Battery: " << batteryLevel << "%\n";
    }

    int getBatteryLevel() const {
        return batteryLevel;
    }

    std::string getId() const {
        return id;
    }
};

// DeliveryRobot inherits everything from Robot and adds its own data/behavior
class DeliveryRobot : public Robot {
   private:
    int cargoCapacity;

   public:
    DeliveryRobot(std::string id, int cargoCapacity)
        : Robot(id), cargoCapacity(cargoCapacity) {}

    void loadCargo() {
        std::cout << id << " loaded with cargo (capacity " << cargoCapacity << "kg)\n";
    }
};

// CleaningRobot also inherits from Robot, but adds different data/behavior
class CleaningRobot : public Robot {
   private:
    int binCapacity;

   public:
    CleaningRobot(std::string id, int binCapacity)
        : Robot(id), binCapacity(binCapacity) {}

    void sweepFloor() {
        std::cout << id << " sweeping floor (bin capacity " << binCapacity << "L)\n";
    }
};

int main() {
    DeliveryRobot delivery("D-1", 20);
    CleaningRobot cleaner("C-1", 5);

    delivery.move();     // inherited from Robot
    delivery.loadCargo();  // specific to DeliveryRobot

    cleaner.move();       // inherited from Robot
    cleaner.sweepFloor(); // specific to CleaningRobot

    return 0;
}
