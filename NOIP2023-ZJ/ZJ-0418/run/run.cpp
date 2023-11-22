#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=1e5+10;
ll c,t;
ll n,m,kmax,d;
struct Task{
	ll x,y,v;
}tasks[maxm];
map <ll,ll> dp[maxm];
// dp[i][j] 表示完成了第i个任务
// 并且在第i个任务的截止日期前连续跑步了j天
// 的最大能量值 
map <ll,bool> has_value[maxm];
bool cmp(Task x,Task y){
	if(x.x!=y.x){
		return x.x<y.x;
	}else{
		return x.y<y.y;
	}
}
void getmax(ll i,ll j,ll y){ // dp[i][j]
	if(has_value[i][j]){
		dp[i][j]=max(dp[i][j],y);
	}else{
		dp[i][j]=y;
		has_value[i][j]=true;
	}
//	cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=LONG_MIN;
		cin>>n>>m>>kmax>>d;
		for(int i=1;i<=m;i++){
			cin>>tasks[i].x>>tasks[i].y>>tasks[i].v;
			dp[i].clear();
			has_value[i].clear();
		}
		sort(tasks+1,tasks+1+m,cmp);
		for(int i=1;i<=m;i++){ // 看到第i个任务 
			for(int k=1;k<i;k++){ // 上一次运动为k 
				for(auto c:dp[k]){ // 上一次运动前连续天数和能量 
					if(tasks[k].x>=tasks[i].x-tasks[i].y){
						// 说明两段运动连在一起了
						if(tasks[k].x-tasks[k].y+1<tasks[i].x-tasks[i].y+1){
							// 不是包含关系 
							ll con_days=c.first+tasks[i].x-tasks[k].x; // 持续天数 
							if(con_days<=kmax){
								// 没有超出连续天数限制
//								cout<<"[DEBUG1]";
								getmax(i,con_days,c.second-d*(tasks[i].x-tasks[k].x)+tasks[i].v);
//								cout<<"; "<<d*(tasks[i].x-tasks[k].x)<<" "<<tasks[i].v<<endl;
								ans=max(ans,dp[i][con_days]);
							} 
						}else{
							// 两段运动是包含关系
							 if(tasks[i].y<=kmax){
								// 没有超出连续天数限制 
//								cout<<"[DEBUG4]";
								getmax(i,tasks[i].y,c.second-d*(tasks[i].y-tasks[k].y)+tasks[i].v);
								ans=max(ans,dp[i][tasks[i].y]);
							} 
						}
					}else{
						// 如果没有连在一起
						if(tasks[i].y<=kmax){
							// 没有超出连续天数限制 
//							cout<<"[DEBUG2]";
							getmax(i,tasks[i].y,c.second-d*tasks[i].y+tasks[i].v);
							ans=max(ans,dp[i][tasks[i].y]);
						} 
					}
				}
			}
			// 如果不想有上一次运动，以这次运动为开始
			if(tasks[i].y<=kmax){
//				cout<<"[DEBUG3]";
				getmax(i,tasks[i].y,tasks[i].v-d*tasks[i].y);
				ans=max(ans,dp[i][tasks[i].y]);
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}
