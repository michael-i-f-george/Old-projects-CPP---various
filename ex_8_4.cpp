// "Exercices en langage C++", Claude Delannoy, page 127.

#include <iostream.h>

class point
 {    int x,y;
   public:
      point(int abs=0, int ord=0)
       { x=abs; y=ord;
       }
      operator int()                                     // point -> int.
       { cout << "Appel de int(): (" << x << "," << y << ")." << endl;
         return x;                    
       }
      operator double()                               // point -> double.
       { cout << "Appel de double(): (" << x << "," << y << ")." << endl;
         return (1.0*x);
       }
 };

void fct(double v)
 { cout << "Appel de fct(): " << v << endl;
 }

int main()
 { point a(1,4);
   int n1;
   double z1,z2;

// n1=a+1.75;                                               // Ambiguite.
   n1=a;                                               // Appel de int().
   cout << "n1: " << n1 << "." << endl;
// z1=a+1.75;                                               // Ambiguite.
// cout << "z1: " << z1 << "." << endl;
   z2=a;                                            // Appel de double().
   cout << "z2: " << z2 << "." << endl;
   fct(a);                                          // Appel de double().
   return 0;
 }