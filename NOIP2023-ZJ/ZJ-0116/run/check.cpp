#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream out("run.out");
    ifstream ans("run.ans");
    vector<long long> v1,v2; long long x;
    while(out>>x)v1.push_back(x);
    while(ans>>x)v2.push_back(x);
    assert(v1.size()==v2.size());
    for(int i=0;i<v1.size();i++)
        assert(v1[i]==v2[i]);
    printf("AC!\n");
    return 0;
}