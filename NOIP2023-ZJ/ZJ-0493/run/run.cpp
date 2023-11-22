#include<bits/stdc++.h>

using namespace std;

const int N=100005;

inline int read(){
	int t=1,x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') t=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return t*x;
}

int c,t;
int n,m,k,d;
int value[N],lim[N];
long long ans;
bool be[N];

void dfs(int x,int leng,long long res){
	if(x>n){
		ans=max(ans,res);
		return ;
	}
	if(leng==k){
		dfs(x+1,0,res);
	}
	else{
		if(be[x] && leng+1>=lim[x]) dfs(x+1,leng+1,res-d+value[x]);
		dfs(x+1,leng+1,res-d);
		dfs(x+1,0,res);
	}
		
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=read(),m=read(),k=read(),d=read();
		for(int i=1;i<=m;i++){
			int x=read();
			lim[x]=read();
			value[x]=read();
			be[x]=1;
		}
		dfs(1,0,0ll);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) be[i]=lim[i]=value[i]=0;
	}
	return 0;
}
