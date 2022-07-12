class Abstraction:
    def __init__(self, name) -> None:
        self.name = name
    
    def method1(self):
        print("Abstraction method1")

    def method2(self):
        pass

class Implementation(Abstraction):
    def method1(self):
        print("Implemtation1 Method1")

    def method2(self):
        print("Implemtation1 Method2")

class Implementation2(Abstraction):
    def method2(self):
        print("Implemtation2 Method2")

if __name__ == "__main__":
    print("App Started")
    # abstraction = Abstraction("Abstraction")
    # implementation = Implementation("Implementation")
    # implementation2 = Implementation2("Implementation2")
    # abstraction.method1()
    # abstraction.method2()
    # implementation.method1()
    # implementation.method2()
    # implementation2.method1()
    # implementation2.method2()
    print("App Ended")
        
    