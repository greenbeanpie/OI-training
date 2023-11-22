#include<bits/stdc++.h>
#define pb push_back
#define N 100005
using namespace std;
struct H{
	char kind;
	int x,y;
}opt[N];
char fin[N],ts[N],s[2];
int n,m,ans;
char F(char x){
	if(x=='T')return 'F';
	if(x=='F')return 'T';
	return x;
}
int check(){
	for(int i=1;i<=n;i++)ts[i]=fin[i];
	for(int i=1;i<=m;i++){
		if(opt[i].kind=='+')ts[opt[i].x]=ts[opt[i].y];
			else if(opt[i].kind=='-')ts[opt[i].x]=F(ts[opt[i].y]);
				else ts[opt[i].x]=opt[i].kind;
	}
	for(int i=1;i<=n;i++)if(ts[i]!=fin[i])return 0;
	return 1;
}
void dfs(int step,int U_num){
	if(U_num>ans)return;
	if(step>n){
		if(check())ans=U_num;
		return;
	}
	fin[step]='T';dfs(step+1,U_num);
	fin[step]='F';dfs(step+1,U_num);
	fin[step]='U';dfs(step+1,U_num+1);
}
void solve1(){
	scanf("%d %d",&n,&m);ans=n+1;
	for(int i=1;i<=m;i++){
		scanf("%s",s);opt[i].kind=s[0];scanf("%d",&opt[i].x);
		if(s[0]=='+'||s[0]=='-')scanf("%d",&opt[i].y);//x是被赋值的！！！别写反了！！！ 
	}
	dfs(1,0);printf("%d\n",ans);
}
void solve2(){
	scanf("%d %d",&n,&m);ans=0;
	for(int i=1;i<=n;i++)fin[i]='T';
	for(int i=1;i<=m;i++){
		scanf("%s",s);opt[i].kind=s[0];scanf("%d",&opt[i].x);fin[opt[i].x]=opt[i].kind;
	}
	for(int i=1;i<=n;i++)ans+=(fin[i]=='U');
	printf("%d\n",ans);
}
int head[N],to[N*2],val[N*2],nxt[N*2],cnt=0,vis[N];
void add_edge(int x,int y,int z){
	to[++cnt]=y;val[cnt]=z;nxt[cnt]=head[x];head[x]=cnt;
}
struct Y{
	int kind,x,ti;
};
vector<Y>op[N];
vector<int>rec[N];
queue<int>q;
void get(int u,int st){
	if(st==op[u].size()&&!vis[u])q.push(u),vis[u]=1;
	for(int i=st;i<op[u].size();i++){
		if(op[u][i].kind!=3)return;
		if(i==op[u].size()-1&&!vis[u])q.push(u),vis[u]=1;
		get(op[u][i].x,op[u][i].ti+1);
	}
}
void solve3(){
	memset(vis,0,sizeof(vis));
	scanf("%d %d",&n,&m);ans=0;
	for(int i=1;i<=n;i++)op[i].clear(),rec[i].clear();
	for(int i=1,x,y;i<=m;i++){
		scanf("%s",s);scanf("%d",&x);
		if(s[0]=='+'){
			scanf("%d",&y);//x是被赋值的！！！别写反了！！！ 
			int ty=op[y].size(),tx=op[x].size();
			op[x].pb(Y{2,y,ty});
			op[y].pb(Y{3,x,tx});
		}
		else op[x].pb(Y{1,0,0}),rec[x].pb(op[x].size());
	}
	for(int i=1;i<=n;i++)
		for(auto x:rec[i])get(i,x);
	while(!q.empty()){
		int u=q.front();q.pop();ans++;get(u,0);
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int Type,T;scanf("%d %d",&Type,&T);
	while(T--){
		if(Type<=2)solve1();
			else if(Type<=4)solve2();
				else if(Type<=6)solve3();
					//else if(Type<=8)solve4();
						else puts("0");
	}
}

