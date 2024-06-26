#include <iostream>

#include "board.h"
#include "coordinates.h"
#include "piece.h"

using namespace std;

const string Square::NAME_BLACK = "black";
const string Square::NAME_WHITE = "white";
const string Square::NO_COLOR_NAME = "*";

Square::Square()
{
    Coordinates = Coordinates();
    color = Square::NO_COLOR_NAME;
    piece = nullptr;
}

Square::Square(Coordinates crdns, string clr, Piece *pp)
{
    Coordinates = crdns;
    color = clr;
    piece = pp;
}

void Square::setColorCoordinates(char column, int row)
{
    if ((row % 2)== 0)
    {
        if ((Coordinates::columnToIndex(column) % 2)==0)
        {
            this->color = Square::NAME_WHITE;
        }
        else
            this->color = Square::NAME_BLACK;
    }
    else if ((Coordinates::columnToIndex(column) % 2) != 0)
    {
            this->color = Square::NAME_WHITE;
    }
    else
            this->color = Square::NAME_BLACK;

        this->coordinates.setColumn(column);
        this->coordinates.setrow(row);
    }

    void Square::setColor(string color)
    {
        this->color = color;
    }

    void Square::setPiece(Piece *pp)
    {
        this->piece = pp;
    }

    Coordinates Square::getCoordinates()
    {
        return Coordinates;
    }
    char Square::getColumn()
    {
        return Coordinates;.getColumn(); 
    }
    int Square::getRow()
    {
        return Coordinates.getRow();
    }
    string Square::getColor::()
    {
        return color;
    }
    Piece *Square::getPiece()
    {
        return this->piece;
    }

    Square::~Square()
    {
        delete piece;
    }

    void Board::indentify() { cout << "Board of 64 squares " << endl; }

    int Board::coordinateToIndex(Coordinates *postion)
    {
        return postion->getRow() * this->numRows + Coordinates::columnToIndex(position->getColumn());
    }

    Piece *Board::pieceOn(char column, int row)
    {
        Piece *aux_return;

        Coordinates *coord_aux = new Coordinates(column, row);
        aux_return = pieceOn(coord_aux);
        delete coord_aux;
        return aux_return;
    }

    Piece*Board::pieceOn(Coordinates *postion)
    {
        return this->squares[coordinateToIndex(postion)].piece;
    }

    Board::Board()
    {
        numRows = 8;
        numColumns = 8;
        squares = new Square [8 * 8];
    }
    Board::Board(int dim)
    {
        numRows = dim;
        numColumns = dim;
        squares = new Square [dim * dim];
    }

    Board::Board( int dim, string array_char_posicion)
    {
        int pos = 0;

        numRows = dim;
        numColumns = dim;

        this->squares = new Square[dim * dim];

        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++, pos++)
            {
                switch (array_char_posicion {pos})
                {
                case 'p':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Pawn("p", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_BLACK));
                    squares [pos].piece->board = this;
                    break;
                case 'P':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Pawn("P", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_WHITE));
                    squares [pos].piece->board = this;
                    break;
                case 'a':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Bishop("a", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_BLACK));
                    squares [pos].piece->board = this;
                    break;
                case 'A':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Bishop("A", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_WHITE));
                    squares [pos].piece->board = this;
                    break;
                case 'c':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Knight("c", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_BLACK));
                    squares [pos].piece->board = this;
                    break;
                case 'C':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Knight("C", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_WHITE));
                    squares [pos].piece->board = this;
                    break;
                case 't':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Rook("t", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_BLACK));
                    squares [pos].piece->board = this;
                    break;
                case 'T':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Rook("T", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_WHITE));
                    squares [pos].piece->board = this;
                    break;
                case 'r':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new King("r", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_BLACK));
                    squares [pos].piece->board = this;
                    break;
                case 'R':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new King("R", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_WHITE));
                    squares [pos].piece->board = this;
                    break;
                case 'd':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Queen("d", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_BLACK));
                    squares [pos].piece->board = this;
                    break;
                case 'D':
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(new Queen("D", Coordinates(Coordinates::indexToColumn(j), i), Square::NAME_WHITE));
                    squares [pos].piece->board = this;
                    break;
                default:
                    squares [pos].setColorCoordinates(Coordinates::indexToColumn(j), i);
                    squares [pos].setPiece(nullptr);
                    break;
                }
            }
        }
    }
    
    Board::~Board()
    {
        delete[] squares;
    }
      
    void Board::setNumRows(int fls)
    {
        numRows = fls;
    }

    void Board::setNumColumns(int clms)
    {
        numColumns = clmns;
    }

    int Board::getNumRows()
    {
        return numRows;
    }

    int Board::getNumColumns()
    {
        return numColumns;
    }    

    Square *Board::getSquares()
    {
        return squares;
    }