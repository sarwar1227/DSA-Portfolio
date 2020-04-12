#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *top=NULL;

void Createstack();
void Push(int);
void Pop();
void Value_At_Top();
void Traverse();

void createstack()
{
    int num,item;
    cout<<endl<<"Enter Initial Size of Stack : ";
    cin>>num;
    cout<<"Enter 1st Item : ";
    cin>>item;
    node *n=new node;
    n->next=NULL;
    top=n;
    n->data=item;
    Push(item);
    for(int i=1;i<num;i++)
    {
        cout<<endl<<"Enter "<<i+1<<" Item : ";
        cin>>item;
        Push(item);
    }
}
void Push(int item)
{
    if(top==NULL)
        cout<<endl<<"Stack Not Created....Create a Stack First";
    else
    {
        node *n=new node;
        n->data=item;
        n->next=top;
        top=n;
        cout<<endl<<"Value Successfully Pushed into Stack !!";
    }
}
void Pop()
{
    if(top==NULL)
        cout<<endl<<"Stack is Empty..Popping Not Possible";
    else
    {
        if(top->next==NULL)
        {
            cout<<endl<<"Popped Item : "<<top->data;
            delete top;
            top=NULL;
        }
        else
        {
            node *temp=top;
            top=top->next;
            cout<<endl<<"Popped Item : "<<temp->data;
            delete temp;
        }
    }
}
void Value_At_Top()
{
   if(top==NULL)
    cout<<endl<<"Stack is Empty";
   else
    cout<<endl<<"Value at Top is : "<<top->data;
}
void Traverse()
{
    node *t=top;
    cout<<endl<<"Values in Stack : TOP->";
    while(t!=NULL){
        cout<<t->data<<"->";
        t=t->next;}
    cout<<"NULL";
}
int menu()
{
    system("cls");
    string ch; int temp; stringstream ss;
    cout<<"1.Create A Stack";
    cout<<endl<<"2.Push Item";
    cout<<endl<<"3.Pop Item";
    cout<<endl<<"4.Check Value at Top";
    cout<<endl<<"5.Traverse Stack";
    cout<<endl<<"6.Exit";
    cout<<endl<<"Enter Your Choice : ";
    cin>>ch; ss<<ch; ss>>temp;
    return temp;
}
int main()
{
    int item;
    while(1)
    {
        switch(menu())
        {
            case 1:
                createstack();
                break;
            case 2:
                cout<<endl<<"Enter Item : ";
                cin>>item;
                Push(item);
                break;
            case 3:
                Pop();
                break;
            case 4:
                Value_At_Top();
                break;
            case 5:
                Traverse();
                break;
            case 6:
                 exit(0);
            default:
               cout<<endl<<"Invalid Choice";
    }
  getch();
 }
 return 0;
}
