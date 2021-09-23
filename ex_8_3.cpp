// "Exercices en langage C++", Claude Delannoy, page 125.

#include <iostream.h>

class point
 {    int x,y;
   public:
      point(int abs=0, int ord=0)
       { x=abs; y=ord;
       }
      operator int()                                     // point -> int.
       { cout << "Appel de int(): (" << x << "," << y << ")." << endl;
         return x;                    // Pas de type de valeur de retour.
       }
 };

void fct(double v)
 { cout << "Appel de fct(): " << v << endl;
 }

int main()
 { point a(1,4);
   int n1;
   double z1,z2;

   n1=a+1.75;                              // Appel de int(): (1,4).
   cout << "n1: " << n1 << "." << endl;    // n1: 2.
   z1=a+1.75;                              // Appel de int(): (1,4).
   cout << "z1: " << z1 << "." << endl;    // z1: 2.75.
   z2=a;                                   // Appel de int(): (1,4).
   cout << "z2: " << z2 << "." << endl;    // z2: 1.
   fct(a);                                 // Appel de int(): (1,4).
                                           // Appel de fct(): 1
   return 0;
 }