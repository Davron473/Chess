#pragma once
#include <iostream>
#include <utility>
#include "coordinates.h"
#include "piece.h"

using namespace std;

class Piece;

class Square
{
    friend class Board;

private:
    Coordinates Coordinates;
    string color;
    Piece *piece;

public:
    static const string NAME_BLACK;
    static const string NAME_WHITE;
    static const string NO_COLOR_NAME;

    void setColorCoordinates(char column, int row);
    void setColor(string color);
    void setPiece(Piece *pp);
    Coordinates getCoordinates();
    char getColumn();
    int getRow();
    string getColor();
    Piece * getPiece();

    Square();
    Square(Coordinates crdns, string clr, Piece *pp);


    ~Square();
};


class Board
{
    private: 
        int numRows, numColumns;

        Square * squares;


        int coordinateToIndex(Coordinates* postition);

    public:
        static void indentify()
        ;
        //

        void setNumRows(int fls);
        void setNumColumns(int clams);

        int getNumRows();
        int getNumColumns();
        Square *getSquares();


        Piece * pieceOn(char column, int row);
        Piece * pieceOn(Coordinates* position);


        Board()
        ;

        Board(int dim)
        ;

        Board(int dim, strings array_char_position);

        ~Board();
};