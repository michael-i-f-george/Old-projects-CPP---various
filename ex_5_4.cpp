// "Exercices en langage de programmation", Claude Delannoy, page 69.

#include <iostream.h>

class set_int
 {    int *vecteur;
      int dimension;
      static int cardinal;
   public:
      set_int(int=20);
      set_int(set_int&);                     // Constructeur par recopie
      ~set_int();
      void ajoute(int);
      int appartient(int);
      int get_cardinal();
      int get_dimension();
 };

int set_int::cardinal=0;
set_int::set_int(int dim)
 { vecteur=new int[dimension=dim];
 }
set_int::set_int(set_int& ancien)
 { int i;

   cardinal=ancien.cardinal;
   vecteur=new int[dimension=ancien.dimension];
   for (i=0; i<cardinal; i++)
      { vecteur[i]=ancien.vecteur[i];
      }
 }
set_int::~set_int()
 { delete [] vecteur;
   cardinal--;
 }
void set_int::ajoute(int nombre)
 { if (!appartient(nombre)&&cardinal<dimension)
     vecteur[cardinal++]=nombre;
 }
int set_int::appartient(int nombre)
 { int i;

   for (i=0; (i<cardinal)&&(vecteur[i]!=nombre); i++);
   return (i<cardinal);
 }
int set_int::get_dimension()
 { return dimension;
 }
int set_int::get_cardinal()
 { return cardinal;
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
   cout << "Quantite maximale d'elements: " << v1.get_dimension() << "." << endl;
   cout << "Nombre d'elements: " << v1.get_cardinal() << "." << endl;
   return 0;
 }