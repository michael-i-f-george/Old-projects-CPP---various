// "Exercices en langage C++", Claude Delannoy, page 123.

#include <iostream.h>

class point
 {    int x,y;
   public:
      point(int abs=0, int ord=0)
       { x=abs; y=ord;
         cout << "Appel du constructeur: (" << x << "," << y << ")." << endl;
       }
      operator int()                                     // point -> int.
       { cout << "Appel de int(): (" << x << "," << y << ")." << endl;
         return x;                    // Pas de type de valeur de retour
       }                            // dans le protype ou dans l'en-tete.
 };

int main()
 { point a(1,5), b(2,8);                    // Appel du constructeur: (1,5).
                                            // Appel du constructeur: (2,8).

   int n1, n2, n3;
   n1=a+3;                                  // Appel de int(): (1,5).
   cout << "n1: " << n1 << "." << endl;     // n1: 4.
   n2=a+b;                                  // Appel de int(): (1,5).
                                            // Appel de int(): (2,8).
   cout << "n2: " << n2 << "." << endl;     // n2: 3.


   double z1, z2;                              
   z1=a+3;                                  // Appel de int(): (1,5).
   cout << "z1: " << z1 << "." << endl;     // z1: 4.
   z2=a+b;                                  // Appel de int(): (1,5).
                                            // Appel de int(): (2,8).
   cout << "z2: " << z2 << "." << endl;     // z2: 3.


   return 0;
 }