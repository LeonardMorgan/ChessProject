//
// Created by Cristofher on 11/23/16.
//

#ifndef UNTITLED2_LOGICCHESS_H
#define UNTITLED2_LOGICCHESS_H

#include <iostream>
using namespace std;
// tokenize chapter 6.5

class Token {
public:
    int number;
    char string;
};

class ChessToken {
public:
    int playerSide;
    string kind;

    void setPositionX(int posistionX); // set position X and Y to private
    void setPositionY(char posistionY);

    int getPositionX();  // return the integer position on X
    char getPositionY();  // return the char position

    ChessToken(string, int, char, int);

    ChessToken(const string &type_ = "Empty") : kind(type_) {
        cout << "Piece " << type_ << " created." << endl;
    }

private:
    int posX;  // cannot be changed from outside without calling the function
    char posY; //
};

void ChessToken::setPositionX(int posistionX){
    this->posX = posistionX;
}

void ChessToken::setPositionY(char posistionY){
    this->posY = posistionY;
}

int ChessToken::getPositionX() {
    return this->posX;
}

char ChessToken::getPositionY() {
    return this->posY;
}

ChessToken::ChessToken(string type, int id, char positionY,  int positionX) {
    this->kind       = type;
    this->playerSide = id;
    this->posX       = positionX;  // cannot be changed from outside without calling the function
    this->posY       = positionY;
}

enum pieces {
    rook    = 'r',
    pawn    = 'p',
    bigshop = 'b',
    queen   = 'q',
};

vector<ChessToken> P1Pieces;
vector<ChessToken> P2Pieces;

#endif //UNTITLED2_LOGICCHESS_H
