#include<bits/stdc++.h>
using namespace std;

const int N=800020;

int n, m;
int x[N];
char v[30];
int p,q;
int u;
int rk[N];
int fa[N];
int ans;
int c, t;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void Union(int u, int v){
	int fu=find(u), fv=find(v);
	if(fu==fv)
		return;
	if(rk[fu]<rk[fv])
		swap(fu,fv);
	fa[fv]=fu;
	rk[fu]+=rk[fv];
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	
	cin>>c>>t;
	
	while(t--){
		cin>>n>>m;
		u=(n<<1)+3;
		ans=0;
		for(int i=1; i<=n; ++i){
			x[i]=i<<1;
			fa[i<<1]=i<<1;
			fa[(i<<1)^1]=(i<<1)^1;
			rk[i<<1]=rk[(i<<1)^1]=1;
		}
		fa[0]=0;
		fa[1]=1;
		fa[u]=fa[u^1]=u;
		rk[0]=rk[1]=1;
		rk[u]=2;
		rk[u^1]=1;
		for(int i=1; i<=m; ++i){
			cin>>v;
			switch(v[0]){
				case 'T':{
					cin>>p;
					x[p]=1;
					break;
				}
				case 'F':{
					cin>>p;
					x[p]=0;
					break;
				}
				case 'U':{
					cin>>p;
					x[p]=2*n+3;
					break;
				}
				case '+':{
					cin>>p>>q;
					x[p]=x[q];
					break;
				}
				case '-':{
					cin>>p>>q;
					x[p]=x[q]^1;
					break;
				}
			}
		}
		for(int i=1; i<=n; ++i){
			Union((i<<1), x[i]);
			Union((i<<1)^1, x[i]^1);
		}
		for(int i=1; i<=n; ++i){
			if(find(i<<1)==find(u)||find((i<<1)^1)==find(u))
				Union((i<<1), (i<<1)^1);
			else if(find(i<<1)==find((i<<1)^1))
				Union((i<<1), u);
		}
		for(int i=1; i<=n; ++i)
			if(find(i<<1)==find(u)||find((i<<1)^1)==find(u)||find(i<<1)==find((i<<1)^1))
				ans+=1;
		cout<<ans<<endl;
	}
	
	return 0;
}