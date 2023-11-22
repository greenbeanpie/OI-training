#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define mst(a,b) memset(a,b,sizeof(a))
#define kp(a,b) make_pair(a,b)
#define fi first
#define se second
inline int read(){
	int x=0;bool f=true;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=false;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return f?x:(~(x-1));
}
int c,T;
int n,m;
int fei(int x){
	if(x==0) return 1;
	if(x==1) return 0;
	if(x==2) return 2;
	return 0;
}
namespace Sub1{
	const int N=15;
	string op[N];
	int ans,a[N],b[N],x[N],y[N];
	void mj(int index){
		if(index<=n){
			for(int i=0;i<=2;i++){
				a[index]=i;
				mj(index+1);
			}
			return;
		}
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int i=1;i<=m;i++){
			if(op[i]=="+") b[x[i]]=b[y[i]];else
			if(op[i]=="-") b[x[i]]=fei(b[y[i]]);else
			if(op[i]=="F") b[x[i]]=0;else
			if(op[i]=="T") b[x[i]]=1;else
			if(op[i]=="U") b[x[i]]=2;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]==2) cnt++;
			if(a[i]!=b[i]) return;
		}
		ans=min(ans,cnt);
	}
	void work(){
		ans=INF;
		n=read();m=read();
		for(int i=1;i<=m;i++){
			cin>>op[i];
			x[i]=read();
			if(op[i]=="+" || op[i]=="-") y[i]=read();
		}
		mj(1);
		printf("%d\n",ans);
	}
}
namespace Sub2{
	const int N=1e5+100;
	int a[N];
	void work(){
		n=read();m=read();
		for(int i=1;i<=m;i++){
			string op;
			cin>>op;
			int x=read();
			if(op=="F") a[x]=0;else
			if(op=="T") a[x]=1;else
			if(op=="U") a[x]=2;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==2) ans++;
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();T=read();
	while(T--){
		if(c<=2) Sub1::work();else
		Sub2::work();
	}
	return 0;
}
/*
hack
8 1
4 4
+ 4 2
- 2 1
- 3 2
- 1 3

*/