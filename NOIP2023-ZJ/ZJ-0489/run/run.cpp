#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define int long long
const int MAXN=1e3+50;
int n,m,k,d;
int c,t;
int dp[MAXN][MAXN];
int ans[MAXN];
struct node{
	int x,y,v;//l=x-y+1 r=x;
}chan[MAXN];
int cnt=0;
bool cmp(node a,node b){
	if(a.x==b.x) return (a.x-a.y+1)<(b.x-b.y+1);
	return a.x<b.x;
}
void print(){
	for(int i=1;i<=n;++i){
		for(int j=0;j<=k;++j){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	scanf("%d %d",&c,&t);
//	if(c<=7){
	int x,y,v;
	while(t--){
		memset(dp,0,sizeof(dp));
		cnt=0;
		scanf("%d %d %d %d",&n,&m,&k,&d);
		for(int i=1;i<=m;++i){
			scanf("%d %d %d",&x,&y,&v);
			if(y<=k)
				chan[++cnt]=(node){x,y,v};
		}
		sort(chan+1,chan+1+cnt,cmp);
		dp[1][0]=0;
		dp[1][chan[1].y]=chan[1].v-chan[1].y*d;
		ans[1]=chan[1].v-chan[1].y*d;
		for(int i=1;i<chan[i].y;++i)
			dp[1][i]=-i*d;
		int as=ans[1];
		for(int i=2;i<=cnt;++i){
			for(int j=1;j<i;++j){
				if(chan[j].x<chan[i].x-chan[i].y+1){
					dp[i][0]=max(ans[j],dp[i][0]);
					dp[i][chan[i].y]=max(ans[j]+chan[i].v-chan[i].y*d,dp[i][chan[i].y]);
					for(int h=1;h<chan[i].y;++h)
						dp[i][chan[i].y]=max(dp[i][chan[i].y],ans[j]+chan[i].v-chan[i].y*d);
					ans[i]=max(dp[i][0],dp[i][chan[i].y]);
				}else{
					dp[i][0]=max(dp[j][0],dp[i][0]);
					dp[i][chan[i].y]=max(dp[j][0]+chan[i].v-chan[i].y*d , dp[i][chan[i].y]);
					ans[i]=max(dp[i][0],dp[i][chan[i].y]);
					for(int h=1;h<chan[i].y;++h){
						dp[i][chan[i].y]=max(dp[i][chan[i].y] , dp[j][0]+chan[i].v-chan[i].y*d);
						ans[i]=max(ans[i],dp[i][chan[i].y]);
					}
					
					for(int h=1;((chan[i].x)-(chan[j].x-h+1))<=k;++h){
						dp[i][(chan[i].x-chan[j].x+h+1)]=max( dp[i][((chan[i].x)-(chan[j].x-h+1))] , dp[j][h]+chan[i].v-(chan[i].x-chan[j].x)*d);
						ans[i]=max(ans[i],dp[i][((chan[i].x)-(chan[j].x-h+1))]);
					}
				}
			}
			as=max(ans[i],as);
		}
//		print();
		printf("%d\n",as);
		
	}
//	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/