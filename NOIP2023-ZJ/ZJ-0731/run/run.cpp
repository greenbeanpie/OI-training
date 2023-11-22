#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int M=100005;
int c,T,n,m,lim,d,eng,cnt,res;
struct clg{
	int x,y,v;
}p[M];
void IO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
bool cmp(clg x,clg y){
	return x.x<y.x;
}
void dfs(int now,int k,int ans){
	//     今天    连续   能量 
	if(now>=n){
		res=max(res,ans);
		return;
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		if(now<p[i].x)	break;
		if(now==p[i].x && k>=p[i].y)
			sum+=p[i].v;
	}
//	cout<<now<<' '<<k<<' '<<sum<<' '<<ans<<endl;
	if(k<lim){
		dfs(now+1,k+1,ans-d+sum);	
		dfs(now+1,0,ans+sum);
	}
	if(k==lim)	dfs(now+1,0,ans+sum);
}
signed main(){
	IO("run");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		cnt=0;	res=0;
		cin>>n>>m>>lim>>d;
		for(int i=1;i<=m;i++)
			cin>>p[i].x>>p[i].y>>p[i].v;
		sort(p+1,p+m+1,cmp);
		dfs(0,0,0);
		cout<<res<<endl;
	}
	return 0;
}
//就到此为止吧。AFO。 
