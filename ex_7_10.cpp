// "Exercices en langage C++", Claude Delannoy, page 114.

#include <stdlib.h>
#include <iostream.h>                           // exit()

class stack_int
 {    int nmax;
      int nelem;
      int *adv;
   public:
      stack_int(int=20);
      ~stack_int();
      stack_int(stack_int&);
      stack_int& operator<<(int);
      stack_int& operator>>(int&);
      int operator++(int);
      int operator--(int);
      void operator=(stack_int&);
 };

stack_int::stack_int(int max)
 {nmax=max; 
  adv=new int[nmax];
  nelem=0;
 }
stack_int::~stack_int()
 { delete [] adv;
 }
stack_int::stack_int(stack_int& p)
 { nelem=p.nelem;
   nmax=p.nmax;
   adv=new int [nmax];
   for (int i=0; i<nelem; i++) adv[i]=p.adv[i];
 }
stack_int& stack_int::operator<<(int n)
 { if (nelem<nmax) adv[nelem++]=n;
   return *this;
 }
stack_int& stack_int::operator>>(int& n)
 { if (nelem>0)
     { adv[nelem]=0;
       nelem--;
       n=adv[nelem];
     }
   else
      n=0;
   return *this;
 }
int stack_int::operator++(int fictif)
 { return (nelem==nmax);
 }
int stack_int::operator--(int fictif)
 { return (nelem==0);
 }
void stack_int::operator= (stack_int& p)
 { cout << "Tentative d'affectation entre piles: arret de l'execution." << endl;
   exit(1);
 }
int main()
 { void fct(stack_int);
   stack_int pile(40);

   cout << "Pleine: " << pile++ << ", vide: " << pile-- << "." << endl;
   pile << 1 << 2 << 3 << 4;
   fct(pile);
   int n,p;
   pile >> n >> p;
   cout << "Haut de la pile au retour de fct(): " << n << ", " << p
      << "." << endl;
   stack_int pileb(25);
   pileb=pile;
   return 0;                                  // Tentative d'affectation.
 }
void fct(stack_int pl)
 { cout << "Haut de la pile recue par fct(): ";
   int n,p;
   pl >> n >> p;
   cout << n << ", " << p << ". " << endl;
   pl << 12;
  }