#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream out("dict.out");
    ifstream ans("dict.ans");
    string s1,s2;
    out>>s1; ans>>s2;
    assert(s1==s2);
    printf("AC!\n");
    return 0;
}