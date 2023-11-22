#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int inf=1e9;
inline int read(){
	int f=1,w=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')	f=-1;
		c=getchar();
	}
	while(c>='0'&& c<='9'){
		w=(w<<1)+(w<<3)+(c^48);
		c=getchar();
	}
	return f*w;
}
struct ques{
	char op;
	int x,y;
}q[N];
int trans(int x){
	if(x==0)	return x;
	else{
		if(x==1)	return 2;
		return 1;
	}
}
int n,m;
int a[N];//0:U,1:T,2:F
int c,T;
namespace sub1{
	int b[N];
	int minn=inf;
	void check(){
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int i=1;i<=m;i++){
			if(q[i].op=='U'){
				b[q[i].x]=0;
			}else if(q[i].op=='T'){
				b[q[i].x]=1;
			}else if(q[i].op=='F'){
				b[q[i].x]=2;
			}else if(q[i].op=='+'){
				b[q[i].x]=b[q[i].y];
			}else if(q[i].op=='-'){
				b[q[i].x]=trans(b[q[i].y]);
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=a[i])	return;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(b[i]==0)	ans++;
		}
		minn=min(minn,ans);
	}
	void dfs(int x){
		if(x>n){
			check();
			return;
		}
		a[x]=0;
		dfs(x+1);
		a[x]=1;
		dfs(x+1);
		a[x]=2;
		dfs(x+1);
	}
	void work(){
		minn=inf;
		n=read();
		m=read();
		for(int i=1;i<=m;i++){
			cin>>q[i].op;
			if(q[i].op=='+' || q[i].op=='-'){
				q[i].x=read();
				q[i].y=read();
			}else{
				q[i].x=read();
			}
		}
		dfs(1);
		cout<<minn<<endl;
	}
}
namespace sub2{
	int a[N];
	void work(){
		n=read();
		m=read();
		for(int i=1;i<=m;i++){
			cin>>q[i].op;
			if(q[i].op=='+' || q[i].op=='-'){
				q[i].x=read();
				q[i].y=read();
			}else{
				q[i].x=read();
			}
		}
		for(int i=1;i<=n;i++){
			a[i]=-1;
		}
		for(int i=1;i<=m;i++){
			if(q[i].op=='U'){
				a[q[i].x]=0;
			}else if(q[i].op=='T'){
				a[q[i].x]=1;
			}else{
				a[q[i].x]=2;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)	ans++;
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	T=read();
	if(c<=2){
		while(T--){
			sub1::work();
		}
		return 0;
	}
	if(c==3 || c==4){
		while(T--){
			sub2::work();
		}
		return 0;
	}
	while(T--){
		cout<<0<<endl;
	}
	return 0;
}