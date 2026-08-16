#include <iostream>

/*
    Exercise: Encapsulation

    A Sensor measures distance in centimeters, but it should never report
    a range below 10cm (too close to be useful) or above 500cm (out of
    hardware range).

    TODO:
    1. Add a private field `maxRange` (int).
    2. In the constructor, initialize maxRange to 200.
    3. Write a setter `setMaxRange(int cm)` that clamps the value between
       10 and 500 before storing it.
    4. Write a getter `getMaxRange()` that returns maxRange.
*/
class Sensor {
    // TODO: private field goes here

   public:
    Sensor() {
        // TODO: initialize maxRange to 200
    }

    void setMaxRange(int cm) {
        // TODO: clamp cm between 10 and 500, then store it
    }

    int getMaxRange() const {
        // TODO: return maxRange
        return 0;
    }
};

int main() {
    Sensor sensor;
    std::cout << "Default max range: " << sensor.getMaxRange() << "cm\n";

    sensor.setMaxRange(300);
    std::cout << "Max range after setting 300: " << sensor.getMaxRange() << "cm\n";

    sensor.setMaxRange(9999);  // should clamp to 500
    std::cout << "Max range after setting 9999: " << sensor.getMaxRange() << "cm\n";

    sensor.setMaxRange(-50);  // should clamp to 10
    std::cout << "Max range after setting -50: " << sensor.getMaxRange() << "cm\n";

    return 0;
}
