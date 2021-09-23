// "Exercices en langage C++", Claude Delannoy, page 111.

#include <iostream.h>

class histo
 {    float min;
      float max;
      int nint;
      int *adc;
      float ecart;      // Largeur d'une tranche.
   public:
      histo(float=0.0,float=1.0,int=10);
      ~histo();
      histo& operator<<(float);
      int operator[](int);
 };

histo::histo(float mini,float maxi,int ninter)
 { if (maxi<mini)
     { int temp=maxi;
       maxi=mini;
       mini=temp;
     }
   if (maxi==mini) maxi++;
   if (ninter<1) ninter=1;
   min=mini;
   max=maxi;
   nint=ninter;
   adc=new int[nint-1];
   for (int i=0; i<nint; i++) adc[i]=0;
   ecart=(max-min)/nint;
 }
histo::~histo()
 { delete [] adc;
 }
histo& histo::operator<<(float v)
 { int nt=(v-min)/ecart;
   if ((nt>=0)&&(nt<=nint-1)) adc[nt]++;
   return *this;
 }
int histo::operator[](int n)
 { if (n<1||n>nint) n=1;
   return adc[n-1];
 }

int main()
 { const int nint=4;
   int i;
   histo h(0.,5.,nint);

   h << 1.5 << 2.4 << 3.8 << 3.0 << 2.0 << 3.5 << 2.8 << 4.6;
   h << 12.0 << -3.5;
   for (i=0; i<10; i++) h << i/2.0;
   cout << "valeurs des tranches \n";
   for (i=1; i<=nint; i++)
      cout << "num‚ro " << i << ": " << h[i] << "\n";
   return 0;
 }