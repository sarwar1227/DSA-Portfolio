#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class Queue
{
    private:
        struct node
        {
            int data;
            node *next;
        }*front,*rear;
    public:
        Queue()
        {
            front=rear=NULL;
        }
        int check_empty()
        {
            return(front==NULL);
        }
        void insert_item(int item)
        {
            node *n=new node;
            n->data=item;
            n->next=NULL;
            if(check_empty())
                front=rear=n;
            else
            {
                rear->next=n;
                rear=n;
            }
            cout<<endl<<"Value Inserted";
        }
        void remove_item()
        {
           if(check_empty())
            cout<<endl<<"Queue is Empty";
           else
           {
               node *temp=front;
               front=front->next;
               cout<<"Deleted Item : "<<temp->data;
               delete temp;
           }
        }
        void check_front()
        {
            if(check_empty())
                cout<<endl<<"Queue is Empty";
            else
                cout<<"Value at front : "<<front->data;
        }
        void check_rear()
        {
            if(check_empty())
                cout<<endl<<"Queue is Empty";
            else
                cout<<"Value at front : "<<rear->data;
        }
        void traverse()
        {
            if(check_empty())
                cout<<endl<<"Queue is Empty";
            else
            {
                cout<<endl<<"Values in Queue : ";
                node *temp=front;
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
            }
        }
        void count_items()
        {

            if(check_empty())
                cout<<endl<<"Queue is Empty";
            else
            {
                node *temp=front; int c=0;
                while(temp!=NULL)
                {
                    c++;
                    temp=temp->next;
                }
                cout<<endl<<"Total Items : "<<c;
            }
        }
};
int menu()
{
    system("cls");
    string ch; stringstream ss; int temp;
    cout<<endl<<"1.Insert Item";
    cout<<endl<<"2.Remove Item";
    cout<<endl<<"3.Check Value at Front";
    cout<<endl<<"4.Check Value at Rear";
    cout<<endl<<"5.Traverse";
    cout<<endl<<"6.Count Items";
    cout<<endl<<"7.Exit";
    cout<<endl<<"Enter Your Choice : ";
    cin>>ch; ss<<ch; ss>>temp;
    return temp;
}
int main()
{
    Queue q; int item;
    while(1)
    {
        switch(menu())
    {
        case 1:
            cout<<endl<<"Enter Item : ";
            cin>>item;
            q.insert_item(item);
            break;
        case 2:
            q.remove_item();
            break;
        case 3:
            q.check_front();
            break;
        case 4:
            q.check_rear();
            break;
        case 5:
            q.traverse();
            break;
        case 6:
            q.count_items();
            break;
        case 7:
            exit(0);
        default:
            cout<<endl<<"Invalid Choice";
    }
    getch();
    }
    return 0;
}
