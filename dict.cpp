#include<iostream>
#include<cstring>
#define max 10
using namespace std;

class hashtable
{
    public:
    
    string h[max][2];
    char word[10];
    char meaning[10];
    int count=0;

    hashtable()
    {
        for(int i=0;i<max;i++){
            for(int j=0;j<2;j++){
                h[i][j]="$";
            }
        }
    }
    void insert();
    int hashfunc(char[]);
    void linearprob(string word,int);
    void delet();
    int search(char[]);
    void update();
    void display();
};
void hashtable::insert(){
    char key[10];
    int ch;
    int x;
    while(1)
    {
    cout<<"Enter the word : "<<endl;
    cin>>key;
    cout<<"Enter meaning : ";
    cin>>meaning;

    ch=hashfunc(word);
    linearprob(word,ch);
    cout<<"Do you want to insert more? "<<endl;
    cin>>x;
    if(x=='n'){
        break;
    }
    }
}
int hashtable::hashfunc(char word[])
{
    //char word[max];
    int sum;
    int ch;
    for(int i=0;i<strlen(word);i++){
        sum=sum+int(word[i]);
    }
    ch=sum%100;
    return ch;
}
void hashtable::linearprob(string word,int ch)
{
    if(count==max)
    {
        cout<<"Hashtable is full!"<<endl;

    }
    while (h[ch][0]!= "$" && count!=0){
         ch++;
         ch=ch%100;
        
    }
    h[ch][0]=word;
    h[ch][1]=meaning;
     count++;
}

int hashtable::search(char key[]){
    int ch;
    ch=hashfunc(key);
    while(h[ch][0]!=key && count!=0)
    {
        ch++;
        ch=ch%100;
    }
    if(h[ch][0]==key){
    cout<<"Element is found at index "<<ch<<endl;
    }
    return ch;
}

void hashtable :: delet()
{
    int ch;
    char key[10];
    cout<<"Enter word to be deleted : "<<endl;
    cin>>key;
    ch=search(key);
    h[ch][0]="$";
    h[ch][1]="$";
    cout<<"Word deleted from index : "<<ch<<endl;
}
void hashtable::update()
{ 
    int ch;
    char key[10],meaning[10];
    cout<<"Enter word to be modified : "<<endl;
    cin>>key;
    cout<<"Enter modified meaning : "<<endl;
    cin>>meaning;
    ch=search(key);
    h[ch][0]=key;
    h[ch][1]=meaning;
    cout<<"Meaning is updated from index :"<<ch<<endl;

}
void hashtable:: display()
{
    cout<<"Your dictionary is : "<<endl;
    for(int i=0;i<max;i++){
        cout<<"\t\t";
    for(int j=0;j<2;j++){
        cout<<h[i][j]<<"\n";
    }
    }
    
}

int main(){
    hashtable t;
    int op;
cout<<"1.Insert \n2.Display \n3.Delete\n4.Search\n5.Update\6.Exit"<<endl;
cin>>op;
do{
    switch(op){
        case 1:
    t.insert();
    break;
    case 2:
    t.display();
    break;
    case 3:
    t.delet();
    break;
    case 4:
    char key[10];
    cout<<"Enter word to be searched : "<<endl;
    cin>>key;
    t.search(key);
    break;
    case 5:
    t.update();
    break;
    case 6:
    exit(0);

    }
}while(op<7);
return 0;
}