#include<bits/stdc++.h>
using namespace std;

template<class T>inline void read(T&x){
	char last=' ',c;
	while(!isdigit(c=getchar()))last=c;
	x=c^48;
	while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+(c^48);
	if(last=='-')x=-x;
}

#define i64 long long

const int MAXN=1e3+7,MAXM=1e5+7,MAXK2=1e2+7;
int n,m,k,d;

i64 dp[MAXN][MAXN];
i64 val[MAXN][MAXN];

void solve_dp(){
	for(int i=1;i<=n;++i){
		for(int j=0;j<=k;++j){
			dp[i][j]=-1e18;
			val[i][j]=0;
		}
	}
	for(int x,y,v;m--;){
		read(x),read(y),read(v);
		val[x][y]+=v;
	}
	for(int i=1;i<=n;++i){
		i64 s=0;
		for(int j=1;j<=min(i,k);++j){
			s+=val[i][j];
			dp[i][j]=dp[i-1][j-1]-d+s;
		}
		for(int j=0;j<=min(i-1,k);++j)dp[i][0]=max(dp[i][0],dp[i-1][j]);
	}
	i64 ans=-1e18;
	for(int j=0;j<=k;++j)ans=max(ans,dp[n][j]);
	cout<<ans<<'\n';
}

i64 dp2[MAXM][MAXK2];
i64 val2[MAXM][MAXK2];
int x2[MAXM],y2[MAXM],v2[MAXM];
vector<int>S;

void init_dp2(){
	sort(S.begin(),S.end());
	S.erase(unique(S.begin(),S.end()),S.end());
}

int getid_dp2(int x){
	return lower_bound(S.begin(),S.end(),x)-S.begin();
}

void solve_dp2(){
	vector<int>().swap(S);
	for(int i=1,x,y,v;i<=m;++i){
		read(x2[i]),read(y2[i]),read(v2[i]);
		S.push_back(x2[i]);
	}
	init_dp2();
	int t=S.size();
	for(int i=0;i<t;++i){
		for(int j=0;j<=k;++j){
			dp2[i][j]=-1e18;
			val2[i][j]=0;
		}
	}
	for(int i=1;i<=m;++i){
		x2[i]=getid_dp2(x2[i]);
		if(y2[i]<=k)val2[x2[i]][y2[i]]+=v2[i];
	}
	for(int i=0;i<t;++i){
		i64 s=0;
		if(i==0){
			dp2[i][0]=0;
			for(int j=1;j<=min(S[i],k);++j){
				s+=val2[i][j];
				dp2[i][j]=s-j*d;
			}
		}
		else{
			for(int j=0;j<=min(S[i-1],k);++j)dp2[i][0]=max(dp2[i][0],dp2[i-1][j]);
			for(int j=1;j<=min(S[i],k);++j){
				s+=val2[i][j];
				if(S[i-1]+j<S[i])dp2[i][j]=dp2[i][0]-j*d+s;
				else dp2[i][j]=dp2[i-1][j-(S[i]-S[i-1])]-(S[i]-S[i-1])*d+s;
			}
		}
	}
	i64 ans=-1e18;
	for(int j=0;j<=k;++j)ans=max(ans,dp2[t-1][j]);
	cout<<ans<<'\n';
}

void solve_greedy(){
	i64 ans=0;
	for(int x,y,v;m--;){
		read(x),read(y),read(v);
		ans+=max(0ll,v-1ll*y*d);
	}
	cout<<ans<<'\n';
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int Id,T;read(Id),read(T);
	while(T--){
		read(n),read(m),read(k),read(d);
		if(Id<=9)solve_dp();
		if(Id>=15&&Id<=16)solve_dp2();
		if(Id>=17&&Id<=18)solve_greedy();
	}
	return 0;
}
