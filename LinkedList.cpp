#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *START=NULL;
node *create_node()
{
    node *n=new node;
    cout<<endl<<"Enter Value : ";
    cin>>n->data;
    n->next=NULL;
    return n;
}
void insert_node()
{
    node *n=create_node();
    if(START==NULL)
        START=n;
    else
    {
        node *temp=START;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=n;
    }
    cout<<endl<<"Value Successfully Inserted";
}
void delete_node()
{
    if(START==NULL)
        cout<<"List is Empty";
    else
    {
        node *temp=START;
        START=START->next;
        delete temp;
        cout<<endl<<"First Value Successfully Deleted !!";
    }
}
void traverse()
{
    cout<<"Values in List :";
    node *n=START;
    while(n!=NULL){
        cout<<" "<<n->data;
        n=n->next;}
}
node* reverse_list(node *start)
{
    node *t1=NULL,*t2=NULL;
    while(start!=NULL)
    {
        t2=start->next;
        start->next=t1;
        t1=start;
        start=t2;
    }
    return t1;
}
int menu()
{
    int ch;
    cout<<"1.Insert Value at end";
    cout<<endl<<"2.Delete First Value";
    cout<<endl<<"3.Traverse List";
    cout<<endl<<"4.Exit";
    cout<<endl<<"5.Reverse The List";
    cout<<endl<<"Enter Your Choice : ";
    cin>>ch;
    return ch;
}
int main()
{
    while(1){
            system("cls");
    switch(menu())
    {
    case 1:
        insert_node();
        break;
    case 2:
        delete_node();
        break;
    case 3:
        traverse();
        break;
    case 4:
        exit(0);
    case 5:
        START=reverse_list(START);
        cout<<endl<<"List Reversed";
        break;
    default:
        cout<<endl<<"Invalid Choice";
    }
    getch();}
    return 0;
}
