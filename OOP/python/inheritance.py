class Inheritance:
    age = 0
    def method1(self):
        print("Inheritance method1")

    def method2(self):
        print("Inheritance method2")


class App(Inheritance):
    def method1(self):
        print("App method1")



if __name__ == "__main__":
    print("App Started")
    # app = App()
    # app.method1()
    # print(f"Age: {app.age}")
    # app.method2()
    print("App Ended")