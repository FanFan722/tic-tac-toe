#ifndef M
#define M
#include "ttt.c"

//define
#define Y 3
#define X 3

//Structs

typedef struct VECTOR2{

    int x;
    int y;

}Vector2;

typedef struct PLAYER{

    Vector2 v2;
    char sign;

}Player;

//prototypes

void ft_putchar(char c);
void fill_grid();
void place(Player *player);
bool check_emplacement(Player *player);
void init_player();
bool check_win();
bool check_draw();
void check(Player *player);

//variables

char grid[Y][X] = {
    {'1', '2', '3'}, 
    {'4', '5', '6'}, 
    {'7', '8', '9'}
};

Player player1;
Player player2;

int turn = 1;
bool won = false;
bool draw = false;

//functions

void ft_putchar(char c){
    write(1, &c, 1);
}

void fill_grid(){
    for (int i = 0; i < Y; i++){
        for (int j = 0; j < X; j++){
            ft_putchar(grid[i][j]);
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}

bool check_emplacement(Player *player){
    if (grid[player->v2.y][player->v2.x] == 'O' || grid[player->v2.y][player->v2.x] == 'X'){
        return true;
    }else {
        return false;
    }
} 

void check(Player *player){
    if(check_emplacement(player)){
        printf("This emplacement is already taken !");
        place(player);
    }else if (check_draw()){
        printf("DRAW !!!");
        draw = true;
    }else if (check_win()){
        printf("%c won !", player->sign);
        won = true;
    }else {
        grid[player->v2.y][player->v2.x] = player->sign;
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
        case 6 : player->v2.x = 2, player->v2.y = 1, check(player); break;
        case 7 : player->v2.x = 0, player->v2.y = 2, check(player); break;
        case 8 : player->v2.x = 1, player->v2.y = 2, check(player); break;
        case 9 : player->v2.x = 2, player->v2.y = 2, check(player); break;
    }
}

void init_player(Player *player1, Player *player2){
    player1->sign = 'X';
    player2->sign = 'O';
}

void game_loop(Player *player1, Player *player2){
    while (won != true || draw != true){
        init_player(player1, player2);
        if (turn == 1){
            fill_grid();
            place(player1);
            turn = 2;
        }
        else if (turn == 2){
            fill_grid();
            place(player2);
            turn = 1;
        }
    }
}

bool check_draw(){
    int count = 0;
    for (int i = 0; i < Y; i ++){
        for (int j = 0; j < X; j ++){
            if (grid[i][j] == 'X' || grid[i][j] == 'O'){
                count ++;
            }
        }
    }
    if (count >= 9){
        return true;
    }else {
        return false;
    }

}

bool check_win(){

    //check columns

    for (int i = 0; i < Y; i ++){
        int countX = 0;
        int countO = 0;
        for (int j = 0; j < X; j ++){
            if (grid[i][j] == 'X'){
                countX += 1;
                
            }
            else if (grid[i][j] == 'O'){
                countO += 1;
            }
        }
        if (countX >= 3){
            return true;
        }
        else if (countO >= 3){
            return true;
        }
    }

    return false;
}

#endif