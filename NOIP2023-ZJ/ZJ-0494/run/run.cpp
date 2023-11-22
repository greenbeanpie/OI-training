#include<bits/stdc++.h>
using namespace std;
#define re register
#define inl inline
#define rep(i,l,r) for(re int i=l;i<=r;i++)
#define N 1000000009
int ans=-INT_MAX;
int c,t;
int n,m,k,d;
struct node{
	int x,y,v;
}a[100004];
int dp[100005];
bool cmp(node X,node Y){
	return X.x<Y.x;
}
unordered_map<int,int> mp; 
unordered_map<int,int> lim;
unordered_map<int,int> reward;
template <typename T> inl T read(){
	T ret=0;bool p=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') p=0;c=getchar();}
	while(isdigit(c)){ret=(ret<<3)+(ret<<1)+(c-'0');c=getchar();}
	if(p) return ret;
	else return ~(ret-1);
}
template <typename T> inl void write(T x){
	static int sta[50];int top=0;
	if(x<0){putchar('-');x=~(x-1);}
	while(x){sta[++top]=x%10;x/=10;}
	if(top==0) sta[++top]=0;
	while(top){putchar(sta[top--]+'0');}
	putchar('\n');
	return;
}
void init(){
	mp.clear();reward.clear();lim.clear();
	n=read<int>();m=read<int>();k=read<int>();d=read<int>();
	rep(i,1,m){
		a[i].x=read<int>();a[i].y=read<int>();a[i].v=read<int>();
		mp[a[i].x]=1;
		lim[a[i].x]=a[i].y;
		reward[a[i].x]=a[i].v;
	}
	sort(a+1,a+m+1,cmp);
}
int con[100005];
void dpw(){
	dp[1]=max(0,a[1].x>=a[1].y ? a[1].v-d*a[1].y : 0);
	if(dp[1]==0) con[1]=0;
	else con[1]=a[1].y;
	for(re int i=2;i<=n;i++){
		if(a[i].x-a[i-1].x<a[i].y+1){
			if(con[i-1]+a[i].x-a[i-1].x<=k){
				if(dp[i-1]<dp[i-1]-d*(a[i].x-a[i-1].x)+a[i].v){
					con[i]=con[i-1]+a[i].x-a[i-1].x;
					dp[i]=dp[i-1]-d*(a[i].x-a[i-1].x)+a[i].v;
				}
			}
		}
		else{
			if(a[i].y<=k){
				dp[i]=max(dp[i-1],dp[i-1]-d*a[i].y+a[i].v);
				if(dp[i]>dp[i-1]){
					con[i]=a[i].y;
				}
			}
		}
	}
}
void dfs(int day,int ener,int conti){
	if(day==n){ans=max(ans,ener);return;}
	if(mp[day]==1&&conti>=lim[day]){
		if(conti+1<=k) dfs(day+1,ener+reward[day]-d,conti+1);
		dfs(day+1,ener+reward[day],0);
	}
	else{
		if(conti+1<=k) dfs(day+1,ener-d,conti+1);
		dfs(day+1,ener,0);
	}
}
void fre(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}
int main(){
	//fre();
	c=read<int>();t=read<int>();
	while(t--){
		ans=-INT_MAX;
		init();
		dfs(1,-d,1);dfs(1,0,0);
		//dpw();
		write(dp[m]);
	}
	return 0;
}