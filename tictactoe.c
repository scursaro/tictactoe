//Game between two players

// have some funcitions that check the board,print the board, have a random move, or a player move
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char PLAYER2 = '0';
const char COMPUTER = '0';


void resetBoard();
void printBoard();
int checkSpace(); //Functions for the game
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
    //prompt user for game they wish to play

    char winner = ' ';

    resetBoard();

    while(winner == ' ' && checkSpace() !=0)
    {
        printBoard();

        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkSpace() ==0)
        {
            break;

        }
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkSpace() ==0)
        {
            break;

        }


    }




    //read information from console

    //possibly start the game, maybe a while loop with a nested switch
    //Will also need two separate cases, One for With Player, and One with random 

    //after selection is made, prompt user to enter two int's for their location
    //check if the location is taken, if not place guess, else return to user to pick new spot

    //print out the new layout

    //maybe also have an array? or keep track somehow 
    
    
    //have a way to keep track of three in a row possibly a function that is for add(), and 
    // another function to check if the person on didWin()
    
    
    return 0;
}

void resetBoard()
{
    for(int i =0; i<3;i++)
    {
        for(int j =0; j < 3; j++)
        {
            board[i][j] = ' ';
        }

    }

}
void printBoard()
{
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");
    printf("\n");

}
int checkSpace()
{
    int openSpaces =9;

    for(int i =0; i < 3; i++)
    {
        for(int j =0; j <3; j++)
        {
            if(board[i][j] != ' ')
            {
                openSpaces--;
            }

        }
    }
    return openSpaces;


}
void playerMove()
{
    int x;
    int y;

    do
    {
    printf("Enter a row (1-3): ");
    scanf("%d", &x);
    x--;
    printf("Enter a col. (1-3): ");
    scanf("%d", &y);
    y--;

    if(board[x][y] != ' ' )
    {
        printf("Invalid move, spot taken\n");
    }
    else
    {
        board[x][y] = PLAYER;
        break;

    }

        
    } while (board[x][y] != ' ');
    
    


}
void computerMove()
{
   srand(time(0));
   int x;
   int y;

   if(checkSpace() > 0)
   {
    do
    {
        x=rand() % 3;
        y =rand() %3
    } while (board[x][y] != ' ');
    board[x][y] = COMPUTER;
   } 
   else{
    printWinner(' ');
   }


}
char checkWinner()
{
    //check the rows
    for(int i =0; i<3; i++ )
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    //check the columns
    for(int i =0; i<3; i++ )
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    //check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];
        }

    return ' ';




}
void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("Player wins")
    }
    else if(winner == COMPUTER)
    {
        printf("Computer Wins")
    }
    else if(winner == PLAYER2)
    {
        printf("Player2 Wins")
    }
    else
    {
        printf("Y'all trash, y'all tied")
    }

}