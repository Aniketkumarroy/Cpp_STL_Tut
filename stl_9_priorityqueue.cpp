#include<bits/stdc++.h>
using namespace std;
void PrintPriorityqueue(priority_queue<int> pq)
{
    // priority_queue<int> pq2=pq;
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
}
int main()
{
    priority_queue<int> pq; // by default it makes a max heap data structure

    /*
    
        // for using a min heap datastructure
        priority_queue<int, vector<int>, greater<int>> pq;
    
    */

    pq.push(5); // O(log(n))
    pq.push(1);
    pq.push(4);
    pq.push(3);
    pq.push(2);
    
    cout<<"The elements of the priority queue are:"<<endl;
    PrintPriorityqueue(pq);
    
    cout<<"The size of the priority queue: "<<pq.size()<<endl;
    cout<<"The top element of the priority queue: "<<pq.top()<<endl; // O(1)
    cout<<"Pop the top element: "<<endl;
    pq.pop(); // O(log(n))
    PrintPriorityqueue(pq);

    priority_queue<int> pq1;
    pq1.push(10);
    pq1.push(50);
    pq1.push(30);
    pq1.push(40);
    pq1.push(20);

    PrintPriorityqueue(pq);
    pq.swap(pq1);
    PrintPriorityqueue(pq);

    cout<<pq.empty()<<"\n";
    return 0;
}