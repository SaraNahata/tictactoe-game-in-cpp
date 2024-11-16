#include <iostream>
using namespace std;
void board(char *spaces);
void playermove1(char player,char *spaces);
void playermove2(char player,char *spaces);
bool checkWinner(char *spaces);
bool checkTie(char *spaces);

int main(){
   bool game= true;
   char player1='X';
   char player2='0';
   char spaces[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
   board(spaces);
   while(game){
     playermove1(player1,spaces);
     board(spaces);
     if (checkWinner(spaces)){
      game= false;
      cout<<"Player 1 wins!"<<endl;;
      break;
    }

    playermove2(player2,spaces);
    board(spaces);
    if (checkWinner(spaces)){
      game= false;
      cout<<"Player 2 wins!"<<endl;
      break;
    }
    if (checkTie(spaces)){
      game=false;
      cout<<"Game is a Tie!"<<endl;
    }

   }
}

void board(char *spaces){
   cout<<"     |     |     "<<endl;
   cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<endl;
   cout<<"_____|_____|_____"<<endl;
   cout<<"     |     |     "<<endl;
   cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<endl;
   cout<<"_____|_____|_____"<<endl;
   cout<<"     |     |     "<<endl;
   cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<endl;
   
   cout<<"     |     |     "<<endl;
}

void playermove1(char player,char *spaces){
   int move;
   do {
      cout<<" Player 1 Enter your move (0-8): ";
      cin>>move;
      if (spaces[move]==' '){
         spaces[move]=player;
      }else{
         while(spaces[move]!=' '){
            
            cout<<"Spot taken! Enter another move (0-8): ";
            cin>> move;
         }
         spaces[move]=player;
         
      }
      
   }while(move<0 || move>9);

   
}


void playermove2(char player,char *spaces){
   int move;
   do {
      cout<<" Player 2 Enter your move (0-8): ";
      cin>>move;
      if (spaces[move]==' '){
         spaces[move]=player;
      }else{
         while(spaces[move]!=' '){
            
            cout<<"Spot taken! Enter another move (0-8): ";
            cin>> move;
         }
         spaces[move]=player;
      }
      
   }while(move<0 || move>9);

   
}

bool checkWinner(char *spaces){
   //row win
   if (spaces[0]!=' ' && spaces[0]==spaces[1]&&  spaces[1]==spaces[2])
   return true;
   else if (spaces[3]!=' ' && spaces[3]==spaces[4]&&  spaces[4]==spaces[5])
   return true;
   else if (spaces[6]!=' ' && spaces[6]==spaces[7]&&  spaces[7]==spaces[8])
   return true;
   //column win
   else if (spaces[0]!=' ' && spaces[0]==spaces[3]&&  spaces[3]==spaces[6])
   return true;
   else if (spaces[1]!=' ' && spaces[1]==spaces[4]&&  spaces[4]==spaces[7])
   return true;
   else if (spaces[2]!=' ' && spaces[2]==spaces[5]&&  spaces[5]==spaces[8])
   return true;
   //diagonal win
   else if (spaces[0]!=' ' && spaces[0]==spaces[4]&&  spaces[4]==spaces[8])
   return true;
   else if (spaces[2]!=' ' && spaces[2]==spaces[4]&&  spaces[2]==spaces[6])
   return true;
   else {
      return false;
   }
}


bool checkTie(char *spaces){
   for (int i=0;i<9;i++){
      if (spaces[i]==' '){
         return false;
      }
   }
   return true;
}