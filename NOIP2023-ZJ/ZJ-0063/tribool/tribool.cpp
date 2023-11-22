#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int T;
int ans[N];
int fa[N*2];
int n,m;
char ch;
bool pd[N];
vector<int>v[N];
void dfs(int a){
	if(pd[a])return;
	pd[a]=1;
	for(int i=0;i<v[a].size();i++)dfs(v[a][i]);
	return;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	fa[x]=y;
	return;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		v[i].clear();
		ans[i]=i;
		pd[i]=0;
	}
	for(int i=1;i<=n*2+2;i++){
		fa[i]=i;
	}
	for(int i=1,x,y;i<=m;i++){
		ch=getchar();
		while(ch!='+'&&ch!='T'&&ch!='U'&&ch!='F'&&ch!='-')ch=getchar();
		if(ch=='T'){
			scanf("%d",&x);
			ans[x]=n+1;
		}
		else if(ch=='F'){
			scanf("%d",&x);
			ans[x]=-(n+1);
		}
		else if(ch=='U'){
			scanf("%d",&x);
			ans[x]=0;
		}
		else if(ch=='+'){
			scanf("%d%d",&x,&y);
			ans[x]=ans[y];
		}
		else{
			scanf("%d%d",&x,&y);
			ans[x]=-ans[y];
		}
	}
	for(int i=1,w;i<=n;i++){
		w=abs(ans[i]);
		if(w==0||w>n)continue;
		v[w].push_back(i);
		v[i].push_back(w);
	}
	for(int i=1;i<=n;i++){
		if(!ans[i])dfs(i);
	}
	for(int i=1,w;i<=n;i++){
//		if(pd[i])continue;
		w=abs(ans[i]);
		if(w==n+1){
			if(ans[i]>0){
				merge(i,n*2+1);
				merge(i+n,n*2+2);
			}
			else{
				merge(i+n,n*2+1);
				merge(i,n*2+2);
			}
		}
		else if(w){
			if(ans[i]>0){
				merge(i,w);
				merge(i+n,w+n);
			}
			else{
				merge(i+n,w);
				merge(i,n+w);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(find(i)==find(i+n)||pd[i])ans++;
	}
	printf("%d",ans);
	return;
}
int c;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
		if(T)printf("\n");
	}
	return 0;
}