#include<bits/stdc++.h>
using namespace std;

int c,n,m,q;
int a[2100],b[2100],aa[2100],bb[2100];
bool f[2100][2100];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		aa[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		bb[i]=b[i];
	}
	for(int qq=0;qq<=q;qq++){
		for(int i=1;i<=n;i++)aa[i]=a[i];
		for(int i=1;i<=m;i++)bb[i]=b[i];
		if(qq){
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++){
				int p,v;
				scanf("%d%d",&p,&v);
				aa[p]=v;
			}
			for(int i=1;i<=ky;i++){
				int p,v;
				scanf("%d%d",&p,&v);
				bb[p]=v;
			}
		}
		int ans=0;
		memset(f,false,sizeof(f));
		f[0][1]=f[1][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(aa[i]>bb[j]){
					f[i][j]=f[i-1][j]||f[i][j-1];
				}
			}
		}
		if(f[n][m])ans=1;
		memset(f,false,sizeof(f));
		f[0][1]=f[1][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(aa[i]<bb[j]){
					f[i][j]=f[i-1][j]||f[i][j-1];
				}
			}
		}
		if(f[n][m])ans=1;
		printf("%d",ans);
	}
}
