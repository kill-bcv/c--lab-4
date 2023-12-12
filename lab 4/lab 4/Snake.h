#pragma once
#include <windows.h> // Заголовочный файл для использования COORD в Windows API
#include <vector>
#include <iostream>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{
private:
    COORD pos; // Текущая позиция головы змеи
    int vel;   // Скорость движения змеи
    char dir;  // Направление движения змеи (u - вверх, d - вниз, l - влево, r - вправо)
    int len;   // Длина змеи
    vector<COORD> body; // Вектор, представляющий тело змеи

public:
    // Конструктор по умолчанию
    Snake() {}

    // Конструктор с параметрами
    Snake(COORD pos, int vel);

    // Метод для увеличения длины змеи
    void grow();

    // Метод для движения змеи в зависимости от текущего направления
    void move_snake();

    // Метод для изменения направления движения змеи
    void direction(char dir);

    //объявление оператора вывода
    friend std::ostream& operator<<(std::ostream& os, Snake& snake) {
        os << snake.vel << snake.dir << snake.len;
        return os;
    }
    //объявление оператора ввода
    friend std::istream& operator>>(std::istream& os, Snake& snake) {
        os >> snake.vel;
        os >> snake.dir;
        os >> snake.len;
    }

    //  оператор присваивания для объекта Snake
    Snake& operator = (Snake& other) {

        if (this != &other) {  // Проверка на самоприсваивание

            this->pos = other.pos;
            this->vel = other.vel;
            this->dir = other.dir;
            this->len = other.len;
            this->body = other.body;
        }
        return *this;
    }

    bool operator == (Snake& other) {
        return this->vel == other.vel && this->dir == other.dir && this->len==other.len;
    }
    
    vector<COORD> get_body();

    bool collided();
    bool eaten(COORD food);

    COORD get_pos();
};
