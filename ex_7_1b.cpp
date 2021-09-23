// "Exercices en langage C++", Claude Delannoy, page 94.

#include <iostream.h>

class vecteur3d
 {    float x,y,z;
   public:
      vecteur3d(float c1=0.0, float c2=0.0, float c3=0.0)
       { x=c1; y=c2; z=c3;
       }
      friend int operator== (vecteur3d,vecteur3d);
      friend int operator!= (vecteur3d,vecteur3d);
 };

int operator== (vecteur3d v,vecteur3d w)
 { if ((v.x==w.x)&&(v.y==w.y)&&(v.z==w.z)) return 1;
   else return 0;
 }
int operator!= (vecteur3d v,vecteur3d w)
 { if (v==w) return 0;
   else return 1;
 }

int main()
 { vecteur3d A(1,2,3),B(1,2,4),C(1,2,3);

   if (A==B) cout << "A = B" << endl;
   if (A!=B) cout << "A <> B" << endl;
   if (A==C) cout << "A = C" << endl;
   if (A!=C) cout << "A <> C" << endl;
   return 0;
 }