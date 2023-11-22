#include<bits/stdc++.h>
using namespace std;
//T  1
//F  -1
//U  0
const int N=1e5+10;
int p[N];
int in[N];
int n,m;
vector<int> a[N];
void topu(){
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(p[i]==1||p[i]==0||p[i]==-1) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<a[x].size();i++){
			int y=a[x][i];in[y]--;
			if(p[y]==-(x+1))p[y]=-p[x];
			else p[y]=p[x];
			if(in[y]==0) q.push(y);
		}
	}
}
//void dfs()
void wrk(){
	int cnt=0;
	cin>>n>>m;
//	for(int i=1;i<=n;i++) tmp[i]=false;
	for(int i=1;i<=n;i++) p[i]=i+1;
	for(int i=1;i<=m;i++){
		char c;cin>>c;int x,y;
		if(c=='+') scanf("%d%d",&x,&y),p[x]=p[y];
		if(c=='-') scanf("%d%d",&x,&y),p[x]=-p[y];
		if(c=='T') scanf("%d",&x),p[x]=1;
		if(c=='F') scanf("%d",&x),p[x]=-1;
		if(c=='U') scanf("%d",&x),p[x]=0;
	}
//	for(int i=1;i<=n;i++) printf("%d ",p[i]);printf("\n");
//	for(int i=1;i<=n;i++) printf("%d ",p[i]);printf("\n");
	for(int i=1;i<=n;i++) a[i].clear();
	for(int i=1;i<=n;i++){
		if(p[i]!=0&&p[i]!=1&&p[i]!=-1){
			if(p[i]==-i-1) p[i]=0;
			else if(p[i]==i+1) p[i]=1;
			else a[abs(p[i])-1].push_back(i),in[i]++;
		}
	}
	topu();
//	for(int i=1;i<=n;i++)
//		if(p[i]==0||p[i]==1||p[i]==-1) tmp[i]=true;
//	for(int i=1;i<=n;i++) if(tmp[i]==false) dfs(i);
	for(int i=1;i<=n;i++) if(p[i]==0) cnt++;
	printf("%d\n",cnt);//printf("\n\n\n");
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int T,C;
	cin>>C>>T;
	while(T-->0)wrk();
	return 0;
}
