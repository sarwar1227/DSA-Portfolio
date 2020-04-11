#include<iostream>
#include<conio.h>
using namespace std;
struct ArrayStack
{
    int top;
    int capacity;
    int *Array;
};
ArrayStack *CreateStack(int cap)
{
    ArrayStack *Stack=new ArrayStack;
    Stack->top=-1;
    Stack->capacity=cap;
    Stack->Array=new int[Stack->capacity];
    return Stack;
}
bool isFull(ArrayStack *Stack)
{
    return(Stack->top==Stack->capacity-1);
}
bool isEmpty(ArrayStack *Stack)
{
   return(Stack->top==-1);
}
void PushItem(ArrayStack *Stack,int item)
{
      if(!isFull(Stack))
      {
          Stack->top++;
          Stack->Array[Stack->top]=item;
          cout<<endl<<"Value Successfully Pushed";
      }
      else
        cout<<endl<<"Stack is Full....Value Can't Be Inserted";
}
int PopItem(ArrayStack *Stack)
{
      int item;
      if(!isEmpty(Stack))
      {
          item=Stack->Array[Stack->top];
          Stack->top--;
          return item;
      }
      cout<<endl<<"Stack is Empty";
      return -1;
}
int ReturnTop(ArrayStack *Stack)
{
   if(Stack->top!=-1)
    return(Stack->Array[Stack->top]);
   return -1;
}
void Traverse(ArrayStack *Stack)
{
    cout<<endl<<"Values in Stack : ";
    for(int i=0;i<=Stack->top;i++)
        cout<<Stack->Array[i]<<" ";
}
int menu()
{
    int ch;
    cout<<endl<<"1.Push Item";
    cout<<endl<<"2.Pop Item";
    cout<<endl<<"3.Check Top Item";
    cout<<endl<<"4.Traverse Stack";
    cout<<endl<<"5.Exit";
    cout<<endl<<"Enter Your Choice : ";
    cin>>ch;
    return ch;
}
int main()
{
    cout<<"Enter Size of Stack : ";
    int n,item;
    cin>>n;
    ArrayStack *Stack;
    Stack=CreateStack(n);
    while(1){
            system("cls");
    switch(menu())
    {
    case 1:
        cout<<endl<<"Enter Number to Push : ";
        cin>>item;
        PushItem(Stack,item);
        break;
    case 2:
        item=PopItem(Stack);
        if(item!=-1)
            cout<<endl<<"Popped Item : "<<item;
        break;
    case 3:
        item=ReturnTop(Stack);
        if(item!=-1)
            cout<<endl<<"Element at Top is : "<<item;
        else
            cout<<endl<<"Stack is Empty";
        break;
    case 4:
        Traverse(Stack);
        break;
    case 5:
        exit(0);
    default:
        cout<<endl<<"Wrong Choice";
    }
 getch();
}
return 0;
}
