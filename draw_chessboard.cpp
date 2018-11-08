#include <iostream>
#include <cstdio>

using namespace std;

#define BOARD_W 4
#define BOARD_H 4

void generate(char[][BOARD_H]);
void display(char[][BOARD_H]);
bool validate(char);
bool validate(char[][BOARD_H], int, int);
void mark(char[][BOARD_H], int, int);
bool check(char[][BOARD_H]);
//bool check(char[][BOARD_H],int,int);

int main()
{
    bool finish = false, valid_reply = false;
    char board[BOARD_W][BOARD_H];
    char reply;
    int count1, count2;
    
    while(finish != true)
    {
                 for(count1 = 0; count1 < BOARD_W; count1++)
                 {
                            for(count2 = 0; count2 < BOARD_H; count2++)
                            {
                                       board[count1][count2] = '.';
                            }
                 }
                 generate(board);
                 display(board);
                 
                 //Asks for another go, and ends if told no.
                 while(valid_reply != true)
                 {
                                   cout << "\n\nWould you like to generate another configuration? (y/n)";
                                   cin >> reply;
                                   valid_reply = validate(reply);
                                   if(reply == 'n')
                                       finish = true;
                                   else
                                       finish = false;
                 }
                 valid_reply = false;
    }
}

void generate(char board[][BOARD_H])
{
     int W;
     int H;
     bool valid = false;
     do
     {
          W = rand()%(BOARD_W);
          H = rand()%(BOARD_H);
          while(board[W][H] != '.')
          {
                          W = rand()%BOARD_W;
                          H = rand()%BOARD_H;
          }
          mark(board, W, H);
          board[W][H] = 'Q';
          cout << endl << H + 1 << " " << W + 1 << " " << check(board) << endl; //DEBUG LINE  */
     }
     while(check(board) != true);
}

void display(char board[][BOARD_H])
{
     int count, count1;
     for(count1 = 0; count1 < BOARD_H; count1 ++)
     {
                cout << "\n";
                for(count = 0; count < BOARD_W; count++)
                {
                          cout << " -";
                }
                cout << " \n";
                for(count = 0; count < BOARD_W; count++)
                {
                          cout << "|" << board[count][count1];
                }
                cout << "|";
     }
     cout << "\n";
     for(count = 0; count < BOARD_W; count++)
     {
                cout << " -";
     }
}

bool validate(char reply)
{
     if(reply == 'y' || reply == 'n')
              return true;
     else
              return false;
}

void mark(char board[][BOARD_H], int W, int H)
{
     int W1, H1, count1;
     W1 = W;
     H1 = H;
     while(W1 > 0 && H1 > 0)
     {
            W1-- && H1--;
            board[W1][H1] = 'X';
     }
     W1 = W;
     H1 = H;
     while(W1 <= BOARD_W && H1 > 0)
     {
            W1++ && H1--;
            board[W1][H1] = 'X';
     }
     W1 = W;
     H1 = H;
     while(W1 > 0 && H1 <= BOARD_H)
     {
            W1-- && H1++;
            board[W1][H1] = 'X';
     }
     W1 = W;
     H1 = H;
     while(W1 <= BOARD_W && H1 <= BOARD_H)
     {
            W1++ && H1++;
            board[W1][H1] = 'X';
     }
     for(count1 = 0; count1 < BOARD_W; count1++)
     {
                board[count1][H] = 'X';
     }
     for(count1 = 0; count1 < BOARD_H; count1++)
     {
                board[W][count1] = 'X';
     }
     board[W][H] = 'Q';
     return;
}

bool check(char board[][BOARD_H])
{
     bool done = true;
     int count, count2;
     for(count = 0; count < BOARD_W; count++)
     {
               for(count2 = 0; count2 < BOARD_H; count2++)
               {
                          if(board[count][count2] == '.')
                                                  done = false;
               }
     }
     return done;
}

/*bool check(char board[][BOARD_H], int W, int H)
{
     int W1, H1, count1;
     W1 = W;
     H1 = H;
     while(W1 > 0 && H1 > 0)
     {
            W1-- && H1--;
            if(board[W1][H1] == 'Q')
                             return false;
     }
     W1 = W;
     H1 = H;
     while(W1 <= BOARD_W && H1 > 0)
     {
            W1++ && H1--;
            if(board[W1][H1] == 'Q')
                             return false;
     }
     W1 = W;
     H1 = H;
     while(W1 > 0 && H1 <= BOARD_H)
     {
            W1-- && H1++;
            if(board[W1][H1] == 'Q')
                             return false;
     }
     W1 = W;
     H1 = H;
     while(W1 <= BOARD_W && H1 <= BOARD_H)
     {
            W1++ && H1++;
            if(board[W1][H1] == 'Q')
                             return false;
     }
     for(count1 = 0; count1 < BOARD_W; count1++)
     {
                if(board[W1][H1] == 'Q')
                             return false;
     }
     for(count1 = 0; count1 < BOARD_H; count1++)
     {
                if(board[W1][H1] == 'Q')
                             return false;
     }
     return true;
}
*/