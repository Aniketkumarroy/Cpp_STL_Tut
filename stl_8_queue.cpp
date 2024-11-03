#include<bits/stdc++.h>
using namespace std;
void PrintQueue(queue<int> q1)
{
    queue<int> q2=q1;
    while(!q2.empty())
    {
        cout<<q2.front()<<" ";
        q2.pop();
    }
    cout<<"\n";
}
int main()
{
    queue<int> q;
    for(int i=1;i<=5;i++)
    q.push(i);
    
    cout<<"The elements of the queue are:"<<endl;
    PrintQueue(q);
    
    cout<<"The size of the queue: "<<q.size()<<endl;
    cout<<"The front element of the queue: "<<q.front()<<endl;
    cout<<"The last element of the queue: "<<q.back()<<endl;
    cout<<"Pop the front element: "<<endl;
    q.pop();
    PrintQueue(q);

    queue<int> q1;
    for(int i=1;i<=5;i++)
    q1.push(i*10);

    PrintQueue(q);
    q.swap(q1);
    PrintQueue(q);

    cout<<q.empty()<<"\n";
    return 0;
}