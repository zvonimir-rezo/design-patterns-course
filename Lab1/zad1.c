#include <stdio.h>
#include <stdlib.h>

typedef char const * (*PTRFUN)();

struct Animal {
  char *name;
  PTRFUN* table;
};

char const* dogGreet(void){
  return "vau!";
}
char const* dogMenu(void){
  return "kuhanu govedinu";
}
char const* catGreet(void){
  return "mijau!";
}
char const* catMenu(void){
  return "konzerviranu tunjevinu";
}

PTRFUN dogFunctions[2] = {dogGreet, dogMenu};
PTRFUN catFunctions[2] = {catGreet, catMenu};

void animalPrintGreeting(struct Animal* a) {
  printf("%s pozdravlja: %s\n", a->name, a->table[0]());
}

void animalPrintMenu(struct Animal* a) {
  printf("%s voli %s\n", a->name, a->table[1]());
}

struct Animal* constructDog(struct Animal* dog, char* name) {
  dog->name = name;
  dog->table = &dogFunctions[0];
  return dog;
}

struct Animal* constructCat(struct Animal* cat, char* name) {
  cat->name = name;
  cat->table = &catFunctions[0];
  return cat;
}

struct Animal* createDog(char* name) {
  struct Animal *dog = (struct Animal *) malloc(sizeof(struct Animal));
  dog = constructDog(dog, name);
  return dog;
}

struct Animal* createCat(char* name) {
  struct Animal *cat = (struct Animal *) malloc(sizeof(struct Animal));
  cat = constructCat(cat, name);
  return cat;
}

struct Animal* createNDogs(char** name, int n) {
  struct Animal *dogs = (struct Animal *) malloc(sizeof(struct Animal) * n);
  for (int i = 0; i < n; i++) {
    constructDog(&dogs[i], name[i]);
  }
  return dogs;
}

void testAnimals(void){
  struct Animal* p1=createDog("Hamlet");
  struct Animal* p2=createCat("Ofelija");
  struct Animal* p3=createDog("Polonije");

  animalPrintGreeting(p1);
  animalPrintGreeting(p2);
  animalPrintGreeting(p3);

  animalPrintMenu(p1);
  animalPrintMenu(p2);
  animalPrintMenu(p3);

  free(p1); free(p2); free(p3);
  printf("\n");
}

void testStackCreation() {
  struct Animal p1 = {"Hamlet", dogFunctions};
  struct Animal p2 = {"Ofelija", catFunctions};
  struct Animal p3 = {"Polonije", dogFunctions};

  animalPrintGreeting(&p1);
  animalPrintGreeting(&p2);
  animalPrintGreeting(&p3);

  animalPrintMenu(&p1);
  animalPrintMenu(&p2);
  animalPrintMenu(&p3);

  printf("\n");
}

void testNDogs(int n) {
  char *dogs[2]={'\0'};
  dogs[0]="Prvi";
  dogs[1]="Drugi";
  dogs[2]="Treci";
  
  struct Animal* dogsObj=createNDogs(dogs, n);

  for (int i = 0; i < n; i++) {
    animalPrintGreeting(&dogsObj[i]);
  }
}

int main(int argc, char *argv[]) {
  testAnimals();
  testStackCreation();
  testNDogs(3);
}