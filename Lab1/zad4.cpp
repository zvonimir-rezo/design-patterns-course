#include <iostream>
using namespace std;

class Base{
public:
  //if in doubt, google "pure virtual"
  virtual void set(int x)=0;
  virtual int get()=0;
};

class CoolClass: public Base{
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

int main(){
  PlainOldClass poc;
  Base* pb=new CoolClass;
  poc.set(42);
  pb->set(42);
}

/*
1. Alociranje memorije za CoolClass linija 111-113, 
PlainOldClass linija 136-137?
2. CoolClass zove konstruktor i zauzima prostor u memoriji, a kod PlainOldClass
se to događa implicitno.
3. Nema poziva konstruktora PlainOldClass.
4. Poziv konstruktora CoolClass je na liniji 140, a unutar te funkcije se poziva konstruktor nadklase.
5. poc.set(42) je na linijama 143-145, a pb->set(42) na linijama 146-151. Razlika je u tome što
pb->set ima više instrukcija. Razlog tome je što se nevirtualne
funckcije pozivaju direktno s neke memorijske lokacije i nije potrebno dohvaćati i dereferencirati
pokazivač na tablicu virtualnih funkcija.
6. Definicija na 162-170, inicijalizacija na 111
*/