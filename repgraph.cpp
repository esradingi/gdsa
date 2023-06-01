/* Represent a graph using adjacency list and adjacency Matrix
*/

#include<iostream>
#include<stdio.h>
using namespace std;
class Graphnode
  {
	public:
	Graphnode *next;
	int vertex;
  };

class Graph
{
	public:
	//Functions for list
	Graphnode *head[20];  		//heads of the linked list
	int no;       	// no of nodes   
	int graphMatrix[10][10];
	void insert(int vi,int vj,int);              //insert an edge (vi,vj)in adj.list
	void display(int );
	int create();
	//Functions for Matrix
	void insert1(int vi,int vj );
	void creatematrix();
	void displaymatrix();
	public:
		Graph()
		  {
			//n=5;
			no=0;
		  }
	
};
int Graph::create()
{
	int i=0,vi=0,vj=0,n=5;

	/*cout<<"\nEnter no. of vertices :";
cout<<"hello";
i=vi+vj;
cout<<i;

	cin >>n;
	cout<<"hello";
cout<<"hello";
i=vi+vj;
cout<<i;*/
	//initialise head with NULL
	for(i=0;i<n;i++)
	{
		//head[i]->next=NULL;
		cout<<"\n\n\tEnter the vertax  ";
		cin>>head[i]->vertex;
	}
	while(1)
	{
		cout<<"\n\nEnter an edge (u,v)  :";
		cin>>vi>>vj;
		insert(vi,vj,n);
		insert(vj,vi,n);
		cout<<"\n\n\tWant to enter more?\t";
		char ch;
		cin>>ch;
		if(ch=='n')
			break;
		
	}
return(n);
}
void Graph::insert(int vi,int vj,int n)
{
	Graphnode *temp,*freashnode;

	freashnode=new Graphnode ;
	freashnode->vertex=vj;
	freashnode->next=NULL;
	//insert the node in the linked list for the vertex no. vi
	for(int i=0;i<n;i++)
	{
		if(head[i]->vertex==vi)
		{
			if(head[i]->next==NULL)
				head[i]->next=freashnode;
			else
			{
				temp=head[i];
					// go to the end of linked list
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=freashnode;
			}
		}
	}
}

void Graph::display(int n)
{
	Graphnode *temp;
	cout<<"\n\n\t\tNode\tAdjacent Nodes\n";
	cout<<"---------------------------------------------------";
	for(int i=0;i<n;i++)
	{
		cout<<"\n\t\t"<<head[i]->vertex;
		temp=head[i];
		while(temp->next!=NULL)
		{
			temp=temp->next;
			cout<<"\t"<<temp->vertex;
		}

	}
}
void Graph:: creatematrix()
{
	int i,j,vi,vj;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			graphMatrix[i][j] = 0;
		}
	}
	cout<<"\n\n\tEnter number of Nodes:";
	cin>>no;
	
	while(1)
	{
		cout<<"\n\n\tEnter an edge (u,v)  :";
		cin>>vi>>vj;
		insert1(vi,vj);
		insert1(vj,vi);
		cout<<"\n\n\tWant to enter more?\t";
		char ch;
		cin>>ch;
		if(ch=='n')
			break;
		
	}
	
}
void Graph::insert1(int vi,int vj)
{
	int i,j;
	for(int i=1; i<=no; i++)
	{
		for(int j=1; j<=no; j++)
		{
			if(i==vi&&j==vj)			
				graphMatrix[i][j] =1;
		}
	}
}
void Graph:: displaymatrix()
{
	int i,j,k=1;
	cout<<"\n\n\t\tGraph Matix Representation\n\n\n";
	for(int i=1; i<=no; i++)
	{	
		if(i==1)
		cout<<"\t";		
		cout<<"  "<<i;
	}
	cout<<"\n";
	for(int i=1; i<=no; i++)
	{
		cout<<"\n\n  "<<k<<"\t";
		k++;		
		for(int j=1; j<=no; j++)
		{
			cout<<"  "<<graphMatrix[i][j];
		}
	}		
}
int main()
{
	int ch,n;
	Graph g;
	
	do
	{
		
		cout<<"\n\n\t\t1.Create a graph By List \n\n\t\t2.Display\n\n\t\t3.Crete a graph by matrix\n\n\t\t4.Display by matrix";
		cout<<"\n\n\tEnter Your Choice : ";
		cin >> ch;
		switch(ch)
		{
			case 1:
						n=g.create();
						break;
			case 2:
						g.display(n);
						break;
			case 3:
						g.creatematrix();
						break;
			case 4:		g.displaymatrix();
						break;		 
}

	 }while(ch!= 5);
return 0;
}


