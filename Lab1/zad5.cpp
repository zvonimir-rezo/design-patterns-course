#include <iostream>
using namespace std;

class B{
public:
  virtual int __cdecl prva()=0;
  virtual int __cdecl druga(int)=0;
};

class D: public B{
public:
  virtual int __cdecl prva(){return 42;}
  virtual int __cdecl druga(int x){return prva()+x;}
};

typedef int (*PTRFUN_PRVA)(B*);
typedef int (*PTRFUN_DRUGA)(B*, int);

void print(B* pb) {
	PTRFUN_PRVA** tablePointer = (PTRFUN_PRVA**)pb;
    PTRFUN_PRVA* table = *tablePointer;
	cout << table[0](pb) << endl;
	cout << ((PTRFUN_DRUGA)table[1])(pb, 5) << endl;
}

int main() {
	B* pb = new D;
	print(pb);
	return 0;
}