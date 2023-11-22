#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int M=17,N=1e5+7;
int c,T; bool ok[N];
ll n,m,ans,fa[N+N];
struct node{
	char op[7];
	ll x,y;
}now;
char s[M],tmp[M];
vector<node> vec;
void prepr(){
	vec.clear(),ans=1e18;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%s",now.op+1);
		if(now.op[1]=='T') scanf("%lld",&now.x);
		if(now.op[1]=='F') scanf("%lld",&now.x);
		if(now.op[1]=='U') scanf("%lld",&now.x);
		if(now.op[1]=='+') scanf("%lld%lld",&now.x,&now.y);
		if(now.op[1]=='-') scanf("%lld%lld",&now.x,&now.y);
		vec.pb(now);
	}
	return;
}
void prepr1(){
	scanf("%lld%lld",&n,&m),ans=0;
	for(int i=1;i<=n;i++) ok[i]=0;
	for(int i=1;i<=m;i++){
		scanf("%s",now.op+1);
		if(now.op[1]=='T'){
			scanf("%lld",&now.x);
			if(ok[now.x]) ok[now.x]=0,ans--;
		}
		if(now.op[1]=='F'){
			scanf("%lld",&now.x);
			if(ok[now.x]) ok[now.x]=0,ans--;
		}
		if(now.op[1]=='U'){
			scanf("%lld",&now.x);
			if(!ok[now.x]) ok[now.x]=1,ans++;
		}
	}
	return;
}
int findfa(int x){
	if(fa[x]==x) return x;
	fa[x]=findfa(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	if(ok[y] && !ok[x]) swap(x,y);
	fa[y]=x;
	return;
}
void work(){
	for(auto i:vec){
		if(i.op[1]=='+')
			merge(findfa(i.x),findfa(i.y)),
			merge(findfa(i.x+n),findfa(i.y+n));
		if(i.op[1]=='-')
			merge(findfa(i.x+n),findfa(i.y)),
			merge(findfa(i.x),findfa(i.y+n));
		if(i.op[1]=='U')
			merge(findfa(i.x),findfa(i.x+n));
	}
	for(int i=1;i<=n;i++)
		if(findfa(i)==findfa(i+n)) ans++;
	return;
}
char f(char x){
	if(x=='T') return 'F';
	else if(x=='F') return 'T';
	else return 'U';
}
bool check(){
	for(int i=1;i<=n;i++) tmp[i]=s[i];
	for(auto i:vec){
		if(i.op[1]=='T') tmp[i.x]='T';
		if(i.op[1]=='F') tmp[i.x]='F';
		if(i.op[1]=='U') tmp[i.x]='U';
		if(i.op[1]=='+') tmp[i.x]=tmp[i.y];
		if(i.op[1]=='-') tmp[i.x]=f(tmp[i.y]);
	}
	for(int i=1;i<=n;i++)
		if(s[i]!=tmp[i]) return 0;
	return 1;
}
void dfs(int now,ll cntu){
	if(now>n){
		if(check()) ans=min(ans,cntu);
		return;
	}
	s[now]='T',dfs(now+1,cntu);
	s[now]='F',dfs(now+1,cntu);
	s[now]='U',dfs(now+1,cntu+1);
	return;
}
void Subtask1(){
	while(T--){
		prepr(),dfs(1,0);
		printf("%lld\n",ans);
	}
	return;
}
void Subtask2(){
	while(T--){
		prepr1();
		printf("%lld\n",ans);
	}
}
void Subtask3(){
	while(T--){
		prepr(),ans=0;
		for(int i=1;i<=n+n;i++)
			fa[i]=i;
		work();
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c==1 || c==2) Subtask1();
	if(c==3 || c==4) Subtask2();
	if(c>=5 && c<=8) Subtask3();
	return 0;
}
/*
5 1
10 9
+ 1 3
+ 1 2
- 2 3
+ 2 4
- 4 6
- 7 8
- 9 10
+ 7 9
+ 8 10

1 1
10 9
- 5 6
U 3
+ 3 10
U 5
+ 5 8
- 1 8
U 8
U 9
U 10
*/