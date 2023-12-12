#include "Snake.h"
#include <iostream>
#include <algorithm>


// ����������� ������ Snake, ����������� ��������� ��������� � ��������
Snake::Snake(COORD pos, int vel)
{
    // ������������� ���������� ������
    this->pos = pos;
    this->vel = vel;
    dir = 'n'; // ��������� �����������
    len = 1;   // ��������� ����� ����
    body.push_back(pos); // ��������� ��������� ����������� � ������ ���� ����
}

// ����� ��� ��������� ������ ����������� ����
void Snake::direction(char dir)
{
    this->dir = dir;
}

// ����� ��� ���������� ����� ����
void Snake::grow()
{
    len++;
}

// ����� ��� ��������� �������� ��������� ������ ����
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
    // ��������� ��������� ������ � ����������� �� �������� �����������
    switch (dir)
    {
    case 'u': pos.Y -= vel; break;
    case 'd': pos.Y += vel; break;
    case 'l': pos.X -= vel; break;
    case 'r': pos.X += vel; break;
    }

    // ���������� ������ ��������� ������ � ������ ���� ����
    body.push_back(pos);

    if (body.size() > len)
        body.erase(body.begin());
}

bool Snake::collided()
{
    // �������� �� ������������ � ��������� �������� ����
    if (pos.X < 1 || pos.X > WIDTH - 2 || pos.Y < 1 || pos.Y > HEIGHT - 2)
        return true;

    // �������� �� ������������ � ����� �����
    for (int i = 0; i < len - 1; i++)
    {
        if (pos.X == body[i].X && pos.Y == body[i].Y)
            return true;
    }

    return false;
}

// ���������� ��������� "==" ��� ��������� COORD
bool operator==(const COORD& lhs, const COORD& rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

//����� �� ���� ���
bool Snake::eaten(COORD food)
{
    // ���������� �������� STL ��� ��������, ����� �� ���� ���
    return std::find(body.begin(), body.end(), food) != body.end();;
}
