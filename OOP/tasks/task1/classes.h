#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////
class Publication  // base class
{
 private:
  string title;
  float price;

 public:
  void getData() {
    cout << "\nEnter title : ";
    cin >> title;
    cout << "Enter price : ";
    cin >> price;
  }
  void putData() const {
    cout << "\nTitle : " << title;
    cout << "\nPrice : " << price;
  }
};

class Book : private Publication  // derived class
{
 private:
  int pages;

 public:
  void getData() {
    Publication::getData();
    cout << "Enter number of pages : ";
    cin >> pages;
  }
  void putData() const {
    Publication::putData();
    cout << "\nPages : " << pages;
  }
};

class tape : private Publication  // derived class
{
 private:
  float time;

 public:
  void getData() {
    Publication::getData();
    cout << "Enter playing time : ";
    cin >> time;
  }
  void putData() const {
    Publication::putData();
    cout << "\nPlaying time : " << time;
  }
};
