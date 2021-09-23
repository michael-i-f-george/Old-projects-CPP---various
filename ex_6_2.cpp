// "Exercices en langage C++", Claude Delannoy, page 85.

#include <iostream.h>

class vecteur3d
 {    float x,y,z;
   public:
      vecteur3d(float c1=0.0, float c2=0.0, float c3=0.0)
       { x=c1; y=c2; z=c3;
       }
      friend int coincide(const vecteur3d&, const vecteur3d&);
 };

int coincide(const vecteur3d &v1,const vecteur3d &v2)
 { return v1.x==v2.x&&v1.y==v2.y&&v1.z==v2.z;
 }

int main()
 { vecteur3d a(1,2,3),b(1,2,4),c(1,2,3);

   if (coincide(a,b)) cout << "a=b." << endl;
   else cout << "a<>b." << endl;
   if (coincide(a,c)) cout << "a=c." << endl;
   else cout << "a<>c." << endl;
   return 0;
 }