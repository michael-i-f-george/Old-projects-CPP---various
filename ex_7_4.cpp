// "Exercices en langage C++", Claude Delannoy, page 99.

#include <iostream.h>

class set_int
 {    int *adval;                            // Table
      int nmax;                              // Nbre d'element maximal
      static int nelem;                      // Nbre d'elements courants
   public:
      set_int(int=20);
      set_int(set_int&);                     // Constructeur par recopie
      ~set_int();
      set_int& operator= (set_int&);          // pour "v1 = v2 = v3" et "v1 = v1"
      void ajoute(int);
      int appartient(int);
      int get_nelem();
      int get_nmax();
 };
set_int& set_int::operator= (set_int &e)
 { if (this!=&e)
     { delete [] adval;
       adval=new int[nmax=e.nmax];
       nelem=e.nelem;
       for (int i=0; i<nelem; adval[i++]=e.adval[i]);
     }
   return *this;
 }
int set_int::nelem=0;
set_int::set_int(int dim)
 { adval=new int[nmax=dim];
 }
set_int::set_int(set_int& ancien)
 { int i;

   nelem=ancien.nelem;
   adval=new int[nmax=ancien.nmax];
   for (i=0; i<nelem; i++)
      { adval[i]=ancien.adval[i];
      }
 }
set_int::~set_int()
 { delete [] adval;
   nelem--;
 }
void set_int::ajoute(int nombre)
 { if (!appartient(nombre)&&nelem<nmax)
     adval[nelem++]=nombre;
 }
int set_int::appartient(int nombre)
 { int i;

   for (i=0; (i<nelem)&&(adval[i]!=nombre); i++);
   return (i<nelem);
 }
int set_int::get_nmax()
 { return nmax;
 }
int set_int::get_nelem()
 { return nelem;
 }
int main()
 { set_int v1(20);

   v1.ajoute(13);
   v1.ajoute(5);
   v1.ajoute(1972);
   v1.ajoute(22);
   v1.ajoute(8);
   v1.ajoute(1974);
   v1.ajoute(8);
   v1.ajoute(9);
   v1.ajoute(1976);
   cout << "Quantite maximale d'elements: " << v1.get_nmax() << "." << endl;
   cout << "Nombre d'elements: " << v1.get_nelem() << "." << endl;
   return 0;
 }