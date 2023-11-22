#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

int n,m,ans,c,q;
int a[10],b[10];
int f[10],d[10];

inline int read(){
	int x=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			k=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*k;
}


int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	if(c==1){
		while(q--)
			cout<<1;
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
		b[i]=read();
	if((a[1]-b[1])*(a[n]-b[m])>0)
		cout<<1;
	else cout<<0;
	while(q--){
		int k1=read(),k2=read();
		for(int i=1;i<=n;i++)
			f[i]=a[i];
		for(int i=1;i<=m;i++)
			d[i]=b[i];
		for(int i=1;i<=k1;i++)
			f[read()]=read();
		for(int i=1;i<=k2;i++)
			d[read()]=read();
		if((f[1]-d[1])*(f[n]-d[m])>0)
			cout<<1;
		else cout<<0;
	}
	return 0;
}





