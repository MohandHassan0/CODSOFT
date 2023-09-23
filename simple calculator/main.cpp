#include <iostream>

using namespace std;

int main()
{
    cout << "This is a simple calculator can perform any of these operations on two operands:" << endl;
    cout<<"-Addition(+)"<<endl<<"-Subtraction(-)"<<endl<<"-Multiplication(*)"<<endl<<"-Division(/)"<<endl<<endl<<endl;

    int x,y;
    char operation;

    start:
    cout<<"Enter the first operand: "; cin>>x;
    cout<<"Enter the second operand: "; cin>>y;

    start2:
    cout<<"Enter the symbol of operation: ";cin>>operation;
    cout<<endl;

    switch(operation)
    {

    case '*': {cout<<x<<operation<<y<<"="<<x*y<<endl<<endl; break;}
    case '+': {cout<<x<<operation<<y<<"="<<x+y<<endl<<endl; break;}
    case '-': {cout<<x<<operation<<y<<"="<<x-y<<endl<<endl; break;}
    case '/':
    {if (y==0)
    {cout<<"The second operand is zero and division on zero can't be done"<<endl;
    cout<<"if you want to divide on another operand choose 1"<<endl;
    cout<<"if you want to make another operation from the beginnig enter 2"<<endl;
    cout<<"to exit enter any value other than these "<<endl;
    int check;
    cin>>check;
    if (check==1) {cout<<"Enter the second operand: "; cin>>y;}
    else if (check==2) goto start;
    else return 0;}
    cout<<x<<operation<<y<<"="<<(float)x/y<<endl<<endl;
    break;
    }
    default :
    {
    cout<<"In valid operation"<<endl;
    cout<<"if you want to choose another operation on the same operands choose 1"<<endl;
    cout<<"if you want to make another operation from the beginnig enter 2"<<endl;
    cout<<"to exit enter any value other than these "<<endl;
    int l;
    cin>>l;
    if (l==1) goto start2;
    else if (l==2) goto start;
    else return 0;
    }
    }

    cout<<"if you want to do another operation on the same operands choose 1 "<<endl;
    cout<<"if you want to make another operation from the beginnig enter 2"<<endl;
    cout<<"to exit enter any value other than these "<<endl;
    int k;
    cin>>k;
    if (k==1) goto start2;
    else if (k==2) goto start;
    return 0;
}
