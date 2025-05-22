#ifndef TTT
#define TTT
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "m.h"

int main(){
    game_loop(&player1, &player2);
    return 0;
}

#endif