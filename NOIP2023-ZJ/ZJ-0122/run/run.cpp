#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
	long long z;
	bool operator < (const node b)const{return r<b.r;}
}c[100005];
int t,n,m,k;
long long ans,d,opt[100005],F[100005];
int read(){
	int ret=0;bool f=true;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=false;ch=getchar();}
	while (isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return f?ret:-ret;
}
int main(){
	freopen ("run.in","r",stdin);
	freopen ("run.out","w",stdout);
	read(),t=read();
	while (t--){ans=0;
		n=read(),m=read(),k=read(),d=read();
		for (int i=1;i<=m;i++){
			c[i].r=read(),c[i].l=c[i].r-read()+1,c[i].z=read();
			if (c[i].r-c[i].l+1>k) i--,m--;
		}sort(c+1,c+1+m);
		memset(opt,0,sizeof opt),memset(F,0,sizeof F);
		for (int i=1;i<=m;i++){
			for (int j=max(1,c[i].r-k+1);j<=c[i].l;j++)
				opt[j]+=c[i].z,F[c[i].r+1]=max(F[c[i].r+1],F[j-1]+opt[j]-d*(c[i].r-j+1));
			for (int j=c[i].r+2;j<=n+1;j++) F[j]=max(F[j],F[c[i].r+1]);
		}printf ("%lld\n",F[n+1]);
	}return 0;
}