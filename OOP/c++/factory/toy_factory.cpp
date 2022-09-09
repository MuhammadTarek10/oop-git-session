#include "toy.h"
#include "types.h"

class ToyFactory {
 public:
  static Toy* createToy(ToyTypes type) {
    Toy* toy = NULL;
    switch (type) {
      case CAR:
        toy = new Car;
        break;
      case BIKE:
        toy = new Bike;
        break;
      case PLANE:
        toy = new Plane;
        break;
      default:
        std::cout << "Invalid Type" << std::endl;
        return NULL;
    }

    toy->prepareParts();
    toy->combineParts();
    toy->assembleParts();
    toy->applyLabel();

    return toy;
  }
};