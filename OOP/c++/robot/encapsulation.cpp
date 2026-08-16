#include <iostream>

class Motor {
   private:
    int speed;  // 0-100, never set directly from outside

   public:
    Motor() : speed(0) {}

    void setSpeed(int newSpeed) {
        if (newSpeed < 0) newSpeed = 0;
        if (newSpeed > 100) newSpeed = 100;
        speed = newSpeed;
        std::cout << "Motor speed set to " << speed << "%\n";
    }

    int getSpeed() const {
        return speed;
    }
};

class Robot {
   private:
    int batteryLevel;  // 0-100, protected from invalid values

   public:
    Robot() : batteryLevel(100) {}

    void consumeBattery(int amount) {
        batteryLevel -= amount;
        if (batteryLevel < 0) batteryLevel = 0;
        std::cout << "Battery drained to " << batteryLevel << "%\n";
    }

    void chargeBattery(int amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) batteryLevel = 100;
        std::cout << "Battery charged to " << batteryLevel << "%\n";
    }

    int getBatteryLevel() const {
        return batteryLevel;
    }
};

int main() {
    Motor motor;
    motor.setSpeed(60);
    motor.setSpeed(9999);  // clamped to 100, can't burn out the motor
    std::cout << "Final motor speed: " << motor.getSpeed() << "%\n\n";

    Robot robot;
    robot.consumeBattery(30);
    robot.consumeBattery(9999);  // clamped to 0, can't go negative
    robot.chargeBattery(50);
    std::cout << "Final battery level: " << robot.getBatteryLevel() << "%\n";

    return 0;
}
