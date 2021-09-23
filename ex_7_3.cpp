// "Exercices en langage C++", Claude Delannoy, page 98.
// Surchage de l'opérateur []

#include <iostream.h>

class vecteur3d
 {    float v[3];
   public:
      vecteur3d(float c1=0.0, float c2=0.0, float c3=0.0)
       { v[0]=c1; v[1]=c2; v[2]=c3;
       }
      float& operator[](int);
      void affiche();
 };

float& vecteur3d::operator[](int i)         // Pq renvoi par reference?
  { if ((i<0)||(i>2)) i=0;
    return v[i];
  }
void vecteur3d::affiche()
 { cout << " v=(" << v[0] << "," << v[1] << "," << v[2] << ")" << endl;
 }

int main()
 { int a=0;
   vecteur3d v1(1.0,2.0,3.0);

   cout << v1[0] << endl;                  //Pq pas d'erreur de compile?
   cout << "a=" << a; v1.affiche();
   a=v1[0];
   v1[0]=17;
   cout << "a=" << a; v1.affiche();
   return 0;
 }