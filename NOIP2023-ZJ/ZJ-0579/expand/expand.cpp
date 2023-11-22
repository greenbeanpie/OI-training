#include<bits/stdc++.h>
#define ll long long
#define debug cout<<"ok desu"<<endl
using namespace std;

int read(){
	int f=1,x=0; char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}

const int inf=0x7fffffff;
const int maxn=5e5+10;

int c,n,m,q;
int xs[maxn],ys[maxn];
int x[maxn],y[maxn];

void rewrite(){
	for(int i=1;i<=n;i++){
		x[i]=xs[i];
	}
	for(int i=1;i<=m;i++){
		y[i]=ys[i];
	}
}

void clannad(){
	int i=1,j=1;
	while(i<=n&&j<=m){
		if(x[i]>y[j])j++;
		else {
			if(j<=i)break;
			i++;
		}
	}
	if(j==m+1){
		int flag=1;
		for(;i<=n;i++){
			if(x[i]<=y[m])flag=0;
		}
		if(flag){
			printf("1");
			return;
		}
	}
	i=1,j=1;
	while(i<=n&&j<=m){
		if(x[i]<y[j])i++;
		else {
			if(i<=j)break;
			j++;
		}
	}
	if(i==n+1){
		int flag=1;
		for(;j<=n;j++){
			if(y[j]<=x[n])flag=0;
		}
		if(flag){
			printf("1");
			return;
		}
	}
	printf("0");
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++){
		xs[i]=read();
	}
	for(int i=1;i<=m;i++){
		ys[i]=read();
	}
	rewrite();
	clannad();
	while(q--){
		rewrite();
		int kx=read(),ky=read();
		while(kx--){
			int p=read(),v=read();
			x[p]=v;
		}
		while(ky--){
			int p=read(),v=read();
			y[p]=v;
		}
		clannad();
	}
	return 0;
}