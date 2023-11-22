#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
inline int read(){
	int w=1,s=0;
	char c=getchar();
	for(;c<'0'||c>'9';w*=(c=='-')?-1:1,c=getchar());
	for(;c>='0'&&c<='9';s=s*10+c-'0',c=getchar());
	return w*s;
}
int c,n,m,q;
int a[N],b[N];
string s;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
	}
	if(n==1&&m==1){
		int t1=a[1],t2=b[1];
		if(a[1]!=b[1]) s+='1';
		else s+='0';
		while(q--){
			a[1]=t1,b[1]=t2;
			int n1=read(),m1=read();
			for(int i=1;i<=n1;i++){
				int p=read(),v=read();
				a[p]=v;
			}
			for(int i=1;i<=m1;i++){
				int p=read(),v=read();
				b[p]=v;
			}
			if(a[1]!=b[1]) s+='1';
			else s+='0';
		}
		cout<<s<<endl;
	}
	return 0;
}

