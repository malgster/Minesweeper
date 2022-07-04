#include "mystructs.h"
#include "main.h"


map_t* new_map(int lignes, int colonnes){
    map_t* mapu;
    mapu = malloc(sizeof(*mapu));
    mapu->nb_colonnes = colonnes;
    mapu->nb_lignes = lignes;
    mapu->array = malloc(mapu->nb_lignes*sizeof(char *));
    int i;
    for (i=0; i < mapu->nb_lignes; i++){
        mapu->array[i] = malloc(mapu->nb_colonnes*sizeof(char));
    }
    return mapu;
}

map_t* init_map(int lignes, int colonnes)
{
    int i, j;
    map_t* terrain = new_map(lignes, colonnes);
    for(i=0; i<terrain->nb_lignes; i++){
        for(j=0; j<terrain->nb_colonnes; j++){
            *(*(terrain->array+i)+j) = '?';
        }
    }
    return terrain;
}

char map_content(map_t* terrain,int ligne, int colonne)
{
    return terrain->array[ligne][colonne];
}

int print_map(map_t* terrain)
{ 
    int idxL, idxC;
    int cpt = 0;
    printf("  || a | b | c | d | e | f | g | h |\n--++---+---+---+---+---+---+---+---+\n");
    for(idxL=0; idxL<terrain->nb_lignes; idxL++){
        printf("%d |", cpt);
        for(idxC=0; idxC<terrain->nb_colonnes; idxC++){
            printf("| %c ", terrain->array[idxL][idxC]);
        }
        printf("|\n");
        printf("--++---+---+---+---+---+---+---+---+\n");
        cpt++;
    }
    return 0;
}

int put_in_map(map_t* terrain ,int ligne, int colonne, char car)
{
     *(*(terrain->array+ligne)+colonne) = car;
    return 0;
}

int map_reveal(map_t* terrain,grid_t* grille ,int ligne, int colonne){
    if (grille->array[ligne][colonne] == 0){
        terrain->array[ligne][colonne] = bombs_around(ligne,colonne, grille) + '0';
    } else {
        put_in_map(terrain,ligne, colonne, '@');
        return 1;
    }
    return 0;
}

int finished(map_t* terrain, grid_t* grille){
    int idxL, idxC;
    for(idxL=0; idxL<terrain->nb_lignes; idxL++){
        for(idxC=0; idxC<terrain->nb_colonnes; idxC++){
            if(grille->array[idxL][idxC]== 0 && terrain->array[idxL][idxC]=='?'){
                return 0;
            }
        }
    }
    return 1;
}

