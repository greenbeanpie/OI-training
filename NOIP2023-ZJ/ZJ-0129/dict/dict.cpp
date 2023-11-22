#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

const int N=3005;
int n,m;
string w[2*N];

int D[2*N],rk[2*N],pre[2*N],suf[2*N];

bool cmp(int i,int j){
    return w[i]<w[j];
}

int main(){

    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        sort(w[i].begin(),w[i].end());
        w[i+n]=w[i];
        reverse(w[i+n].begin(),w[i+n].end());
    }

    for(int i=1;i<=2*n;i++) D[i]=i;
    sort(D+1,D+n+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=2*n;i++){
        if(i==1 || w[D[i]]!=w[D[i-1]]) cnt++;
        rk[D[i]]=cnt;
    }

    pre[0]=2*n+1;
    for(int i=1;i<=n;i++) pre[i]=min(pre[i-1],rk[i+n]);
    suf[n+1]=2*n+1;
    for(int i=n;i>=1;i--) suf[i]=min(suf[i+1],rk[i+n]);

    for(int i=1;i<=n;i++){
        if(rk[i]<pre[i-1] && rk[i]<suf[i+1]) cout<<"1";
        else cout<<"0";
    }
    cout<<"\n";

    cout.flush(); fclose(stdin); fclose(stdout);

    return 0;
}