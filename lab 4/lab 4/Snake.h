#pragma once
#include <windows.h> // ������������ ���� ��� ������������� COORD � Windows API
#include <vector>
#include <iostream>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{
private:
    COORD pos; // ������� ������� ������ ����
    int vel;   // �������� �������� ����
    char dir;  // ����������� �������� ���� (u - �����, d - ����, l - �����, r - ������)
    int len;   // ����� ����
    vector<COORD> body; // ������, �������������� ���� ����

public:
    // ����������� �� ���������
    Snake() {}

    // ����������� � �����������
    Snake(COORD pos, int vel);

    // ����� ��� ���������� ����� ����
    void grow();

    // ����� ��� �������� ���� � ����������� �� �������� �����������
    void move_snake();

    // ����� ��� ��������� ����������� �������� ����
    void direction(char dir);

    //���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& os, Snake& snake) {
        os << snake.vel << snake.dir << snake.len;
        return os;
    }
    //���������� ��������� �����
    friend std::istream& operator>>(std::istream& os, Snake& snake) {
        os >> snake.vel;
        os >> snake.dir;
        os >> snake.len;
    }

    //  �������� ������������ ��� ������� Snake
    Snake& operator = (Snake& other) {

        if (this != &other) {  // �������� �� ����������������

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
