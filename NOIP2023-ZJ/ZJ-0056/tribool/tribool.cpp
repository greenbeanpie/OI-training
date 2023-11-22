#include<bits/stdc++.h>
using namespace std;
long long C,T;
long long n,m,f[600001],a[600001],b[600001],siz[600001],tmp[600001];
inline int find(int x){while (x!=f[x]) x=f[x]=f[f[x]]; return x;}
inline void merge(int x,int y){
if (find(x)==find(y)) return;
siz[find(x)]+=siz[find(y)]; f[find(y)]=find(x);
}
int main(){
freopen("tribool.in","r",stdin);
freopen("tribool.out","w",stdout);
ios::sync_with_stdio(false); cin.tie(0);
cin>>C>>T;
while (T--){
cin>>n>>m;
n+=3;//n-2->T n-1->F n->U
for (int i=1;i<=2*n;++i) f[i]=i,siz[i]=(i<=n-3),tmp[i]=0;
for (int i=1;i<=n;++i) a[i]=i,b[i]=0;
while (m--){
char op; int x,y;
cin>>op; 
if (op=='U') y=n;
if (op=='F') y=n-1;
if (op=='T') y=n-2;
cin>>x;
if (op=='+' || op=='-') cin>>y;
a[x]=a[y]; b[x]=b[y];
if (op=='-') b[x]^=1;
}
for (int i=1;i<=n-3;++i){
if (!b[i]) merge(a[i],i),merge(a[i]+n,i+n);
else merge(a[i],i+n),merge(a[i]+n,i);
}
for (int i=1;i<=n-3;++i) if (find(i)==find(i+n)) tmp[find(i)]=1;
tmp[find(n)]=tmp[find(n+n)]=1;
long long ans=0;
for (int i=1;i<=n+n;++i) if (find(i)==i && tmp[find(i)])
ans+=siz[find(i)];
cout<<ans<<'\n';
}
return 0;
}
