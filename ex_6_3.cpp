// "Exercices en langage C++", Claude Delannoy, page 87.

#include <iostream.h>

class matrice;     // Pour pouvoir compiler la d‚claration de vect.
class vect
 {    double v[3];
   public:
      vect(double v1=0.0, double v2=0.0, double v3=0.0)
       { v[0]=v1; v[1]=v2; v[2]=v3;
       }
      void affiche()
       { cout << "(" << v[0] << "," << v[1] << "," << v[2] << ")" << endl;
       }
      friend vect prod(const matrice&, const vect&);
 };
class matrice
 {    double mat[3][3];
   public:
      matrice(double t[3][3]);
      friend vect prod(const matrice&,const vect&);
 };
matrice::matrice(double t[3][3])
 { int i,j;
   for (i=0; i<3; i++)
      for (j=0; j<3; j++)
         mat[i][j]=t[i][j];
 }
vect prod(const matrice &m,const vect &x)
 { int i,j,som;
   vect res;

   for (i=0; i<3; i++)
      { for (j=0, som=0; j<3; j++)
           som+=m.mat[i][j]*x.v[i];
        res.v[i]=som;
      }
   return res;
}

int main()
 { vect w(1,2,3);
   vect res;
   double tb[3][3]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
   matrice a=tb;

   res=prod(a,w);
   res.affiche();
   return 0;
 }