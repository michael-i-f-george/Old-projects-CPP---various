// "Exercices en langage C++", Claude Delannoy, page 122.
// "Cours de langage C++" (1999), Anne Vandevorst et R.D., page 123.

#include <iostream.h>

class point
 {    int x,y;
   public:
      point(int abs=0, int ord=0)
       { x=abs; y=ord;
         cout << "Appel du constructeur: (" << x << "," << y << ")." << endl;
       }
      operator int()                    // Convertit un point en un int.
       { cout << "Conversion: (" << x << "," << y << ")." << endl;
         return x;            // Pas de type de valeur de retour dans le
       }            // le protype ou dans l'en-tete meme si on renvoie x.
 };

int main()
 { point a(3,4), b(5,7);
   int n1, n2;

   n1=int(a);                                          // <=> n1=(int) a.
   cout << "n1: " << n1 << endl;
   n2=b;                                     // Appel implicite de int().
   cout << "n2: " << n2 << endl;
   return 0;
 }