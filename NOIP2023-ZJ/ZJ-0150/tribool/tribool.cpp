#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0; bool f=1; char c=getchar();
	while(c<48||c>57) f^=(c==45), c=getchar();
	while(c>=48&&c<=57) x=x*10+(c^48), c=getchar();
	return (f?x:-x);
}
int n, ans, siz;
pair<int, bool> w[100105];
vector<pair<int, bool> > e[100105];
bitset<100105> p, f;
queue<pair<int, bool> > q;
struct dsu{
	int f[500105], s[500105];
	void init(){for(int i=1; i<=n; i++) f[i]=i, s[i]=1; }
	int find(int x){return (x==f[x]?x:f[x]=find(f[x])); }
	void merge(int x, int y){
		x=find(x), y=find(y);
		if(x==y) return;
		if(s[x]<s[y]) swap(x, y);
		f[y]=x, s[x]+=s[y];
	}
}s;
bool _dir(int i, bool c){
	if(f[i]) return c; else f[i]=1;
	return _dir(w[i].first, c^w[i].second);
}
int dfs(int i, int j){
	do i=w[i].first, j=w[w[j].first].first; while(i!=j);
	return i;
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	for(int id=read(), _=read(); _; --_){
		n=read(); int m=read(); ans=0, siz=0; s.init();
		for(int i=1; i<=n; i++) w[i]=make_pair(i, 0);
		while(m--){
			char c; cin>>c; int i=read();
			switch(c){
				case 'F': w[i]=make_pair(0, true); break;
				case 'T': w[i]=make_pair(0, false); break;
				case 'U': w[i]=make_pair(-1, false); break;
				case '+': w[i]=w[read()]; break;
				case '-': w[i]=w[read()], w[i].second=!w[i].second; break;
			}
		}
		for(int i=1; i<=n; i++){
			if(w[i].first<=0){
				q.push(make_pair(i, -w[i].first));
				continue;
			}
			if(w[i].first==i){
				q.push(make_pair(i, w[i].second));
				continue;
			}
			e[w[i].first].push_back(make_pair(i, w[i].second));
			s.merge(w[i].first, i);
			p[i]=1;
		}
		while(!q.empty()){
			pair<int, bool> u=q.front();
			p[u.first]=0, q.pop(), ans+=u.second;
			for(auto v : e[u.first])
				q.push(make_pair(v.first, u.second));
		}
		for(int i=1; i<=n; i++, siz=0)
			if(p[i]&&!f[s.find(i)]){
				int x=dfs(i, i);
				if(_dir(x, false)) ans+=s.s[s.find(x)];
			}
		printf("%d\n", ans);
		for(int i=1; i<=n; i++) e[i].clear();
		f.reset();
	}
	return 0;
}