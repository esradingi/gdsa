#include<iostream>
using namespace std;
 class Record
 {
   private:
     string name;
     string phoneNo;
   public:
Record() 
{
    name=" ";
    phoneNo=" ";

}

Record(string name,string phoneNo){
    this->name=name;
    this->phoneNo=phoneNo;
}
friend class TelephoneBook;
 };

class TelephoneBook
{
    private:
    Record hashTable[100];
    
    int hashingFunction(string &name){
        int count;
        int len=name.length();

        for(int i=0;i<len;i++){
            name[i]=char(tolower(name[i]));
            count += name[i]-'a';
        }
    return (count%100);
    }
    public: 

    TelephoneBook()
    {
    for(int i=0;i<100;i++){
        hashTable[i].name=" ";
        hashTable[i].phoneNo=" ";
    }
    }
    void InsertwithoutReplacement(string &name,string &phoneNo){
    int key=hashingFunction(name);
    while(key<100)
    {
    if(hashTable[key].name==" ")
    {
    hashTable[key].name=name;
    hashTable[key].phoneNo=phoneNo;
    cout<<"Record insert successfuly"<<endl;
    return;
    }
    if(hashTable[key].name==name){
        cout<<"Record already inserted";
        char ch='n';
        cout<<"If you wanna update phone number press y";
        cin>>ch;
        if(ch='y'){
            hashTable[key].phoneNo=phoneNo;
            return;
        }
    }
    key++;
    if(key=100){
    key=key%100;
    }
    }
    
    }

    void InsertWithReplacement(string &name, string &phoneNo)
    {
        int key=hashingFunction(name);
        if(hashTable[key].name==" "){
         hashTable[key].name=name;
         hashTable[key].phoneNo=phoneNo;
         cout<<"Record already inserted";
         return;
        }
        else{

            int newKey=hashingFunction(hashTable[key].name);
                if(newKey==key){
                    InsertwithoutReplacement(name,phoneNo);
                }
                else{
                    string tempName=hashTable[key].name;
                    string tempphoneNo=hashTable[key].phoneNo;
                    hashTable[key].name=name;
                    hashTable[key].phoneNo=phoneNo;

                    InsertwithoutReplacement(tempName,tempphoneNo);

                }
            }
        }
    
void searchName(string &name){
    int key=hashingFunction(name);
    int comparisons_count=0;
    if(hashTable[key].name==" "){
        cout<<"Record of name : "<<name<<"not found";

    }
    while(key<100 && comparisons_count!=100){
        comparisons_count++;
    if(hashTable[key].name==name){
        cout<<"Record found !"<<endl;
        cout<<"Name : "<<name<<"\n Phoneno : "<<hashTable[key].phoneNo;

    }
    
     key++;
    if(key=100){
    key=key%100;
    }
    cout<<"Record not found"<<endl;
    }
}
    };
    

 
int main()
{
TelephoneBook obj;
int option;
string name;
string phoneNo;
cout<<"Menu"<<endl;
cout<<"1.Insert names \n 2. Search \n 3.Exit"<<endl;
cout<<"choose : ";
cin>>option;
if(option=1){
int ch;
do{
cout<<"1.Provide name and number \n 2.Insert with replacement \n 3.Insert without replacement"<<endl;
cout<<"Choose an option : ";
cin>>ch;
switch(ch){
    case 1:
    cout<<"Name : "<<endl;;
    cin>>name;
    cout<<"Phoneno : "<<endl;
    cin>>phoneNo;
    break;
    case 2:
    obj.InsertWithReplacement(name,phoneNo);
    break;

    case 3: 
    obj.InsertwithoutReplacement(name,phoneNo);
    break;
}
}while(option>=1&&option<=3);
}
if(option==2){
    cout<<"Name to be searched : "<<endl;;
    cin>>name;
obj.searchName(name);
}
if(option==3){
    return 0;
}

}



