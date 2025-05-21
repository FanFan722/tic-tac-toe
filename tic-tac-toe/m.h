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

//variables

char grid[ROWS][COLS] = {
    {'1', '2', '3'}, 
    {'4', '5', '6'}, 
    {'7', '8', '9'}
};

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


#endif