#include<bits/stdc++.h>
using namespace std;

void PrintList(list<int> l)
{
    for(auto i: l)
    cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    list<int> l;

    l.push_back(1); // O(1)
    l.push_back(2);
    l.emplace_back(3);
    PrintList(l);

    // since it uses a doubly linkedlist, pushing and popping in front is handy
    l.push_front(4); // O(1)
    l.push_front(5);
    l.emplace_front(6);
    PrintList(l);

    cout<<l.front()<<" "<<l.back()<<"\n";

    list<int>::iterator it1 = l.begin(), it2 = l.end(); // auto is a smart keyword who automatically understand the datatype
    cout<<*it1<<" "<<*(++it1)<<" "<<*(++it1)<<" "<<*(--it2)<<"\n"; // remember since list is not a continuous memory, so it+1/it-1 is hazardious, use ++/-- instead

    l.insert(++l.begin(), 8);
    PrintList(l);

    list<int> l1;
    l1.emplace_back(10);
    l1.emplace_back(30);
    l1.emplace_front(20);
    l.insert(++++l.begin(), l1.begin(), l1.end());
    PrintList(l);
    cout<<l.size()<<"\n";

    auto it = find(l.begin(), l.end(), 3);
    if(it != l.end()){
        l.erase(it);
        PrintList(l);
    }

    l.erase(++++l.begin(), ++++++++++l.begin());
    PrintList(l);

    l.swap(l1);
    PrintList(l);
    cout<<l.empty()<<"\n";
    l.clear();
    cout<<l.empty()<<"\n";

    return 0;
}