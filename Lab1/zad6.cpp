#include <stdio.h>

class Base{
public:
  Base() {
    metoda();
  }

  virtual void virtualnaMetoda() {
    printf("ja sam bazna implementacija!\n");
  }

  void metoda() {
    printf("Metoda kaze: ");
    virtualnaMetoda();
  }
};

class Derived: public Base{
public:
  Derived(): Base() {
    metoda();
  }
  virtual void virtualnaMetoda() {
    printf("ja sam izvedena implementacija!\n");
  }
};

int main(){
  Derived* pd=new Derived();
  pd->metoda();
}

/* 
Na liniji 105 se poziva Base() konstruktor, a tek nakon njega
se mijenja pointer na tablicu virtualnih funkcija.
*/