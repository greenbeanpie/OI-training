#include<bits/stdc++.h>
using namespace std;
//T:1,F:2,U:3,+:4,-:5
const int N = 2e5 + 5;
struct oper{
	int x,y,op;
}q[N];
struct node{
	int nxt,to,w;
}e[N * 2];
int c,t,n,m,a[N],ans,tmp[N],tot,head[N],din[N];
bool judge(){
	for(int i=1;i<=n;i++) tmp[i] = a[i];
	for(int i=1;i<=m;i++){
		if(q[i].op <= 3) tmp[q[i].x] = q[i].op;
		else{
			if(q[i].op == 4) tmp[q[i].x] = tmp[q[i].y];
			else{
				if(tmp[q[i].y] <= 2) tmp[q[i].x] = !(tmp[q[i].y] - 1) + 1;
				else tmp[q[i].x] = 3;
			}
		}
	}
	for(int i=1;i<=n;i++) if(tmp[i] != a[i]) return 0;
	return 1;
}
int cnt(){
	int res = 0;
	for(int i=1;i<=n;i++) res += (a[i] == 3);
	return res;
}
void dfs(int pos){
	if(pos == n + 1){
		if(judge()) ans = min(ans,cnt());
		return;
	}
	a[pos] = 1,dfs(pos + 1);
	a[pos] = 2,dfs(pos + 1);
	a[pos] = 3,dfs(pos + 1);
}
int solve1(){
	ans = 1e9,dfs(1);
	return ans;
}
int solve2(){
	memset(a,0,sizeof a);
	int res = 0;
	for(int i=1;i<=m;i++) a[q[i].x] = q[i].op;
	for(int i=1;i<=n;i++) res += (a[i] == 3);
	return res;
}
void add(int u,int v,int l){
	e[tot].to = v,e[tot].nxt = head[u];
	e[tot].w = l,head[u] = tot ++;
}
void search(int u,int flag){
	//cout<<"u: "<<u<<" "<<st<<endl;
	if(a[u] == 3 && !flag) return;
	a[u] = 3;
	for(int i=head[u];i!=-1;i=e[i].nxt){
		int v = e[i].to;
		search(v,0);
	}
}
int solve3(){
	memset(head,-1,sizeof head);
	int res = 0;
	memset(a,0,sizeof a);
	for(int i=1;i<=m;i++){
		if(q[i].op == 3) a[q[i].x] = 3;
		else if(q[i].op == 4){
			add(q[i].y,q[i].x,0);
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i] == 3) search(i,1);
	for(int i=1;i<=n;i++) res += (a[i] == 3);
	return res;
}
int vis[N],all = 0;
void getval(int u,int vl,int sum){
	if(vis[u]){
		if(vl) all += sum;
		return;
	}
	vis[u] = 1;
	for(int i=head[u];i!=-1;i=e[i].nxt){
		int v = e[i].to; if(!din[v]) continue;
		getval(v,vl ^ e[i].w,sum + 1);
	}
}
int solve4(){
	memset(head,-1,sizeof head);
	memset(din,0,sizeof din);
	for(int i=1;i<=m;i++){
		if(q[i].op == 4) add(q[i].y,q[i].x,0),din[q[i].x] ++ ;
		else if(q[i].op == 5) add(q[i].y,q[i].x,1),din[q[i].x] ++;
	}
	queue <int> qu;
	for(int i=1;i<=n;i++) if(!din[i]) qu.push(i);
	while(!qu.empty()){
		int u = qu.front(); qu.pop();
		for(int i=head[u];i!=-1;i=e[i].nxt){
			int v = e[i].to;
			din[v] --;
			if(!din[v]) qu.push(v);
		}
	}
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
	    if(din[i] && !vis[i])
	    	getval(i,0,0);
	return all;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t --){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int tag;
			char op; scanf(" %c",&op);
			if(op == 'T') tag = 1;
			if(op == 'F') tag = 2;
			if(op == 'U') tag = 3;
			if(op == '+') tag = 4;
			if(op == '-') tag = 5;
			q[i].op = tag;
			if(tag <= 3) scanf("%d",&q[i].x);
			else scanf("%d%d",&q[i].x,&q[i].y);
		}
		if(c <= 2) printf("%d\n",solve1());
		else if(c <= 4) printf("%d\n",solve2());
		else if(c <= 6) printf("%d\n",solve3());
		else if(c <= 8) printf("%d\n",solve4());
	}
	return 0;
}
