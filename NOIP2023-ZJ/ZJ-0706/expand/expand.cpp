#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c) && c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int n,m,c,q;
int x[N],y[N];
int ans[N],top;
namespace subtask1{
	bool judge(){
		if(n==1 && m==1) return true;
		return false;
	}
	void work(){
		if(judge()){
			ans[++top]=1;
		}
	}
}
namespace subtask2{
	bool judge(){
		if(n<=2 && m<=2 && !subtask1::judge()){
			return true;
		}
		return false;
	}
	void work(){
		if(n==1 && m==1) ans[++top]=1;
		if(n==1 && m==2){
			if(y[1]>x[1] && y[2]>x[1]) ans[++top]=1;
			else if(y[1]<x[1] && y[2]<x[1]) ans[++top]=1;
			else ans[++top]=0;
		}
		if(n==2 && m==1){
			if(x[1]>y[1] && x[2]>y[1]) ans[++top]=1;
			else if(x[1]<y[1] && x[2]<y[1]) ans[++top]=1;
			else ans[++top]=0;
		}
		if(n==2 && m==2){
			if((x[1]-y[1])*(x[2]-y[2])>0) ans[++top]=1; 
			else ans[++top]=0;
		}
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(); n=read(); m=read(); q=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=m;i++) y[i]=read();
	if(subtask1::judge())
		subtask1::work();
	else if(subtask2::judge())
		subtask2::work();
	else ans[++top]=0;
	while(q--){
		int kx,ky;
		kx=read(); ky=read();
		for(int i=1;i<=kx;i++){
			int px,vx;
			px=read(); vx=read();
			x[px]=vx;
		}
		for(int i=1;i<=ky;i++){
			int py,vy;
			py=read(); vy=read();
			y[py]=vy;
		}
		if(subtask1::judge())
			subtask1::work();
		else if(subtask2::judge())
			subtask2::work();
		else ans[++top]=0;
	}
	for(int i=1;i<=top;i++) printf("%d",ans[i]);
	return 0;
}
//1 2 2 1
//1 2
//3 4
//0 1
//2 1
