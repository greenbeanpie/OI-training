#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll read(){
	ll x=0,sgn=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')sgn*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
	return x*sgn;
}
ll c,t,n,m,u,v,ans,f[N],poi[N],res[N],vis[N],co[N];
char ch;
int dfs(int x,int col){
//	cout<<"*"<<x<<" "<<col<<endl;
	if(res[x]>0)return res[x];
	if(vis[x]==1){
		//cout<<"lllllllllll"<<endl;
		if(co[x]==col){
		//	cout<<res[x]<<" ";
		//	cout<<"FFFFF"<<endl;
			res[x]=1;return res[x];
			
		}else{
		//	cout<<res[x]<<" ";
		//	cout<<"PPPPPPP"<<endl;
			res[x]=3;return res[x];
			
		}
	}
	vis[x]=1;co[x]=col;
	int tmp;
	if(f[x]==0){
		tmp=dfs(poi[x],col);
	}else{
		tmp=dfs(poi[x],1-col);
	}
	if(tmp==3){
		res[x]=3;
		return 3;
	}
	else{
		if(f[x]==0){
			res[x]=tmp;
			return tmp;
		}
		else{
			res[x]=3-tmp;
			return 3-tmp;
		} 
	}
}
//ll pans[10],cnt;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();m=read();
		for(int i=1;i<=n;i++)poi[i]=i,f[i]=0,res[i]=0,vis[i]=0,co[i]=0;
		ans=0;
		poi[n+1]=n+1;poi[n+2]=n+2;poi[n+3]=n+3;//TFU
		for(int i=1;i<=m;i++){
			cin>>ch;
			if(ch=='+'){
				u=read();v=read();
				poi[u]=poi[v];
				f[u]=f[v];
			}else if(ch=='-'){
				u=read();v=read();
				poi[u]=poi[v];
				f[u]=1-f[v];
			}else if(ch=='T'){
				u=read();
				poi[u]=poi[n+1];
				f[u]=0;
			}else if(ch=='F'){
				u=read();
				poi[u]=poi[n+2];
				f[u]=0;
			}else if(ch=='U'){
				u=read();
				poi[u]=poi[n+3];
				f[u]=0;
			}else {
				cout<<"-----------";
			}
		}
		for(int i=1;i<=n;i++){
			if(poi[i]==i){
				if(f[i]==0)res[i]=1;
				else res[i]=3;
			}else if(poi[i]>n)res[i]=poi[i]-n;
		}
		//cout<<"=========="<<endl;
		for(int i=1;i<=n;i++){
			if(res[i]==0){
				res[i]=dfs(i,0);
			}
			if(res[i]==3)ans++;
			//cout<<res[i]<<" ";
			
		}//cout<<endl;
		cout<<ans<<endl;
		//pans[++cnt]=ans;
	}
	//for(int i=1;i<=cnt;i++)cout<<pans[i]<<" ";
	return 0;
}
//T#YMS@4
//1 1
//10 10
//- 9 8
//- 8 6
//- 6 5
//- 5 4
//- 4 3
//+ 3 9
//- 1 2
//+ 2 7
//+ 7 10
//- 10 1
