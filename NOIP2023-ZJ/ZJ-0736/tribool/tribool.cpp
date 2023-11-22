#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int e,t,n,m;
struct edge{
	char op;
	int x;
	int y;
}b[N];
int a[N];
int c[N];
int ans;
bool check(){
	for(int i=1;i<=n;i++){
		c[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		char q=b[i].op;
		if(q=='+'){
			int x1=b[i].x;
			int x2=b[i].y;
			a[x1]=a[x2];
		}
		if(q=='-'){
			int x1=b[i].x;
			int x2=b[i].y;
			a[x1]=(-1*a[x2]);
		}
		if(q=='U'){
			int x1=b[i].x;
			a[x1]=0;
		}
		if(q=='T'){
			int x1=b[i].x;
			a[x1]=1;
		}
		if(q=='F'){
			int x1=b[i].x;
			a[x1]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=c[i]){
			return false;
		}
	}
	return true;
}
void dfs(int idx,int sum){
	if(idx==n){
		if(check()==true){
			ans=min(sum,ans);
		}
		return;
	}
	if(sum>ans)return;
	for(int i=-1;i<=1;i++){
		if(i==0){
			a[idx+1]=0;
			dfs(idx+1,sum+1);
		}
		else{
			a[idx+1]=i;
			dfs(idx+1,sum);
		}
	}
	
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout)
	cin.tie(0);
	cin>>e>>t;
	for(int ii=1;ii<=t;ii++){
		ans=1e7+7;
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			b[i].op=0;
			b[i].x=0;
			b[i].y=0;
		}
		for(int i=1;i<=m;i++){
			char q;
			cin>>q;
			if(q=='+' || q=='-'){
				b[i].op=q;
				cin>>b[i].x>>b[i].y;
			}
			else{
				b[i].op=q;
				cin>>b[i].x;
			}
			}
		dfs(0,0);
		cout<<ans<<endl;	
		}
		return 0;
	}
