#ifndef MYSTRUCT_H_
#define MYSTRUCT_H_

typedef struct {
    char** array;
    int nb_lignes;
    int nb_colonnes;
}map_t;


typedef struct {
    int** array;
    int nb_lignes;
    int nb_colonnes;
}grid_t;

typedef enum {
    false,
    true
} bool;

#endif