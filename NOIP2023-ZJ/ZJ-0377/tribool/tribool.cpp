#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
queue<int>q;
stack<int>st;
bool ins[N];
struct edge{int u,v,w,next;}e[N],e1[N];
int C,T,n,m,i,k,x,y,u,v,w,fir,sec,cnt,cnt1,ans,tot,xx[N],yy[N],rudu[N],b[N],c[N],tmp[N],bel[N],head[N],head1[N],dfn[N],low[N],timer;
char ch,opt[N];
pair<int,int>a[N];
map<pair<int,int>,int>ma;
inline int val(char c){
	if(c=='T') return 0;
	if(c=='F') return 2;
	if(c=='U') return 1;
	return 724703;
}
inline void add0(int u,int v,int w){
	e[++cnt]=(edge){u,v,w,head[u]};
	head[u]=cnt;
}
inline void add(int u,int v,int w){
	e[++cnt]=(edge){u,v,w,head[u]};
	head[u]=cnt;
	ma[make_pair(u,v)]=w;
}
inline void add1(int u,int v,int w){
	e1[++cnt1]=(edge){u,v,w,head1[u]};
	head1[u]=cnt1;
}
void tarjan(int u){
	dfn[u]=low[u]=++timer;
	ins[u]=1;st.push(u);
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		tot++;int x,now=0,sum1=0,sum2=0;
		while(1){
			x=st.top();
			st.pop();
			ins[x]=0;
			tmp[++now]=x;
			bel[x]=tot;
			if(x==u) break;
		}
		for(int i=1;i<now;i++)
			sum1+=ma[make_pair(tmp[i],tmp[i+1])],
			sum2+=ma[make_pair(tmp[i+1],tmp[i])];
		sum1+=ma[make_pair(tmp[now],tmp[1])];
		sum2+=ma[make_pair(tmp[1],tmp[now])];
		sum1=max(sum1,sum2);
		if(sum1&1){
			for(int i=1;i<=now;i++)
				b[tmp[i]]=1;
			c[tot]=1;
		}else{
			int maxx=-1;
			for(int i=1;i<=now;i++)
				maxx=max(maxx,b[tmp[i]]);
			for(int i=1;i<=now;i++) b[tmp[i]]=maxx;
			c[tot]=maxx;
		}
	}
}
bool check(){
	for(int i=1;i<=n;i++) c[i]=b[i];
	for(int i=1;i<=m;i++){
		if(opt[i]=='T'||opt[i]=='F'||opt[i]=='U') c[xx[i]]=val(opt[i]);
		else if(opt[i]=='+') c[xx[i]]=c[yy[i]];
		else if(opt[i]=='-') c[xx[i]]=2-c[yy[i]];
	}
	for(int i=1;i<=n;i++)
		if(b[i]!=c[i]) return 0;
	return 1;
}
void dfs(int now,int res){
	if(now>n){
		if(check())	ans=min(ans,res);
		return;
	}
	b[now]=0;dfs(now+1,res);
	b[now]=1;dfs(now+1,res+1);
	b[now]=2;dfs(now+1,res);
}
signed main(){
	freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>C>>T;
	if(C==1||C==2){
		while(T--){
			cin>>n>>m;ans=0x7fffffff;
			for(i=1;i<=m;i++){
				cin>>opt[i];
				if(opt[i]=='T'||opt[i]=='F'||opt[i]=='U') cin>>xx[i];
				else cin>>xx[i]>>yy[i];
			}
			dfs(1,0);cout<<ans<<'\n';
		}
		return 0;
	}
	if(C==3||C==4){
		while(T--){
			cin>>n>>m;ans=0;
			for(i=1;i<=n;i++) b[i]=0;
			for(i=1;i<=m;i++){
				cin>>ch>>x;
				b[x]=val(ch);
			}
			for(i=1;i<=n;i++) if(b[i]==1) ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
	/*
	if(C==5||C==6){
		while(T--){
			memset(b,0,sizeof(b));
			ans=0;
			cin>>n>>m;
			for(i=1;i<=m;i++){
				cin>>opt[i];
				if(opt[i]=='U'){
					cin>>x;
					b[x]=1;
				}else cin>>xx[i]>>yy[i];
			}
			for(i=1;i<=m;i++)
				if(opt[i]=='+'){
					
					b[xx[i]]=b[yy[i]];
				}
			for(i=1;i<=n;i++) if(b[i]==1) ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
	*/
	if(C==5||C==7||C==9){
		while(T--){
		cin>>n>>m;ans=cnt=0;
		for(i=1;i<=n;i++){
			a[i]=make_pair(0,0);
			b[i]=-1;
			head[i]=0;
		}
		while(m--){
			cin>>ch;
			if(ch=='T'||ch=='F'||ch=='U'){
				cin>>x;
				a[x]=make_pair(3,val(ch));
			}
			if(ch=='+'){
				cin>>x>>y;
				a[x]=make_pair(1,y);
			}
			if(ch=='-'){
				cin>>x>>y;
				a[x]=make_pair(2,y);
			}
			//y -> x
		}
		for(i=1;i<=n;i++){
			fir=a[i].first;
			sec=a[i].second;
			if(fir){
				if(fir==3) b[i]=sec;
				else add0(sec,i,fir-1);
			}
		}
		for(k=1;k<=n;k++){
			q.push(k);
			for(i=1;i<=n;i++) ins[i]=0;
			while(!q.empty()){
				u=q.front();q.pop();ins[u]=0;
				if(b[u]==-1) continue;
				for(i=head[u];i;i=e[i].next){
					v=e[i].v;w=e[i].w;
					if(!ins[v]&&b[v]==-1) ins[v]=1,q.push(v);
					if(w) b[v]=2-b[u];
					else b[v]=b[u];
				}
			}
		}
		for(i=1;i<=n;i++) if(b[i]==1) ans++;
		cout<<ans<<'\n';
		}
		return 0;
	}
	while(T--){
		cin>>n>>m;ans=cnt=cnt1=timer=tot=0;
		ma.clear();
		for(i=1;i<=n;i++){
			a[i]=make_pair(0,0);
			b[i]=-1;
			c[i]=-1;
			head[i]=0;
			head1[i]=0;
			dfn[i]=low[i]=0;
			bel[i]=0;
			rudu[i]=0;
			ins[i]=0;
		}
		while(m--){
			cin>>ch;
			if(ch=='T'||ch=='F'||ch=='U'){
				cin>>x;
				a[x]=make_pair(3,val(ch));
			}
			if(ch=='+'){
				cin>>x>>y;
				a[x]=make_pair(1,y);
			}
			if(ch=='-'){
				cin>>x>>y;
				a[x]=make_pair(2,y);
			}
			//y -> x
		}
		for(i=1;i<=n;i++){
			fir=a[i].first;
			sec=a[i].second;
			if(fir){
				if(fir==3) b[i]=sec;
				else add(sec,i,fir-1);
			}
		}
		for(i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		for(i=1;i<=cnt;i++){
			u=bel[e[i].u];
			v=bel[e[i].v];
			if(u!=v){
				add1(u,v,e[i].w);
				rudu[v]++;
			}
		}
		for(i=1;i<=tot;i++)
			if(!rudu[i]){
				q.push(i);
			}
		while(!q.empty()){
			u=q.front();q.pop();
			for(i=head1[u];i;i=e1[i].next){
				v=e1[i].v;
				if(e1[i].w) c[v]=2-c[u];
				else c[v]=c[u];
				rudu[v]--;
				if(!rudu[v]) q.push(v);
			}
		}
		for(i=1;i<=n;i++)
			if(c[bel[i]]==1)
				b[i]=1;
		for(i=1;i<=n;i++) if(b[i]==1) ans++;
		cout<<ans<<'\n';
		/*
		cout<<"Now:"<<T<<'\n';
		for(i=1;i<=cnt;i++) cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
		*/
	}
	return 0;
}
