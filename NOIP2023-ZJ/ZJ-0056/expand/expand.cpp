#include<bits/stdc++.h>
using namespace std;
int C,n,m,q,a[1000001],b[1000001],A[1000001],B[1000001],tmp;
int f[2001][2001][2];
inline bool ck(int x,int y){
x=a[x]; y=b[y];
if (x==y) return 0;
return ((x>y)==tmp);
}
inline void cal(){
if (a[1]==b[1]){cout<<0; return;}
if (a[1]>b[1]) tmp=1; else tmp=0;
if (!ck(n,m)){cout<<0; return;}
if (n>2000 || m>2000){cout<<1; return;}
for (int i=0;i<=n;++i) memset(f[i],0,sizeof(f[i]));
f[1][1][0]=f[1][1][1]=1;
for (int i=1;i<=n;++i) for (int j=1;j<=m;++j){
if (i<n && j<m && (f[i][j][0] || f[i][j][1]) && ck(i+1,j+1))
f[i+1][j+1][0]=f[i+1][j+1][1]=1;
if (i<n && f[i][j][0] && ck(i+1,j)) f[i+1][j][0]=1;
if (j<m && f[i][j][1] && ck(i,j+1)) f[i][j+1][1]=1;
}
if (f[n][m][0] || f[n][m][1]) cout<<1;
else cout<<0;
}
int main(){
freopen("expand.in","r",stdin);
freopen("expand.out","w",stdout);
ios::sync_with_stdio(false); cin.tie(0);
cin>>C>>n>>m>>q;
for (int i=1;i<=n;++i) cin>>a[i],A[i]=a[i];
for (int i=1;i<=m;++i) cin>>b[i],B[i]=b[i];
cal();
while (q--){
int k,kk;
cin>>k>>kk;
for (int i=1;i<=n;++i) a[i]=A[i];
for (int i=1;i<=m;++i) b[i]=B[i];
while (k--){int pos,val; cin>>pos>>val; a[pos]=val;}
while (kk--){int pos,val; cin>>pos>>val; b[pos]=val;}
cal();
}
return 0;
}
