#include<bits/stdc++.h>
using namespace std;
#define clo 1000.*clock()/CLOCKS_PER_SEC
#ifndef xxzx
#define endl '\n'
#endif
using ll=long long;
using PII=pair<int,int>;
const int N=3e3+10;
bool mem1;
int n,m,cnt[N][40],c[3][40];
string s[N];
bool check(int i,int j) {
    int p1=0,p2=25,tot=0;
    for(int k=0;k<26;k++) 
        c[1][k]=cnt[i][k], c[2][k]=cnt[j][k];
    while(tot<m) {
        while(!c[1][p1]) p1++;
        while(!c[2][p2]) p2--;
        int v=min(c[1][p1],c[2][p2]);
        c[1][p1]-=v, c[2][p2]-=v, tot+=v;
        if(p1>p2) return false;
        if(p1<p2) return true;
    }
    return false;
}
bool mem2;
int main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        for(int j=0;j<m;j++) cnt[i][s[i][j]-'a']++;
    }
    for(int i=1;i<=n;i++) {
        int pd=1;
        for(int j=1;j<=n;j++) if(i!=j) pd&=check(i,j);
        cout<<pd;
    }
    cout<<endl;

    #ifdef xxzx
    cerr<<"Time "<<clo<<"MS"<<endl;
    cerr<<"Memory "<<abs(&mem1-&mem2)/1024./1024.<<"MB"<<endl;
    #endif
    return 0;
}