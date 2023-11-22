#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[128];
string s[3009],qz[3009],hz[3009];
int main(){
freopen("dict.in","r",stdin);
freopen("dict.out","w",stdout);
ios::sync_with_stdio(false); cin.tie(0);
cin>>n>>m;
if (n==1){cout<<1; return 0;}
for (int i=1;i<=n;++i){
cin>>s[i];
for (int j=0;j<=25;++j) cnt[j]=0;
for (int j=0;j<m;++j) ++cnt[s[i][j]-97];
int now=0;
for (int j=25;j>=0;--j) for (int k=1;k<=cnt[j];++k)
s[i][now++]=char(j+97);
}
qz[1]=s[1];
for (int i=2;i<=n;++i) qz[i]=min(qz[i-1],s[i]);
hz[n]=s[n];
for (int i=n-1;i;--i) hz[i]=min(hz[i+1],s[i]);
for (int i=1;i<=n;++i){
string now=s[i];
reverse(now.begin(),now.end());
string A;
if (i>1 && i==n) A=qz[i-1];
else if (i==1 && i<n) A=hz[i+1];
else A=min(qz[i-1],hz[i+1]);
cout<<(now<A?1:0);
}
return 0;
}
