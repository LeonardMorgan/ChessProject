// Copyright
#include <iostream>
#include <vector>
#include "logicChess.h"

using namespace std;

bool player1 = true;
bool isValidPosition(string);
bool isValidName(const string &);

void createPieces();
void beginGame();
void getPlayerTurn();
void setPosition(ChessToken *pieceType, string nextPos);

ChessToken* getPiece(string, int posX, char PosY);
ChessToken* playerPieces;

int main() {
    beginGame();
    return 0;
}

void getPlayerTurn() {
    if(player1) {
        cout << "Player 1 turn  ";
        playerPieces = P1Pieces.data();
        player1 = false;
    } else { // player 2
        cout << "Player 2 turn  ";
        playerPieces = P2Pieces.data();
        player1 = true;
    }
}

bool isValidPosition(string Pos) {
    for (size_t i = 0 ; i < 16; i++) {
        if (playerPieces[i].getPositionY() == Pos[0] and
            playerPieces[i].getPositionX() == (int) Pos[1] - '0') {
            cout << "found at position " << i << " of player side " << playerPieces[i].playerSide << "\n";
            return true;
        }
    }

    cout << "invalid Position \n";
    return false;
}

// check if the name exist
bool isValidName(const string &Piece) {
    vector<string> PieceNames;
    // pieces name to compare with
    PieceNames.push_back("Rook");
    PieceNames.push_back("King");
    PieceNames.push_back("Pawn");
    PieceNames.push_back("Queen");
    PieceNames.push_back("Bishop");
    PieceNames.push_back("Knight");

    for (size_t i = 0; i < PieceNames.size(); i++) {
        if (Piece == PieceNames[i])
            return true;
    }

    cout << "invalid Piece \n";

    return false;
}

void beginGame() {
    ChessToken* playerTurn;
    string pieceType, posInitial, posFinal, to;
    createPieces();
    player1 = true;
    getPlayerTurn();

    cout << "\nPlease enter a piece, a position initial and position final \n"
         << "Example: rook a1 to b2: \n";

    while(cin >> pieceType >> posInitial >> to >> posFinal) {
        if(pieceType == "quit") {
            break;
        }
        posInitial[0] = toupper(posInitial[0]);
        posFinal[0]   = toupper(posFinal[0]);
        pieceType[0]  = toupper(pieceType[0]);

        if (isValidPosition(posInitial)) {
            if (isValidName(pieceType)) {
                playerTurn = getPiece(pieceType, (int) posInitial[1] - '0', posInitial[0]);

                if (playerTurn->kind != "Empty") {
                    cout << playerTurn->kind << " "
                         << playerTurn->getPositionY()
                         << playerTurn->getPositionX()
                         << "\n";

                    setPosition(playerTurn, posFinal);
                } else {
                    cout << "not Piece found at that position \n";
                }

            } else {
                cout << "Wrong Name \n";
            }
        } else {
            cout << "No chess piece found in that position \n";
        }

        cout << "\nPlease enter a piece, a position initial and position final \n"
             << "Example: rook a1 to b2: \n";
    }
    cout << "  Game over \n";
    // delete playerTurn;
    cout << "  Thanks for playing \n ";

}

ChessToken* getPiece(string userInput, int posX, char posY) {
    for (size_t i = 0 ; i < 16; i++) {
      if (playerPieces[i].kind == userInput) {
        if (playerPieces[i].getPositionX() == posX and
            playerPieces[i].getPositionY() == posY) {
                cout << playerPieces[i].kind << " piece found at position vector[" << i << "] on Player "
                     << playerPieces[i].getPositionX() << playerPieces[i].getPositionY() << " player "
                     << playerPieces[i].playerSide << " vector \n";
                return playerPieces[i].getThisPiece();
        }
      }
    }
    return nullptr;
}

void createPieces() {
    // Pieces store in vector located in the header
    vector <string> names    { "Rook", "Knight", "Bishop", "Queen",
                               "King", "Bishop", "Knight", "Rook"};

    vector <char> positionY  { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    cout << "Pieces Created \n";

     cout << "\n\n************\n"
          << "* Player 1 *\n"
          << "************\n";
    for (int i= 0 ; i < 8; i++) {
        //  name, id, positionY, positionX
        ChessToken piecesP1(names[i], 1 , positionY[i] , 1);
        P1Pieces.push_back(piecesP1);
    }

    for (int i= 0 ; i < 8; i++) {
        ChessToken piecesP1("Pawn", 1 , positionY[i] , 2);
        P1Pieces.push_back(piecesP1);
    }

    for (int i= 0 ; i < 16; i++) {
        cout << P1Pieces[i].kind << " "
             << P1Pieces[i].getPositionY()
             << P1Pieces[i].getPositionX() << (i == 8 ? "\n" : " ");
    }

    cout << "\n\n************\n"
         << "* Player 2 *\n"
         << "************\n";

    for (int i= 0 ; i < 8; i++) {
        ChessToken piecesP2(names[i], 2 , positionY[i] , 7);
        P2Pieces.push_back(piecesP2);
    }

    for (int i= 0 ; i < 8; i++) {
        ChessToken piecesP2("Pawn", 2 , positionY[i] , 8);
        P2Pieces.push_back(piecesP2);
    }

    for (int i= 0 ; i < 16; i++) {
        cout << P2Pieces[i].kind << " "
             << P2Pieces[i].getPositionY()
             << P2Pieces[i].getPositionX() << (i == 8 ? "\n" : " ");
    }

    names.clear();
    positionY.clear();

    cout << "\n" << endl;
}

void setPosition(ChessToken *pieceType, string nextPos) {
    pieceType->setPositionY(nextPos[0]);
    pieceType->setPositionX((int)nextPos[1] - '0');

    cout << pieceType->kind << " Changed Position to "
         << pieceType->getPositionY()
         << pieceType->getPositionX()
         << "\n"
         << endl;

    getPlayerTurn();
}
