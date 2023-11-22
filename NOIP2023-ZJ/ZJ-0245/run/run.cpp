//I would appreciate it if CCF cound give me 1=
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0),cout.tie(0)
#define pb push_back
#define int long long
using namespace std;
int c,T,n,m,k,d,ans;
struct node{
	int x,y,v;
}b[200005];
void solve(){
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++) cin>>b[i].x>>b[i].y>>b[i].v;
	ans=0;
	if(c<=2){
		for(int i=0;i<(1<<n);i++){
			int res=0;
			int now=0,fl=1;
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1)){
					res-=d;
					now++;
					if(now>k) fl=0;
				}
				else now=0;
			}
			if((!fl)||(now>k)) continue;
			for(int j=1;j<=m;j++){
				bool ok=1;
				for(int z=b[j].x-b[j].y+1;z<=b[j].x;z++){
					if(!(i&(1<<z-1))){
						ok=0;
						break;
					}
				}
				if(ok) res+=b[j].v;
			}
			ans=max(ans,res);
		}
		cout<<ans<<endl;
	}
	else{
		int now_all=0,lst=0;
		for(int i=1;i<=m;i++){
			if(b[i].y>k||b[i].v<b[i].y*d) continue;
			if(b[i].x-b[i].y+1>lst+1) now_all=0;
			if(now_all+b[i].y>k) continue;
			now_all+=b[i].y;
			ans+=b[i].v-b[i].y*d;
			lst=b[i].x;
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	IOS;TIE;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

