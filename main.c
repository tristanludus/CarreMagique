#include <stdio.h>
#include <stdlib.h>
#define TAILLE 7

//BUT: afficher un carré magique
//ENTREE: longueur et hauteur du tableau avec le remplissage des nombres croissant du tableau.
//SORTIE: un carré magique évoluant vers le nord-est.

typedef struct Pos
{
    int x;
    int y;
}Pos;

void Debut(Pos *ptPosition,int tabCarre[][TAILLE]);
void Forward(Pos *ptPosition,int tabCarre[][TAILLE],int nCase);
int Increase(int value);
int Decrease(int value);

int main()
{
    int tabCarre[TAILLE][TAILLE];
    int nEmplacement = TAILLE * TAILLE;
    int nCase;
    Pos Position;

    Pos *ptPosition = &Position;

    Debut(ptPosition,tabCarre);

    for(nCase=2;nCase<=nEmplacement;nCase++)
    {
        Forward(ptPosition,tabCarre,nCase);
    }

    for(Position.y=TAILLE-1;Position.y>=0;Position.y--)
    {
        for(Position.x=0;Position.x<=TAILLE-1;Position.x++)
        {
            printf("%d \t",tabCarre[Position.x][Position.y]);
        }

        printf("\n");
    }

    return 0;
}

void Debut(Pos *ptPosition,int tabCarre[][TAILLE])
{

    for(ptPosition->x=0;ptPosition->x<=TAILLE-1;ptPosition->x++)
    {
        for(ptPosition->y=0;ptPosition->y<=TAILLE-1;ptPosition->y++)
        {
            tabCarre[ptPosition->x][ptPosition->y]=0;
        }
    }

    ptPosition->x = TAILLE / 2;
    ptPosition->y = TAILLE / 2 + 1;
    tabCarre[ptPosition->x][ptPosition->y]=1;
}

void Forward(Pos *ptPosition,int tabCarre[][TAILLE],int nCase)
{
    int check=1;
    ptPosition->x = Increase(ptPosition->x);
    ptPosition->y = Increase(ptPosition->y);

    while(check)
    {
        if(tabCarre[ptPosition->x][ptPosition->y] == 0)
        {
            tabCarre[ptPosition->x][ptPosition->y] = nCase;
            check=0;
        }

        else
        {
            ptPosition->x = Decrease(ptPosition->x);
            ptPosition->y = Increase(ptPosition->y);
        }
    }
}

int Increase(int value)
{
    if(value == TAILLE-1)
        return 0;
    else
        return ++value;
}

int Decrease(int value)
{
    if(value == 0)
        return TAILLE-1;
    else
        return --value;
}
