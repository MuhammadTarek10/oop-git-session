abstract class BaseClass {
  void method1() {
    print("Base");
  }

  void method2();
  void method3();
}

class ChildClass extends BaseClass {
  @override
  void method2() {
    print("Child method2");
  }

  @override
  void method3() {
    print("Child method3");
  }
}

void main() {
  final BaseClass app = ChildClass();
  app.method1();
  app.method2();
  app.method3();
}
