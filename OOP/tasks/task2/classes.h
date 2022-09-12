#include <iostream>
#include <string>
using namespace std;

class Sales {
 private:
  enum { MONTHS = 3 };
  float salesArr[MONTHS];

 public:
  void getData();
  void putData() const;
};
//--------------------------------------------------------------
void Sales::getData() {
  cout << "Enter sales for 3 months\n";
  for (int j = 0; j < MONTHS; j++) {
    cout << " Month " << j + 1 << ": ";
    cin >> salesArr[j];
  }
}
void Sales::putData() const {
  for (int j = 0; j < MONTHS; j++) {
    cout << "\n Sales for month " << j + 1 << ": ";
    cout << salesArr[j];
  }
}

////////////////////////////////////////////////////////////////
class Publication {
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
    cout << "\n Price : " << price;
  }
};

class Book : private Publication, private Sales {
 private:
  int pages;

 public:
  void getdata() {
    Publication::getData();
    cout << " Enter number of pages : ";
    cin >> pages;
    Sales::getData();
  }
  void putdata() const {
    Publication::putData();
    cout << "\n Pages : " << pages;
    Sales::putData();
  }
};
////////////////////////////////////////////////////////////////
class tape : private Publication, private Sales {
 private:
  float time;

 public:
  void getdata() {
    Publication::getData();
    cout << " Enter playing time : ";
    cin >> time;
    Sales::getData();
  }
  void putdata() const {
    Publication::putData();
    cout << "\n Playing time : " << time;
    Sales::putData();
  }
};
