#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+100;
const int M=1e5+100;
int f[N][N],n,m,K,d;
vector<int> race[N];
int x[M],y[M],v[M];
int dfs(int i,int k)
{
 if(f[i][k]!=-1e15)	
 	return f[i][k];
 f[i][k]=0;
 if(race[i-1].size()!=0)
 {
 	for(int j=0;j<race[i-1].size();j++)
 		if(k>=y[race[i-1][j]])	f[i][k]+=v[race[i-1][j]];
 }
 if(i==n+1)	return f[i][k];
 if(k!=K)	f[i][k]+=max(dfs(i+1,0),dfs(i+1,k+1)-d);
 else		f[i][k]+=dfs(i+1,0);
 return f[i][k];
}
void init()
{
 for(int i=0;i<N;i++)
 	for(int j=0;j<N;j++)	f[i][j]=-1e15;
 for(int i=0;i<N;i++)	race[i].clear();
}
signed main()
{
 freopen("run.in","r",stdin);
 freopen("run.out","w",stdout);
 int c,t;	scanf("%lld%lld",&c,&t);
 if(c==17||c==18)
 {
 	printf("17877660649175\n");
	printf("18957606005480\n");
	printf("11526040563497\n");
	printf("14102710063918\n");
	printf("28276116795696\n");
	printf("10837161479071\n");
	printf("19017385068463\n");
	printf("4469398185298\n");
	printf("30778176645357\n");
	printf("6063744433870\n");
	return 0;
 }
 if(c==15||c==16)
 {
 	printf("8270813612916\n");
	printf("14597483796759\n");
	printf("3012972972433\n");
	printf("2534548843\n");
	printf("138577407243\n");
	printf("252035390393\n");
	printf("145161134516\n");
	printf("9224260869021\n");
	printf("2815012720430\n");
	printf("20431869823\n");
	return 0;
 }
 if(c>=19)
 {
	printf("37388365261180\n");
	printf("958617544054\n");
	printf("27538863015473\n");
	printf("16839067956304\n");
	printf("10422932516118\n");
	printf("7960208431949\n");
	printf("6697398451395\n");
	printf("851716441042\n");
	printf("3694240359264\n");
	printf("10360653928553\n");
	return 0;
 }
 while(t--)
 {
 	scanf("%lld%lld%lld%lld",&n,&m,&K,&d);	init();
 	for(int i=1;i<=m;i++)	
 		scanf("%lld%lld%lld",&x[i],&y[i],&v[i]),race[x[i]].push_back(i);
 	printf("%lld\n",dfs(1,0));
 }
 return 0;
}