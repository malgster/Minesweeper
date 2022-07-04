#include "main.h"

grid_t* new_grid(int lignes, int colonnes){
    grid_t* gridu;
    gridu = malloc(sizeof(*gridu));
    gridu->nb_colonnes = colonnes;
    gridu->nb_lignes = lignes;
    gridu->array = malloc(gridu->nb_lignes*sizeof(int *));
    int i;
    for (i=0; i < gridu->nb_lignes; i++){
        gridu->array[i] = malloc(gridu->nb_colonnes*sizeof(int));
    }
    return gridu;
}

grid_t* init_grid(int lignes, int colonnes) // initialise une grille de mine vide
{
    grid_t* gridu = new_grid(lignes, colonnes);
    int i, j;
    for(i=0; i<gridu->nb_lignes; i++){
        for(j=0; j<gridu->nb_colonnes; j++){
            *(*(gridu->array+i)+j) = 0;
        }
    }
    return gridu;
}

int print_bombs(grid_t* gridu) // affiche la grille des mines.
{
    int idxL, idxC;
    printf("\n+---+---+---+---+---+---+---+---\n");
    for(idxL=0; idxL<gridu->nb_lignes; idxL++){
        for(idxC=0; idxC<gridu->nb_colonnes; idxC++){
            printf("| %d ", gridu->array[idxL][idxC]);
        }
        printf("|\n");
        printf("+---+---+---+---+---+---+---+---\n");
    }
    return 0;
}

int is_a_bomb(int ligne, int colonne, grid_t* gridu)
{
    return gridu->array[ligne][colonne];
}

int put_bomb(int ligne, int colonne, grid_t* gridu) // place une mine manuellement sur la carte.
{
    gridu->array[ligne][colonne] = 1;
    return 0;
}

int bombs_around(int lig, int col, grid_t* grille) // renvoi le nombre de mine autour de la case dévoilée (si la case est vide ofc).
{
    int idxL, idxC;
    int res = 0;
    for (idxL=lig-1; idxL<=lig+1; idxL++) {
        for (idxC=col-1; idxC<=col+1; idxC++) {
            if ((idxL>=0 && idxC>=0) && (idxL<grille->nb_lignes && idxC<grille->nb_colonnes)) {
                if (grille->array[idxL][idxC]==1){
                    res+= 1;
                }
            }
        }
    }
    if (grille->array[lig][col]==1) {
            res-=1;
    }
    return res;   
}

int put_random_bombs(int nb_mines, grid_t* gridu) // place dans la grille un nombre de mines choisi par l'utilisateur.
{
    int i;
    srand(time(NULL));
    for(i=0; i <=nb_mines; i++){
    put_bomb(rand()%gridu->nb_colonnes,rand()%gridu->nb_lignes, gridu);
    }
    return 0;
}

