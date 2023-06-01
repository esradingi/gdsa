#include<iostream>
#include<stdlib.h>
using namespace std;
 class treeNode
 {
    public :
    int data;
    treeNode *rchild,*lchild;
 };

class tree
{
    public:
    void create();
    void insert(treeNode *,treeNode *);
    void display();
    void preorder(treeNode *);
    void inorder(treeNode *);
    void postorder(treeNode *);
    void search();
    treeNode* searchmin(treeNode *);
    treeNode* searchmax(treeNode *);
    treeNode* searchEle(treeNode *,int ,int );
    treeNode* delet(treeNode *, int );
    treeNode* mirror(treeNode*);

    treeNode *root;
   
    tree()
    {
        root=NULL;
    }
};

void tree::create()
{
    char ch;
    treeNode *freshnode;
    while(1)
    {
    freshnode=new treeNode;
    freshnode->lchild=NULL;
    freshnode->rchild=NULL;

    cout<<"Enter data to create new node : ";
    cin>>freshnode->data;

    if(root==NULL){
        root=freshnode;
    }
    else{
        insert(root,freshnode);
    }

    cout<<"Do you wanna add more nodes : "<<endl;
    cin>>ch;

    if(ch=='n'){
        break;
    }
    }
}
void tree::insert(treeNode *root,treeNode *freshnode){
    char ch;
    if(root->data<freshnode->data){
        if(root->rchild==NULL){
            root->rchild=freshnode;
        }
        else{
            insert(root->rchild,freshnode);
        }
      
    }

    else
    {
        if(root->lchild==NULL){
            root->lchild=freshnode;
        }
        else{
            insert(root->lchild,freshnode);
        }
        
    }
   
}

void tree::display()
{
    int ch;
    
    do{
        cout<<"Methods of displaying tree : "<<endl;
    cout<<"1.Preorder \n 2.Inorder \n3.Postorder"<<endl;
    cin>>ch;
    switch(ch){
    case 1:
     cout<<"Preorder traversal is : "<<endl;

        preorder(root);
        break;
    
    
    case 2:
     cout<<"Inorder traversal is : "<<endl;

        inorder(root);
        break;
    
    case 3:
     cout<<"Postorder traversal is : "<<endl;
        postorder(root);
        break;
    
    case 4:
    break; 
    }
}while(ch<4);
}
void tree::preorder(treeNode *root1)
{

    if(root1!=NULL){
        
        cout<<root1->data<<" "<<endl;
        preorder(root1->lchild);
        preorder(root1->rchild);
    }

}
void tree::inorder(treeNode *root1)
{
    
    if(root1!=NULL){
       
        
        inorder(root1->lchild);
        cout<<root1->data<<" "<<endl;
        inorder(root1->rchild);
    }

}

void tree::postorder(treeNode *root1)
{
            
    if(root1!=NULL)
    {
       
        postorder(root1->lchild);
        postorder(root1->rchild);
        cout<<root1->data<<" "<<endl;
    }

}

void tree :: search()
{
int ch;
do{
    cout<<"What do you want to search : "<<endl;
    cout<<"1.Searchmax \n2.Searchmin \n3.Search an element "<<endl;
    cin>>ch;

    switch(ch){
        case 1:
        cout<<"Max element is : "<<endl;
        searchmax(root);
        break;

        case 2:
        cout<<"Min element is : "<<endl;
        searchmin(root);
        break;

        case 3:
        int count=1;
        int ele;
        cout<<"Element to be searched is : "<<endl;
        cin>>ele;

        searchEle(root,ele,count);
        break;

    }
}while(ch<4);
}
treeNode* tree::searchmax(treeNode *root1){
while(root1->rchild!=NULL){
    root1=root1->rchild;
}
return (root1);
}


treeNode* tree::searchmin(treeNode *root1){
while(root1->lchild!=NULL){
    root1=root1->lchild;
}

 return (root1);
}

treeNode *tree::searchEle(treeNode *root1,int ele,int count){
if(root1==NULL){
    cout<<"Element not found : "<<endl;
}
else if(root1->data==ele){
    cout<<"Element found at : "<<count<<endl;
    return (root1);
}
else if(root1->data<ele){
    count++;
    root1=root1->rchild;
    searchEle(root1,ele,count);
}
else if(root->data>ele){
    count++;
    root1=root1->lchild;
    searchEle(root1,ele,count);
}

}

treeNode* tree::delet(treeNode *root1,int ele){
    treeNode *temp;
    temp=new treeNode;
    int count;
    
	if(root1==NULL)
	{
		cout<<"\nElement not found :"<<endl;;

		return(root1);
	}
	if(ele< root1->data)                // delete in left subtree
	{
		root1->lchild=delet(root1->lchild,ele);
		return(root1);
	}
	else if(ele > root1->data)                // delete in right subtree
	{
		root1->rchild=delet(root1->rchild,ele);
		return(root1);
	}
	if(root1->data==ele)
	{

    if(root1->lchild==NULL&&root1->rchild!=NULL){
        temp=root1;
        root1=root1->rchild;
        free(temp);
        return (root1);
    }
    else if(root1->rchild==NULL&&root1->lchild!=NULL){
        temp=root1;
        root1=root1->lchild;
        free(temp);
        return (root1);
    }
    else if(root1->lchild==NULL && root1->rchild==NULL){
        temp=root1;
        root1=NULL;
        free(temp);
        return (root1);

    }
    else if(root1->lchild!=NULL && root1->rchild!=NULL){
    temp=searchmin(root1->rchild);
    root1->data=temp->data;
    root1->rchild= delet(root1->rchild,temp->data);
    return (root1);


    }
    
}
cout<<"Element deleted :"<<root1->data;
}

treeNode* tree:: mirror(treeNode *root1){
treeNode *temp;
temp=NULL;
if(root1!=NULL){
temp=new treeNode;
temp->data=root1->data;
root1->lchild=mirror(root1->rchild);
root1->rchild=mirror(root1->lchild);
}
return (temp);
}

int main(){
tree t;
int ch;
do{
cout<<"1.Create\n 2.Insert\n 3.Display\n 4.Search \n5. Delete \n6.Mirror"<<endl;
cin>>ch;
switch(ch){
    case 1: 
    t.create();
    break;
    case 2:
    treeNode *freshnode;
    freshnode=new treeNode;
    freshnode->rchild=NULL;
    freshnode->lchild=NULL;
    cout<<"enter the value you wanna insert : ";
    cin>>freshnode->data;
    t.insert(t.root, freshnode);
    break;
    case 3:
    t.display();
    break;
    case 4 :
    t.search();
    break;
    case 5:
    int ele;
    cout<<"Enter the element to be deleted : "<<endl;
    cin>>ele;
    t.delet(t.root,ele);
    case 6:
    cout<<"Mirror of the tree that is swapping of left and right nodes : "<<endl;
    t.mirror(t.root);
}
}while(ch<=6);

return 0;
}
