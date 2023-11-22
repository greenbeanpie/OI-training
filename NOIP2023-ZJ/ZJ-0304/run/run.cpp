#include <bits/stdc++.h>
using namespace std;

struct node{
	long long x,y,v;
};

long long n,m,k,d;
node a[100010];
bool opt[100010];
long long ans=0;

long long cnt(){
	long long lx=0;
	long long pnt=0;
	for(int i=1;i<=n;i++){
		if(opt[i]==1){
			lx++;
			pnt-=d;
		}else{
			lx=0;
		}
		if(lx>k){
			return -1;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=a[i].x-a[i].y+1;j<=a[i].x;j++){
			if(opt[j]==0){
				break;
			}
			if(j==a[i].x){
				pnt+=a[i].v;
			}
		}
	}
	return pnt;
}

void dfs(int nw){
	if(nw==n+1){
		ans=max(ans,cnt());
		return;
	}
	opt[nw]=0;
	dfs(nw+1);
	opt[nw]=1;
	dfs(nw+1);
	opt[nw]=0;
}

int main(){
	//freopen and long long!!!!
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> m >> k >> d;
		for(int i=0;i<m;i++){
			cin >> a[i].x >> a[i].y >> a[i].v;
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}