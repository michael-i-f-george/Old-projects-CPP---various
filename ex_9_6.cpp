// "Exercices en langage C++", Claude Delannoy, page 147.

class int2d
 {    int nlig;
      int ncol;
      int *adv;
   public:
      int2d(int nl,int nc);
      ~int2d();
      int &operator()(int,int);
 };
class int2db
 {    int ligdeb,ligfin;
      int coldeb,colfin;
   public:
      int2db(int ld, int lf, int cd, int cf):int2d(cd-ld+1,cf-lf+1)
       { ligdeb=ld;
         ligfin=lf;
         coldeb=cd;
         colfin=cf;
       }
      int& operator()(int lig,int col)
       { return int2d::operator(lig-liddeb)(col-coldeb);
       }
 };   