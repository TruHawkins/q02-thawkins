#include "Piezas.h"
#include <vector>
 #include<iostream>
 using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    std::vector<Piece> tmp;
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int k = 0; k < BOARD_COLS; k++)
        {
            tmp.push_back(Blank);
        }
        board.push_back(tmp);
        tmp.clear();
    }
    turn = X;
    
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int k = 0; k < BOARD_COLS; k++)
        {
            board[i][k] = Blank;
        }
    }
    turn = X;
}

Piece Piezas::check()
{
    return O;   
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece p = Blank;
    if(column >= 0 && column < BOARD_COLS){
        int i = 0;
        while(i < BOARD_ROWS){
            //cout<<i<<endl;
            if(board[i][column] == Blank)
            {
                board[i][column] = turn;
                p = board[i][column];
                i =  5;
            }
             i++;
        } 
    }else {
        p = Invalid ;
    }
    
    if(turn == X){
        turn = O;   
    } else {
        turn = X;   
    }
    
    return p;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row < 0 || row > BOARD_ROWS || column < 0 || column > BOARD_COLS){
        return Invalid;   
    } else {
        return   board[row][column];
    }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    for(int i = 0; i < BOARD_ROWS; i++){
        for(int k = 0; k < BOARD_COLS;k++){
            if(board[i][k] == Blank){
                return Invalid;
            }
        }
    }
    
    Piece lastPiece = Blank;
    int xScore = 0;
    int oScore = 0;
    int highX = 0;
    int highO = 0;
    
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int k = 0; k < BOARD_COLS; k++)
        {
            if(board[i][k] == lastPiece){
                if(board[i][k] == X){
                    oScore = 1;
                    xScore++;
                    if(xScore > highX){
                        highX = xScore; 
                        
                    }
                } else {
                    xScore = 1;
                    oScore++; 
                    if(oScore > highO){
                        highO = oScore;
                        
                    }
                }
            }else {
                oScore = 1;
                xScore = 1;
            }
            lastPiece = board[i][k];
        }
        
        lastPiece = Blank;
    }
    //out<<highX<<endl;
    //cout<<highO<<endl;
    oScore = 0;
    xScore = 0;
    
    for(int k = 0; k < BOARD_COLS; k++)
    {
        for(int i = 0; i < BOARD_ROWS; i++)
        {
            if(board[i][k] == lastPiece){
                if(board[i][k] == X){
                    xScore++;
                    oScore = 1;
                    if(xScore > highX){
                        highX = xScore;   
                    }
                } else {
                    oScore++; 
                    xScore = 1;
                    if(oScore > highO){
                        highO = oScore;
                    }
                }
            } else {
                oScore = 1;
                xScore = 1;
            }
            lastPiece = board[i][k];
        }
        lastPiece = Blank;
    }
    
   // cout<<"x score = "<<highX<<endl;
   // cout<<"o score = "<<highO<<endl;
    //printBoard();
    if(highX > highO){
        return X;
    } else if(highO > highX){
        return O;
    } else {
        return Blank;
    }
}

void Piezas::printBoard()
{
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int k = 0; k < BOARD_COLS; k++)
        {
            cout<<board[i][k]<<" ";
        }
        cout<<endl;
    }
}