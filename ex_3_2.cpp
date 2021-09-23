// "Exercices en langage C++", Claude Delannoy, page 29.

#include <iostream.h>

class point
 {    float x,y;
   public:
      point(float,float);
      void deplace(float,float);
      float abscisse();
      float ordonnee();
 };

main()
 { point A(3,4);

   cout << "(" << A.abscisse() << "," << A.ordonnee() << ")" << endl;
   A.deplace(6,9);
   cout << "(" << A.abscisse() << "," << A.ordonnee() << ")" << endl;
   return 0;
 }
point::point(float abs, float ord)
 { x=abs;
   y=ord;
 }
void point::deplace(float dx, float dy)
 { x+=dx;
   y+=dy;
 }
float point::abscisse()
 { return x;
 }
float point::ordonnee()
 { return y;
 }