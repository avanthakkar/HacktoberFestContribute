#include<iostream>
using namespace std;
int front = -1, rear= -1;
int queue[100],stack[100],top= -1,size;

void enqueue(int x)
{
    if(front == -1)
        front =0;
    rear ++ ;
    queue[rear]= x;

}
int dequeue(){
    if(front >rear || front == -1)
        return INT_MIN;
    return queue[front++];
}
void reverseK(int k)
{
    while(front<=rear && k--){
        int x=dequeue();
        stack[++top]= x;
    }
    while(top!= -1){
        int x = stack[top--];
        enqueue(x);
    }
    for (int i = front; i < rear-front-k; i++) {
        int x= dequeue();
        enqueue(x);
    }

    return;
}

void display()
{
    if(front > rear || front ==-1){
        cout<< "cannot dispay";
        return;}
    int i = front;
    while(i <=rear){
        cout<< queue[i++]<<" ";
    }
}

int main ()
{
    int q;
    cout<<"Enter the size of Queue: ";
    cin>> size;
    cout<< "\nEnter the elements of Queue: ";

    for (int i=0;i<size;i++)
    {
        cin>>q;
        enqueue(q);
    }
    int k ;
    cout<<"\nEnter value of k: ";
    cin>> k;
    cout<< "\nFirst "<< k << " elements reversed: ";
    reverseK(k);
    display();
    cout<<endl;

    return 0;

}
