#include <iostream>
#include <string>

// Stage 1: a bare Robot. No components yet — just its own data.
// This is where Part 1 left off. Composition starts in the next stage.
class Robot {
   private:
    std::string id;
    int batteryLevel;

   public:
    Robot(std::string id) : id(id), batteryLevel(100) {}

    void move() {
        batteryLevel -= 5;
        std::cout << id << " is moving. Battery: " << batteryLevel << "%\n";
    }

    std::string getId() const {
        return id;
    }
};

int main() {
    Robot robot("R-1");
    robot.move();
    robot.move();

    return 0;
}
