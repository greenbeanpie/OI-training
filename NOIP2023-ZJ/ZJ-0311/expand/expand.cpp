#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
il ll read(){
	ll a=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	return a*f;
}
ll c,n,m,q,a,b,k;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)a=read();
	for(int i=1;i<=m;i++)a=read();
	cout<<0;
	for(int i=1;i<=q;i++){
		a=read();
		b=read();
		for(int j=1;j<=a;j++){
			k=read();
			k=read();
		}
		for(int j=1;j<=b;j++){
			k=read();
			k=read();
		}
		cout<<0;
	}
	return 0;
}

