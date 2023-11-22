#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,t;
int a[100010],zf[100010],ans[100010],cnt,jl[100010];//200001=T,199999=F,200000=U
						//1=+,-1=-
bool vis[100010];
void say(int x){
	cout<<x<<endl;
}
int solve(int now,int from,int jj){
	vis[now]=1;
	jj*=zf[now];
	
	if(ans[now]==200001||ans[now]==200000||ans[now]==199999){
		vis[now]=0;
		return ans[now];
	}
	if(a[now]==200001||a[now]==200000||a[now]==199999){
		ans[now]=a[now];
		if(zf[now]==-1)
		ans[now]=400000-a[now];
		vis[now]=0;
		return ans[now];
	}
	if(vis[a[now]]==1){
		if(jj!=jl[a[now]])
		ans[now]=200000;
		else
		ans[now]=200001;
		vis[now]=0;
		return ans[now];
	}
	jl[a[now]]=jj;
	if(a[now]==now){
		if(zf[now]==-1)
		ans[now]=200000;
		else
		ans[now]=200001;
		vis[now]=0;
		return ans[now];
	}
	
	if(a[now]==from){
		if(jj==-1){
			ans[now]=200000;
			vis[now]=0;
			return ans[now];
		}
		else{
			ans[from]=200001;
			if(zf[now]==-1)
			ans[now]=400000-ans[from];
			else
			ans[now]=ans[from];
			vis[now]=0;
			return ans[now];
		}
	}
	
	if(zf[now]==-1){
		ans[now]=400000-solve(a[now],from,jj);
	}
	else{
		ans[now]=solve(a[now],from,jj);
	}
	vis[now]=0;
	return ans[now];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			a[i]=i;
			zf[i]=1;
			ans[i]=0;
			vis[i]=0;
		}
		for(int i=1;i<=m;i++){
			char k;
			cin>>k;
			if(k=='U'){
				int x;
				cin>>x;
				a[x]=200000;
			}
			if(k=='T'){
				int x;
				cin>>x;
				a[x]=200001;	
			}
			if(k=='F'){
				int x;
				cin>>x;
				a[x]=199999;	
			}
			if(k=='-'){
				int x,y;
				cin>>x>>y;
				a[x]=a[y];
				zf[x]=zf[y]*(-1);
			}
			if(k=='+'){
				int x,y;
				cin>>x>>y;
				a[x]=a[y];
				zf[x]=zf[y];
			}
		}
		
		cnt=0;
//		for(int i=1;i<=n;i++){
//			cout<<i<<" "<<a[i]<<" "<<zf[i]<<endl;
//		}
		for(int i=1;i<=n;i++){
			int op;
			jl[i]=1;
			if(ans[i]==0){
				op=solve(i,i,1);
			}
//			cout<<ans[i]<<" "<<i<<endl;
			jl[i]=0;
			if(ans[i]==200000){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
