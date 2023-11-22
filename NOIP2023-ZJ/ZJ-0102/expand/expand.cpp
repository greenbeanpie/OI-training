#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,q,p,v,aa[N],bb[N],a[N],b[N];
bool f[N];
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
bool cmp(int x,int y){return (a[1]>b[1]&&x>y)||(a[1]<b[1]&&x<y);}
bool work(){
	if((ll)(a[1]-b[1])*(a[n]-b[m])<=0)return false;
	bool c=true;
	for(int i=1;i<=m;i++){
		if(!cmp(a[1],b[i]))c=false;
		f[i]=c;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++)
			f[j]=(cmp(a[i],b[j])&&(f[j]||f[j-1]));
	}
	return f[m];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)aa[i]=a[i]=read();
	for(int i=1;i<=m;i++)bb[i]=b[i]=read();
	printf("%d",work());
	while(q--){
		int k1=read(),k2=read();
		for(int i=1;i<=n;i++)a[i]=aa[i];
		for(int i=1;i<=m;i++)b[i]=bb[i];
		for(int i=1;i<=k1;i++)
			p=read(),v=read(),a[p]=v;
		for(int i=1;i<=k2;i++)
			p=read(),v=read(),b[p]=v;
		printf("%d",work());
	}
	printf("\n");
	return 0;
}