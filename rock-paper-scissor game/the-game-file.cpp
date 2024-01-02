#include <iostream>
#include<random>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

int computer_move(void){
    
    srand(time(0));
    mt19937 seed(rand());
    uniform_int_distribution<> range(1,3);
    int d =range(seed);
    return d;
}

int main(){
    cout<<"#########   ROCK-PAPER-SCISSORS   #########"<<endl;
    string name;
    int matches;
    cout<<"Enter your name"<<endl;
    cin>>name;

    while(1){
        int end=1;
        cout<<"If you want to exit, Enter 0 or enter the any other number"<<endl;
        cin>>end;
        
        
        if(end==0){
            exit(0);
        }
        else{
            int score_player=0;
            int score_computer=0;
            cout<<"Enter the number of matches you want to play"<<endl;
            cout<<"for rock enter 1"<<endl;
            cout<<"for paper enter 2"<<endl;
            cout<<"for scissors enter 3"<<endl;
            
            cin>>matches;

            for(int i=1;i<=matches;i++){
                int player_mov=0;
                int computer_mov=0;
                cout<<i<<".Enter you move"<<endl;
                cin>>player_mov;

                computer_mov=computer_move();

                
                if((player_mov==1 && computer_mov==2) || (player_mov==2 && computer_mov==3) || (player_mov==3 && computer_mov==1)){
                    cout<<"computer wins this round"<<endl<<endl;
                    score_computer++;
                }
                else if((player_mov==1 && computer_mov==3) || (player_mov==2 && computer_mov==1) || (player_mov==3 && computer_mov==2)){
                    cout<<"you wins this round"<<endl<<endl;
                    score_player++;
                }
                else if((player_mov==computer_mov)){
                    cout<<"tie in this round"<<endl<<endl;
                    
                }
                else{
                    cout<<"Error"<<endl<<endl;
                    exit(0);}
            }

            if(score_player==((matches/2)+1)){
                cout<<"you won the match"<<endl;
            }
            else{
                cout<<"computer won the match"<<endl;
            }
        }
    }
    



    return 0;
}

