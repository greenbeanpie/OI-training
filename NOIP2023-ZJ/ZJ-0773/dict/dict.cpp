#include <bits/stdc++.h>
using namespace std;
ifstream fin("dict.in");
ofstream fout("dict.out");
#ifdef DEBUG
#define fin cin
#define fout cout
#endif // DEBUG
using ll = long long;
using ull = unsigned long long;
using sh = short;
using ush = unsigned short;

int n,m;
bool operator<(string &a,string &b) {
    for(int i=0; i<m; ++i) {
        if(a[i]==b[i]) continue;
        return a[i]<b[i];
    }
    return false;
}
inline char min(pair<char,char> x) {
    return x.first<x.second?x.first:x.second;
}
inline char max(pair<char,char> x) {
    return x.first>x.second?x.first:x.second;
}

int main() {
    fin>>n>>m;
    if(n==1) {
        fout<<'1';
        return 0;
    }
    if(m==1) {
        vector<char> vc(n);
        pair<int,char> cmin= {0,'z'};
        for(auto&&i:vc) fin>>i;
        for(int i=0; i<n; ++i)
            if(vc[i]<cmin.second) cmin= {i,vc[i]};
        int pmin=cmin.first;
        for(int i=0; i<n; ++i)
            fout.put((i==pmin)+'0');
        fout<<endl;
        return 0;
    }
    if(m==2) {
        vector<pair<char,char>> vc(n);
        for(auto&&i:vc) fin>>i.first>>i.second;
        char mmc='z';
        for(auto i:vc)
            if(max(i)<mmc) mmc=max(i);
        for(int i=0; i<n; ++i)
            fout.put((min(vc[i])<=mmc)+'0');
        fout<<endl;
    }
    return 0;
}
