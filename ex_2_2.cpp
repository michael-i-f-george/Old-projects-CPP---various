// "Exercices en langage C++", Claude Delannoy, page 12.

#include <iostream.h>

void echange(int &, int &);

main()
 { int a=1,b=2;

   cout << "a: " << a << " b: " << b << endl;
   echange(a,b);
   cout << "a: " << a << " b: " << b;
   return 1;
 }

void echange(int &a, int &b)
 { int temp;

   temp=a;
   a=b;
   b=temp;
 }