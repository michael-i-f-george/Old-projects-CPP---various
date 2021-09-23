// "Exercices en langage C++", Claude Delannoy, page 106.

#include <iostream.h>

class vect
 {    int *adr;
      int nelem;
   public:
      vect(int);
      ~vect();
      vect(vect&);
      vect& operator=(vect&);
      int& operator[](int);
 };

vect::vect(int n)
 { adr=new int[nelem=n];
   for (int i=0; i<nelem; i++) adr[i]=0;
 }
vect::~vect()
 { delete [] adr;
 }
vect::vect(vect& e)
 { adr=new int[nelem=e.nelem];
   for (int i=0; i<nelem; adr[i++]=e.adr[i]);
 }
vect& vect::operator=(vect& e)
 { if (this!=&e)
     { delete [] adr;
       adr=new int[nelem=e.nelem];
       for (int i=0; i<nelem; adr[i++]=e.adr[i]);
     }
   return *this;
 }
int& vect::operator[](int i)
 { if (i<0||i>nelem) i=0;
   return adr[i];
 }

int main()
 { vect v(6);

   int i;
   for (i=0; i<6; i++) v[i]=i;
   cout << "v: (";
   for (i=0; i<5; cout << v[i++] << ",");
   cout << v[5] << ")." << endl;
   return 0;
 }