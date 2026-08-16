#include <iostream>
#include <string>
#include <vector>

// Stage 3: DistanceSensor becomes a second component.
// Robot now HAS a Motor AND a DistanceSensor — composition scales by just
// adding another field + delegating another method to it.
class DistanceSensor {
   private:
    int maxRange;                  // clamps every reading, like the Part 1 exercise
    std::vector<int> readings;     // a fixed, scripted sequence — deterministic, not random
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
};

class Robot {
   private:
    std::string id;
    int batteryLevel;
    Motor motor;
    DistanceSensor frontSensor;  // Robot HAS-A DistanceSensor too

   public:
    Robot(std::string id)
        : id(id),
          batteryLevel(100),
          frontSensor(200, {120, 95, 40, 200}) {}

    void move() {
        motor.spin(70);
        batteryLevel -= 5;
        std::cout << id << " is moving. Battery: " << batteryLevel << "%\n";
    }

    void checkFront() {
        int distance = frontSensor.getReading();  // delegate reading to the sensor
        std::cout << id << " front sensor reads " << distance << "cm\n";
    }
};

int main() {
    Robot robot("R-1");
    robot.move();
    robot.checkFront();
    robot.checkFront();

    return 0;
}
