#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,x[100005],y[100005],a[100005],b[100005],ans;
char v[100005];
void dfs(long long s){
	if(s==n+1){
		long long sum=0;
		bool f=1;
		for(int i=1;i<=n;i++){
			y[i]=x[i];
			if(x[i]==2){
				sum++;
			}
		}
		for(int i=1;i<=n;i++){
			if(v[i]=='T'){
				y[a[i]]=1;
			}
			else if(v[i]=='F'){
				y[a[i]]=0;
			}
			else if(v[i]=='U'){
				y[a[i]]=2;
			}
			else if(v[i]=='+'){
				y[a[i]]=y[b[i]];
			}
			else if(v[i]=='-'){
				if(y[b[i]]==0){
					y[a[i]]=1;
				}
				else if(y[b[i]]==1){
					y[a[i]]=0;
				}
				else if(y[b[i]]==2){
					y[a[i]]=2;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(x[i]!=y[i]){
				f=0;
				break;
			}
		}
		if(f==1&&ans>sum){
			ans=sum;
		}
		return;
	}
	x[s]=0;
	dfs(s+1);
	x[s]=1;
	dfs(s+1);
	x[s]=2;
	dfs(s+1);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>v[i];
			if(v[i]=='+'||v[i]=='-'){
				cin>>a[i]>>b[i];
			}
			else{
				cin>>a[i];
			}
		}
		ans=1e11;
		dfs(1);
		cout<<ans<<endl;
	}
}