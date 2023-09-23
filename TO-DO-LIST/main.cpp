#include <iostream>
#include<string.h>
#include <iomanip>



using namespace std;

class todo
{
private:
    struct node;
    typedef node* link;
    struct node
    {
        char data[200];
        char state[50];
        link previous;
        link next;
    };
link head,current,tail;
public:
    todo(){head=current=tail=NULL;}

    void add (char data[],char state[])
    {
        link addnode=new node;
        strcpy(addnode->data,data);
        strcpy(addnode->state,state);
        if (head==NULL)
        {head=addnode;
         addnode->previous=NULL;
         addnode->next=NULL;
         current=tail=addnode;
        }
        else
        {
            addnode->previous=current;
            addnode->next=NULL;
            addnode->previous->next=addnode;
            current=addnode;
            tail=addnode;
        }


    }
    void view ()
    {
     if (head==NULL) {cout<<"List is empty"<<endl; return;}
     link now;
     now=head;
     while (now!=NULL)
     {
       cout<<left<<setw(50)<<now->data<<now->state<<endl;
       now=now->next;
     }
    }
    void delete_ (char data[])
    {
        if (head==NULL) {cout<<"List is empty"<<endl; return;}
        link now;
        now=head;
        int x=1;
        while (now)
       {
        x=strcmp(now->data,data);
        if(!x)
        {
         if (now->previous==NULL)
         {
             head=now->next;
             now->next->previous=NULL;
             delete now;
             break;
         }
         else if(now->next==NULL)
         {
             now->previous->next=NULL;
             current=now->previous;
             delete now;
             break;
         }
         else
         {

         now->next->previous=now->previous;
         now->previous->next=now->next;
         delete now;
         break;
        }
        }
        now=now->next;
       }
       if (x)  {cout<<"No element matched to be deleted"<<endl;}
       else cout<<"Element is deleted"<<endl;
    }
    void edit(char data[])
    {
        if (head==NULL) {cout<<"List is empty"<<endl; return;}
        link now;
        now=head;
        int x=1;
        while (now)
       {
        x=strcmp(now->data,data);
        if(!x)
        {
         strcpy(now->state,"Completed");
         break;
        }
        now=now->next;
       }
       if (x)  {cout<<"No element matched to be edited"<<endl;}
       else cout<<"Element is edited to completed"<<endl;
    }
};

int main()
{
    todo the_list;
    cout<<"This program is designed to do your To-Do list with state of every task"<<endl;
    cout<<"Enter every task and its state"<<endl;
    char data[200];
    char state;
    char r[50];
    int x=1000;
    while(x)
    {
    cout<<endl<<endl;
    cout<<"Choose from this menu which operation you want to do: "<<endl;
    cout<<"1:add new task"<<endl;
    cout<<"2:remove task"<<endl;
    cout<<"3:mark task as completed"<<endl;
    cout<<"4:View the list"<<endl;
    cout<<"0:quit"<<endl;
    cin>>x;
    switch (x)
    {
    case 1:
        {
        cout<<endl<<endl;
        cin.ignore();
        cout<<"Task is:";
        cin.getline(data,200);
        cout<<endl;
        bool flag=true;
        while(flag)
        {
        cout<<"for state: enter C for completed or P for pending"<<endl;
        cout<<"state is:";
        cin>>state;
        switch (state)
        {
            case 'C' :{strcpy(r,"Completed"); the_list.add(data,r); flag=false; break; }
            case 'P' :{strcpy(r,"Pending"); the_list.add(data,r); flag=false; break;}
            default  :{cout<<"In valid input"<<endl;break;}
        }
        }
        cout<<"-----------------------------------------------------------------\n";
        break;}
     case 2:
            {
                cout<<endl<<endl;
                cin.ignore();
                cout<<"The task which you want delete is:";
                cin.getline(data,200);
                the_list.delete_(data);
                break;
            }
     case 3:
        {
                cout<<endl<<endl;
                cin.ignore();
                cout<<"The task which you want to make it completed is:";
                cin.getline(data,200);
                the_list.edit(data);
                break;
        }
     case 4:
        {
            cout<<endl<<endl;
            the_list.view();
            break;
        }
        case 0: return 0;
        default: {cout<<endl<<endl;
            cout<<"You entered a wrong choice form the menu"<<endl;
        break;}
    }
    }

    return 0;
}
