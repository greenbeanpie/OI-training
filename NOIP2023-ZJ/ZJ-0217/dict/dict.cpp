#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
//bool al1;
int n,m,Tong[N][28],ans[N];
char sc[N];
struct node{
	int minn[N<<2][28];
	void Gmin(int *f,int a[],int b[]){
		int flag=0;
		for(int i=26;i>=1;i--){
			if(a[i]>b[i]){flag=2;break;}
			if(a[i]<b[i]){flag=1;break;}
		}
		if(flag==2)for(int i=1;i<=26;i++)f[i]=b[i];
		else for(int i=1;i<=26;i++)f[i]=a[i];
		return;
	}
	void build(int u,int l,int r){
		if(l==r){for(int i=1;i<=26;i++)minn[u][i]=Tong[l][i];return;}
		int mid=(l+r)>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		Gmin(minn[u],minn[u<<1],minn[u<<1|1]);
		return;
	}
	void solve(int u,int l,int r,int m[]){
		if(l==r){
//			if(l==4){
//				for(int i=1;i<=26;i++)cout<<m[i]<<" ";cout<<endl;
//				for(int i=1;i<=26;i++)cout<<Tong[l][i]<<" ";cout<<endl;
//			}
			
			
			int tmp[28];
			for(int i=1;i<=26;i++)tmp[i]=Tong[l][i];
			int i=1,j=26;
			while(1){
				while(i<=26 && tmp[i]==0)i++;
				while(j>=1 && m[j]==0)j--;
				if(i>26 || j<1)break;
				if(i<j){ans[l]=1;break;}
				if(i>j){ans[l]=0;break;}
				if(i==j){
					int t=min(tmp[i],m[j]);
					tmp[i]-=t;
					m[j]-=t;
				}
			}
			return;
		}
		int mid=(l+r)>>1,tmp[28];
		Gmin(tmp,m,minn[u<<1|1]);solve(u<<1,l,mid,tmp);
		Gmin(tmp,m,minn[u<<1]);  solve(u<<1|1,mid+1,r,tmp);
		return;
	}
}T;
//bool al2;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
//	cerr<<(&al1-&al2)/1024.0/1024.0;
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",sc+1);
		for(int j=1;j<=m;j++)Tong[i][sc[j]-'a'+1]++;
	}
	T.build(1,1,n);
	int tmp[28];
	for(int i=1;i<=26;i++)tmp[i]=3010;
	T.solve(1,1,n,tmp);
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}
//consider::n=1