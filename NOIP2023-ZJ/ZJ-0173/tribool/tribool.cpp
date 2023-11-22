#include<bits/stdc++.h>
#define siz(x) int((x).size())
#define all(x) std::begin(x),std::end(x)
#define fi first
#define se second
using namespace std;
using loli=long long;
using pii=pair<int,int>;
constexpr int N=2e5+7;
int C,T,n,m,fa[N];
int impact(int x){
	if(fa[x]==x)return x;
	return fa[x]=impact(fa[x]);
}
void genshin(int x,int y){
	x=impact(x),y=impact(y);
	if(x!=y)fa[y]=x;
}
pii a[N];
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=n;i++)a[i]={i+n,0};
		for(int i=1;i<=2*n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			char c;int x,y;
			cin>>c;
			if(c=='+'){
				cin>>x>>y;
				a[x]=a[y];
			}else if(c=='-'){
				cin>>x>>y;
				a[x]=a[y];
				a[x].se=!a[x].se;
			}else if(c=='T'){
				cin>>x;
				a[x]={0,0};
			}else if(c=='F'){
				cin>>x;
				a[x]={2,0};
			}else if(c=='U'){
				cin>>x;
				a[x]={1,0};
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].fi==1){
				genshin(i,i+n);
			}
			if(a[i].fi>=n){
				int j=a[i].fi-n;
				if(a[i].se==0){
					genshin(i,j);
					genshin(i+n,j+n);
				}else{
					genshin(i,j+n);
					genshin(i+n,j);
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(impact(i)==impact(i+n))
				ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
