#include "main.h"

char entree[2];

int char_put(void)
{   
    bool done = false;
    while (done != true){
        printf("Select the case : ");
        scanf("%s",entree);
        printf("choosen lign : %c\n", entree[0]);
        printf("choosen column : %c\n", entree[1]);
        if (entree[0] >= 'a' && entree[0] <= 'h' && entree[1] >= '0' && entree[1] <= '7'){
            done = true;
        } else {
            printf("wrong input, try again\n");
        }
    }
    return 0;
}

int get_column_num (void)
{
    return entree[0] - 'a';
}

int get_lign_num (void)
{
  return entree[1] - '0';  
}

int int_put(void){
    int num = 1;
    int read = 0;
    bool done = false;
    do {
        printf("how many mines do you want ?\n");
        read = scanf("%d", &num);
        while (read != 1){
            printf("wrong input, try again.\n");
            scanf("%*[^\n]"); // regex that frees the buffer
            printf("how many mines do you want ?\n");
            read = scanf("%d", &num);
        }
        if (num < 64 && num > 0){
        printf("you entered %d\n", num);
        done = true;
        } else {
            printf("the limit for bombs is 64, try again.\n");
        }
    } while (done != true);
    return num;
}
