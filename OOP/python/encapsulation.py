class Encapsulation:
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    def getName(self):
        return self.__name

    def getAge(self):
        return self.__age

    def setName(self, name):
        self.__name = name

    def setAge(self, age):
        self.__age = age

    def __str__(self):
        return "Name: " + self.__name + " Age: " + str(self.__age)

if __name__ == "__main__":
    print("App Started")
    # encapsulation = Encapsulation("John", 30)
    # print(encapsulation)
    # encapsulation.setName("Jane")
    # encapsulation.setAge(31)
    # # encapsulation.__age(32)
    # print(encapsulation)
    print("App Ended")