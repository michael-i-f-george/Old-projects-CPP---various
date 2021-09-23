// "Exercices en langage C++", Claude Delannoy, page 118.

#include <iostream.h>

class point
 {    int x,y;
      static int nptd,npt;
   public:
      point(int abs=0, int ord=0)
       { x=abs; y=ord;
         npt++;
       }
      ~point()
       { npt--;
       }
      void* operatornew(size_t);
      void operatordelete(void*);
      static int npt_tot();
      static int npt_dyn();
 };

int point::nptd=0;
int point::npt=0;
void* point::operatornew(size_t sz)
 { nptd++;
   return ::new char[sz];
 }
void point::operatordelete(void* dp)
 { nptd--;
   ::delete [] dp;
 }
int point::npt_tot()
 { return npt;
 }
int point::npt_dyn()
 { return nptd;
 }

int main()
 { point *ad1, *ad2;

   point a(3,5);
   cout << point::npt_tot() << ", " << point::npt_dyn() << endl;
   ad1=new point(1,3);
   point b;
   cout << point::npt_tot() << ", " << point::npt_dyn() << endl;
   ad2=new point(2,0);
   delete ad1;
   cout << point::npt_tot() << ", " << point::npt_dyn() << endl;
   point c(2);
   delete ad2;
   cout << point::npt_tot() << ", " << point::npt_dyn() << endl;
   return 0;
 }