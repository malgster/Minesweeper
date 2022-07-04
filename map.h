map_t* init_map(int lignes, int colonnes);
char map_content(map_t* mapu,int ligne, int colonne);
int print_map(map_t* mapu);
int put_in_map(map_t* mapu,int ligne, int colonne, char car);
int map_reveal(map_t* mapu,grid_t* gridu,int ligne, int colonne);
int finished(map_t* mapu, grid_t* gridu);