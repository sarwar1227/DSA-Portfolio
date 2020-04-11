import java.util.Scanner;
class Node
{
  private int data;
  private Node next;
  public Node()
  { data=0; next=null;}
  public Node(int d,Node n)
  { data=d; next=n;}
  public int GetData()
  { return data;}
  public Node GetNext()
  { return next;}
  public void SetData(int d)
  { data=d;}
  public void SetNext(Node n)
  { next=n;}
}
class LinkedList
{
  private Node START;
  private int size;
  public LinkedList()
  { size=0;  START=null;}
  public boolean IsEmpty()
  { if(START==null)
	  return true;
    else
	  return false;
  }
  public int GetListSize()
  { return size;}
  public void ViewList()
  {
	  Node t;
	  if(IsEmpty())
		  System.out.println("List is Empty");
   	  else{
		  t=START;
		  System.out.println("Values in List : ");
	      for(int i=0;i<size;i++)
		   {
		     System.out.print(t.GetData()+" ");
		     t=t.GetNext();
		   }
		  }
  }
 public void InsertAtFirst(int data)
 {
   Node n=new Node();
   n.SetData(data);
   n.SetNext(START);
   START=n;
   size++;
 }
 public void InsertAtLast(int data)
 {
	 Node t,n=new Node();
	 n.SetData(data);
	 t=START;
	 if(t==null)
		START=n;
     else
	 {
        while(t.GetNext()!=null)
            t=t.GetNext();
        t.SetNext(n);		
	 }
	 size++;
 }
public void InsertAtPos(int val,int pos)
{
 if(pos==1)
    InsertAtFirst(val);
 else if(pos==size+1)
	 InsertAtLast(val);
 else if(pos>1&&pos<=size)
 {
     Node n=new Node(val,null);
	 Node t=START;
     for(int i=1;i<pos-1;i++)
		 t=t.GetNext();
	 n.SetNext(t.GetNext());
	 t.SetNext(n);
	 size++;
 }
 else
	 System.out.println("Insertion Not Possible at Position"+pos+" : INVALID POSITION");
}
 public void DeleteFromStart()
 {
   START=START.GetNext();
   size--;
 }
 public void DeleteFromEnd()
 {
	 if(START==null)
		 System.out.println("List is Empty");
	 else if(size==1)
	         {
			   START=null;
		       size--;
			 }
		 else
		    {
			   Node t=START;
			   for(int i=1;i<size-1;i++)
				   t=t.GetNext();
			   t.SetNext(null);
		       size--;
		    }
}
 public void DeleteAtPos(int pos)
 {
     if(START==null)
		 System.out.println("List is Empty");
	 else if(pos<1||pos>size)
		 System.out.println("Invalid Deletion Request...Position Not Exist");
	 else if(pos==1)
			  DeleteFromStart();
     else if(pos==size)
			  DeleteFromEnd();
	else
	  {
	     Node t,t1;
		 t=START;
		 for(int i=1;i<pos-1;i++)
			 t=t.GetNext();
		 t1=t.GetNext();
		 t.SetNext(t1.GetNext());
		 size--;
	  }  
   	 }	 
}
public class ExampleList
{
	public static void main(String[] args)
	{
	   LinkedList list=new LinkedList();
	   int pos,temp;
	   Scanner sc=new Scanner(System.in);
	   while(true){
   	   System.out.println("\n1.Insert in the Beginning ");
	   System.out.println("2.Insert At End");
	   System.out.println("3.Insert At Position");
	   System.out.println("4.Delete From Start");
	   System.out.println("5.Delete From End");
	   System.out.println("6.Delete From Positin");
	   System.out.println("7.Traverse List");
	   System.out.println("8.Exit");
	   System.out.print("Enter Your Choice : ");
	   int choice=sc.nextInt();
	   boolean flag=true;
	   switch(flag)
	   {
		   case 1:
		        System.out.print("Enter Value : ");
				temp=sc.nextInt();
				list.InsertAtFirst(temp);
				break;
		   case 2:
		        System.out.print("Enter Value : ");
				temp=sc.nextInt();
				list.InsertAtLast(temp);
				break;
		   case 3:
		       System.out.print("Enter Position : ");
			   pos=sc.nextInt();
			   System.out.print("Enter Value : ");
			   temp=sc.nextInt();
			   list.InsertAtPos(temp,pos);
			   break;
		   case 4:
		       list.DeleteFromStart();
			   break;
		   case 5:
		       list.DeleteFromEnd();
			   break;
		   case 6:
		      System.out.print("Enter A Position : ");
			  pos=sc.nextInt();
			  list.DeleteAtPos(pos);
			  break;
		   case 7:
		      list.ViewList();
			  break;
		   case 8:
			  flag=false;
		   default:
		    System.out.print("Invalid Choice");
	   }
	}
}
}
