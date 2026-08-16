#include <iostream>
#include <string>
#include <vector>

enum class Direction { FORWARD, BACKWARD, STOPPED };

std::string directionName(Direction dir) {
    switch (dir) {
        case Direction::FORWARD:
            return "FORWARD";
        case Direction::BACKWARD:
            return "BACKWARD";
        default:
            return "STOPPED";
    }
}

class Motor {
   private:
    std::string label;
    int speed;
    Direction direction;

   public:
    Motor(std::string label) : label(label), speed(0), direction(Direction::STOPPED) {}

    void spin(Direction dir, int newSpeed) {
        if (newSpeed < 0) newSpeed = 0;
        if (newSpeed > 100) newSpeed = 100;
        speed = newSpeed;
        direction = dir;
        std::cout << label << " motor spinning " << directionName(direction)
                   << " at " << speed << "%\n";
    }
};

class DistanceSensor {
   private:
    std::string label;
    int maxRange;
    std::vector<int> readings;
    size_t nextReadingIndex;

   public:
    DistanceSensor(std::string label, int maxRange, std::vector<int> readings)
        : label(label), maxRange(maxRange), readings(readings), nextReadingIndex(0) {}

    int getReading() {
        int raw = readings[nextReadingIndex % readings.size()];
        nextReadingIndex++;
        if (raw > maxRange) raw = maxRange;
        std::cout << label << " sensor reads " << raw << "cm\n";
        return raw;
    }
};

class Robot {
   private:
    std::string id;
    Motor leftMotor;
    Motor rightMotor;
    DistanceSensor frontSensor;
    DistanceSensor rearSensor;

   public:
    Robot(std::string id)
        : id(id),
          leftMotor("Left wheel"),
          rightMotor("Right wheel"),
          frontSensor("Front", 200, {120, 95, 40, 200}),
          rearSensor("Rear", 150, {80, 30, 200}) {}

    void move(Direction dir) {
        frontSensor.getReading();
        leftMotor.spin(dir, 70);
        rightMotor.spin(dir, 70);
    }

    void checkRear() {
        rearSensor.getReading();
    }
};

int main() {
    Robot robot("R-1");
    robot.move(Direction::FORWARD);
    robot.checkRear();

    return 0;
}
