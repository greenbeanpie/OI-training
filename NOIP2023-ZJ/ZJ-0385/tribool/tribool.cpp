#include<bits/stdc++.h>
using namespace std; constexpr int maxn(1e5+10),inf(1e9+7);
// ru guo quan shi unknown xian ran cheng li
// jia she yi kai shi dou you zhi
// xian xie bao li
int winc,T;
struct operation{ char op; int x,y; }op[maxn];
namespace subtask1{ int n,m,ori[12],vec[12],ans;
	inline bool check(){
		for(int i=1;i<=n;i++) vec[i]=ori[i];
		for(int i=1;i<=m;i++){
			if(op[i].op=='+') vec[op[i].x]=vec[op[i].y];
			else if(op[i].op=='-') vec[op[i].x]=-vec[op[i].y];
			else if(op[i].op=='T') vec[op[i].x]=1;
			else if(op[i].op=='F') vec[op[i].x]=-1;
			else vec[op[i].x]=0;
		}
		for(int i=1;i<=n;i++)
			if(ori[i]!=vec[i]) return false;
		int res=0;
		for(int i=1;i<=n;i++)
			if(!ori[i]) res++;
		ans=min(ans,res);
		return true;
	}
	inline void dfs(int pos){
		if(pos==n+1){ check(); return; }
		for(int i=-1;i<=1;i++)
			ori[pos]=i,dfs(pos+1),ori[pos]=0;
	}
	inline void solve(){
		cin >> n >> m,ans=inf;
		for(int i=1;i<=m;i++){
			cin >> op[i].op;
			if(op[i].op=='+'||op[i].op=='-')
				cin >> op[i].x >> op[i].y;
			else cin >> op[i].x;
		}
		dfs(1),cout << ans << '\n';
	}
}
namespace subtask2{ int n,m,ori[maxn],ans;
	inline void solve(){
		cin >> n >> m,ans=inf;
		for(int i=1;i<=n;i++) ori[i]=1;
		for(int i=1;i<=m;i++){
			cin >> op[i].op;
			if(op[i].op=='+'||op[i].op=='-')
				cin >> op[i].x >> op[i].y;
			else cin >> op[i].x;
		}
		int res=0;
		for(int i=1;i<=n;i++)
			if(!ori[i]) res++;
//		for(int i=1;i<=n;i++)
//			printf("ori[%d]: %d\n",i,ori[i]);
		cout << res << '\n';
	}
}
namespace subtask3{ int n,m,ans,ori[maxn],nori[maxn];
	inline void solve(){
		cin >> n >> m;
		for(int i=1;i<=n;i++) ori[i]=1,nori[i]=1;
		for(int i=1;i<=m;i++){
			cin >> op[i].op >> op[i].x;
			if(op[i].op=='U') ori[op[i].x]=0;
			else if(op[i].op=='T') ori[op[i].x]=1;
			else if(op[i].op=='F') ori[op[i].x]=-1;
			else if(op[i].op=='-') cin >> op[i].y,ori[op[i].x]=ori[op[i].y];
			else cin >> op[i].y,ori[op[i].x]=ori[op[i].y];
		}
		int res=0;
		for(int i=1;i<=n;i++)
			if(ori[i]!=nori[i]) res++;
		int ans=res;
		for(int i=1;i<=n;i++)
			nori[i]=ori[i];
		while(true){
			for(int i=1;i<=m;i++){
				if(op[i].op=='U') ori[op[i].x]=0;
				else if(op[i].op=='T') ori[op[i].x]=1;
				else if(op[i].op=='F') ori[op[i].x]=-1;
				else if(op[i].op=='-') ori[op[i].x]=-ori[op[i].y];
				else ori[op[i].x]=ori[op[i].y];
			} ans=0;
			for(int i=1;i<=n;i++)
				if(ori[i]!=nori[i]) ans++,ori[i]=0;
			if(ans==res) break;
			res=ans;
			for(int i=1;i<=n;i++)
				nori[i]=ori[i];
		}
		cout << res << '\n';
	}
}
namespace subtask4{
	int n,m,ans,ori[maxn];
	inline void solve(){
		cin >> n >> m;
		for(int i=1;i<=n;i++) ori[i]=1;
		for(int i=1;i<=m;i++){
			cin >> op[i].op >> op[i].x;
			if(op[i].op=='U') ori[op[i].x]=0;
			else cin >> op[i].y,ori[op[i].x]=ori[op[i].y];
		}
		int res=0;
		for(int i=1;i<=n;i++)
			if(!ori[i]) res++;
		int ans=res;
		while(true){
			for(int i=1;i<=m;i++){
				char op=::op[i].op; int x=::op[i].x,y=::op[i].y;
				assert(op=='U'||op=='+');
				if(op=='U') ori[x]=0;
				else ori[x]=ori[y];
			} ans=0;
			for(int i=1;i<=n;i++)
				if(!ori[i]) ans++;
			if(ans==res) break;
			res=ans;
		}
		cout << res << '\n';
	}
}
signed main(){ freopen("tribool.in","r",stdin),freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin >> winc >> T;
	if(winc<=2) while(T--) subtask1::solve();
	else if(winc<=4) while(T--) subtask2::solve();
	else if(winc<=6) while(T--) subtask4::solve();
	else while(T--) subtask3::solve();
	return 0;
}
/*
1 1
5 7
+ 2 3
+ 3 1
+ 5 4
+ 3 3
- 4 2
- 2 2
+ 1 5
*/
/*
1 1
5 7
+ 2 3
+ 3 1
+ 5 4
+ 3 3
- 4 2
- 2 2
+ 1 5
*/
/*
1 1
5 7
+ 2 3
+ 3 1
+ 5 4
+ 3 3
- 4 2
- 2 2
+ 1 5
*/
/*
1 1
5 7
+ 2 3
+ 3 1
+ 5 4
+ 3 3
- 4 2
- 2 2
+ 1 5
*/
/*
1 1
5 7
+ 2 3
+ 3 1
+ 5 4
+ 3 3
- 4 2
- 2 2
+ 1 5
*/
/*
1 1
5 7
+ 2 3
+ 3 1
+ 5 4
+ 3 3
- 4 2
- 2 2
+ 1 5
*/