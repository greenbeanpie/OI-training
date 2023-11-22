#include<bits/stdc++.h>
using namespace std;
struct opt{
	char op;
	int x,y;
}a[100005];
int c,T,n,m,x[105],minn=1e9,g[100005];
bool check(){
	int s[105];
	for(int i=1;i<=n;i++){
		s[i]=x[i];
	}
	for(int i=1;i<=m;i++){
		if(a[i].op=='U'){
			s[a[i].x]=1;
		}else if(a[i].op=='T'){
			s[a[i].x]=2;
		}else if(a[i].op=='F'){
			s[a[i].x]=3;
		}else if(a[i].op=='+'){
			s[a[i].x]=s[a[i].y];
		}else if(a[i].op=='-'){
			if(s[a[i].y]==1) s[a[i].x]=1;
			else if(s[a[i].y]==2) s[a[i].x]=3;
			else if(s[a[i].y]==3) s[a[i].x]=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]!=x[i]) return false;
	}
	return true;
}
int get(){
	int tot=0;
	for(int i=1;i<=n;i++){
		if(x[i]==1) tot++;
	}
	return tot;
}
void dfs(int st){
	if(st==n+1){
		if(check()){
			minn=min(minn,get());
		}
		return;
	}
	for(int i=1;i<=3;i++){
		x[st]=i;
		dfs(st+1);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i].op;
			if(a[i].op=='T'||a[i].op=='F'||a[i].op=='U'){
				cin>>a[i].x;
			}else{
				cin>>a[i].x>>a[i].y;
			}
		}
		if(n<=11){///!!!!!!!!!!!!!!!
			dfs(1);
			cout<<minn<<endl;
			minn=1e9;
		}
		else{
			memset(g,0,sizeof(g));
			for(int i=1;i<=m;i++){
				if(a[i].op=='U'){
					g[a[i].x]=1;
				}else if(a[i].op=='T'){
					g[a[i].x]=2;
				}else if(a[i].op=='F'){
					g[a[i].x]=3;
				}
			}
			int tot=0;
			for(int i=1;i<=n;i++){
				if(g[i]==1) tot++;
			}
			cout<<tot<<endl;
		}
	}
	
	return 0;
}//9:26  9:40 40pts
