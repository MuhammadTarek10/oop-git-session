class Polymorphism:
    def __init__(self):
        self.implementation = None

    def set_implementation(self, implementation):
        self.implementation = implementation

    def method1(self):
        print("Polymorphism: method1")

    def method2(self):
        print("Polymorphism: method2")
    
    def method2(self, a):
        print("Polymorphism: method2(a)")

class App(Polymorphism):
    def method1(self):
        print("App: method1")


class App2(Polymorphism):
    def method1(self):
        print("App2: method1")


if __name__ == "__main__":
    print("App Started")
    # app = Polymorphism()
    # choice = 0
    # while True:
    #     choice = int(input())
    #     if choice == 1:
    #         app.set_implementation(App())
    #     elif choice == 2:
    #         app.set_implementation(App2())
    #     else:
    #         break
    #     app.implementation.method1()
    print("App Ended")
    