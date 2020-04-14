#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class node
{
private:
    int data;
    node *next,*prev;
public:
    node()
    {
        data=0;
        next=prev=NULL;
    }
    node(int d,node *n,node *p)
    {
        data=d;
        next=n;
        prev=p;
    }
    int get_data()
    {
        return data;
    }
    node *get_next()
    {
        return next;
    }
    node *get_prev()
    {
        return prev;
    }
    void set_data(int d)
    {
        data=d;
    }
    void set_next(node *n)
    {
        next=n;
    }
    void set_prev(node *p)
    {
        prev=p;
    }
};
class DLL
{
    private:
        int capacity;
        node *start;
    public:
        DLL()
        {
            capacity=0;
            start=NULL;
        }
        DLL(int cap,node *n)
        {
            capacity=cap;
            start=n;
        }
        void create()
        {
            int temp; int temp2;
            cout<<endl<<"Enter Initial Size of DLL : ";
            cin>>temp2;
            node *n=new node();
            cout<<endl<<"Enter 1st Value : ";
            cin>>temp;
            start=n;
            n->set_data(temp);
            n->set_next(NULL);
            n->set_prev(NULL);
            cout<<endl<<"First Value inserted";
            capacity++;
            for(int i=1;i<temp2;i++)
            {
              cout<<endl<<"Enter "<<i+1<<" Value : ";
              cin>>temp;
              add_at_end(temp);
              capacity++;
              cout<<endl<<"Value Successfully Inserted";
            }
     }
      void add_at_end(int item)
      {
        if(start==NULL)
           cout<<endl<<"Create A DLL First....DLL Not Created";
        else
         {
           node *t=start;
           node *n=new node(item,NULL,NULL);
               while(t->get_next()!=NULL)
                   t=t->get_next();
               t->set_next(n);
               n->set_prev(t);
         }
      }
       void add_at_front(int item)
        {
           if(start==NULL)
              cout<<endl<<"Create A DLL First....DLL Not Created";
           else
           {
              node *t=start;
              node *n=new node(item,NULL,NULL);
              start->set_prev(n);
              n->set_next(start);
              start=n;
           }
        }
       void add_after(int value,int item)
       {
         if(start==NULL)
          cout<<endl<<"Create A DLL First....DLL Not Created";
         else
         {
             node *t=start;
             node *n=new node(item,NULL,NULL);
             while(t->get_data()!=value)
                t=t->get_next();
             n->set_next(t->get_next());
             t->get_next()->set_prev(n);
             node *temp=t->get_next();
             temp->set_prev(n);
             n->set_prev(t);
             t->set_next(n);
         }
       }
      void add_before(int value,int item)
      {
         if(start==NULL)
           cout<<endl<<"Create A DLL First....DLL Not Created";
         else
         {
           node *t=start;
           while(t->get_data()!=value)
             t=t->get_next();
           t=t->get_prev();
           add_after(value,item);
         }
      }
      void delete_from_end()
      {
         if(start==NULL)
           cout<<endl<<"DLL is Empty...";
         else{
         node *t=start;
         while(t->get_next()!=NULL)
             t=t->get_next();
         node *temp=t->get_prev();
         temp->set_next(NULL);
         cout<<endl<<"Value Deleted : "<<t->get_data();
         delete t;
         }
      }
      void delete_from_front()
      {
             if(start==NULL)
              cout<<endl<<"DLL is Empty...";
             else{
               node *t=start;
               start=start->get_next();
               start->set_prev(NULL);
               cout<<endl<<"Value Deleted : "<<t->get_data();
               delete t;
             }
      }
      void delete_after(int item)
      {
             node *t=start;
             while(t->get_data()!=item)
                t=t->get_next();
             node *temp=t->get_next();
             t->set_next(temp->get_next());
             temp->get_next()->set_prev(t);
             cout<<endl<<"Value Deleted : "<<temp->get_data();
             delete temp;
      }
      void delete_before(int item)
      {
           node *t=start;
           while(t->get_data()!=item)
            t=t->get_next();
           t=t->get_prev()->get_prev();
           delete_after(item);
      }
      int get_front_value()
      {
            if(start==NULL)
              cout<<endl<<"DLL is Empty...";
            else
                return start->get_data();
      }
      int get_end_value()
      {
          if(start==NULL)
           cout<<endl<<"DLL is Empty...";
        else
        {
            node *t=start;
            while(t->get_next()!=NULL)
                t=t->get_next();
            return t->get_data();
        }
      }
    int search_item(int item)
    {
       if(start==NULL){
        cout<<endl<<"DLL is Empty";
        return -1;}
       else{
       node *t=start; int pos=1;
       while(t->get_data()!=item)
       {
           pos++;
           t=t->get_next();
       }
       if(t!=NULL)
        return pos;
       else{
            cout<<endl<<"Value Not Found !!";
        return -1;}}
    }
    void view_list()
    {
        if(start==NULL)
            cout<<endl<<"List is Empty ";
        else{
                cout<<endl<<"Values in List : ";
                node *t=start;
                while(t!=NULL){
                  cout<<t->get_data()<<" " ;
                   t=t->get_next();}
        }
    }
};
int menu()
{
    system("cls");
    stringstream ss; int temp; string ch;
    cout<<endl<<"1.Create A DLL";
    cout<<endl<<"2.Add At End";
    cout<<endl<<"3.Add At Front";
    cout<<endl<<"4.Add After a Value";
    cout<<endl<<"5.Add Before a Value";
    cout<<endl<<"6.Delete From End";
    cout<<endl<<"7.Delete From Front";
    cout<<endl<<"8.Delete After a Value";
    cout<<endl<<"9.Delete Before a Value";
    cout<<endl<<"10.Check Value at Front";
    cout<<endl<<"11.Check Value at End";
    cout<<endl<<"12.Search Any Value";
    cout<<endl<<"13.View List";
    cout<<endl<<"14.Exit";
    cout<<endl<<"Enter Your Choice : ";
    cin>>ch; ss<<ch; ss>>temp;
    return temp;
}
int main()
{
 DLL D;
 int item,temp;
 while(1)
 {
     switch(menu())
     {
     case 1:
         D.create();
         break;
     case 2:
         cout<<endl<<"Enter Item : ";
         cin>>item;
         D.add_at_end(item);
         break;
     case 3:
        cout<<endl<<"Enter Item : ";
         cin>>item;
         D.add_at_front(item);
         break;
     case 4:
         cout<<endl<<"Enter Value After Which Value to be added : ";
         cin>>temp;
         cout<<endl<<"Enter Value : ";
         cin>>item;
         D.add_after(temp,item);
         break;
     case 5:
         cout<<endl<<"Enter Values Before Which Value to be added : ";
         cin>>temp;
         cout<<endl<<"Enter Value : ";
         cin>>item;
         D.add_before(temp,item);
         break;
     case 6:
         D.delete_from_end();
         break;
     case 7:
        D.delete_from_front();
        break;
     case 8:
         cout<<endl<<"Enter Value After Which Value is to deleted : ";
         cin>>item;
         D.delete_after(item);
         break;
     case 9:
         cout<<endl<<"Enter Value Before Which Value is to deleted : ";
         cin>>item;
         D.delete_before(item);
         break;
     case 10:
         item=D.get_front_value();
         cout<<endl<<"Value at Front : "<<item;
         break;
     case 11:
         item=D.get_end_value();
         cout<<endl<<"Value at End : "<<item;
         break;
      case 12:
         cout<<endl<<"Enter Item to Search : ";
         cin>>item;
         item=D.search_item(item);
         if(item!=-1)
            cout<<endl<<"Value Found at Position : "<<item;
        break;
      case 13:
        D.view_list();
        break;
      case 14:
         exit(0);
      default:
         cout<<endl<<"Invalid Choice";
     }
 getch();
 }
 return 0;
}
