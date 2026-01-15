/*major project : rock, paper, scissors-game , with fixed no. of rounds,score evaluation and winner */
#include <iostream>
#include<cstring>
#include <cstdlib>
#include<ctime>
using namespace std;
void compChoice (string[],string&);
void userChoice (string[],char[]);
void compareChoice (string[],string&,char[],int*,int*);
void final_winner(int*,int*);

int main()
{
    int a,score_u=0,score_c=0;
    char b;
    char uChoice[10] ;
    string options[]={"rock","paper","scissors"};
    string cChoice;
    starting:cout<<"enter no. of rounds in a match:"<<endl;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
    cout<<endl<<"round "<<i<<endl;
    compChoice(options,cChoice);
    userChoice(options,uChoice);
    cout<<"computer's choice:"<<cChoice<<endl<<"your choice:"<<uChoice<<endl<<"result:"<<endl;
    compareChoice(options,cChoice,uChoice,&score_u,&score_c);
    cout<<"your score="<<score_u<<endl<<"computer's score="<<score_c<<endl;
    }
    final_winner(&score_u,&score_c);
    if(score_u==score_c)
    {
    cout<<"another match?"<<endl<<"press y to continue , n to exit :"<<endl;
    cin>>b;
    if (b=='y')
    goto starting;
    if (b=='n')
    exit(1); 
    }
    return 0;
}
void compChoice(string options[],string&cChoice)
{
    srand(time(0));
    int c=rand()%3;
    cChoice=options[c];
}
void userChoice (string options[],char uChoice[])
{
    cout<<"enter your choice(rock/paper/scissors):";
    cin>>uChoice;
}
void compareChoice(string options[],string&cChoice,char uChoice[],int*score_u,int*score_c)
{
    string userschoice = uChoice;
    if (cChoice==userschoice)
    cout<<"tie"<<endl;
    else if ((cChoice=="rock"&&userschoice=="paper")||(cChoice=="paper"&&userschoice=="scissors")||(cChoice=="scissors"&&userschoice=="rock"))
    {
    cout<<"you win!"<<endl;
    (*score_u)++;
    }
    else
    {
    cout<<"computer wins"<<endl;
    (*score_c)++;
    }
}
void final_winner(int*score_u, int*score_c)
{
    if (*score_u==*score_c)
    cout<<"tie"<<endl<<endl<<"scores:"<<endl<<"you:"<<*score_u<<endl<<"comp:"<<*score_c<<endl<<endl;
    else if (*score_u>*score_c)
    cout<<"you won!"<<endl<<endl<<"scores:"<<endl<<"you:"<<*score_u<<endl<<"comp:"<<*score_c;
    else
    cout<<"computer won!"<<endl<<endl<<"scores:"<<endl<<"you:"<<*score_u<<endl<<"comp:"<<*score_c;
}