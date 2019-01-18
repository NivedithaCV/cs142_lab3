#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node*next;
	Node*prev;
	Node(int value)
	{
	next=NULL;
	prev=NULL;
	data=value;
	}
};

class DLL
{
	public:
	Node*head;
	
	DLL()
{
	head=NULL;
	
}
	void insert(int value)
	{
	Node *temp=new Node(value);
	if (head==NULL)
{	head=temp;
	}
	else
	{
	Node*current=head;
	while(current->next!=NULL)
		current=current->next;
		current->next=temp;
		temp->prev=current;
	}
}
	void insertAt(int pos,int value)
	{
	
	Node*temp=new Node(value);
	Node*current=head;
	
	if(pos==1)
	{
	temp->next=head;
	head->prev=temp;}
	else{
	int i=2;
	
	while(i<pos)
	{
	current=current->next;
	if(current==NULL)
	{
	cout<<"the pos exceed the limit"<<endl;
	break;}
	
	i++;
	}
	if(current!=NULL)
	{
	
	temp->next=current->next;
	temp->prev=current;
	current->next=temp;
	temp->next->prev=temp;
	}}}
	
	void display()
	{
	Node*current=head;
	Node*last;
	while(current->next!=NULL)
	{
		cout<<current->data<<"->";
		last=current;
		current=current->next;
	}
	cout<<"null"<<endl;
	cout<<"print in reverse oder:";
	while(last!=NULL)
	{
	cout<<last->data<<"->";
	last=last->prev;
	}
	cout<<"null"<<endl;
	}
	
	int countItems()
{
	Node*current=head;int i=0;
	while(current->next!=NULL)
{
	i++;
	current=current->next;
}
	return(i);
}
	void delet()
	{Node *temp;
	Node*current=head;
	while(current->next!=NULL)
	{current=current->next;}
	temp=current->next;
	current->next->prev=NULL;
	current->next=NULL;
	delete temp;}
		
};

int main()
{
DLL l1;
int a,b,c;
l1.insert(1);
l1.insert(2);
l1.insert(3);
cout<<"give the position and the value"<<endl;
cin>>a;
cin>>b;
l1.insertAt(a,b);
l1.display();
cout<<l1.countItems();
l1.delet();
l1.display();
return 0;

}


	
	
