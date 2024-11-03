#include<bits/stdc++.h>
using namespace std;


void PrintStack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}
int main()
{
    stack<int> s;
    for(int i=1;i<=5;i++)
    s.push(i);
    
    cout<<"The elements of the stack are:"<<endl;
    PrintStack(s);
    
    cout<<"The size of the stack: "<<s.size()<<endl;
    cout<<"The top element of the queue: "<<s.top()<<endl;
    cout<<"Pop the top element: "<<endl;
    s.pop();
    PrintStack(s);

    stack<int> s1;
    for(int i=1;i<=5;i++)
    s1.push(i*10);

    PrintStack(s);
    s.swap(s1);
    PrintStack(s);

    cout<<s.empty()<<"\n";
    return 0;
}