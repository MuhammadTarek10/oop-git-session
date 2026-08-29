#include <iostream>
#include <memory>
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

class MovementStrategy {
   public:
    virtual bool shouldMove(int distanceReading) = 0;
    virtual ~MovementStrategy() {}
};

class CautiousStrategy : public MovementStrategy {
   public:
    bool shouldMove(int distanceReading) override {
        return distanceReading >= 80;
    }
};

class AggressiveStrategy : public MovementStrategy {
   public:
    bool shouldMove(int distanceReading) override {
        return distanceReading >= 20;
    }
};

class Robot {
   protected:
    std::string id;
    int batteryLevel;

   private:
    Motor motor;
    DistanceSensor sensor;
    std::unique_ptr<MovementStrategy> strategy;
    bool obstacleEncountered;

   public:
    Robot(std::string id, std::unique_ptr<MovementStrategy> strategy)
        : id(id),
          batteryLevel(100),
          sensor(200, {120, 95, 40, 200}),
          strategy(std::move(strategy)),
          obstacleEncountered(false) {}

    bool move() {
        int distance = sensor.getReading();
        if (!strategy->shouldMove(distance)) {
            motor.stop();
            obstacleEncountered = true;
            std::cout << id << " (" << distance << "cm) says too risky — staying put.\n";
            return false;
        }
        motor.spin(70);
        batteryLevel -= 5;
        std::cout << id << " is moving. Battery: " << batteryLevel << "%\n";
        return true;
    }

    virtual void performTask() = 0;

    virtual ~Robot() = default;

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
    DeliveryRobot(std::string id, std::unique_ptr<MovementStrategy> strategy)
        : Robot(id, std::move(strategy)) {}

    void performTask() override {
        if (move()) {
            std::cout << id << " delivered a package.\n";
        }
    }
};

class GuardRobot : public Robot {
   public:
    GuardRobot(std::string id, std::unique_ptr<MovementStrategy> strategy)
        : Robot(id, std::move(strategy)) {}

    void performTask() override {
        if (move()) {
            std::cout << id << " patrolled its zone.\n";
        }
    }
};

int main() {
    std::vector<Robot*> fleet;
    fleet.push_back(new DeliveryRobot("D-1", std::make_unique<CautiousStrategy>()));
    fleet.push_back(new GuardRobot("G-1", std::make_unique<AggressiveStrategy>()));

    // Same scripted readings for both: 120, 95, 40, 200 (cycled per robot).
    for (int i = 0; i < 3; i++) {
        for (Robot* robot : fleet) {
            robot->performTask();
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
