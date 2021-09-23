// "Exercices en langage C++", Claude Delannoy, page 137.

#include <iostream.h>
#include <math.h>          //sqrt();

class point
 {    float x,y;
   public:
      void initialise(float abs=0.0,float ord=0.0)
       { x=abs; y=ord;
       }
      void affiche()
       { cout << "(" << x << "," << y << ")" << endl;
       }
      float abs()
       { return x;
       }
      float ord()
       { return y;
       }
 };
class pointb:public point
 { public:
      float rho();
 };
float pointb::rho()
 { return sqrt(abs()*abs()+ord()*ord());
 }