grid_t* new_grid(int lignes, int colonnes);
int is_a_bomb(int ligne, int colonne, grid_t* gridu);
int put_bomb(int ligne, int colonne, grid_t* gridu);
int print_bombs(grid_t* gridu);
grid_t* init_grid(int lignes, int colonnes); 
int bombs_around(int ligne, int colonne, grid_t* gridu);
int put_random_bombs(int nb_mines, grid_t* gridu);
