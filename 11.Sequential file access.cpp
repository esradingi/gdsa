/*Department maintains a student information. The file contains roll number, name, division
and address. Allow user to add, delete information of student. Display information of
particular employee. If record of student does not exist an appropriate message is displayed.
If it is, then the system displays the student details. Use sequential file to main the data.*/

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Student
	{
		char Name[10],Addr[20];
		int Roll_No,Div;
		public:
		Student(){ Name[0]=Addr[0]='\0';Div=Roll_No=-1;}
		void get_Data();
		void put_Data();
		int return_Roll(){ return Roll_No;}

	};

void Student::get_Data()
	{
	    cout<<"\nEnter Student Data:";
	    cout<<"\nName: ";cin>>Name;
	    cout<<"Address: ";cin>>Addr;
	    cout<<"Roll Number: ";cin>>Roll_No;
	    cout<<"Div(1/2): ";cin>>Div;

	}
void Student::put_Data()
	{
	     cout<<"\n"<<Div<<"\t"<<Roll_No<<"\t"<<Name<<"\t"<<Addr;
	 }

class Seq_File

{
		char File_Name[15];
		public:
		void Create();
		void Display();
		void Add();
		void Remove(int);
		int Search(int);
		void modify(int);
};

void Seq_File::Create()
	{
		ofstream  File;
		Student S;
		int i,n;
		cout<<"\nEnter File Name\t";
		cin>>File_Name;
		File.open(File_Name,ios::app);

		if(File)
		{ 	cout<<"\nHow many student u have to add? ";
			cin>>n;
			for(i=0;i<n;i++)
			{
			S.get_Data();
			File.write((char*)(&S),sizeof(S));
			}

		  File.close();
		}
		else cout<<"\nFile creation Error";
	}
void Seq_File::Remove(int Roll)
	{
		 ifstream File;
		 ofstream Temp;
		 Student S;
		 int Flag=0;
		 File.open(File_Name);
		 Temp.open("Temp.Txt");
		 if(File && Temp)
		 {
		   File.read((char*)(&S),sizeof(S));
		   while(!File.eof())
			    {
				     if(Roll==S.return_Roll())
					 {   S.put_Data(); Flag=1;}
				      else
					  Temp.write((char*)(&S),sizeof(S));
				      File.read((char*)(&S),sizeof(S));
			    }
		   if(Flag==0) cout<<"Roll No. "<<Roll<<" does not present \n";
		   File.close();
		   Temp.close();
		   remove(File_Name);
		   rename("Temp.Txt",File_Name);
		 }  else cout<<"File opening Error";
	}
void Seq_File::Display()
	{
		ifstream  File;
		Student S;
		File.open(File_Name);
		if(File)
		{ cout<<"\n----Student Database----\nDiv\tRoll No\tName\tAddress";
		  File.read((char*)(&S),sizeof(S));
		  while(!File.eof())
			    {
				      S.put_Data();
				      File.read((char*)(&S),sizeof(S));
			    }
			    cout<<"\n";
		  File.close();
		}else cout<<"\nFile opening Error";

	}
void Seq_File::Add()
	{
		ofstream  File;
		Student S;
		File.open(File_Name,ios::app);
		if(File)
		{
			S.get_Data();
			  File.write((char*)(&S),sizeof(S));
			  File.close();
		}
		else cout<<"File opening Error";
	}
int Seq_File::Search(int Roll)
	{
		 ifstream File;
		 Student S;
		 int Flag=0;
		 File.open(File_Name);
		 if(File)
		 {
		   File.read((char*)(&S),sizeof(S));
		   while(!File.eof())
			    {
				     if(Roll==S.return_Roll())
					  {
						S.put_Data();
						Flag=1;
					   }
				      File.read((char*)(&S),sizeof(S));
			    }
		  File.close();
		} else cout<<"\nFile opening Error";
		return Flag;
	}
int main()
      {
	int Choice;
	char F[15];
	int R;
	Seq_File  sFile;
	do
	{
      cout<<"\n\n-----MAIN MENU-----";
      cout<<"\n1: Create Database\n2: Display Database\n3: Add a record\n4.Delete a Record\n5: Search a record\n7:Exit\nEnter your choice: ";
	  cin>>Choice;
	  switch(Choice)
	    {
			    case 1:
					    sFile.Create();
					    break;
			    case 2:
					    sFile.Display();
					    break;
			    case 3:
					    sFile.Add();
					    break;
			    case 4:
					    cout<<"\nEnter Roll No to delete";
					    cin>>R;
					    sFile.Remove( R);
					    break;
			    case 5:
					    cout<<"\nEnter Roll No to Search";
					    cin>>R;
					    if(!sFile.Search(R))
					      cout<<"\nRecored does not present";
					    break;

			   case 6:          return 0;

			}
		     }  while(Choice<7);
	cout<<"\n";
	return 0;
      }

/*Output
1: Create Database
2: Display Database
3: Add a record
4: Delete a record
5: Search a record
6:Exit
Enter your choice: 1
Enter File Name	prt.txt

How many student u have to add
3

Enter Student Data
Name: shivangi

Address: pune

Roll Number: 11

Div(1/2): 1

Enter Student Data
Name: rishita

Address: nagpur

Roll Number: 12

Div(1/2): 1

Enter Student Data
Name: snehal

Address: nashik

Roll Number: 13

Div(1/2): 1

1: Create Database
2: Display Database
3: Add a record
4: Delete a record
5: Search a record
6:Exit
Enter your choice: 2

 Student Database
Div	Roll No	Name	Address
1	11	shivangi pune
1	12	rishita	nagpur
1	13	snehal	nashik
1: Create Database
2: Display Database
3: Add a record
4: Delete a record
5: Search a record
6:Exit
Enter your choice: 3

Enter Student Data
Name: ram

Address: surat

Roll Number: 14

Div(1/2): 1

1: Create Database
2: Display Database
3: Add a record
4: Delete a record
5: Search a record
6:Exit
Enter your choice: 2

 Student Database
Div	Roll No	Name	Address
1	11	shivangi pune
1	12	rishita	nagpur
1	13	snehal	nashik
1	14	ram	surat
1: Create Database
2: Display Database
3: Add a record
4: Delete a record
5: Search a record
6:Exit
Enter your choice: 4

Enter Roll No to delete13

1	13	snehal	nashik
1: Create Database
2: Display Database
3: Add a record
4: Delete a record
5: Search a record
6:Exit
Enter your choice: 5

Enter Roll No to Search12

1	12	rishita	nagpur
1: Create Database
2: Display Database
3: Add a record
4: Delete a record
5: Search a record
6:Exit
Enter your choice: 6
*/
