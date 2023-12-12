#include "Apple.h"
#include <iostream>


void Apple::gen_apple()
{
    pos.X = (rand() % WIDTH - 1) + 1;
    pos.Y = (rand() % HEIGHT - 1) + 1;
}

COORD Apple::get_pos() { return pos; }