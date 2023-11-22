#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int IDDDDD,T,n,m;
int v1[N],v2[N],ans=1e9;
struct OP{
	int a,b,c;
}op[N];
int change(int x){
	if(x==1||x==2) return 3-x;
	return 3;
}
bool check(){
	for(int i=1;i<=n;i++){
		v2[i]=v1[i];
	}
	for(int i=1;i<=m;i++){
		if(op[i].c!=0){
			if(op[i].c==1) v2[op[i].b]=v2[op[i].a];
			else v2[op[i].b]=change(v2[op[i].a]);
		}
		else v2[op[i].b]=-op[i].a;
	}
	bool suc=true;
	for(int i=1;i<=n;i++){
		if(v1[i]!=v2[i]) suc=false;	
	} 
	return suc;
}
void dfs(int u,int sum){
	if(u==n+1){
		if(check()){
			ans=min(ans,sum);
		} 
		return;
	}
	v1[u]=1;
	dfs(u+1,sum);
	v1[u]=2;
	dfs(u+1,sum);
	v1[u]=3;
	dfs(u+1,sum+1);
}
void solve(){
	ans=1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char p[2];
		int a,b;
		cin>>p;
		if(*p=='+'){
			cin>>a>>b;
			op[i]={b,a,1};
		}
		else if(*p=='-'){
			cin>>a>>b;
			op[i]={b,a,-1};
		}
		else{
			cin>>a;
			if(*p=='T') op[i]={-1,a,0};
			else if(*p=='F') op[i]={-2,a,0};
			else op[i]={-3,a,0};
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
}
int type[100010];
void solve2(){
	memset(type,-1,sizeof type);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		char op[2];
		int a;
		cin>>op>>a;
		if(*op=='T') type[a]=1;
		else if(*op=='F') type[a]=2;
		else type[a]=3;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(type[i]==3) cnt++;
	cout<<cnt<<endl;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>IDDDDD>>T;
	if(IDDDDD>=3){
		while(T--){
			solve2();
		}
		return 0;
	}
	while(T--){
		solve();
	}
	return 0;
}
/*
1 3
3 3
- 2 1
‐ 3 2
+ 1 3
3 3
‐ 2 1
‐ 3 2
‐ 1 3
2 2
T 2
U 2


*/