#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,res[100005],ans=1000000000,tmp[100005];
struct  Node{
	char op;
	int x,y;
}a[100005];
inline int opp(int x){
	return x==-1?-1:(!x);
}
void dfs(int x,int cnt){
	if(cnt>=ans) return;
	if(x==n+1){
		bool flag=true;
		for(int i=1;i<=n;i++){
			tmp[i]=res[i];
		}
		for(int i=1;i<=m;i++){
			if(a[i].op=='+'){
				tmp[a[i].x]=tmp[a[i].y];
			}else if(a[i].op=='-'){
				tmp[a[i].x]=opp(tmp[a[i].y]);
			}else if(a[i].op=='T'){
				tmp[a[i].x]=1;
			}else if(a[i].op=='F'){
				tmp[a[i].x]=0;
			}else{
				tmp[a[i].x]=-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(tmp[i]!=res[i]){
				flag=false;
				break;
			}
		}
		if(flag) ans=cnt;
		return;
	}
	for(int i=1;i>=-1;i--){
		res[x]=i;
		dfs(x+1,cnt+(i==-1));
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		memset(res,0,sizeof(res));
		memset(tmp,0,sizeof(tmp));
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i].op;
			if(a[i].op=='+'||a[i].op=='-'){
				cin>>a[i].x>>a[i].y;
			}else{
				cin>>a[i].x;
			}
		}	
		if(c<=2){
			ans=1000000000;
			dfs(1,0);
			cout<<ans<<'\n';			
		}else if(c<=4){
			ans=0;
			for(int i=1;i<=m;i++){
				if(a[i].op=='T'||a[i].op=='F') res[a[i].x]=0;
				else if(a[i].op=='U') res[a[i].x]=1;
			}
			for(int i=1;i<=n;i++){
				if(res[i]==1) ans++;
			}
			cout<<ans<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	cout.flush();
	return 0;
}