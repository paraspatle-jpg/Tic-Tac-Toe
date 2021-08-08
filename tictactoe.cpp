#include <bits/stdc++.h>
using namespace std;

bool check_win(char board[][3], char player_sign, char computer_sign)
{
 for (int i = 0; i < 3; i++)
 {
  if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
  {
   if (board[i][0] == player_sign)
   {
    cout << "You Win";
    return true;
   }
   else if (board[i][0] == computer_sign)
   {
    cout << "Computer Won,It's a Shame,You lost ";
    return true;
   }
  }
  else if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
  {
   if (board[0][i] == player_sign)
   {
    cout << "You Win";
    return true;
   }
   else if (board[0][i] == computer_sign)
   {
    cout << "Computer Won,It's a Shame,You lost ";
    return true;
   }
  }
  else if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
  {
   if (board[0][0] == player_sign)
   {
    cout << "You Win";
    return true;
   }
   else if (board[0][0] == computer_sign)
   {
    cout << "Computer Won,It's a Shame,You lost ";
    return true;
   }
  }

  else if (board[1][1] == board[0][2] && board[1][1] == board[2][0])
  {
   if (board[2][0] == player_sign)
   {
    cout << "You Win";
    return true;
   }
   else if (board[2][0] == computer_sign)
   {
    cout << "Computer Won,It's a Shame,You lost ";
    return true;
   }
  }
 }
 return false;
}

void print_man()
{
 cout << "To place Your sign press the number in below matrix according to your choice" << endl;
 cout << " 1 | 2 | 3 " << endl;
 cout << "-----------" << endl;
 cout << " 4 | 5 | 6 " << endl;
 cout << "-----------" << endl;
 cout << " 7 | 8 | 9 " << endl;
}

void print_status(char board[][3])
{
 cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
 cout << "-----------" << endl;
 cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
 cout << "-----------" << endl;
 cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void tictactoe(char sign, char c_sign)
{

 char board[3][3];
 for (int i = 0; i < 3; i++)
 {
  for (int j = 0; j < 3; j++)
  {
   board[i][j] = ' ';
  }
 }

 for (int i = 1; i <= 5; i++)
 {
  cout << "Your Turn :" << endl;
  int num;
  cin >> num;

  if (num > 0 && num <= 3)
  {
   if (board[0][num - 1] != ' ')
   {
    i--;
    cout << "Please choose another number" << endl;
    continue;
   }
   board[0][num - 1] = sign;
  }
  else if (num > 3 && num <= 6)
  {
   if (board[0][num - 4] != ' ')
   {
    i--;
    cout << "Please choose another number" << endl;
    continue;
   }
   board[1][num - 4] = sign;
  }
  else
  {
   if (board[0][num - 7] != ' ')
   {
    i--;
    cout << "Please choose another number" << endl;
    continue;
   }
   board[2][num - 7] = sign;
  }

  cout << "Computers Turn" << endl;
  srand(time(0));
  while (1)
  {
   int num1 = rand() % 3;
   int num2 = rand() % 3;
   if (board[num1][num2] == ' ')
   {
    board[num1][num2] = c_sign;
    break;
   }
  }

  print_status(board);
  if (check_win(board, sign, c_sign))
   return;
 }

 cout << "Match Tied";
}

int main()
{

 cout << "Enter Your Sign O or X" << endl;
 char player_sign, computer_sign;
 cin >> player_sign;
 if (player_sign == 'O')
  computer_sign = 'X';

 else if (player_sign == 'X')
  computer_sign = 'O';

 print_man();

 tictactoe(player_sign, computer_sign);
}