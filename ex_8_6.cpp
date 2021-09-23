// "Exercices en langage C++", Claude Delannoy, page 128.

#include <iostream.h>

class point
 {    int x,y;
   public:
      point(int abs=0, int ord=0)
       { x=abs; y=ord;
         cout << "Appel du constructeur: (" << x << "," << y << ")." << endl;
       }
      friend point operator+(point,point);      // point + point -> point;
      void affiche()
       { cout << "(" << x << "," << y << ")" << endl;
       }
 };

point operator+(point a,point b)
 { point r;
   r.x=a.x+b.x;
   r.y=a.y+b.y;
   return r;
 }

int main()
 { point a,b(2,4);                      // Appel du constructeur: (0,0). 
                                        // Appel du constructeur: (2,4).

   a=b+6;                               // Appel du constructeur: (6,0).
                                        // Appel du constructeur: (0,0).
   a.affiche();                         // (8,4)
   a=6+b;                               // Appel du constructeur: (6,0).
                                        // Appel du constructeur: (0,0).
   b.affiche();                         // (2,4)

   return 0;
 }