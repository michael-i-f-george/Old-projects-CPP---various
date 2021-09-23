// "Exercices en langage C++", Claude Delannoy, page 69.

#include <iostream.h>

class point
 {    int point_nbr;
      static int points_qty;
   public:
      point()
       { point_nbr=++points_qty;
         cout << "Creation du point: " << point_nbr << endl;
       }
      ~point()
       { cout << "Destruction du point: " << point_nbr << endl;
       }
 };
int point::points_qty=0;  // Initialisation de la variable statique
int main(void)
 { point *vecteur=new point[4];

   delete [] vecteur;
   return 0;
 }