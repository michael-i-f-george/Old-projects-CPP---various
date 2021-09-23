// "Exercices en langage C++", Claude Delannoy, page 148.

#include "vect.h"
#include <iostream.h>

class vectok:public vect
 { public:
      vectok(int dim):vect(dim)     // Constr. de vectok: appelle constr. de vect.
       {}
      vectok(vectok&);
      vectok& operator=(vectok&);
      int taille()
       { return nelem;
       }
 };
vectok::vectok(vectok &v):vect(v.nelem)     // Constr. par recopie de vectok.
 { for (int i=0; i<nelem; i++) adr[i]=v.adr[i];
 }
vectok& vectok::operator=(vectok &v)
 { if (this!=&v)
     { delete adr;
       adr=new int[nelem=v.nelem];
       for (int i=0; i<nelem; i++) adr[i]=v.adr[i];
     }
   return *this;
 }

int main()
 { void fct(vectok);
   int i;

   vectok v(6);
   for (i=0; i<v.taille(); i++) v[i]=i;
   cout << "Vecteur v:";
   for (i=0; i<v.taille(); i++) cout << " " << v[i];
   cout << endl;

   vectok w(3);
   w=v;
   cout << "Vecteur w:";
   for (i=0; i<w.taille(); i++) cout << " " << w[i];
   cout << endl;

   fct(v);

   return 0;
 }
void fct(vectok v)
 { cout << "Vecteur recu par fct:";
   for (int i=0; i<v.taille(); i++) cout << " " << v[i];
   cout << endl;
 }