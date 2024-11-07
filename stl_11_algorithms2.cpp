#include<algorithm>
#include<string>
#include<vector>
#include<iostream>

int main()
{
    // works even for vector
    std::string s1 = "Hello Aniket How are you?";
    std::string s2 = "Hello Aniket how are you?";
    // ************************************** finding mismatch **************************************
    auto result = std::mismatch(s1.begin(), s1.end(), s2.begin());
    if (result.first != s1.end() && result.second != s2.end()) {
        std::cout << "The first mismatch is at index " << std::distance(s1.begin(), result.first) << ":\n";
        std::cout << "s1: " << *result.first << ", s2: " << *result.second << std::endl;
    }
    s1[13] = s2[13];
    // *********************************** comparing for equality ***********************************
    if(std::equal(s1.begin(), s1.end(), s2.begin()))
    std::cout<<"both are now equal\n";
    // ************************************** substring search **************************************
    std::cout<<"############### subsequence search ################\n";
    std::string s3 = "Anik";
    auto it = std::search(s1.begin(), s1.end(), s3.begin(), s3.end());
    if (it != s1.end()){
        std::cout<<"found 'Anik' at index "<<std::distance(s1.begin(), it)<<"\n";
    }
    // ********************************* consecutive element search *********************************
    std::vector<int> v = {1, 1, 1, 1, 2, 3, 3, 3, 3, 1, 1, 1, 4};
    auto it1 = std::search_n(v.begin(), v.end(), 3, 1);
    if(it1 != v.end())
    std::cout<<"found 3 consecutive 1 at index "<<std::distance(v.begin(), it1)<<"\n";
    // ******************************************** move ********************************************
    std::vector<std::string> source = {"it", "transfer", "ownership", "instead", "of", "copy", "preferable", "for", "memory", "optimization"};
    std::vector<std::string> destination(source.size());
    std::move(source.begin(), source.end(), destination.begin());

    // destination
    for (const auto& str : destination) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    // source (now in an unspecified state)
    for (const auto& str : source) {
        std::cout << str << " ";
    }
    return 0;
}