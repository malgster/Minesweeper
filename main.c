#include "main.h"
int main (void)
{
    system("clear");
    printf("\n(¯`·.,,.·´¯`·.,,.-> Malgster's Minesweeper >-.,,.·`¯´·.,,.·`¯(\n\n");
    int lig, col;
    grid_t* grille = init_grid(8,8);
    map_t* terrain = init_map(8,8); 
    put_random_bombs(int_put(), grille);
    do {
        print_map(terrain);
        char_put();
        lig = get_lign_num();
        col = get_column_num();
        map_reveal(terrain, grille ,lig, col);
        system("clear");
    } while((map_reveal(terrain,grille,lig, col) == 0) && (finished(terrain, grille)== 0));
    if (finished(terrain, grille)== 0){
        printf("\nYOU LOST !\n");
    } else {
        printf("\nYOU WIN !\n\n");
    }
    print_map(terrain);
    printf("mines map reveal :");
    print_bombs(grille);
    int resp;
    printf("Replay ? (1 for YES / 0 for NO)");
    scanf("%d", &resp);
    if (resp == 1){
        main();
    }
    return 0;
}