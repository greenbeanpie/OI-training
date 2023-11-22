#include<bits/stdc++.h>
using namespace std;
long long c,T,ans;
long long n,m,x,y;
char opt[5];
long long flag[100010],vis[100010];
struct node {
	long long op,x,y;
} work[100010];
long long num[100010],che[100010];
vector<long long>v[100010];
long long check(int sum) {
	for(long long i=1; i<=n; i++) che[i]=num[i];
	long long res=0;
	for(long long i=1; i<=m; i++) {
		if(work[i].op==1) che[work[i].x]=1;
		if(work[i].op==2) che[work[i].x]=2;
		if(work[i].op==3) che[work[i].x]=3;
		if(work[i].op==4) {
//			if(num[1]==1&&num[2]==1&&num[3]==3&&num[4]==2&&num[5]==3&&num[6]==2&&num[7]==3&&num[8]==1&&num[9]==1&&num[10]==1) cout<<i<<":"<<che[work[i].x]<<" "<<che[work[i].y]<<endl;
			if(che[work[i].y]==1) che[work[i].x]=2;
			else if(che[work[i].y]==2) che[work[i].x]=1;
			else if(che[work[i].y]==3) che[work[i].x]=3;
//			if(num[1]==1&&num[2]==1&&num[3]==3&&num[4]==2&&num[5]==3&&num[6]==2&&num[7]==3&&num[8]==1&&num[9]==1&&num[10]==1) cout<<i<<":"<<che[work[i].x]<<" "<<che[work[i].y]<<endl;
		}
		if(work[i].op==5) che[work[i].x]=che[work[i].y];
	}
//	for(int i=1; i<=n; i++) cout<<num[i]<<" ";
//	cout<<endl;
//	for(int i=1; i<=n; i++) cout<<che[i]<<" ";
//	cout<<endl;
	for(long long i=1; i<=n; i++) if(che[i]!=num[i]) return 0;
	return 1;
}
void dfs(long long step,long long sum) {
	if(step==n+1) {
//		cout<<step<<" "<<sum<<endl;
		if(check(sum)) {
			ans=min(ans,sum);
//			if(sum==3) {
//				for(int i=1; i<=n; i++) cout<<num[i]<<" ";
//				cout<<endl;
//				for(int i=1; i<=n; i++) cout<<che[i]<<" ";
//				cout<<endl<<endl;
//			}
		}
		return ;
	}
	for(long long i=1; i<=3; i++) {
		num[step]=i;
		if(i!=3) dfs(step+1,sum);
		else dfs(step+1,sum+1);
		num[step]=0;
	}
}
void dfs2(long long step,long long num) {
	vis[step]=1;
	flag[step]=num;
	for(long long i=0; i<v[step].size(); i++) {
		long long nxt=v[step][i];
		if(!vis[nxt]) dfs2(nxt,num);
	}
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	if(c!=5&&c!=6) {
		while(T--) {
			ans=1e8;
			scanf("%lld%lld",&n,&m);
			for(long long i=1; i<=n; i++) num[i]=0;
			for(long long i=1; i<=m; i++) {
				scanf("%s",opt);
				if(opt[0]=='T') {
					scanf("%lld",&x);
					work[i].op=1;
					work[i].x=x;
				}
				if(opt[0]=='F') {
					scanf("%lld",&x);
					work[i].op=2;
					work[i].x=x;
				}
				if(opt[0]=='U') {
					scanf("%lld",&x);
					work[i].op=3;
					work[i].x=x;
				}
				if(opt[0]=='-') {
					scanf("%lld%lld",&x,&y);
					work[i].op=4;
					work[i].x=x;
					work[i].y=y;
				}
				if(opt[0]=='+') {
					scanf("%lld%lld",&x,&y);
					work[i].op=5;
					work[i].x=x;
					work[i].y=y;
				}
			}
			dfs(1,0);
			printf("%lld\n",ans);
		}
	} else {
		while(T--) {
			ans=0;
			scanf("%lld%lld",&n,&m);
			for(long long i=1; i<=n; i++) {
				flag[i]=0;
				v[i].clear();
				vis[i]=0;
			}
			for(long long i=1; i<=m; i++) {
				scanf("%s",opt);
				if(opt[0]=='U') {
					scanf("%lld",&x);
					flag[x]=1;
				}
				if(opt[0]=='+') {
					scanf("%lld%lld",&x,&y);
					flag[x]=flag[y];
					v[y].push_back(x);
				}
			}
			for(long long i=1; i<=n; i++) {
				if(flag[i]==1&&vis[i]==0) dfs2(i,1);
			}
			for(long long i=1; i<=n; i++) {
				ans+=flag[i];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
-O2 -std=c++14 -static
*/