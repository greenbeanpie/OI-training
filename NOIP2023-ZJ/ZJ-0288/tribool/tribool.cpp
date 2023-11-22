#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,used[100001],ans;
int que[100001],xx[100001],yy[100001];
vector<int>e[100001];
void dfs(int x){
	used[x]=1;
	ans++;
	for(int i=0;i<e[x].size();i++){
		if(!used[e[x][i]]){
			dfs(e[x][i]);
		}
	}
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(used,0,sizeof(used));
		cin>>n>>m;
		if(c==3||c==4){
			for(int i=1;i<=m;i++){
				char ch;int x;
				cin>>ch;cin>>x;
				if(ch=='U'&&(!used[x])){
					used[x]=1,ans++;
				}else if(used[x]&&ch!='U'){
					used[x]=0,ans--;
				}
			}
		}
		if(c==5||c==6){
			for(int i=1;i<=m;i++){
				char ch;int x,y=0;
				cin>>ch;cin>>x;
				if(ch=='U')que[i]=1;
				else cin>>y;
				xx[i]=x,yy[i]=y;
			}
			for(int i=m;i>=1;i--){
				if(que[i]==0){
					if(!used[xx[i]]){
						used[xx[i]]=1;
						e[yy[i]].push_back(xx[i]);
					}
				}
			}
			for(int i=1;i<=m;i++){
				if(que[i]==1&&!used[xx[i]]){
					dfs(xx[i]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
3 3
2 2
T 2
U 2
1 3
U 1
U 1
U 1
3 3
U 2
T 1
U 3
*/
