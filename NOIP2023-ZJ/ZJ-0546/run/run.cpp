#include<bits/stdc++.h>
using namespace std;
#define MAXN 4514
//froepen()
//freopen
//expend
//ni bei pian la!
//luogu chala_tea (id wang le()

struct cha{
	int y=0,v=0;
}ch[MAXN];
int c,t;
int n,m,k,d,ans=-1e9-10;

void dfs(int x,int lst,int e){
	if(x>n){
		ans=max(ans,e);
		return ;
	}
	dfs(x+1,0,e);
	if(x<=k){
		lst++,e-=d;
		if((ch[x].v)&&(ch[x].y<=lst))e+=ch[x].v;
		dfs(x+1,lst,e);	
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			int x;
			cin>>x;
			cin>>ch[x].y>>ch[x].v;
		}
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	
	
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
NOIP 2023(false) DP paradise(true)
*/