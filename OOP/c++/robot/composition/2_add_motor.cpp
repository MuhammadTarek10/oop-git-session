#include <iostream>
#include <string>

// Stage 2: Motor becomes a real, separate object.
// Robot no longer moves itself — it HAS a Motor and delegates to it.
// This is composition: Robot is built out of another object, not just data.
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
    int speed;  // 0-100, clamped — same validated-setter idea from encapsulation
    Direction direction;

   public:
    Motor() : speed(0), direction(Direction::STOPPED) {}

    void spin(Direction dir, int newSpeed) {
        if (newSpeed < 0) newSpeed = 0;
        if (newSpeed > 100) newSpeed = 100;
        speed = newSpeed;
        direction = dir;
        std::cout << "Motor spinning " << directionName(direction) << " at " << speed << "%\n";
    }
};

class Robot {
   private:
    std::string id;
    int batteryLevel;
    Motor motor;  // Robot HAS-A Motor

   public:
    Robot(std::string id) : id(id), batteryLevel(100) {}

    void move() {
        motor.spin(Direction::FORWARD, 70);  // delegate the actual work to Motor
        batteryLevel -= 5;
        std::cout << id << " is moving. Battery: " << batteryLevel << "%\n";
    }
};

int main() {
    Robot robot("R-1");
    robot.move();

    return 0;
}
