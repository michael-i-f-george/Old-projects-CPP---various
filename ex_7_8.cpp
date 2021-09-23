// "Exercices en langage C++", Claude Delannoy, page 108.

#include <iostream.h>

class int2d
 {    int *adval;
      int nlig;
      int ncol;
   public:
      int2d(int,int);
      ~int2d();
      int& operator()(int,int);
 };

int2d::int2d(int l,int c)
 { nlig=l;
   ncol=c;
   adval=new int[nlig*ncol];
   for (int i=0; i<nlig*ncol; i++) adval[i]=0;
 }
int2d::~int2d()
 { delete [] adval;
 }
int& int2d::operator()(int i,int j)
 { if (i<0||i>=ncol) i=0;
   if (j<0||j>=ncol) j=0;
   return adval[i*ncol+j];
 }

int main()
 { int2d t(5,6);
   int i,j;

   for (i=0; i<5; i++)
      for (j=0; j<6; j++)
         t(i,j)=i*6+j;
   for (i=0; i<5; i++)
      { for (j=0; j<6; j++)
           cout << t(i,j) << " ";
        cout << endl;
      }
   cout << endl;
   return 0;
 }