#define PROBLEM dict

#ifdef DEBUG_zPbYWEQlRAWJ3OvuMksw50wYDAJC1812TmBHJtbb6mMCAYXCXJ1B3EZrwVgIcUA0
#include <iostream>
#else
#define _STR(x) #x
#define _FNAME(x, ext) _STR(x) "." #ext
#include <fstream>
namespace std {
    ifstream cin(_FNAME(PROBLEM, in));
    ofstream cout(_FNAME(PROBLEM, out));
}
#undef _FNAME
#undef _STR
#endif

#include <string>
#include <vector>
#include <algorithm>

namespace ns0 {
    int main() {
        int n, m;
        std::cin >> n >> m;
        std::string word;
        std::vector<std::string> words;
        std::string minimum;
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            std::cin >> word;
            words.push_back(word);
            std::sort(word.begin(), word.end(), std::greater<char>());
            if (minIndex == -1 || minimum > word) {
                minimum = word;
                minIndex = i;
            }
        }
        for (int i = 0; i < n; i++) {
            word = words[i];
            std::sort(word.begin(), word.end(), std::less<char>());
            if (i == minIndex || minimum >= word) {
                std::cout << '1';
            }
            else {
                std::cout << '0';
            }
        }
        std::cout << std::endl;
        return 0;
    }
} // ns0

int main() {
    return ns0::main();
}
