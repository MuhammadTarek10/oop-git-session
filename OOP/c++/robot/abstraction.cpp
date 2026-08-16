#include <iostream>
#include <string>

// Robot is now an abstract class: it defines the contract every robot
// must follow, but does not know HOW each robot performs its task.
class Robot {
   protected:
    std::string id;
    int batteryLevel;

   public:
    Robot(std::string id) : id(id), batteryLevel(100) {}

    // Pure virtual function -> no body here, subclasses MUST implement it.
    // This also makes Robot impossible to instantiate directly.
    virtual void performTask() = 0;

    virtual ~Robot() {}

    std::string getId() const {
        return id;
    }
};

class DeliveryRobot : public Robot {
   public:
    DeliveryRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is delivering a package.\n";
    }
};

class CleaningRobot : public Robot {
   public:
    CleaningRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is cleaning the warehouse floor.\n";
    }
};

int main() {
    // Robot r("X-1");        // compile error: cannot instantiate abstract class

    DeliveryRobot delivery("D-1");
    CleaningRobot cleaner("C-1");

    delivery.performTask();
    cleaner.performTask();

    return 0;
}
