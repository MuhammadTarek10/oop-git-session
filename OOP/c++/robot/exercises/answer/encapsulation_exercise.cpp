#include <iostream>

class Sensor {
    int maxRange;

   public:
    Sensor() {
        maxRange = 200;
    }

    void setMaxRange(int cm) {
        if (cm < 10) cm = 10;
        if (cm > 500) cm = 500;
        maxRange = cm;
    }

    int getMaxRange() const {
        return maxRange;
    }
};

int main() {
    Sensor sensor;
    std::cout << "Default max range: " << sensor.getMaxRange() << "cm\n";

    sensor.setMaxRange(300);
    std::cout << "Max range after setting 300: " << sensor.getMaxRange() << "cm\n";

    sensor.setMaxRange(9999);
    std::cout << "Max range after setting 9999: " << sensor.getMaxRange() << "cm\n";

    sensor.setMaxRange(-50);
    std::cout << "Max range after setting -50: " << sensor.getMaxRange() << "cm\n";

    return 0;
}
