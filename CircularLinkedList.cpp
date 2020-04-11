#include<iostream>
#include<conio.h>
#include<cctype>
using namespace std;
struct node
{
    int data;
    node *next;
};

node *last=NULL;

node *createlist();
node *addtoempty(node *last,int data);
node *addatbeg(node *last,int data);
node *addtolast(node *last,int data);
node *addafter(node *last,int data,int val);
void display(node *last);
node *delfrombeg(node *last);
node *delfromend(node *last);
node *delafter(node *last,int data);

node *createlist()
{
   int n,item;
   cout<<endl<<"Enter Initial Size of List : ";
   cin>>n;
   cout<<endl<<"Enter First Value : ";
   cin>>item;
   last=addtoempty(last,item);
   for(int i=1;i<n;i++)
   {
       cout<<endl<<"Enter "<<i+1<<" Value : ";
       cin>>item;
       last=addtolast(last,item);
   }
   return last;
}
node *addtoempty(node *last,int data)
{
    if(last==NULL)
     {
         node *n=new node;
         n->data=data;
         last=n;
         last->next=last;
         cout<<endl<<"Value Added Successfully to an empty List";
     }
     else
        cout<<endl<<"Sorry List is not empty";
     return last;
}
node *addatbeg(node *last,int data)
{
     if(last==NULL)
        cout<<endl<<"List Not Created....Create a List First";
     else
     {
         node *n=new node;
         n->next=last->next;
         last->next=n;
         n->data=data;
         cout<<endl<<"Value Added Successfully at Beginning";
     }
     return last;
}
node *addtolast(node *last,int data)
{
    if(last==NULL)
      cout<<endl<<"List Not Created....Create a List First";
    else
    {
        node *n=new node;
        n->next=last->next;
        last->next=n;
        last=n;
        n->data=data;
        cout<<endl<<"Value Added Successfully at the End";
    }
    return last;
}
node *addafter(node *last,int data,int val)
{
    if(last==NULL)
        cout<<endl<<"Insertion Not Possible...Because List is Empty";
    else
    {node *temp;
    temp=last->next;
    while(temp->data!=data)
    {
        temp=temp->next;
        if(temp==last->next){
            cout<<endl<<"Entered Value does not exist !!";
            return last;}
    }
    node *n=new node;
    n->data=val;
    n->next=temp->next;
    temp->next=n;
    cout<<endl<<val<<" Added After "<<data<<" Successfully";
    }
    return last;
}
void display(node *last)
{
   if(last==NULL)
    cout<<endl<<"List is Empty";
   else{
    cout<<endl<<"Values in List : ";
   node *temp=last->next;
   do
   {
       cout<<temp->data<<" ";
       temp=temp->next;
   }while(temp!=last->next);
   }
}
node *delfrombeg(node *last)
{
  if(last==NULL)
    cout<<endl<<"List is Empty";
  else
    if(last->next==last)
    {
      cout<<endl<<"Value Deleted From Beginning : "<<last->data;
      delete last;
      last=NULL;
    }
   else{
    node *temp=last->next;
    last->next=last->next->next;
    cout<<endl<<"Value Deleted From Beginning : "<<temp->data;
    delete temp;
      }
   return last;
}
node *delfromend(node *last)
{
    if(last==NULL)
        cout<<endl<<"List is Empty";
    else
        if(last->next==last){
           cout<<endl<<"Value Deleted From End : "<<last->data;
           delete last;
           last=NULL;}
         else{
           node *temp=last->next;
           while(temp->next!=last)
              temp=temp->next;
           temp->next=last->next;
           cout<<"Value Delete From End : "<<last->data;
           delete last;
           last=temp;
    }
    return last;
}
node *delafter(node *last,int data)
{
      if(last==NULL)
        cout<<endl<<"List is Empty";
      else
        if(last->next==last&&last->data==data){
          cout<<endl<<"Only Single Element remaining in List...Deletion Not Possible";
        }
      else{
      node *temp=last->next;
      while(temp->data!=data){
        temp=temp->next;
        if(temp==last->next){
         cout<<endl<<"Entered Value Not Found";
         return last;}
      }
      node *temp2;
      temp2=temp->next;
      temp->next=temp->next->next;
      cout<<endl<<"Value "<<temp2->data<<" Deleted After "<<data<<" Successfully";
      delete temp2;
     }
 return last;
}
int menu()
{
    system("cls");
    int ch;
    cout<<"1.Create a List";
    cout<<endl<<"2.Add at Beginning";
    cout<<endl<<"3.Add To Last";
    cout<<endl<<"4.Add After a value";
    cout<<endl<<"5.Display Values";
    cout<<endl<<"6.Delete From Beginning";
    cout<<endl<<"7.Delete From End";
    cout<<endl<<"8.Delete after a Value";
    cout<<endl<<"9.Exit";
    cout<<endl<<"Enter Your Choice : ";
    cin>>ch;
    return ch;
}
int main()
{
    int data,temp;
    while(1)
    {
        switch(menu())
        {
        case 1:
            last=createlist();
            break;
        case 2:
            cout<<endl<<"Enter Value to add at beginning: ";
            cin>>data;
            last=addatbeg(last,data);
            break;
        case 3:
            cout<<endl<<"Enter Value to add at end: ";
            cin>>data;
            last=addtolast(last,data);
            break;
        case 4:
            cout<<endl<<"Enter Value after which New Value to be inserted : ";
            cin>>data;
            cout<<endl<<"Enter New Value : ";
            cin>>temp;
            last=addafter(last,data,temp);
            break;
        case 5:
            display(last);
            break;
        case 6:
            last=delfrombeg(last);
            break;
        case 7:
            last=delfromend(last);
            break;
        case 8:
            cout<<endl<<"Enter Value After Which data is to deleted : ";
            cin>>temp;
            last=delafter(last,temp);
            break;
        case 9:
            exit(0);
        default:
            cout<<endl<<"Invalid Choice";
        }
    getch();
    }
return 0;
}
