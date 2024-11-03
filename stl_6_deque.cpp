#include<bits/stdc++.h>
using namespace std;

void PrintDeque(deque<int> dq)
{
    for(auto i: dq)
    cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    deque<int> dq;

    dq.push_back(1); // O(1)
    dq.push_back(2);
    dq.emplace_back(3);
    PrintDeque(dq);

    // since it uses a doubly linkedlist, pushing and popping in front is handy
    dq.push_front(4); // O(1)
    dq.push_front(5);
    dq.emplace_front(6);
    PrintDeque(dq);

    cout<<dq[0]<<" \n"; // random access is available, it is a continuous memory

    cout<<dq.front()<<" "<<dq.back()<<"\n";

    deque<int>::iterator it1 = dq.begin(), it2 = dq.end(); // auto is a smart keyword who automatically understand the datatype
    cout<<*it1<<" "<<it1[1]<<" "<<*(++it1)<<" "<<*(++it1)<<" "<<*(--it2)<<"\n";

    dq.insert(dq.begin() + 1, 8);
    PrintDeque(dq);

    deque<int> dq1;
    dq1.emplace_back(10);
    dq1.emplace_back(30);
    dq1.emplace_front(20);
    dq.insert(dq.begin() + 1, dq1.begin(), dq1.end());
    PrintDeque(dq);
    cout<<dq.size()<<"\n";

    auto it = find(dq.begin(), dq.end(), 3);
    if(it != dq.end()){
        dq.erase(it);
        PrintDeque(dq);
    }

    dq.erase(dq.begin() + 1, dq.begin() + 4);
    PrintDeque(dq);

    dq.swap(dq1);
    PrintDeque(dq);
    cout<<dq.empty()<<"\n";
    dq.clear();
    cout<<dq.empty()<<"\n";

    return 0;
}