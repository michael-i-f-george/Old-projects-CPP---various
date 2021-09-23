/* Transposee d'une matrice, Michael George, 3 info, 4 fevrier 1999 */

#include <stdio.h> /* printf() */
#include <conio.h> /* clrscr(), getch() */

void transposee(int mat[4][4], int taille)
{ int taille2;

  taille2=(taille*2)-2;

  initia:asm { push ds               /* Sauve l'adresse du tableau */
               mov bx,65534          /* 1er indice = "-1" */
               mov di,65528          /* 2eme indice = "-8" */
               lds si,mat            /* "Charge" la matrice */
             }
  suite:asm { inc bx                 /* incremente 1er indice en partant de 0 */
              inc bx
              inc di                 /* incremente 2eme indice par pas de 4 en partant de 0 */
              inc di
              inc di
              inc di
              inc di
              inc di
              inc di
              inc di
              cmp di,taille2
              jl test
              sub di,taille2
            }
  test:asm { cmp bx,taille2          /* Fin de la matrice? */
             jge fin
           }
  echge:asm { push bx                /* Sauve element numero "di" dans cx */
              mov bx,di
              mov cx,[si+bx]
              pop bx
              mov ax,[si+bx]         /* Sauve element numero "bx" dans ax */
              cmp ax,cx
              jl suite               /* Evite le "double-echange" */

              mov [si+bx],cx
              push bx
              mov bx,di
              mov [si+bx],ax
              pop bx
              jmp suite
            }
  fin:asm { pop ds                   /* Renvoie adresse du tableau */
          }
 }

void main(void)
 { int matrice[4][4];
   int i,j;

/* Initialisation du tableau */
   for (i=0; i<4; i++)
      for (j=0; j<4; j++)
         matrice[i][j]=i*4+j;

/* Affichage de la matrice avant transposition */
   clrscr();
   printf("-- Avant\n");
   for (i=0; i<4; i++)
      { for (j=0; j<4; j++)
           printf(" %2d",matrice[i][j]);
        printf("\n");
      }

/* Transposition */
   transposee(matrice,16);

/* Affichage de la matrice apres transposition */
   printf("\n--Apres\n");
   for (i=0; i<4; i++)
      { for (j=0; j<4; j++)
           printf(" %2d",matrice[i][j]);
        printf("\n");
      }
   getch();
 }