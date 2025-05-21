#ifndef M
#define M
#include "ttt.c"

//prototypes

void ft_putchar(char c);
void fill_grid();
void turn(char player);
void check(int n, char player);
void game();
void check_win();

//variables

int turnn = 1;
const char player1 = 'X';
const char player2 = 'O';
int n = -1;
bool is_running = false;
int played = 0;

//functions

void ft_putchar(char c){
    write(1, &c, 1);
}

char grid[9] = {
    '1', '2', '3',
    '4', '5', '6', 
    '7', '8', '9'
};

void fill_grid(){
    int rows, columns;
    int current = 0;
    printf("==================\n");
    for (rows = 0; rows< 3; rows++){
        for(columns = 0; columns < 3; columns++){
            ft_putchar(grid[current]);
            ft_putchar(' ');
            current ++;
        }
        ft_putchar('\n');
    }

}

void turn(char player){
    fill_grid();
    printf(" : ");
    scanf("%d", &n);
    check(n, player);
    switch(n) {
        case 1 : grid[0] = player; break; 
        case 2 : grid[1] = player; break;
        case 3 : grid[2] = player; break;
        case 4 : grid[3] = player; break;
        case 5 : grid[4] = player; break;
        case 6 : grid[5] = player; break;
        case 7 : grid[6] = player; break;
        case 8 : grid[7] = player; break;
        case 9 : grid[8] = player; break;
    }
     
}

void check(int n, char player){
    if (grid[n - 1] == player1 || grid[n - 1] == player2){
        printf("emplacement already taken !\n");
        turn(player);
    }
    played += 1;
    if (played >= 9){
        is_running = false;
        printf("DRAW !!\n");
    }
    
}

void game(){
    is_running = true;
    do {
        if (turnn == 1){
            turn(player1);
            turnn = 2; 
        }
        else if (turnn == 2){
            turn(player2);
            turnn = 1;
        }
    }while (is_running == true);
}

#endif