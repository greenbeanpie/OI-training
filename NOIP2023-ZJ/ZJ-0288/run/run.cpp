#include<bits/stdc++.h>
using namespace std;
int c,t,ans,cnt;
int n,m,k,d;
int rn[20];
struct node{
	int x,y,v;
}clg[101];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0,cnt=0;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>clg[i].x>>clg[i].y>>clg[i].v;
		}
		for(int i=0;i<(1<<n);i++){
			cnt=0;
			for(int j=1;j<=n;j++){
				rn[j]=(i>>(j-1))&1;
			}
			for(int j=1;j<=n;j++){
				rn[j]+=rn[j-1];
			}
			bool flg=0;
			for(int j=1;j<=n-k;j++){
				if(rn[j+k]-rn[j-1]>k)flg=1;
			}
			if(flg)continue;
			cnt-=rn[n]*d;
			for(int j=1;j<=m;j++){
				if(rn[clg[j].x]-rn[clg[j].x-clg[j].y]==clg[j].y)
					cnt+=clg[j].v;
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
3 3
3 2 2 1
2 2 4
3 2 3
3 2 2 1
2 2 4
3 2 3
3 2 2 1
2 2 4
3 2 3
*/
