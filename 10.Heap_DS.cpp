#include<iostream>
#include <unistd.h>
#include<conio.h>
using namespace std;
#define MAX 10

class Heap
{
private:
    int marks[MAX];
    int n;

public:
    Heap();
    void insert(int num);
    void makeheap();
    void heapsort();
    void display();
    void displayMinMax();

};

Heap::Heap()
{
    n=0;
    for(int i=0;i<MAX;i++)
    {
        marks[i]=0;
    }
}

void Heap::insert(int num)
{
    if(n<MAX)
    {
        marks[n]=num;
        n++;
    }
    else
        cout<<"\nArray is Full!";
}

void Heap::makeheap()
{
    for(int i=1;i<n;i++)
    {
        int val=marks[i];
        int j=i;
        int f=(j-1)/2;
        while(j>0&& marks[f]<val)  //creating max heap
        {
            marks[j]=marks[f];
            j=f;
            f=(j-1)/2;
        }
        marks[j]=val;
    }
}

void Heap::heapsort()
{
    for(int i=n-1;i>0;i--)
    {
        int temp=marks[i];
        marks[i]=marks[0];
        int k=0;
        int j;
        if(i==0)
        {
            j=-1;
        }
        else
            j=1;
        if(i>2&&marks[2]>marks[1])
        {
            j=2;
        }
        while(j>=0 && temp<marks[j])
        {
            marks[k]=marks[j];
            k=j;
            j=2*k+1;
            if(j+1<=i-1&&marks[j]<marks[j+1])
            {
                j++;
            }
            if(j>i-1)
            {
                j=-1;
            }
        }
        marks[k]=temp;
    }
}

void Heap::display()
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<marks[i];
    }
    cout<<"\n";
}

void Heap::displayMinMax()
{
    cout<<"\nMaximum marks scored is: "<<marks[n-1];
    cout<<"\nMinimum marks scored is: "<<marks[0];
}

int main()
{
    Heap obj;
    int ch;
    cout<<"\n------------------------------------------";
    cout<<"\n----------Program for Heap----------------";
    obj.insert(55);
    obj.insert(48);
    obj.insert(89);
    obj.insert(91);
    obj.insert(75);
    obj.insert(63);
    obj.insert(45);
    obj.insert(78);
    cout<<"\nFollowing Marks are entered: ";
    obj.display();
    usleep(2000);
    obj.makeheap();
    cout<<"\nHeapified...";
    obj.heapsort();
    usleep(2000);
    obj.displayMinMax();
    return 0;
}
