#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+5;
int tid,n,m,ans;
struct node{
	int opt,x,y;
}a[N];
int b[N],c[N];
bool check(){
//	if(b[1]==1&&b[2]==2&&b[3]==1)
//		for(int i=1; i<=m; i++) cout<<a[i].opt<<endl;
	for(int i=1; i<=n; i++) c[i]=b[i];
	for(int i=1; i<=m; i++){
//		if(b[1]==1&&b[2]==2&&b[3]==1){
//			for(int j=1; j<=n; j++) cout<<c[j]<<' ';
//			cout<<endl<<"-------------------"<<endl;
//			cout<<a[i].opt<<' '<<a[i].x<<' '<<a[i].y<<endl;
//		}
		if(a[i].opt==1) c[a[i].x]=a[i].y;
		else if(a[i].opt==2) c[a[i].x]=c[a[i].y];
		else if(a[i].opt==3){
			if(c[a[i].y]==1) c[a[i].x]=2;
			else if(c[a[i].y]==2) c[a[i].x]=1;
			else c[a[i].x]=3;
		}
	}
	for(int i=1; i<=n; i++)
		if(c[i]!=b[i]) return 0;
	return 1;
}
void dfs(int x,int s){
	if(x>n){
		if(check()){
			ans=min(s,ans);
//			for(int i=1; i<=n; i++) cout<<b[i]<<' ';
//			cout<<endl;
//			cout<<"--->"<<s<<endl;
		}
//		for(int i=1; i<=n; i++) cout<<b[i]<<' ';
//		cout<<"-->"<<s<<endl;
		return ;
	}
	for(int i=1; i<=3; i++){
		b[x]=i;
		dfs(x+1,s+(i==3));
	}
}
void solve(){
	n=read(),m=read(),ans=n;
	for(int i=1; i<=m; i++){
		string s;
		cin>>s;
		if(s=="T"){
			a[i].opt=1;
			a[i].x=read();
			a[i].y=1;
		}else if(s=="F"){
			a[i].opt=1;
			a[i].x=read();
			a[i].y=2;
		}else if(s=="U"){
			a[i].opt=1;
			a[i].x=read();
			a[i].y=3;
		}else if(s=="+"){
			a[i].opt=2;
			a[i].x=read();
			a[i].y=read();
		}else{
			a[i].opt=3;
			a[i].x=read();
			a[i].y=read();
		}
	}
	dfs(1,0);
	printf("%d\n",ans);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	tid=read();
	int T=read();
	while(T--) solve();
}
