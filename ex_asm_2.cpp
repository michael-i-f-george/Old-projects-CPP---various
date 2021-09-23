/* Correction de l'examen d'assembleur du 4 fevrier 1999 (Transposee
   d'une matrice). */

#define MAX 5

#include <stdio.h>                   /* printf() */
#include <conio.h>                   /* clrscr(), getch() */
#include <stdlib.h>                  /* rand() */

void transposee(int mat[MAX][MAX], int taille)
{ /* Utilise deux indices: SI (balayage horizontal de la matrice) et
     DI (balayage vertical). Leurs positions sont exactement
     symetriques.
     BX correspond au debut de la matrice.
     DX contient l'adresse du dernier element du tableau. Il determine
     donc la fin du traitement.
     AX et CX sont utilises comme "variables" temporaires.
  */

  initia:asm { push ax               /* Sauvegarde sur pile registres */
               push bx               /* qui vont etre modifies. */
               push cx
               push dx
               mov dx,taille         /* DX <- adresse fin tableau. */
               add dx,taille
               sub dx,2
               mov si,65534          /* 1er indice <- "-1" */
               mov di,0              /* 2nd indice <- "-MAX" */
               sub di,MAX
               sub di,MAX
               mov bx,mat            /* BX <- adresse debut tableau. */
             }
  suite:asm { add si,2               /* Deplace 1er indice vers la droite. */
              add di,MAX             /* Descend 2nd indice d'une ligne. */
              add di,MAX
              cmp di,dx              /* Si 2nd indice sort de la... */
              jl test
              sub di,dx              /* ... matrice, on l'y ramene. */
            }
  test:asm { cmp si,dx               /* Fin de la matrice? */
             jge fin
           }
  echge:asm { cmp si,di              /* Compare les 2 indices (SI et DI) */
              jl suite               /* Evite le "double-echange". */
              mov ax,[bx+si]         /* Debut de l'echange. */
              mov cx,[bx+di]
              mov [bx+di],ax
              mov [bx+si],cx         /* Fin de l'echange. */
              jmp suite
            }
  fin:asm { pop dx                   /* Recupere valeurs registres. */
            pop cx
            pop bx
            pop ax
          }
 }

int main()
 { int matrice[MAX][MAX];
   int i,j;

/* Initialisation du tableau. */
   for (i=0; i<MAX; i++)
      for (j=0; j<MAX; j++)
         matrice[i][j]=rand()%100;

/* Affichage de la matrice avant transposition. */
   clrscr();
   printf("-- Avant\n");
   for (i=0; i<MAX; i++)
      { for (j=0; j<MAX; j++)
           printf(" %2d",matrice[i][j]);
        printf("\n");
      }

/* Transposition. */
   transposee(matrice,MAX*MAX);

/* Affichage de la matrice apres transposition. */
   printf("\n--Apres\n");
   for (i=0; i<MAX; i++)
      { for (j=0; j<MAX; j++)
           printf(" %2d",matrice[i][j]);
        printf("\n");
      }
   getch();
   return 0;
 }