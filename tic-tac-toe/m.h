#ifndef M
#define M
#include "ttt.c"

//define
#define COLS 3
#define ROWS 3

//prototypes

void ft_putchar(char c);
void fill_grid();

//Structs

typedef struct VECTOR2{

    int x;
    int y;

}Vector2;

typedef struct PLAYER{

    Vector2 v2;
    char sign;

}Player;

//variables

char grid[ROWS][COLS] = {
    {'1', '2', '3'}, 
    {'4', '5', '6'}, 
    {'7', '8', '9'}
};

void place (Player *player);
//functions

void ft_putchar(char c){
    write(1, &c, 1);
}

void fill_grid(){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            ft_putchar(grid[i][j]);
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}

void check(Player *player){
    if (grid[player->v2.x][player->v2.y] == 'O' || grid[player->v2.x][player->v2.y] == 'X'){
        printf("emplacement already taken !");
        place(player);
    }
} 

void place(Player *player){
    char c = player->sign;
    int n = -1;
    printf(" : ");
    scanf("%d", &n);
    switch(n) {
        case 1 : player->v2.x = 0, player->v2.y = 0, check(player); break;
        case 2 : player->v2.x = 1, player->v2.y = 0, check(player); break;
        case 3 : player->v2.x = 2, player->v2.y = 0, check(player); break;
        case 4 : player->v2.x = 0, player->v2.y = 1, check(player); break;
        case 5 : player->v2.x = 1, player->v2.y = 1, check(player); break;
        case 6 : player->v2.x = 1, player->v2.y = 2, check(player); break;
        case 7 : player->v2.x = 2, player->v2.y = 0, check(player); break;
        case 8 : player->v2.x = 2, player->v2.y = 1, check(player); break;
        case 9 : player->v2.x = 2, player->v2.y = 2, check(player); break;
    }
    grid[player->v2.x][player->v2.y] = player->sign;
}

void init_player(){
    Player player1;
    Player player2;
    player1.sign = 'X';
    player2.sign = 'O';
}

#endif