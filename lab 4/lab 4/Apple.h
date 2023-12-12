#pragma once
#include <windows.h>
#include <cstdio>

#define WIDTH 50
#define HEIGHT 25

class Apple
{
private:
    COORD pos;

public:
    void gen_apple();

    COORD get_pos();
    Apple() {}
};