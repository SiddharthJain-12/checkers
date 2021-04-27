#include <stdio.h>
#include "game.h"

int main(void){

    int status = 0;
    GameState G = initEmptyBoard();
    setBoard(G);
    displayBoardClear(G);
    printf("Enter x and y coordinates of the piece you want to move and the target square\n");

    int x=0,y=0,tX=0,tY=0;


    //need to include a provision to restrict moves if a capture is available
    while(1){
        if(!scanf(" %d %d %d %d",&x,&y,&tX,&tY))
            break;
        x--; y--; tX--; tY--;

        if(x==-1 && y==-1 && tX==-1 && tY==-1)
            break;

        status = movePiece(G,x,y,tX,tY);
        displayBoardClear(G);
        switch(status){
            default:
            case 0:
                printf("Invalid move\n");
                break;
            case -1:
                printf("You must make a capture\n");
                break;
            case 1:
                printf("You made a regular move\n");
                break;
            case 2:
                printf("You captured a piece, you must make another capture if possible\n");
                break;
            case 3:
                printf("You promoted a pawn\n");
                break;

        }
    }
}