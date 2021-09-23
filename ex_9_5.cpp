// "Exercices en langage C++", Claude Delannoy, page 144.

class vect
 {    int nelem;
      int *adr;
   public:
      vect(int);
      vect();
      int& operator[](int);
 };
class vectb
 {    int debut;
      int fin;
   public:
      vectb(int de,int fi):vect(fi-de+1)
       { if (de>fi)
           { int temp;
             temp=de;
             de=fi;
             fi=temp;
           }
       }
      int& operator[](int i)
       { return vect::operator[](i-debut);
       }
 };