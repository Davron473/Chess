#pragma once
#include <iostream>
#include <utility>
#include <string>

#include "coordinates.h"
#include "board.h"

using namespace std;

class Board;


class Piece
{
public:
   static const string NAME_BLACK;
   static const string NAME_WHITE;
   static const string NAME_NO_COLOR;
   static const int BLACK;
   static const int WHITE;
   static const int NO_COLOR;
   string name;
   Coordinates chess; 
   int value;
   string color;
 
   Board * board;
 
   void move(Coordinates finalChess)
   ;
 
   virtual bool movable(Coordinates finalChess)=o;
   virtual int PossibleMoves(Coordinates***&arrayMoves) =0;
 
   friend ostream& operator<<(ostream& os, const Piece& p)
   ;

   int evaluation()
   ;

   virtual ~Piece()
   ;

 };


class Pawn : public Piece
{
    public:

    Pawn(string name, Coordinates chess, string color)
    ;

    bool movable(Coordinates finalChess)
    ;

    int PossibleMoves(Coordinates**&);

    int evaluation()
    ;




    ~Pawn();

}:


class Bishop : public Piece
{
    public:

        Bishop(string name, Coordiantes chess, string color)
        {
            this->names = name;
            this->chess = Coordinates(chess);
            this->value = 3;
            this->color = color;
        }

        int PossibleMoves(Coordinates**&);
        bool movable(Coordinates finalChess)
        {
            cout <<"It is checked if final position is on the diagonal from the current one " <<endl;
            return true;
        }
        int evaluation(){return 3;}
        ~Bishop(){

            }
};



class Knight : public Piece 
{
    public:

        Knight(string name, Coordiantes chess, string color)
        {
            this->names = name;
            this->chess = Coordinates(chess);
            this->value = 3;
            this->color = color;
        }

        int PossibleMoves(Coordinates**&);
        bool movable(Coordinates finalChess)
        {
            cout <<"It is checked if final position is one of the 8 (at max.) possible for the knight " <<endl;
            return true;
        }
        int evaluation(){return 3;}
        ~Knight(){

            }
};


class Rook : public Piece 
{
    public:

        Rook(string name, Coordiantes chess, string color)
        {
            this->names = name;
            this->chess = Coordinates(chess);
            this->value = 5;
            this->color = color;
        }

        int PossibleMoves(Coordinates**&);
        bool movable(Coordinates finalChess)
        {
            cout <<"It is checked if final position is on the same row or column than the current one " <<endl;
            return true;
        }
        int evaluation(){return 5;}
        ~Rook(){

            }
};


class Queen : public Piece 
{
    public:

        Queen(string name, Coordiantes chess, string color)
        {
            this->names = name;
            this->chess = Coordinates(chess);
            this->value = 10;
            this->color = color;
        }

        int PossibleMoves(Coordinates**&);
        bool movable(Coordinates finalChess)
        {
            cout <<"Checks for bishop and rook are done " <<endl;
            return true;
        }
        int evaluation(){return 10;}
        ~Queen(){

            }
};


class King : public Piece 
{
    public:

        King(string name, Coordiantes chess, string color)
        {
            this->names = name;
            this->chess = Coordinates(chess);
            this->value = 1000000;
            this->color = color;
        }

        int PossibleMoves(Coordinates**&);
        bool movable(Coordinates finalChess)
        {
            cout <<"Final postion has to be 1 away from current " <<endl;
            return true;
        }
        int evaluation(){return 1000000;}
        ~King(){

            }
};
