#include <iostream>
#include <string>
#include <vector>

// Stage 4: a real two-wheeled robot.
// Robot now HAS-A leftMotor, HAS-A rightMotor, and HAS-A frontSensor.
// move() coordinates all three components together: it checks the sensor
// first, and only spins both wheel motors if the path ahead is clear.
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

    void stop() {
        speed = 0;
        direction = Direction::STOPPED;
        std::cout << label << " motor stopped\n";
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
    int batteryLevel;
    Motor leftMotor;
    Motor rightMotor;
    DistanceSensor frontSensor;
    static const int SAFE_DISTANCE_CM = 50;

   public:
    Robot(std::string id)
        : id(id),
          batteryLevel(100),
          leftMotor("Left wheel"),
          rightMotor("Right wheel"),
          frontSensor("Front", 200, {120, 95, 40, 200}) {}

    void move(Direction dir) {
        int distance = frontSensor.getReading();
        if (dir == Direction::FORWARD && distance < SAFE_DISTANCE_CM) {
            std::cout << id << " detects an obstacle " << distance
                       << "cm ahead — stopping instead of moving.\n";
            leftMotor.stop();
            rightMotor.stop();
            return;
        }

        leftMotor.spin(dir, 70);
        rightMotor.spin(dir, 70);
        batteryLevel -= 5;
        std::cout << id << " is moving. Battery: " << batteryLevel << "%\n";
    }
};

int main() {
    Robot robot("R-1");
    robot.move(Direction::FORWARD);  // reading 120cm -> clear, moves
    robot.move(Direction::FORWARD);  // reading 95cm  -> clear, moves
    robot.move(Direction::FORWARD);  // reading 40cm  -> too close, stops

    return 0;
}
