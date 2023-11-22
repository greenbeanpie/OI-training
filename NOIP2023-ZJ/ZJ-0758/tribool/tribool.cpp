#include<bits/stdc++.h>
using namespace std;
struct ho{
	char o;
	int x,y;
};
const int N=1e5+10;
int i,j,m,n,c,t,x,y,a[N],ans=2147483647;
char o;
vector<ho>v;
void solve2(){
	while(t--){
		ans=2147483647;
		cin>>n>>m;
		for(i=1;i<=n;i++) a[i]=2;
		for(i=1;i<=m;i++){
			cin>>o;
			if(o=='+'){
				cin>>x>>y;
				a[x]=a[y];
			}
			else if(o=='U'){
				cin>>x;
				a[x]=0;
			}
		}
		for(i=1;i<=n;i++) if(a[i]==0) ans++;
		cout<<ans<<endl;
	}
}
void solve1(){
	while(t--){
		ans=2147483647;
		cin>>n>>m;
		for(i=1;i<=n;i++) a[i]=2;
		for(i=1;i<=m;i++){
			cin>>o;
			if(o=='T'){
				cin>>x;
				a[x]=1;
			}
			else if(o=='F'){
				cin>>x;
				a[x]=-1;
			}
			else if(o=='U'){
				cin>>x;
				a[x]=0;
			}
		}
		for(i=1;i<=n;i++) if(a[i]==0) ans++;
		cout<<ans<<endl;
	}
}
void dfs(int x){
//	printf("%d\n",x);
	
//	cout<<endl;
	if(x==n+1){
//		puts("yes");
		for(auto i:v){
			if(i.o=='+'){
				if(a[i.x]!=a[i.y]) return;
			}
			else {
				if(a[i.x]!=-a[i.y]) return;
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
//		}
		
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) sum++;
		}
//		cout<<sum<<endl;
		ans=min(ans,sum);
		return;
	}
	if(a[x]!=2){
		dfs(x+1);
		return;
	} 
	for(int i=-1;i<=1;i++){
		a[x]=i;
		dfs(x+1);
		a[x]=2;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	if(c==3 or c==4){
		solve1();
		return 0;
	}
	if(c==5 or c==6){
		solve2();
		return 0;
	}
	while(t--){
		ans=2147483647;
		cin>>n>>m;
		for(i=1;i<=n;i++) a[i]=2;
		for(i=1;i<=m;i++){
			cin>>o;
			if(o=='T'){
				cin>>x;
				a[x]=1;
			}
			else if(o=='F'){
				cin>>x;
				a[x]=-1;
			}
			else if(o=='U'){
				cin>>x;
				a[x]=0;
			}
			else if(o=='+'){
				cin>>x>>y;
				v.push_back({'+',x,y});
			}
			else{
				cin>>x>>y;
				v.push_back({'-',x,y});
			}
		}
//		for(i=1;i<=n;i++) cout<<a[i]<<" ";
		dfs(1);
		cout<<ans<<endl;
//		puts("next");
		v.clear();
	}
	return 0;
}

