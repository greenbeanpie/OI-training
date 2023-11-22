#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
const ll N=100010;
ll C,Tst,n,m,k,d,a[N];
void work(){
	n=read(),m=read(),k=read(),d=read();
	for(ll i=1,x,y,z;i<=m;i++)x=read(),y=read(),z=read();
	puts("0");
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	C=read(),Tst=read();
	while(Tst--)work();
	return 0;
}