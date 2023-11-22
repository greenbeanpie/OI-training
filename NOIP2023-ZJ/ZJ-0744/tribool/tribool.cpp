#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int v[MAXN],c,t,n,m,ans;
bool f[MAXN],vis[MAXN],ab[MAXN];
char w;
int query(int from,int a,int r){
	int next = a;
	if(v[r] < 0) next = -next;
	vis[r] = true;
	if(abs(v[r]) == r || vis[abs(v[r])]) return v[r];
	else if(abs(v[r]) == from){
		if(abs(v[r]) == from){
			if(next == ab[abs(v[r])]){
				return MAXN -1;
			}
			else{
				return MAXN - 2;
			}
		}
	}
	else{
		ab[r] = a;
		return v[r] = query(from,next,v[r]);
	} 
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans = 0;
		scanf("%d%d",&n,&m);
		if(c == 3 || c == 4){
			for(int i = 1;i <= n;i++){
				f[i] = false;
			}
			while(m--){
				int id;
				scanf("\n%c%d",&w,&id);
				if(w == 'T') f[id] = false;
				else if(w == 'U') f[id] = true;
				else if(w == 'F') f[id] = false;
			}
			for(int i = 1;i <= n;i++){
				if(f[i]) ans++;
			}
		}
		else{
			for(int i = 1;i <= n;i++){
				v[i] = i;
				f[i] = false;
				vis[i] = false;
				ab[i] = 5 ;
			}
			while(m--){
				scanf("\n%c",&w);
				int id,to;
				scanf("%d",&id);
				if(w == 'T'){f[id] = false;v[id] = id;}
				else if(w == 'U'){f[id] = true;v[id] = id;}
				else if(w == 'F'){f[id] = false;v[id] = id;}
				else{
					scanf("%d",&to);
					if(w == '+'){v[id] = v[to];}
					if(w == '-') {v[id] = -v[to];}
				}
			}
			f[MAXN - 1] = false;
			f[MAXN - 2] = true;
			for(int i = 1;i <= n;i++){
				if(vis[i] || abs(v[i]) == i) continue;
				query(i,1,i);
			}
			for(int i = 1;i <= n;i++){
				if(v[i] == -i){
					f[i] = true;
				}
			}
			for(int i = 1;i <= n;i++){
				if(f[v[i]]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}