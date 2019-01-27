//CIRCULAR LINKED LIST
//Library
#include<iostream>
using namespace std;

class Node		//class Node is defined	
{
	public:		//giving acess
	int data;	
	Node *next;
	Node(int value)	//default constructor
 {
	next=NULL;
	data=value;
 }
};


class Linkedlist	//class linkedlist is defined
{
	public:
	Node*head;	//variables declared
	Node*tail;	//to point to the last data 
	
	Linkedlist()
 {
	head=NULL;
	tail=NULL;
 }



	void insert(int value)		//function for insering data at end
 {
	Node*temp=new Node(value);	//new Node is formed
	tail=temp;			
	if(head==NULL)			//checking if first element
  {				
	head=temp;			//head is linked
	
  }
	else 
  {
	Node*current=head;	
	
	if(current->next==NULL)		//for inserting second element
	{
	current->next=temp;
	temp->next=head;	//linking back to head
	}
	else if(current->next!=NULL)	
	{
	do
	{
	current=current->next;
	}while(current->next!=head);	//stopping loop when it reaches the lst
	current->next=temp;
	temp->next=head;
	}
  }
 }
	void display()
	{
	Node *current=head;
	do
	{
	cout<<current->data<<"->";
	current=current->next;		//displaying each data pointed by current
	}while(current!=head);
	cout<<"NULL";
	cout<<endl;
	}

	void insertAt(int pos,int value)
{
	
	Node*temp=new Node(value);	
	Node*current=head;
	if(pos==1)
	{
	tail->next=temp;
	temp->next=head;		//inserting at first position
	head=temp;		//replacing head
	}
	else if(pos!=1)
	{
	int i=2;
	while(i<pos)
	{
	current=current->next;		
	i++;
	}
	temp->next=current->next;		//for other position
	current->next=temp;		
	}
}
	int countItems()		
{
	Node*current=head;
	int i=0;
	do
	{
	current=current->next;
	i++;
	}while(current!=head);
	return (i);
}	

	void delet()
{
	Node*current=head;Node*temp=tail;
	while(current->next!=tail)
	{
	current=current->next;
	}
	tail->next=NULL;
	tail=current;
	current->next=head;
	delete temp;
}
	
	void deleteAt(int pos)
{	Node*current=head;
	if(pos==1)
	{
	while(current->next!=head)
	{
	current=current->next;
	}
	current->next=head->next;
	Node*temp=head;
	head=head->next;
	delete temp;
	}
	
	
	else
	{
	int i=2;
	while(i<pos)
	{
	current=current->next;
	i++;
	}
	Node*temp=current->next;
	current->next=temp->next;
	delete temp;
	}
}

	
};

int main()
{int p,v,c;
Linkedlist csll;
csll.insert(1);		//call for the function inserting new node
csll.insert(2);
csll.insert(3);
csll.insert(4);
csll.insert(5);
c=csll.countItems();		//count items
cout<<"elements in circularlinkedist are:";
csll.display();		//displaying
cout<<"enter pos and value to be inserted";
cin>>p>>v;		

if(p<=c+1)		//check if the position exceeds the numbr of elements
{
csll.insertAt(p,v);
csll.display();
}
else
{
cout<<"Linked List does not have that many elements"<<endl;
}
cout<<"the number of elements in the linked list is :"<<csll.countItems()<<endl;
csll.delet();
cout<<"the element in the  last is deleted :";
csll.display();
cout<<"enter the pos to be deleted";
cin>>c;
csll.deleteAt(c);
csll.display();


return 0;
}
	  
	
