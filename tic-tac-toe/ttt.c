#ifndef TTT
#define TTT
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "m.h"

int main(){
    Player player1;
    Player player2;
    player1.sign = 'X';
    player2.sign = 'O';
    fill_grid();
    place(&player1);
    return 0;
}

#endif