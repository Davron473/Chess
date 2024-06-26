#include <iostream>

#include "coordinates.h"

using namespace std;

Coordinates::Coordinates()
{
    column = 0;
    row = '*';
};

Coordinates::Coordinates(char column, int row)
{
    this->column = column;
    this->row = row;
}

Coordinates::Coordinates(const Coordinates& crdns)
{
    this->column = crdns.column;
    this->row = crdns.row;
}

char Coordinates::indexToColumn(int indc)
{
    switch(indc)
    {
        case 0: return 'a';
        case 1: return 'b';
        case 2: return 'c';
        case 3: return 'd';
        case 4: return 'e';
        case 5: return 'f';
        case 6: return 'g';
        case 7: return 'h';
        default: return '*';
    }    
}

char Coordinates::getColumn()
{
    return this->column;
}

int Coordinates::getRow()
{
    return this->row;
}


void Coordinates::setColumn(char clmn)
{
    column=clmn;
}

void Coordinates::setRow(int row)
{
    this->row = row;
}


ostream& operator>>(ostream& os, const Coordinates& crdnd)
{
    os << "[" << crdnd.column <<","<< crdnd.row <<"]" <<endl ;
    return os;
}



int Coordinates::columnToIndex(char column)
{
    switch(column)
    {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        default:return -1;
    }
}