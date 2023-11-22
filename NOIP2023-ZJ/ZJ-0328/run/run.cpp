#include <bits/stdc++.h>
#define int long long 
using namespace std;
/*
所有吃饭按x为第一关键字，y为第二关键字排序
从前往后dp
设f[i][j]表示到了第i个吃饭点最早是从j开始跑的方案数
可以做1~7,10,11,A
注意到B性质也很好做
其实可以再拼一个n<=1000，这个直接暴力做就行了
这样是60分
*/
const int N=1005,M=1e5+5,K=105;
int ID,T;
int f[N][N],g[M][K],h[M][2],o[M][2];
int cf[N][N];
int n,m,k,d;
struct node{
	int x,y,v;
	bool operator<(const node &T)const{
		return x==T.x?y>T.y:x<T.x;
	}
}a[M];
vector<int> vec[N];
inline void solvebf(void){
	/*
	设f[i][j]表示到第i个点当前已经连续跑了j天的最优答案
	*/
	cin>>n>>m>>k>>d;
	for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)cf[i][j]=0;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].v,cf[a[i].x][a[i].y]+=a[i].v;
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++)f[i][0]=max(f[i][0],f[i-1][j]);
		for(int j=1;j<=k;j++)f[i][j]=f[i-1][j-1]-d;
		int sum=0;
		for(int j=0;j<=k;j++)sum+=cf[i][j],f[i][j]+=sum;
	}
	int ans=0;
	for(int i=0;i<=k;i++)ans=max(ans,f[n][i]);
	cout<<ans<<"\n";
}
inline void solveA(void){
	/*
	考虑使用g数组
	因为k很小，所以设g[i][j]表示到第i个得分点，已经跑了j天了，的方案数
	不一定是对的，样例太水了
	*/
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].v;
	sort(a+1,a+m+1);
	memset(g,-0x3f,sizeof g);
	g[0][0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=min(k,a[i-1].x);j++)g[i][0]=max(g[i][0],g[i-1][j]);//不跑步
		for(int j=0;j<=min(k,a[i].x);j++){
			if(a[i].x-a[i-1].x<=j){
				g[i][j]=g[i-1][j-(a[i].x-a[i-1].x)]-(a[i].x-a[i-1].x)*d;
				if(a[i].x-a[i-1].x<=j-1 and (i>=2 and a[i-1].x-a[i-2].x>j-(a[i].x-a[i-1].x)))g[i][j]=max(g[i][j],g[i][j-1]-d);
				// if(j>=a[i].y)g[i][j]+=a[i].v;
			}
			else if(j)g[i][j]=g[i][0]-j*d;
		}
		// if(a[i].y==0)g[i][0]+=a[i].v;
		// for(int j=1;j<=min(k,a[i].x);j++)g[i][j]=max(g[i][j],g[i][j-1]-d);
		for(int j=a[i].y;j<=min(k,a[i].x);j++)g[i][j]+=a[i].v;
	}
	int ans=0;
	for(int i=0;i<=min(k,a[m].x);i++)ans=max(ans,g[m][i]);
	cout<<ans<<"\n";
}
int gbg[N];//表示第i个点如果要达成最少要到的点
inline void solveM(void){
	/*
	设f[i][j]表示到了第i个吃饭点最早是从j开始跑(即j也是要算跑的)的最优答案
	o[i][0/1]表示第i个点没跑/跑了的最大价值
	*/
	cin>>n>>m>>k>>d;
	memset(gbg,0,sizeof gbg);
	memset(f,-0x3f,sizeof f);
	memset(o,0,sizeof o);
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].v;
	sort(a+1,a+m+1);
	o[0][0]=o[0][1]=0;
	// a[0].x=-1;
	for(int i=1;i<=m;i++){
		int nw=i-1;
		while(nw and a[i].x-a[i].y+1<=a[nw].x+1)nw--;
		gbg[i]=nw;
		o[i][0]=max(o[i-1][0],o[i-1][1]);
		o[i][1]=o[i][0];
		int lst=gbg[i];
		int cstl=a[i].x-a[i].y;
		int val=0;
		for(int j=i;j>=1;j--){
			lst=min(lst,gbg[j]);
			cstl=min(cstl,a[j].x-a[j].y);
			val+=a[j].v;
			if(a[i].x-cstl>k)break;
			// if(i==2)cout<<lst<<"  -  "<<j<<" "<<cstl<<" "<<a[i].x<<"\n";
			f[i][j]=o[lst][1]-(a[i].x-cstl)*d+val;
			o[i][1]=max(o[i][1],f[i][j]);
		}
		// cout<<o[i][0]<<" "<<o[i][1]<<"\n";
	}
	cout<<max(o[m][0],o[m][1])<<"\n";
}
inline void solveB(void){
	/*
	算是最好写的一个
	直接计算h[i][0/1]表示第i个点是否选择的最大答案
	真的好写吗
	他这个应该是要
	完了
	*/
	cin>>n>>m>>k>>d;
	memset(h,-0x3f,sizeof h);
	int ans=0;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].v;
	// sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		if(a[i].y<=k)
			ans+=max(0ll,a[i].v-a[i].y*d);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	cin>>ID>>T;
	while(T--){
		if(ID<=9)solvebf();
		else if(ID==10 or ID==11)solveM();
		else if(ID==15 or ID==16)solveA();
		else if(ID==17 or ID==18)solveB();
		else cout<<"0\n";
	}
}
/*
1 1
100 2 2 1
4 1 100
6 2 100
*/