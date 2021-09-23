// "Cours de langage C++" (1999), Anne Vandevorst et R.D., page 144.

class Base
 { public:
      void f();
      int publ;
   protected:
      int prot;
   private:
      int priv;
 };
void Base::f()
 { publ=1;
   prot=2;
   priv=3;
 }

class Derive: public Base
 { public:
      void g();
 };
void Derive::g()
 { publ=1;
   prot=2;
   priv=3; // Pas accessible
 }

int main()
 { 
   Base b;
   b.publ=1;
   b.prot=2;     // Inaccessible.
   b.priv=3;     // Inaccessible.

   Derive d;
   d.publ=1;
   d.prot=2;     // Inaccessible.
   d.priv=3;     // Inaccessible.

   return 1;
 }