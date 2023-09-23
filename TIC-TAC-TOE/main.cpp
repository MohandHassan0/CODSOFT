#include <iostream>

using namespace std;
void pattern (char game[3][3])
{
    {for(int i=0;i<2;++i) {cout<<"   "; if(game[0][i]) {cout<<game[0][i];cout<<"  |";} else cout<<"   |";}
    if(game[0][2]){cout<<"   "; cout<<game[0][2];}
    cout<<endl;
    for(int i=0;i<2;++i)  cout<<"______|";
    cout<<"______"<<endl;
    for(int i=0;i<2;++i) {cout<<"   "; if(game[1][i]) {cout<<game[1][i];cout<<"  |";} else cout<<"   |";}
    if(game[1][2]){cout<<"   "; cout<<game[1][2];}
    cout<<endl;
    for(int i=0;i<2;++i) cout<<"______|";
    cout<<"______"<<endl;
    for(int i=0;i<2;++i) {cout<<"   ";if(game[2][i]) {cout<<game[2][i];cout<<"  |";} else cout<<"   |";}
    if(game[2][2]){cout<<"   "; cout<<game[2][2];}
    cout<<endl;
    for(int i=0;i<2;++i) cout<<"      |";
    cout<<endl;
    }
}
char check(char game[3][3],char t)
{
    if ((game[0][0]==t)&&(game[0][1]==t)&&(game[0][2]==t)) return t;
    if ((game[1][0]==t)&&(game[1][1]==t)&&(game[1][2]==t)) return t;
    if ((game[2][0]==t)&&(game[2][1]==t)&&(game[2][2]==t)) return t;
    if ((game[0][0]==t)&&(game[1][0]==t)&&(game[2][0]==t)) return t;
    if ((game[0][1]==t)&&(game[1][1]==t)&&(game[2][1]==t)) return t;
    if ((game[0][2]==t)&&(game[1][2]==t)&&(game[2][2]==t)) return t;
    if ((game[0][0]==t)&&(game[1][1]==t)&&(game[2][2]==t)) return t;
    if ((game[0][2]==t)&&(game[1][1]==t)&&(game[2][0]==t)) return t;

    return 0;
}

int finish (char game[3][3])
{
    for(int i=0;i<3;++i)
   {
       for (int j=0;j<3;++j)
        if(game[i][j]=='\0'){return 0;}
   }
    return 1;
}
int main()
{
   cout<<"Here is some instruction before playing the game:"<<endl;
   cout<<"This is two players mode the first player x and the second is o."<<endl;
   cout<<"every turn each player will enter the dimension he will play in his symbol."<<endl;
   cout<<"dimensions starts from row 1 column 1 to row 3 column 3."<<endl;
   cout<<"wishing the game entertain you, have a nice try."<<endl;
   cout<<endl<<endl;


   start:
   char game [3][3];
   for(int i=0;i<3;++i)
   {
       for (int j=0;j<3;++j)
        game[i][j]='\0';
   }

   pattern(game);
   int x=5,y=5;
   for (int i=0;i<2;++i)
   {
       label :cout<<"Enter dimension you want for X:"; cin>>x>>y;
       if ((x>3)||((y>3))||(x<1)||(y<1)) {cout<<"Not Valid dimension enter dimension in 3x3 matrix"<<endl; goto label;}
       if (game[x-1][y-1]) {cout<<"Not Valid location. it has a value already enter dimension of free location"<<endl; goto label;}
       game[x-1][y-1]='X';
       pattern(game);
       label0 : cout<<"Enter dimension you want for O:"; cin>>x>>y;
       if ((x>3)||((y>3))||(x<1)||(y<1)) {cout<<"Not Valid dimension enter dimension in 3x3 matrix"<<endl; goto label0;}
       if (game[x-1][y-1]) {cout<<"Not Valid location. it has a value already enter dimension of free location"<<endl; goto label0;}
       game[x-1][y-1]='O';
       pattern(game);
   }
   char result=0;
   int done=0;
   while(!result&&!done)
   {
       label1 :cout<<"Enter dimension you want for X:"; cin>>x>>y;
       if ((x>3)||((y>3))||(x<1)||(y<1)) {cout<<"Not Valid dimension enter dimension in 3x3 matrix"<<endl; goto label1;}
       if (game[x-1][y-1]) {cout<<"Not Valid location. it has a value already enter dimension of free location"<<endl; goto label1;}
       game[x-1][y-1]='X';
       pattern(game);
       x=check(game,'X');
       if (x) break;
       done=finish(game);
       if (done) break;
       label2 :cout<<"Enter dimension you want for O:"; cin>>x>>y;
       if ((x>3)||((y>3))||(x<1)||(y<1)) {cout<<"Not Valid dimension enter dimension in 3x3 matrix"<<endl; goto label2;}
       if (game[x-1][y-1]) {cout<<"Not Valid location. it has a value already enter dimension of free location"<<endl; goto label2;}
       game[x-1][y-1]='O';
       pattern(game);
       x=check(game,'O');
       if (x) break;
       done=finish(game);
       if (done) break;
   }
   cout<<endl<<endl;
   if (x){
   if (x=='X') cout<<"player one won the game, congratulations"<<endl;
   else cout<<"player two won the game, congratulations"<<endl;
   }
   if (done) {cout<<"No one won the game.Both of you did a great work"<<endl;}


   check:
   int st;
   cout<<"The Trial is done if you want to start another game enter 1 if you won't enter zero"<<endl;
   cin>>st;
   if (st==1) goto start;
   else if (st==0) return 0;
   else {cout<<"Invalid input enter zero or one"<<endl; goto check; }


    return 0;
}
