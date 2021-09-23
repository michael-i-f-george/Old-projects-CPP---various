// "Exercices en langage de C", Claude Delannoy, page 104.

#include <iostream.h>

class vecteur3d
 {    float v[3];
   public:
      vecteur3d(float c1=0.0, float c2=0.0, float c3=0.0)
       { v[0]=c1; v[1]=c2; v[2]=c3;
       }
      float& operator[](int);
      float operator[](int) const;
 };

float& vecteur3d::operator[](int n)
 { if (n<0||n>2) n=0;
   return v[n];
 }
float vecteur3d::operator[](int n) const
 { if (n<0||n>2) n=0;
   return v[n];
 }
int main()
 { vecteur3d v1(3,4,5);
   const vecteur3d v2(1,2,3);
   int i;

   cout << "v1: ";
   for (i=0; i<3; cout << v1[i++] << " ");
   cout << endl;
   cout << "v2: ";
   for (i=0; i<3; cout << v2[i++] << " ");
   cout << endl;
   for (i=0; i<3; v1[i++]=i);
   cout << "v1: ";
   for (i=0; i<3; cout << v1[i++] << " ");
   cout << endl;
   // v2[1]=3; est bien rejete a la compilation.
   return 0;
 }