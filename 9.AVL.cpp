#include<iostream>
using namespace std;
#define FALSE 0
#define TRUE 1

typedef struct Node
{
    string keyword;
    string meaning;
    int BF;
    struct Node *left;
    struct Node *right;

}node;

class AVL
{
    node *root;
public:
    AVL()
    {
        root=NULL;
    }
    node *insert(string keyword,string meaning,int *current)
    {
        root=create(root,keyword,meaning,current);
        return(root);
    }
    node *create(node *root,string keyword, string meaning,int *current);
    node *remove(node *root,string keyword, int *current);
    node *find_succ(node *temp, node *root, int *current);
    node *right_rotation(node *root,int *current);
    node *left_rotation(node *root, int *current);
    void display(node *root);
};

node *AVL::create(node *root,string keyword, string meaning,int *current)
{
    node *temp1, *temp2;
    if(root==NULL)
    {
        root=new node;
        root->keyword=keyword;
        root->meaning=meaning;
        root->left=NULL;
        root->right=NULL;
        root->BF = 0;
        *current=TRUE;
        return(root);
    }
    if(keyword<(root->keyword))
    {
        root->left=create(root->left,keyword,meaning,current);
        if(*current)
        {
            switch(root->BF)
            {
            case 1:
                temp1=root->left;
                if(temp1->BF==1)
                {
                    cout<<"\n\tSingle Rotation: LL insertion";
                    root->left=temp1->right;
                    temp1->right=root;
                    root->BF=0;
                    root=temp1;

                }
                else
                {
                    cout<<"\n\tDouble Rotation: LR insertion";
                    temp2=temp1->right;
                    temp1->right=temp2->left;
                    temp2->left=temp1;
                    root->left=temp2->right;
                    temp2->right=root;
                    if(temp2->BF==1)
                    {
                       root->BF=-1;
                    }
                    else
                        root->BF=0;
                    if(temp2->BF==-1)
                    {
                        temp1->BF=1;
                    }
                    else
                        temp1->BF=0;
                    root=temp2;
                }
                root->BF=0;
                *current=FALSE;
                break;
            case 0:
                root->BF=1;
                break;
            case -1:
                root->BF=0;
                *current=FALSE;
            }
        }
    }
    if(keyword>root->keyword)
    {
        root->right=create(root->right,keyword,meaning,current);
        if(*current!=NULL)
        {
            switch(root->BF)
            {
            case 1:
                root->BF=0;
                *current=FALSE;
                break;
            case 0:
                root->BF=-1;
                break;
            case -1:
                temp1 = root->right;
                if(temp1->BF==-1)
                {
                    cout<<"\n\tSingle Rotation: RR insertion";
                    root->right=temp1->left;
                    temp1->left=root;
                    root->BF=0;
                    root=temp1;
                }
                else
                {
                    cout<<"\n\tDouble Rotation: RL insertion";
                    temp2=temp1->left;
                    temp1->left=temp2->right;
                    temp2->right=temp1;
                    root->right=temp2->left;
                    temp2->left=root;
                    if(temp2->BF==-1)
                    {
                        root->BF=1;
                    }
                    else
                    {
                        root->BF=0;
                    }
                    if(temp2->BF==1)
                    {
                        temp1->BF=-1;
                    }
                    else
                        temp1->BF=0;
                    root=temp2;
                }
                root->BF=0;
                *current=FALSE;
            }
        }
    }
    return(root);
}

void AVL::display(node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        cout<<"\n\t["<<root->keyword<<"-"<<root->meaning<<"]";
        display(root->right);
    }
}

node *AVL::remove(node *root,string keyword, int *current)
{
    node *temp;
    if(root->keyword=="\n")
    {
        cout<<root->keyword;
        cout<<root->meaning;
    }
    if(root==NULL)
    {
        cout<<"\n\tNo such data found.";
        return(root);
    }
    else
    {
        if(keyword<root->keyword)
        {
            root->left=remove(root->left,keyword,current);
            if(*current)
                root=right_rotation(root,current);
        }
        else
        {
            if(keyword>root->keyword)
            {
                root->right=remove(root->right,keyword,current);
                if(*current)
                    root=left_rotation(root,current);
            }
            else
            {
                temp=root;
                if(temp->right==NULL)
                {
                    root=temp->left;
                    *current=TRUE;
                    delete(temp);
                }
                else
                {
                    if(temp->left==NULL)
                    {
                        root=temp->right;
                        *current=TRUE;
                        delete(temp);
                    }
                    else
                    {
                        temp->right=find_succ(temp->right,temp,current);
                        if(*current)
                        {
                            root=left_rotation(root,current);
                        }
                    }
                }
            }
        }
    }
    return(root);
}

node *AVL::find_succ(node *succ,node *temp,int *current)
{
    node *temp1=succ;
    if(succ!=NULL)
    {
        succ->left=find_succ(succ->left,temp,current);
        if(*current)
            succ=right_rotation(succ,current);
    }
    else
    {
        temp1=succ;
        temp->keyword=succ->keyword;
        temp->meaning=succ->meaning;
        succ=succ->right;
        delete temp1;
        *current=TRUE;
    }
    return(succ);
}

node *AVL::right_rotation(node *root,int *current)
{
    node *temp1, *temp2;
    switch(root->BF)
    {
    case 1:
        root->BF=0;
        break;
    case 0:
        root->BF=-1;
        *current=FALSE;
        break;
    case -1:
        temp1=root->right;
        if(temp1->BF <=0)
        {
            cout<<"\n\tSingle rotation: RR rotation ";
            root->right=temp1->left;
            temp1->left=root;

            if(temp1->BF==0)
            {
                root->BF=-1;
                temp1->BF=1;
                *current=FALSE;
            }
            else
            {
                root->BF=temp1->BF=0;
            }
            root=temp1;
        }
        else
        {
            cout<<"\n\tDouble Rotation: RL rotation ";
            temp2=temp1->left;
            temp1->left=temp2->right;
            temp2->right=temp1;
            root->right=temp2->left;
            temp2->left=root;

            if(temp2->BF==-1)
            {
                root->BF=1;
            }
            else
            {
                root->BF=0;
            }
            if(temp2->BF==1)
            {
                temp1->BF=-1;
            }
            else
                temp1->BF=0;
            root=temp2;
            temp2->BF=0;
        }
    }
    return(root);
}

node *AVL::left_rotation(node *root,int *current)
{
    node *temp1, *temp2;
    switch(root->BF)
    {
    case -1:
        root->BF=0;
        break;
    case 0:
        root->BF=1;
        *current=FALSE;
        break;
    case 1:
        temp1=root->left;
        if(temp1->BF >=0)
        {
            cout<<"\n\tSingle rotation: LL rotation ";
            root->left=temp1->right;
            temp1->right=root;

            if(temp1->BF==0)
            {
                root->BF=1;
                temp1->BF=-1;
                *current=FALSE;
            }
            else
            {
                root->BF=temp1->BF=0;
            }
            root=temp1;
        }
        else
        {
            cout<<"\n\tDouble Rotation: LR rotation ";
            temp2=temp1->right;
            temp1->right=temp2->left;
            temp2->left=temp1;
            root->left=temp2->right;
            temp2->right=root;

            if(temp2->BF==1)
            {
                root->BF=-1;
            }
            else
            {
                root->BF=0;
            }
            if(temp2->BF==-1)
            {
                temp1->BF=1;
            }
            else
                temp1->BF=0;
            root=temp2;
            temp2->BF=0;
        }
    }
    return(root);
}

int main()
{
    AVL obj;
    node *root=NULL;
    int current;
    cout<<"\n\tInsertion: ";
    root=obj.insert("happy","cheerful",&current);
    obj.display(root);
    cout<<"\n\n\tInsertion: ";
    root=obj.insert("fun","playfulness",&current);
    obj.display(root);
    cout<<"\n\n\tInsertion: ";
    root=obj.insert("bad","awful",&current);
    obj.display(root);
    cout<<"\n\n\tInsertion: ";
    root=obj.insert("knowledge","ability",&current);
    obj.display(root);
    cout<<"\n\n\tInsertion: ";
    root=obj.insert("proud","self-respectful",&current);
    obj.display(root);
    cout<<"\n\n\tInsertion: ";
    root=obj.insert("administer","manage",&current);
    obj.display(root);
    cout<<"\n\n\tInsertion: ";
    root=obj.insert("change","modify",&current);
    obj.display(root);
    cout<<"\n\n\tInsertion: ";
    root=obj.insert("domain","area",&current);
    obj.display(root);
    cout<<"\n--------------------------------------";
    cout<<"\n\tFinal AVL tree is:";
    cout<<"\n--------------------------------------";
    obj.display(root);
    cout<<"\n\n\t-----Deletion(proud)-----";
    root=obj.remove(root,"proud",&current);
    obj.display(root);
    cout<<"\n--------------------------------------";
    cout<<"\n\tFinal AVL tree after deletion is : ";
    cout<<"\n--------------------------------------";
    obj.display(root);

    return 0;
}
