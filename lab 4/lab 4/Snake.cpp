#include "Snake.h"
#include <iostream>
#include <algorithm>


// Конструктор класса Snake, принимающий начальное положение и скорость
Snake::Snake(COORD pos, int vel)
{
    // Инициализация переменных класса
    this->pos = pos;
    this->vel = vel;
    dir = 'n'; // Начальное направление
    len = 1;   // Начальная длина змеи
    body.push_back(pos); // Начальное положение добавляется в вектор тела змеи
}

// Метод для установки нового направления змеи
void Snake::direction(char dir)
{
    this->dir = dir;
}

// Метод для увеличения длины змеи
void Snake::grow()
{
    len++;
}

// Метод для получения текущего положения головы змеи
COORD Snake::get_pos()
{
    return pos;
}

vector<COORD> Snake::get_body()
{
    return body;
}

void Snake::move_snake()
{
    // Изменение положения головы в зависимости от текущего направления
    switch (dir)
    {
    case 'u': pos.Y -= vel; break;
    case 'd': pos.Y += vel; break;
    case 'l': pos.X -= vel; break;
    case 'r': pos.X += vel; break;
    }

    // Добавление нового положения головы в вектор тела змеи
    body.push_back(pos);

    if (body.size() > len)
        body.erase(body.begin());
}

bool Snake::collided()
{
    // Проверка на столкновение с границами игрового поля
    if (pos.X < 1 || pos.X > WIDTH - 2 || pos.Y < 1 || pos.Y > HEIGHT - 2)
        return true;

    // Проверка на столкновение с самой собой
    for (int i = 0; i < len - 1; i++)
    {
        if (pos.X == body[i].X && pos.Y == body[i].Y)
            return true;
    }

    return false;
}

// Перегрузка оператора "==" для сравнения COORD
bool operator==(const COORD& lhs, const COORD& rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

//съела ли змея еду
bool Snake::eaten(COORD food)
{
    // Используем алгоритм STL для проверки, съела ли змея еду
    return std::find(body.begin(), body.end(), food) != body.end();;
}
