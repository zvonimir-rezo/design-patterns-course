#include <iostream>
using namespace std;

class CoolClass{
public:
  virtual void set(int x){x_=x;};
  virtual int get(){return x_;};
private:
  int x_;
};

class PlainOldClass{
public:
  void set(int x){x_=x;};
  int get(){return x_;};
private:
  int x_;
};

int main() {
    printf("CoolClass: %lu\n", sizeof(CoolClass));
    printf("PlainOldClass: %lu", sizeof(PlainOldClass));

    return 0;
}

/* 
sizeof(CoolClass) = 16 bajtova
sizeof(PlainOldClass) = 4 bajta

CoolClass ima pointer na virtualnu tablicu koji uzima 8 bajtova,
4 bajta za int i 4 bajta paddinga.
Nevirtualne metode ne zauzimaju memoriju klase pa zato PlainOldClass
ima samo 4 bajta zbog inta.
*/