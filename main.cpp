//
// Created by gabyfle on 22/03/23.
//

#include "Player.h"

/**
 * Entry point
 * @return 1 on fail, 0 on success
 */
int main(void) {

    Player *ply = new Player();

    ply->MakePlayerLaugh();

    delete ply;
    return 0;
}