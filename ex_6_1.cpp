// "Exercices en langage C++", Claude Delannoy, page 83.

#include <iostream.h>

class point
 {    int x,y;
   public:
      point(int abs=0,int ord=0)
       { x=abs; y=ord;
       }
      friend void affiche(const point&);
 };

void affiche(const point& p)
 { cout << "(" << p.x << "," << p.y << ")" << endl;
 }

int main()
 { point a(1,5);

//   a.affiche();     // Erreur de compilation.
   affiche(a);
   point *adp;
   adp=new point(2,12);
   affiche(*adp);
   return 1;
 }