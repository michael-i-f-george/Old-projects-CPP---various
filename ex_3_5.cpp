// "Exercices en langage C++", Claude Delannoy, page 36.

#include <iostream.h>

class point
 {    float x,y;
      static compteur;
   public:
      point(float,float);
      ~point();
      void deplace(float,float);
      float abscisse();
      float ordonnee();
      void affiche();
 };

int main()
 { point A(3,4),B(4,5);

   cout << "(" << A.abscisse() << "," << A.ordonnee() << ")" << endl;
   A.deplace(6,9);
   cout << "(" << A.abscisse() << "," << A.ordonnee() << ")" << endl;
   A.affiche();
   return 0;
 }
int point::compteur=0;
point::point(float abs, float ord)
 { x=abs;
   y=ord;
   compteur++;
 }
point::~point()
 { compteur--;
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
void point::affiche()
 { cout << "(" << x << "," << y << "), " << compteur << " element(s)." << endl;
 }