#include<bits/stdc++.h>
using namespace std;
void fileIO(){
	const string probname="tribool";
	const string suff_in ="in";
	const string suff_out="out";
	const string file_in =probname+"."+suff_in;
	const string file_out=probname+"."+suff_out;
	freopen(file_in.c_str(),"r",stdin);
	freopen(file_out.c_str(),"w",stdout);
}
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
int head[200010],to[200010],nxt[200010];
bool reversed[200010];
bool sign[100010],vis[100010];
int id[100010],c,T,n,m,cnt;
char valset[100010];
vector<vector<int>>v;
void addedge(int from,int to_,bool re){
	nxt[++cnt]=head[from];
	head[from]=cnt;
	to[cnt]=to_;
	reversed[cnt]=re;
}
inline char reverse_c(char x){
	if (x=='T') return 'F';
	if (x=='F') return 'T';
	if (x=='U') return 'U';
	assert(false);
}
vector<int>search(int p){
	vector<int>k;
	queue<int>q;
	q.push(p);
	while (!q.empty()){
		int now=q.front();q.pop();
		if (vis[now]) continue;
		vis[now]=true;
		k.emplace_back(now);
		for (int i=head[now];i;i=nxt[i]){
			q.push(to[i]);
		}
	}
	return k;
}
bool chk(int st){
	queue<pair<int,char>>q;
	q.push(make_pair(st,'F'));
	while (!q.empty()){
		pair<int,char> now=q.front();q.pop();
//		cout<<"dxbt "<<now.first<<" "<<now.second<<endl;
		valset[now.first]=now.second;
		for (int i=head[now.first];i;i=nxt[i]){
			int uu=now.first,vv=to[i];
			char newc=(reversed[i]? reverse_c(valset[uu]):valset[uu]);
			if (valset[vv]){
				if (valset[vv]!=newc){
//					cout<<"DXBT "<<vv<<endl;
					return false;
				}
			}
			else q.push(make_pair(vv,newc));
		}
	}
	return true;
}
int main(){
	fileIO();fastIO();
	cin>>c>>T;
	while (T--){
		cin>>n>>m;cnt=0;v.clear();
		memset(valset,0,sizeof(valset));
		memset(sign,0,sizeof(sign));
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++) id[i]=i;
		while (m--){
			static char op;
			static int x,y;
			cin>>op;
			if (op=='+' || op=='-') cin>>x>>y;
			else cin>>x;
			if (op=='+'){
				if (!valset[y]){
					id[x]=id[y];
					sign[x]=sign[y];
					valset[x]=0;
				}
				else{
					id[x]=sign[x]=0;
					valset[x]=valset[y];
				}
			}
			else if (op=='-'){
				if (!valset[y]){
					id[x]=id[y];
					sign[x]=!sign[y];
					valset[x]=0;
				}
				else{
					id[x]=sign[x]=0;
					valset[x]=reverse_c(valset[y]);
				}
			}
			else valset[x]=op;
		}
		for (int i=1;i<=n;i++){
			if (!valset[i]){
				if (sign[i] || i!=id[i]){
					addedge(i,id[i],sign[i]);
					addedge(id[i],i,sign[i]);
				}
			}
		}
		for (int i=1;i<=n;i++){
			if (!vis[i]) v.emplace_back(search(i));
		}
		int ans=0;
		for (vector<int>i:v){
			bool flag=true;
			char val;
			for (int j:i){
				if (valset[j]){
					val=valset[j];
					flag=false;
					break;
				}
			}
			if (flag){
				/*
				* If no value is set, then try to
				* set them to either 'F' or 'T'.
				*
				* If failed, add them to the total ans.
				*
				* Only passing one argument is okay
				* 'cause a start point can only match
				* one connected block.
				*/
				if (!chk(i[0])) ans+=i.size();
			}
			else if (val=='U') ans+=i.size();
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
