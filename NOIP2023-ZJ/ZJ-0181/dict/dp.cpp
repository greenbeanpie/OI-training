#include <bits/stdc++.h>
using namespace std;
int main() {
    system("g++ brute.cpp -o brute -lm -O2 -std=c++14");
    system("g++ data.cpp -o data -lm -O2 -std=c++14");
    system("g++ dict.cpp -o dict -lm -O2 -std=c++14");
    int count = 0;
    while (1) {
        // printf("hexu\n");
        system("data > .in");
        // printf("hexu\n");
        system("brute < .in > brute.out");
        // printf("hexu\n");
        system("dict < .in > dict.out");
        if (system("fc brute.out dict.out")) {
            printf("hexuhexu!!!\n");
            break;
        }
        printf("#%d Test OK Accepted\n", ++count);
    }
    system("pause");
    return 0;
}