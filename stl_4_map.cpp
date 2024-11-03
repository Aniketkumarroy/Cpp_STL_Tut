#include<map> // map
#include<unordered_map> // unordered_map
#include<algorithm>
#include<string>
#include<iostream>

void PrintMap(std::map<int, std::string> m)
{
    for (auto it: m)
    std::cout<<it.first<<" "<<it.second<<"\n";
}

int main()
{
    std::map<int, std::string> m1;
    /*
        std::map<key_type, value_type>, key should be unique in map, each key will correspond to a value.
        in map the key value pair is stored in a sorted order, ofcourse you can provide a custom sort function

        struct CustomCompare {
            bool operator()(const int& lhs, const int& rhs) const {
                // Custom sorting logic: Sort in descending order
                return lhs > rhs;
            }
        };
        std::map<int, std::string, CustomCompare> myMap;
    */

    /*

        // keys will not be unique
        std::multimap<int, std::string> m2;
        // for unsorted keys
        std::unordered_map<int, std::string> m3;
        // only lower_bound() and upper_bound() doesn't work for it. all operations will be of O(1)
    */
    m1[1] = "Hello";    // {1, "Hello"}
    m1.emplace(0, "hi");// {0, "hi"}
    PrintMap(m1);
    std::cout<<m1[0]<<" "<<m1[1]<<"\n";
    m1.emplace(2, "Hey");// {0, "hi"}
    std::cout<<m1[2]<<"\n";

    auto it1 = m1.find(1); // O(log(n))
    if (it1 != m1.end())
    {
        std::cout<<"m[1] exists and key value is  "<<(*it1).first<<"\n";
        std::cout<<"m[1] exists and its value is "<<it1->second<<"\n";
    }
    auto it2 = m1.find(3);
    if (it2 != m1.end())
    std::cout<<"m[1] exists and its value is "<<m1[3]<<"\n";
    auto it3 = std::find_if(m1.begin(), m1.end(), [](const std::pair<int, std::string>& pair) {
    return pair.first == 0;
    });
    if (it3 != m1.end())
    {
        std::cout<<"m[0] exists and key value is  "<<it3->first<<"\n";
        std::cout<<"m[0] exists and its value is "<<(*it3).second<<"\n";
    }

    m1[3] = "three";
    m1[4] = "four";
    m1[6] = "six";
    m1[7] = "seven";

    std::map<int, std::string>::iterator it4 = m1.lower_bound(5);
    if(it4 != m1.end())
    std::cout<<"lower bound on 5 is "<<it4->first<<"\n";
    auto it5 = m1.upper_bound(5);
    if(it5 != m1.end())
    std::cout<<"upper bound on 5 is "<<it5->first<<"\n";
    
    auto it6 = m1.lower_bound(3);
    if(it6 != m1.end())
    std::cout<<"lower bound on 3 is "<<it6->first<<"\n";
    std::map<int, std::string>::iterator it7 = m1.upper_bound(3);
    if(it7 != m1.end())
    std::cout<<"upper bound on 3 is "<<it7->first<<"\n";
    return 0;
}