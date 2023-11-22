#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x7fffffff
const int N(1e5+5);
int n,m,C;
int a[N];
void solve1(){
	cin>>n>>m;
	memset(a,-1,sizeof a);
	int x,y,z;char ch[10];
	for(int i=1;i<=m;++i){
		cin>>ch>>x;
		if(ch[0]=='+') {cin>>y;z=4;}
		else if(ch[0]=='-'){cin>>y;z=3;}
		else if(ch[0]=='U'){z=2;}
		else if(ch[0]=='T'){z=1;}
		else if(ch[0]=='F'){z=0;}
		if(z<3){
			a[x]=z;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]==2) ++ans;
	}
	cout<<ans<<endl;
}
void solve2(){
	cin>>n>>m;
	memset(a,-1,sizeof a);
	int x,y,z;char ch[10];
	for(int i=1;i<=m;++i){
		cin>>ch>>x;
		if(ch[0]=='+') {cin>>y;z=4;}
		else if(ch[0]=='-'){cin>>y;z=3;}
		else if(ch[0]=='U'){z=2;}
		else if(ch[0]=='T'){z=1;}
		else if(ch[0]=='F'){z=0;}
		if(z<3){
			a[x]=z;
		}
		if(z==4){
			a[x]=a[y];
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]==2) ++ans;
	}
	cout<<ans<<endl;
}
struct op{
	int x,y,z;
}c[N];
int b[N],tnn[10],ans;
bool cp(){
	for(int i=1;i<=n;++i) b[i]=a[i];
	for(int i=1;i<=m;++i){
		if(c[i].z==4){
			b[c[i].x]=b[c[i].y];
		}
		else if(c[i].z==3){
			b[c[i].x]=tnn[b[c[i].y]];
		}
		else b[c[i].x]=c[i].z;
	}
	for(int i=1;i<=n;++i) if(a[i]!=b[i]) return 0;
	return 1; 
}
void dfs1(int now,int res){
	if(res>=ans) return ;
	if(now==n+1) {
		if(cp()) ans=res;
		return ;
	}
	a[now]=0;
	dfs1(now+1,res);
	a[now]=1;
	dfs1(now+1,res);
	a[now]=2;
	dfs1(now+1,res+1);
}
void solve3(){
	ans=n;
	cin>>n>>m;
	memset(a,-1,sizeof a);
	int x,y,z;char ch[10];
	for(int i=1;i<=m;++i){
		cin>>ch>>x;y=0;
		if(ch[0]=='+') {cin>>y;z=4;}
		else if(ch[0]=='-'){cin>>y;z=3;}
		else if(ch[0]=='U'){z=2;}
		else if(ch[0]=='T'){z=1;}
		else if(ch[0]=='F'){z=0;}
		c[i].x=x,c[i].y=y,c[i].z=z;
	}
	dfs1(1,0);
	cout<<ans<<endl;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;cin>>C>>T;
	tnn[0]=1,tnn[1]=0,tnn[2]=2;
	while(T--) {
		if(C<=2||n<=15) {solve3();continue;}
		if(C<=4) {solve1();continue;}
		if(C<=6) {solve2();continue;}
		cout<<0<<endl;
	}
}