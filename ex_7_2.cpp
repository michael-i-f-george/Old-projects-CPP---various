// "Exercices en langage C++", Claude Delannoy, page 96.

#include <iostream.h>

class vecteur3d
 {    float x,y,z;
   public:
      vecteur3d(float c1=0.0, float c2=0.0, float c3=0.0)
       { x=c1; y=c2; z=c3;
       }
      void affiche();
      friend vecteur3d operator+ (vecteur3d,vecteur3d);
      friend int operator* (vecteur3d,vecteur3d);
 };

void vecteur3d::affiche()
 { cout << "(" << x << "," << y << "," << z << ")";
 }
vecteur3d operator+ (vecteur3d v1, vecteur3d v2)
 { vecteur3d v3;
 
   v3.x=v1.x+v2.x;
   v3.y=v1.y+v2.y;
   v3.z=v1.z+v2.z;
   return v3;
 }
int operator* (vecteur3d v1,vecteur3d v2)
 { return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
 }

int main()
 { vecteur3d v1(1,2,3),v2(4,5,6),v3;
   
   v3=v1+v2;
   cout << "Somme: ";
   v3.affiche();
   cout << endl; 
   cout << "Produit scalaire: " << v1*v2 << endl;
   return 0;
 }