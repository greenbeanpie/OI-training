#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=75;
int a[maxn];
//int f[maxn][maxn][151];
int ans[maxn];
int b[11],vis[11];
void dfs(int tot){
	if(tot>=ans[m]) return;
	bool flag=1;
	for(int i=1;i<=m;++i){
		if(b[i]<a[i]){
			flag=0;
			break;
		}
	}	
	if(flag){
		ans[m]=tot;
		return;
	}
	int cb[11],cvis[11];
	memcpy(cb,b,sizeof b);
	memcpy(cvis,vis,sizeof vis);
	for(int i=1;i<=m;++i){
		if(b[i]<a[i]){
			for(int j=1;j<=5;++j){
				b[i]+=j;
				for(int k=i;k<=m;++k){
					if(!vis[k]&&b[k]>=a[k]){
						vis[k]=1;
						int p=k+1;
						for(p=k+1;p<=m&&vis[p];++p);
						b[p]+=b[k]/2;
					}
				}
				dfs(tot+j);			
				memcpy(b,cb,sizeof b);
				memcpy(vis,cvis,sizeof vis);	
			}
		}
	}
}
int main(){
	freopen("qidong.in","r",stdin);
	freopen("qidong.out","w",stdout);
	memset(ans,63,sizeof ans);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	if(n>10){// a[i]=1,2
		int tot=0,cur=0;
		for(int i=1;i<=n;++i){
			if(cur<a[i]) tot+=a[i]-cur,cur=a[i];
			cur>>=1;
			printf("%d ",tot);
		}
		return 0;
	}
	for(m=1;m<=n;++m){
		dfs(0);
		printf("%d ",ans[m]);
	}
//	memset(f,0xfe,sizeof f);
//	for(int i=1;i<=n;++i){
//		for(int j=a[j];j<=150;++j){
//			f[i][i][j]=j/2;
//		}
//	}
//	for(int L=2;L<=n;++L){
//		for(int i=1;i+L-1<=n;++i){
//			int j=i+L-1;
//			for(int k=0;k<=150;++k){
//				int tmp=f[i][j-1][k];
//				for(int l=0;l<=150;++l)
//				if(tmp+l>=a[j]){
//					f[i][j][k]=min(f[i][j][k],(tmp+l)/2); 
//				}
//				tmp=f[i][i][k];
//				if()
//			}
//		}
//	}
}
/*
2
10 3
*/
