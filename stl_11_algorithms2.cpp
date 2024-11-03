#include<algorithm>
#include<string>
#include<vector>
#include<iostream>

int main()
{
    // works even for vector
    std::string s1 = "Hello Aniket How are you?";
    std::string s2 = "Hello Aniket how are you?";

    auto result = std::mismatch(s1.begin(), s1.end(), s2.begin());
    if (result.first != s1.end() && result.second != s2.end()) {
        std::cout << "The first mismatch is at index " << std::distance(s1.begin(), result.first) << ":\n";
        std::cout << "s1: " << *result.first << ", s2: " << *result.second << std::endl;
    }
    s1[13] = s2[13];
    if(std::equal(s1.begin(), s1.end(), s2.begin()))
    std::cout<<"both are now equal\n";

    std::cout<<"############### subsequence search ################\n";
    std::string s3 = "Anik";
    auto it = std::search(s1.begin(), s1.end(), s3.begin(), s3.end());
    if (it != s1.end()){
        std::cout<<"found 'Anik' at index "<<std::distance(s1.begin(), it)<<"\n";
    }

    std::vector<int> v = {1, 1, 1, 1, 2, 3, 3, 3, 3, 1, 1, 1, 4};
    auto it1 = std::search_n(v.begin(), v.end(), 3, 1);
    if(it1 != v.end())
    std::cout<<"found 3 consecutive 1 at index "<<std::distance(v.begin(), it1)<<"\n";
    return 0;
}