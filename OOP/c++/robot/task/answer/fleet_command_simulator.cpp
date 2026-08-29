#include <iostream>
#include <map>
#include <string>
#include <vector>

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
        std::cout << "Sensor reads " << raw << "cm\n";
        return raw;
    }
};

class Robot {
   protected:
    std::string id;
    int batteryLevel;

   private:
    Motor motor;
    DistanceSensor sensor;
    bool obstacleEncountered;
    static const int SAFE_DISTANCE_CM = 50;

   public:
    Robot(std::string id)
        : id(id),
          batteryLevel(100),
          sensor(200, {120, 95, 40, 200}),
          obstacleEncountered(false) {}

    bool checkObstacle() {
        return sensor.getReading() < SAFE_DISTANCE_CM;
    }

    bool move() {
        if (checkObstacle()) {
            motor.stop();
            obstacleEncountered = true;
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

    int getBatteryLevel() const {
        return batteryLevel;
    }

    bool hasEncounteredObstacle() const {
        return obstacleEncountered;
    }
};

class DeliveryRobot : public Robot {
   public:
    DeliveryRobot(std::string id) : Robot(id) {}

    void performTask() override {
        if (move()) {
            std::cout << id << " delivered a package.\n";
        }
    }
};

class CleaningRobot : public Robot {
   public:
    CleaningRobot(std::string id) : Robot(id) {}

    void performTask() override {
        if (move()) {
            std::cout << id << " cleaned the floor.\n";
        }
    }
};

class GuardRobot : public Robot {
   public:
    GuardRobot(std::string id) : Robot(id) {}

    void performTask() override {
        if (move()) {
            std::cout << id << " patrolled its zone.\n";
        }
    }
};

int main() {
    std::vector<Robot*> fleet;
    fleet.push_back(new DeliveryRobot("D-1"));
    fleet.push_back(new CleaningRobot("C-1"));
    fleet.push_back(new GuardRobot("G-1"));

    std::vector<std::pair<std::string, std::string>> commands = {
        {"D-1", "run"},
        {"C-1", "run"},
        {"G-1", "run"},
        {"D-1", "run"},
        {"D-1", "run"},  // 3rd command to D-1 hits its 40cm reading -> blocked
    };

    for (auto& command : commands) {
        for (Robot* robot : fleet) {
            if (robot->getId() == command.first) {
                robot->performTask();  // polymorphic dispatch
                break;
            }
        }
    }

    std::cout << "\n--- Fleet Report ---\n";
    for (Robot* robot : fleet) {
        std::cout << robot->getId() << ": battery " << robot->getBatteryLevel()
                   << "%, obstacle encountered: "
                   << (robot->hasEncounteredObstacle() ? "yes" : "no") << "\n";
    }

    for (Robot* robot : fleet) {
        delete robot;
    }

    return 0;
}
