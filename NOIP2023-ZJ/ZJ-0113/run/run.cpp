#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char ch=getchar();
	int x=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int M=1e5+10;
const int N=1e3+10;
const int INF=1e18;
int n,m,k,d,f[N][N],maxn[N],sump[M];
struct Task{
	int x,y,v;
	friend bool operator<(Task a,Task b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
}task[M];
int calc(int x,int len){
	int l=1,r=m,L=m+1,R=0,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(task[mid].x>=x)L=mid,r=mid-1;
		else l=mid+1;
	}
	if(task[L].x!=x)return 0;
	l=1,r=m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(task[mid].x<=x)R=mid,l=mid+1;
		else r=mid-1;
	}
	if(task[R].x!=x)return 0;
	int st=L-1;
	while(L<=R){
		int mid=(L+R)>>1;
		if(task[mid].y<=len)res=mid,L=mid+1;
		else R=mid-1;
	}
	if(res>st)return sump[res]-sump[st];
	else return 0;
}
#define endl '\n'
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		n=read(),m=read(),k=read(),d=read();
		for(int i=1;i<=m;i++)
			task[i].x=read(),task[i].y=read(),task[i].v=read();
		sort(task+1,task+m+1);
		for(int i=1;i<=m;i++)sump[i]=sump[i-1]+task[i].v;
		for(int i=1;i<=n;i++){
			maxn[i]=f[i][0]=-INF;
			for(int j=1;j<=min(i,k);j++)
				f[i][j]=f[i-1][j-1]-d+calc(i,j);
			for(int j=0;j<i;j++)
				f[i][0]=max(f[i][0],maxn[j]);
			for(int j=0;j<=min(i,k);j++)maxn[i]=max(maxn[i],f[i][j]);
		}
		cout<<maxn[n]<<endl;
	}
	return 0;
}
