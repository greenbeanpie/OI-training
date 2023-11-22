#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;

int from[N],ch[N];
int col[N];
int used[N];

int n,m;

struct node_edge{
	int v,ch;
};

vector<node_edge> e[N];

queue<int> q,q2;

void init(){
	for(int i=1;i<=n;i++){
		col[i]=0,used[i]=0;
		e[i].clear();
	}
		
	
	cin>>n>>m;
//	cout<<"n = "<<n<<" m = "<<m<<endl;
	for(int i=1;i<=n;i++)
		from[i]=i,ch[i]=1;
	for(int i=1;i<=m;i++){
		char opt;
		int u,v;
		cin>>opt>>u;
//		cout<<opt<<' '<<u<<' ';
		if(opt=='T'){
			col[u]=1;
			from[u]=u;
			ch[u]=1;
		}
		else if(opt=='F'){
			col[u]=2;
			from[u]=u;
			ch[u]=1;
		}
		else if(opt=='U'){
			col[u]=3;
			from[u]=u;
			ch[u]=1;
		}
		else if(opt=='+'){
			cin>>v;
//			cout<<v;
			from[u]=from[v];
			ch[u]=ch[v];
		}
		else{
			cin>>v;
//			cout<<v;
			from[u]=from[v];
			ch[u]=(ch[v]==0 ? 1 : 0);
		}
//		cout<<endl;
	}
	return;
}

int change(int x,int ch){
	if(ch==1)
		return x;
	if(x==1) return 2;
	if(x==2) return 1;
	return 3;
}

void bfs(int st){
	while(!q.empty()) q.pop();
	q.push(st);
	bool flag=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		cout<<"u = "<<u<<endl;
		for(auto edge:e[u]){
			int v=edge.v;
			int ch=edge.ch;
			int temp=change(col[u],ch);
			if(col[v]==0){
				col[v]=temp;
				q.push(v);
			}
			else if(col[v]!=temp){
				flag=1;
				break;
			}
		}
	}
	
	if(flag==1){
//		cout<<"fffff"<<endl;
		while(!q2.empty()) q2.pop();
		q2.push(st);
		while(!q2.empty()){
			int u=q2.front();
			q2.pop();
			col[u]=3;
//			cout<<"u = "<<u<<endl;
			for(auto edge:e[u]){
				int v=edge.v;
				int ch=edge.ch;
				if(used[v]==1) continue;
				q2.push(v);
				used[v]=1;
			}
		}
	}
	return;
}

void solve(){
	for(int i=1;i<=n;i++){
//		cout<<"from "<<i<<" = "<<from[i]<<endl;
		if(from[i]==-1) continue;
		e[i].push_back({from[i],ch[i]});
		e[from[i]].push_back({i,ch[i]});
	}
	for(int i=1;i<=n;i++){
		if(col[i]!=0){
			bfs(i);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(col[i]==0){
			col[i]=1;
			bfs(i);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
//		cout<<"col "<<i<<" = "<<col[i]<<endl;
		if(col[i]==3) cnt++;
	}
	cout<<cnt<<"\n";
	return;
}

signed main(){
	
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int C,T;
	cin>>C>>T;
	while(T--){
		init();
		solve();
	}
	
	return 0;
}
