// "Exercices en langage C++", Claude Delannoy, page 141.

#include <iostream.h>

class point
 {    float x,y;
   public:
      point(float abs=0.0,float ord=0.0)
       { x=abs; y=ord;
       }
      void affiche()
       { cout << "(" << x << "," << y << ")" << endl;
       }
      void deplace(float dx,float dy)
       { x=x+dx;
         y=y+dy;
       }
 };
class pointcol
 {    point p;
      int cl;
   public:
      pointcol(float a,float b, int c);
      void affiche()
       { p.affiche();
         cout << "[" << cl << "]" << endl;
       }
      void colore(int c)
       { cl=c;
       }
 };
pointcol::pointcol(float abs,float ord,int coul):p(abs,ord)
 { cl=coul;
 }