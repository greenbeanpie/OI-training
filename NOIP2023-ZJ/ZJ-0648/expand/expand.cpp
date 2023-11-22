#include<bits/stdc++.h>
const int maxn = 5e4+5;
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int c,n,m,q;
int x[maxn],y[maxn];
int a[maxn],b[maxn];
bool work(int *a,int ln,int *b,int lm){
	if(a[ln]<=b[lm]) return 0;
	int i=1;
	for(int j=1;j<=lm;j++){
		if(a[i]>b[j]) i++;
		else {
			while(a[i]<=b[j]){
				i--;
				if(i==0) return 0;	
			}
		}
	}
	while(i<=ln){
		if(a[i]>b[lm]) i++;
		else {
			while(a[i]<=b[lm]){
				i--;
				if(i==0) return 0;
			}
		}
	}
	return 1;
}
bool solve(int *a,int *b){
	if(a[1]==b[1]) return 0;
	if(a[1]>b[1]) return work(a,n,b,m);
	else return work(b,m,a,n);
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	q=read();
	for(register int i=1;i<=n;i++) a[i]=x[i]=read();
	for(register int i=1;i<=m;i++) b[i]=y[i]=read();
	cout<<solve(a,b);
	while(q--){
		int kx=read(),ky=read();
		for(register int i=1;i<=kx;i++){
			int dx=read(),dy=read();
			a[dx]=dy;
		}
		for(register int i=1;i<=ky;i++){
			int dx=read(),dy=read();
			b[dx]=dy;
		}
		cout<<solve(a,b);
		for(int i=1;i<=n;i++) a[i]=x[i];
		for(int i=1;i<=m;i++) b[i]=y[i];
	}
	return 0;
}

