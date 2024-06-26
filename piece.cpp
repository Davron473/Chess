#include <iostream>
#include <utility>

#include "piece.h"
using namespace std;

const int Piece::BLACK = 0;
const int Piece::WHITE = 1;
const int Piece::NO_COLOR = -1;
const string Piece::NAME_BLACK = "black";
const string Piece::NAME_WHITE = "white";
const string Piece::NAME_NO_COLOR = "*";


void Piece::move(Coordinates finalChess)
{


    chess = finalChess;
}

ostream& operator<<(ostream& os, const Piece& p)
{
    os << p.name << "(" << p.value << ") "<< p.color << endl ;
    return os;
}

int Piece::evaluation()
{
    return 0;
}

Piece::~Piece()
{

}


bool Pawn::movable (Coordinates finalChess)
{
    cout << "It checks if final postion is in front of the current one or at one diagonal step" << endl;
    this->board->identify();
    cout <<"Board size: " << this->board->getNumRows() << " x " << this->board->getNumColumns() <<endl;

    return true;
}

int Queen::PossibleMoves(Coordinates**& arrayMoves){return 0;}
int King::PossibleMoves(Coordinates**& arrayMoves){return 0;}
int Knight::PossibleMoves(Coordinates**& arrayMoves){return 0;}
int Rook::PossibleMoves(Coordinates**& arrayMoves){return 0;}
int Bishop::PossibleMoves(Coordinates**& arrayMoves){return 0;}
int Pawn::PossibleMoves(Coordinates**& arrayMoves)
{
    int num_movs = 0;
    int current_row;
    char current_column;
    int ind_current_column;
    Piece *piece_board;

    arrayMoves = nullptr;

    current_row = this->chess.getRow();
    current_column = this->chess.getColumn();
    ind_current_column = Coordinates::columnToIndex(current_column);

    cout<< " Pawn on " << this->chess << endl;


    if ( this->color.compare(Piece::NAME_BLACK) ==0 )
    {
        If ( current_row == 0 )
        {
            arrayMoves = nullptr;
            return 0;
        }
        else
        {
            if (this->board->pieceOn(current_column,current_row -1 )== nullptr )
            {
                arrayMoves = (Corrdinates**) realloc(arrayMoves, sizeof(Coordinates*)*(num_movs+1));
                arrayMoves [num_movs]=new Coordinates(current_column,current_row-1);
                num_movs++;
            }
            if ( ind_current_column != 0)
            {
                piece_board = this->board->pieceOn(current_column - 1, current_row-1);
                if ( piece_board != nullptr )
                {
                    if ( piece_board->color.compare(this->color) != 0)
                    {
                        arrayMoves = (Coordinates**) realloc(arrayMoves, sizeof(Coordinates*)*(num_movs+1));
                        arrayMoves [num_movs]=new Coordinates(Coordinates::indexToColumn(ind_current_column-1),current_row-1);
                        num_movs++;
                    }
                }
            }
            if (ind_current_column != this->board->getNumColoumns()-1)
            {
                piece_board = this->board->pieceOn(current_column + 1, current_row-1);
                if ( piece_board != nullptr )
                {
                    if ( piece_board->color.compare(this->color) !=0)
                    {
                        arrayMoves = (Coordinates**) realloc(arrayMoves, sizeof(Coordinates*)*(num_movs+1));
                        arrayMoves [num_movs]=new Coordinates(Coordinates::indexToColumn(ind_current_column+1),current_row-1);
                        num_movs++;
                    }
                }
            }
        }
    
    }

    if ( this->color.compare(Piece::Name_White) == 0 )
    {
        If ( current_row == this->board->getNumRows() )
        {
            arrayMoves = nullptr;
            return 0;
        }
        else
        {
            if (this->board->pieceOn(current_column,current_row +1 )== nullptr )
            {
                arrayMoves = (Corrdinates**) realloc(arrayMoves, sizeof(Coordinates*)*(num_movs+1));
                arrayMoves [num_movs]=new Coordinates(current_column,current_row+1);
                num_movs++;
            }
            if ( ind_current_column != 0)
            {
                piece_board = this->board->pieceOn(current_column - 1, current_row+1);
                if ( piece_board != nullptr )
                {
                    if ( piece_board->color.compare(this->color) != 0)
                    {
                        arrayMoves = (Coordinates**) realloc(arrayMoves, sizeof(Coordinates*)*(num_movs+1));
                        arrayMoves [num_movs]=new Coordinates(Coordinates::indexToColumn(ind_current_column-1),current_row-1);
                        num_movs++;
                    }
                }
            }
             if (ind_current_column != this->board->getNumColoumns()-1)
            {
                piece_board = this->board->pieceOn(current_column + 1, current_row+1);
                if ( piece_board != nullptr )
                {
                    if ( piece_board->color.compare(this->color) !=0)
                    {
                        arrayMoves = (Coordinates**) realloc(arrayMoves, sizeof(Coordinates*)*(num_movs+1));
                        arrayMoves [num_movs]=new Coordinates(Coordinates::indexToColumn(ind_current_column+1),current_row-1);
                        num_movs++;
                    }
                }
            }
        }
    }



    return num_movs;

}

Pawn::Pawn(string names, Coordiantes chess, string color)
{

    this->name = name;
    this->chess = Coordinates (chess);
    this->value = 1;
    this->color = color;
}

int Pawn::evaluation()
{
    return 1;
}

Pawn::~Pawn(){};

