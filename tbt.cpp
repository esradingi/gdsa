#include<iostream>
using namespace std;
 class node{
 public :
 int data;
 node *lchild;
 node *rchild;
 int rpointer;
 int lpointer;

};
 class tbt{
 
 node *head;
 public :
 tbt()
 {
 head = new node;
 head->data=99;
 head->lchild=head;
 head->rchild=head;
 head->rpointer=0;
 head->lpointer=0;
 
 }

 void create();
 void insert(int);
void inorderTraversal();
node* inorderSucc(node *);
};

void tbt::create()
{
   int data;
   while(1)
   {
   
   if(head->lchild==head&&head->rchild==head)
   {
      cout<<"Enter new Data:"<<endl;
	   cin>>data;
   
      node *temp;
      temp=new node;
       
      temp->data=data;
      temp->lchild=temp->rchild=head;
      head->lchild=temp;
      head->lpointer=1;
      cout<<"create tbt with a start node "<<data<<endl;
        
   }
   else{
      char ch;
      insert(data);
      cout<<"Do you wanna add more nodes : "<<endl;
      cin>>ch;
      if(ch=='n'){
          break;
      }
       
   }
 }
}
void tbt::insert(int data)
{
   cout<<"Enter data: "<<endl;
	cin>>data;
  node *temp;
  temp=head->lchild;
 while(1){
  if(data>temp->data){
  if(temp->rpointer==0)
  {
   node *freshnode;
   freshnode=new node;
   freshnode->data=data;
   temp->rchild=freshnode;
   temp->rpointer=1;
   freshnode->lpointer=freshnode->rpointer=0;
   break;
  } 
  else{
   
  temp=temp->rchild;
  }
  }
  if(data<temp->data){
   if(temp->lpointer==0){
   node *freshnode;
   freshnode=new node;
   freshnode->data=data;
   temp->lchild=freshnode;
   temp->lpointer=1;
   freshnode->lpointer=freshnode->rpointer=0;
   break;
   }
  else{
   temp=temp->lchild;
  }
}
 }
}

void tbt :: inorderTraversal()
{
node *temp;
temp=head->lchild;
do{
while(temp->lpointer==1){
 temp=temp->lchild;
}
cout<<temp->data<<" ";
temp=inorderSucc(temp);
}while(temp!=head);
}

node* tbt::inorderSucc(node *temp)
{
  if(temp->rpointer==0)
  {
    return temp->rchild;
  }
  else{
   temp=temp->rchild;
  }
  while(temp->lpointer==1){
   temp=temp->lchild;
  }
   return temp;

}
int main(){
tbt t;
int ch;
do{
cout<<"1.Create\n 2.Insert\n 3.Inodertraversal"<<endl;
cout<<"Choose : "<<endl;
cin>>ch;
switch(ch){
    case 1:
    t.create();
    break;
    case 2 :
    int data;
    
	 t.insert(data);
    break;
    case 3:
    cout<<"Inorder traversal is : "<<endl;
    t.inorderTraversal();
    break;
}
}while(ch<4);
return 0;

}
