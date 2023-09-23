#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int x;
void guess()
{
    cout<<"Enter your new guess : ";
    cin>>x;
}
int main()
{
    srand(time(0));
    cout<<"This game is designed to guess a number between zero and max number you choose\n\n";
    int max;
    cout<<"The max number is:";cin>>max;
    cout<<endl<<endl;
    int target=rand()%max;
    cout << "Guess the number less than "<<max<<" : "  ;
    cin>>x;
    while (x!=target)
    {
    if(x>(target*2)) {cout<<"your guess is too high"<<endl; guess();continue;}
    if(x>(target*1.5)) {cout<<"your guess is high"<<endl; guess(); continue;}
    if(x>(target*1.2)) {cout<<"your guess is a little bit high"<<endl; guess();continue;}
    if((x>target)&& (x<(target*1.2)))  {cout<<"your guess is high but a much closer to the target"<<endl; guess();continue;}
    if(x<(target*.4)) {cout<<"your guess is too low"<<endl; guess();continue;}
    if(x<(target*.6)) {cout<<"your guess is low"<<endl; guess(); continue;}
    if(x<(target*.8)) {cout<<"your guess is a little bit low"<<endl; guess();continue;}
    if(x<target)   {cout<<"your guess is low but a much closer to the target"<<endl; guess();continue;}
    }
    if (x==target)
    {
    cout<<"Finally your guess "<<x<<" is correct."<<endl;
    }
    return 0;
}
