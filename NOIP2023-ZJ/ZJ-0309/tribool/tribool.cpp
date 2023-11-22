#include<bits/stdc++.h>
#define num 2
using namespace std;
int cz[100010];
int size[100010];
int f[100010];
int gx[100010];
int vis[100010];
//vector<int>a[100010];
//vector<int>b[100010];
//bool dfs(int x){
//	size[x]=1;
//	for(int i=0;i<a[x].size();i++){
//		if(size[a[x][i]]==0)
//			dfs(a[x][i]);
//		size[x]+=size[a[x][i]];
//	}
////	cout<<x<<" "<<size[x]<<endl;
//}
//int qwq=0;
//int st[100010];
int find(int x){
//	int lx=x;
//	cout<<qwq<<endl;
//	int len=1;
//	st[len]=x;
//	while(f[st[len]]!=st[len])
//		st[++len]=f[st[len]];
//	for(int i=len-1;i>=1;i--)
//		gx[st[i]]*=gx[st[i+1]],f[st[i]]=st[len];
	if(f[x]!=x){
		int flag=f[x];
//		if(qwq==1)
//			cout<<x<<" "<<f[x]<<endl;
		f[x]=find(f[x]);
		gx[x]*=gx[flag];		
	}
//	if(qwq==1)
//		cout<<gx[x]<<endl;
	return f[x];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			cz[i]=-2,size[i]=1,f[i]=i,vis[i]=1,gx[i]=1;
		//1=true,-1=false,0=unknown,-2=truly unknown
		while(m--){
			char opt;
			cin>>opt;
			if(opt=='+'){
				int x,y;
				scanf("%d%d",&x,&y);
				if(cz[y]==-2)
					cz[x]=num+y;
				else
					cz[x]=cz[y];
			}else if(opt=='-'){
				int x,y;
				scanf("%d%d",&x,&y);
				if(cz[y]==-2)
					cz[x]=-(num+y);
				else
					cz[x]=-cz[y];
			}else if(opt=='T'){
				int x;
				scanf("%d",&x);
				cz[x]=1;
			}else if(opt=='F'){
				int x;
				scanf("%d",&x);
				cz[x]=-1;
			}else{
				int x;
				scanf("%d",&x);
				cz[x]=0;
			}
		}
//		cout<<1;
		for(int i=1;i<=n;i++){
//			cout<<cz[i]<<" ";
			if(cz[i]==0)
				vis[find(i)]=0;
			else{
//				if(cz[i]==-6){
//					qwq=1;
//					cout<<find(abs(cz[i])-2)<<endl;					
//				}
				int fx=find(i),fy=find(abs(cz[i])-2);
//				cout<<fx<<" "<<fy<<endl;
				int gxx;
				if(cz[i]>0)
					gxx=1;
				else
					gxx=-1;
				if(fx==fy){
					if(gx[i]*gx[abs(cz[i])-2]!=gxx)
						vis[fx]=0;
				}else{
					size[fy]+=size[fx];
					f[fx]=fy;
					gx[fx]=gxx*gx[i]*gx[abs(cz[i])-2];
				}
			}
		}
//		cout<<1<<endl;
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			if(abs(cz[i])>=3&&abs(cz[i])-2!=i)
//				a[abs(cz[i])-2].push_back(i);
//		}
//		for(int i=1;i<=n;i++){
//			printf("%d ",cz[i]);
//			if(abs(cz[i])>=3)
//				size[abs(cz[i])-2]++;
//		}
//		printf("\n");
//		for(int i=1;i<=n;i++){
//			if(size[i]==-1)
//				dfs(i);
//		}
		int ans=0;
//		for(int i=1;i<=n;i++){
//			if(cz[i]==1||cz[i]==-1)
//				ans+=size[i];
//			else if(cz[i]==-2)
//				ans+=size[i];
//			else if(cz[i]==num+i)
//				ans+=size[i];
//			cout<<i<<" "<<ans<<endl;
//		}
		for(int i=1;i<=n;i++){
//			cout<<f[i]<<" "<<size[i]<<" "<<vis[i]<<endl;
			if(f[i]==i&&vis[i]==0)
				ans+=size[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}