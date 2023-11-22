#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m;

int fa[N];
bool g[N],flag[N];//
int f[N];
bool sst[N];
bool d[N];
vector<int>e[N];
/*
flag = 1 p
*/
int ans;
void search(int x){
	flag[x]=1;
	ans++;
	d[x]=1;
	for(int y:e[x])if(!flag[y])search(y);
	return ;
}
void find(int x,bool state){
	d[x]=1;
//	cout<<x<<endl;
	sst[x]=1;
	for(int y:e[x]){
		if(sst[y]){
			if(state^g[y]){
//				cout<<x<<" "<<y<<"dibodibo\n";
				search(x);
				sst[x]=0;
				return ;
			}
		}else if(!d[y]){
			find(y,state^g[y]);
		}
	}
	sst[x]=0;
	return ;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
//		cout<<"xiaodibo";
	char v;
	int x,y;
	while(t){
		memset(sst,0,sizeof(sst));
		memset(g,0,sizeof(g));
		memset(e,0,sizeof(e));
		memset(flag,0,sizeof(flag));
		memset(d,0,sizeof(d));
//		memset(p,0,sizeof(p));
		t--;
//		int cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n+3;i++)fa[i]=i;
		while(m){
			m--;
			cin>>v;
//			scanf("%c",&v);
			if(v=='+'){
				scanf("%d%d",&x,&y);
//				if(x>1e5||y>1e5)cout<<"xiaodibo";
//cout<<"xiaodibo";
				fa[x]=fa[y];
				g[x]=g[y];
//				flag[x]=flag[y];
			}else if(v=='-'){
//			cout<<"dibo";
				scanf("%d%d",&x,&y);
				fa[x]=fa[y];
				g[x]=!g[y];
//				flag[x]=flag[y];
			}else{
				scanf("%d",&x);
//				st[n+cnt]=x;
//				flag[x]=1;
				
				if(v=='U'){
					fa[x]=n+1;
				}else if(v=='T'){
					fa[x]=n+2;
				}else{
					fa[x]=n+3;
				}
			}
		}

//		cout<<"xiaodibo";
		ans=0;
		for(int i=1;i<=n;i++){
//			if(t==3||t==2)cout<<i<<" "<<fa[i]<<" "<<g[i]<<endl;
			e[fa[i]].push_back(i);
		}
//		cout<<ans<<endl;
		search(n+1);
//		cout<<ans<<endl;
		ans--;
		for(int i=1;i<=n;i++){
			if(fa[i]==i){
				if(g[i]==1){
//					flag[i]=1;
//					ans++;
					search(i);
				}
			}
			if(!d[i]){
				find(i,0);
			}
//				else if(fa[i]==n+2){
//					
//				}else if(fa[i]==n+3){
//					
//				}
//			}
		}
//		for(int i=1;i<=n;i++){
//			if(fa[i]!=i&&fa[i]<=n&&flag[fa[i]]){
//				flag
//			}
//		}
		printf("%d\n",ans);
	}
}
