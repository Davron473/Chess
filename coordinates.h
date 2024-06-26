#pragma once

#include <iostream>


using namespace std;

class Coordinates
{

public:

   Coordinates()
   ;


   Coordinates(char column, int row)
   ;

   Coordinates(const Coordinates& crdns)
   ;

   static int columnToIndex(char column);


   static char indexToColumn(int indc)
   ;

   char getColumn();

   int getRow();

   void setColumn(char clmn);

   void setRow(int row);
   
   
   friend ostream& operator<<(ostream& os, const Coordinates& crdnd);

private:
   char column;
   int row;
 
};
