#include <iostream>
#include <string>
#include <vector>

// --- Full working robot hierarchy + fleet dispatcher ---
// Your job: add a GuardRobot class below (see TODO) and register an
// instance of it in the fleet in main(). Everything else already works.
//
// Robot now composes a Motor and a DistanceSensor (Part 2: composition).
// Every subclass inherits these components for free and its performTask()
// calls the shared move()/checkObstacle() helpers before doing its own job.

class Motor {
   private:
    int speed;

   public:
    Motor() : speed(0) {}

    void spin(int newSpeed) {
        if (newSpeed < 0) newSpeed = 0;
        if (newSpeed > 100) newSpeed = 100;
        speed = newSpeed;
        std::cout << "Motor spinning at " << speed << "%\n";
    }

    void stop() {
        speed = 0;
    }
};

class DistanceSensor {
   private:
    int maxRange;
    std::vector<int> readings;
    size_t nextReadingIndex;

   public:
    DistanceSensor(int maxRange, std::vector<int> readings)
        : maxRange(maxRange), readings(readings), nextReadingIndex(0) {}

    int getReading() {
        int raw = readings[nextReadingIndex % readings.size()];
        nextReadingIndex++;
        if (raw > maxRange) raw = maxRange;
        return raw;
    }
};

class Robot {
   protected:
    std::string id;
    int batteryLevel;

   private:
    Motor motor;              // Robot HAS-A Motor
    DistanceSensor frontSensor;  // Robot HAS-A DistanceSensor
    static const int SAFE_DISTANCE_CM = 50;

   public:
    Robot(std::string id)
        : id(id),
          batteryLevel(100),
          frontSensor(200, {120, 95, 40, 200}) {}

    // true if something is too close to move forward safely
    bool checkObstacle() {
        int distance = frontSensor.getReading();
        std::cout << id << " front sensor reads " << distance << "cm\n";
        return distance < SAFE_DISTANCE_CM;
    }

    // returns true if the robot actually moved
    bool move() {
        if (checkObstacle()) {
            motor.stop();
            std::cout << id << " sees an obstacle ahead — staying put.\n";
            return false;
        }
        motor.spin(70);
        batteryLevel -= 5;
        std::cout << id << " is moving. Battery: " << batteryLevel << "%\n";
        return true;
    }

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
        if (move()) {
            std::cout << id << " is delivering a package (capacity "
                       << cargoCapacity << "kg).\n";
        }
    }
};

class CleaningRobot : public Robot {
   private:
    int binCapacity;

   public:
    CleaningRobot(std::string id, int binCapacity)
        : Robot(id), binCapacity(binCapacity) {}

    void performTask() override {
        if (move()) {
            std::cout << id << " is cleaning the warehouse floor (bin capacity "
                       << binCapacity << "L).\n";
        }
    }
};

/*
    TODO: Capstone Exercise

    Add a GuardRobot class here:
    1. It should inherit publicly from Robot.
    2. Give it a private field `patrolZone` (std::string).
    3. Constructor takes (id, patrolZone) and passes id up to Robot.
    4. Implement performTask() so it calls move() first (like DeliveryRobot
       and CleaningRobot do), and if it succeeds, prints:
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
