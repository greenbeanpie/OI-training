#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+7;

int C, T, n, m, cnt, ing[MAXN], head[MAXN];
struct edge{
	int v, nxt; bool f;
}e[MAXN];

namespace subtack1{
	int a[15], b[15];
	int opt[15], v[15], t[15], ans=20;
	
	int cl(int &lhs, int opt, int rhs)
	{	
		if(opt==0) return lhs=rhs;
		if(opt==1) return lhs=(rhs==3?3:3-rhs);
		return lhs=opt-1;
	}
	
	void dfs(int now, int cnt)
	{
		if(now==n+1){
			for(int i=1; i<=n; ++i)
				b[i]=a[i];
			for(int i=1; i<=m; i++)
				cl(b[v[i]], opt[i], b[t[i]]);
			for(int i=1; i<=n; i++)
				if(a[i]!=b[i]) return;
			ans=min(ans, cnt);
			return;
		}
		a[now]=1, dfs(now+1, cnt);
		a[now]=2, dfs(now+1, cnt);
		a[now]=3, dfs(now+1, cnt+1);
	}
	
	void main()
	{
		ans=20, memset(a, 0, sizeof a);
		for(int i=1; i<=m; ++i){
			char c;
			cin>>c;
			if(c=='+' || c=='-'){
				cin>>v[i]>>t[i];
				opt[i]=(c=='-');
			}
			else{
				cin>>v[i];
				opt[i]=(c=='T'?2:(c=='F'?3:4));
			}
		}
		dfs(1, 0);
		cout<<ans<<endl;
	}
}

namespace subtack2{
	void main(){
		int ans=0, v[2], t[2];
		for(int i=1; i<=m; ++i){
			char c;
			scanf("%c", &c);
			if(c=='+' || c=='-'){
				scanf("%d%d", v, t);
			}
			else{
				scanf("%d", v);
			}
			if(c=='U') ++ans;
		}
		cout<<ans<<endl;
	}
}

namespace subtack3{
	const int MAXN=1e5+7;

	int n, m, tot, head[MAXN<<1], f[MAXN<<1], bel[MAXN<<1], ans;
	int a[MAXN<<1], son[MAXN<<1], vis[MAXN<<1];
	vector<int> s[MAXN];
	bool flag;

	int read();
	void init(int, int, bool);

	void clear()
	{
		for(int i=1; i<=n; i++) s[i].clear();
		for(int i=1; i<=tot; i++) son[i]=vis[i]=a[i]=head[i]=f[i]=bel[i]=0;
		cnt=ans=0;
	}

	void dfs(int now, int pre, int root)
	{
		int be=bel[now];
		son[now]=(now==root || be!=root &&
			!s[be].empty() && s[be][s[be].size()-1]==now);
		for(int i=head[now]; i; i=e[i].nxt)
			if(e[i].v!=pre){
				int v=e[i].v, r=bel[v];
				if(e[i].f) f[v]=3-f[now];
				else f[v]=f[now];
				if(s[r][s[r].size()-1]==v)
					if(f[v]!=f[r] && vis[r]==root) flag=1;
				vis[v]=root, dfs(v, now, root), son[now]+=son[v];
			}
	}

	void cl(int now, int pre){
	}

	void run()
	{
		clear();
		tot=n=read(), m=read();
		for(int i=1; i<=n; i++) bel[i]=i;
		for(int i=1; i<=m; i++){
			char c;
			scanf("%c", &c);
			if(c=='+' || c=='-'){
				int t=read(), v=read();
				v=(s[v].empty()?v:s[v][s[v].size()-1]);
				s[t].emplace_back(++tot), init(v, tot, c=='-');
				bel[tot]=t;
			}
			else {
				int t=read();
				if(c=='T') a[t]=1;
				else if(c=='F') a[t]=2;
				else a[t]=3;
			}
		}
	
		for(int i=1; i<=n; i++){
			flag=0, f[i]=1, vis[i]=i, dfs(i, -1, i);
			if(flag==1) cl(i, -1), ans+=son[i];
		}
		int tmp=0;
		for(int i=1; i<=n; i++) tmp+=son[i];
		cout<<ans<<endl;
	}

	signed main()
	{
		while(T--) run();
		return 0;
	}

	int read(){
		int x=0; bool f=0; char c;
		while(!isdigit(c=getchar())) if(c=='-') f=1;
		do x=x*10+c-48; while(isdigit(c=getchar()));
		return f?-x:x;
	}

	void init(int u, int v, bool f){
		e[++cnt]={v, head[u], f}, head[u]=cnt;
	}
}

signed main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin>>C>>T;
	if(C==7 || C==8){
		subtack3::main();
		return 0;
	}
	while(T--){
		cin>>n>>m;
		if(C==1 || C==2) subtack1::main();
		if(C==3 || C==4) subtack2::main();
	}
	return 0;
}