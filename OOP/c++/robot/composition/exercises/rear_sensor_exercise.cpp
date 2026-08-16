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

/*
    Exercise: Composition

    The Robot below has a leftMotor, rightMotor, and frontSensor, just like
    stage 4. It's missing a rear sensor.

    TODO:
    1. Add a private `rearSensor` field (DistanceSensor).
    2. Initialize it in the constructor with label "Rear", maxRange 150,
       and readings {80, 30, 200}.
    3. Add a method `checkRear()` that reads it (same pattern as
       checkFront-style delegation you've already seen) and prints the
       result via the sensor's own getReading().
*/
class Robot {
   private:
    std::string id;
    Motor leftMotor;
    Motor rightMotor;
    DistanceSensor frontSensor;
    // TODO: DistanceSensor rearSensor;

   public:
    Robot(std::string id)
        : id(id),
          leftMotor("Left wheel"),
          rightMotor("Right wheel"),
          frontSensor("Front", 200, {120, 95, 40, 200})
          // TODO: initialize rearSensor here
    {}

    void move(Direction dir) {
        frontSensor.getReading();
        leftMotor.spin(dir, 70);
        rightMotor.spin(dir, 70);
    }

    // TODO: implement checkRear()
};

int main() {
    Robot robot("R-1");
    robot.move(Direction::FORWARD);
    // robot.checkRear();  // uncomment once checkRear() is implemented

    return 0;
}
