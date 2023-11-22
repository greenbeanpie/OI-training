#include<bits/stdc++.h>
using namespace std;
const int MS=3e3+5;
int n,m;
int maxx[MS],minn[MS];
char c[MS];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		maxx[i]=-1;
		minn[i]=1e3;
		scanf("%s",c+1);
		for(int j=1;j<=m;j++){
//			while(~scanf("%c",&c)&&(c<'a'||c>'z'));
			int x=int(c[j]);
			maxx[i]=max(maxx[i],x);
			minn[i]=min(minn[i],x);
		}
	}
	for(int i=1;i<=n;i++){
		int ans=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(maxx[j]<=minn[i]){
				ans=0;
				break;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
//伟大的CCF保佑我rp++ 
