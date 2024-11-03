#include<algorithm>
#include<string>
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
    return 0;
}