#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

#define N 500005
int c,n,m,Q;
int p,q;
int x[2][N],y[2][N],k1,k2,u,v;
int t[N],cnt;
set<int> ds;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&Q);
	p=0,q=1;
	for (int i=1 ; i<=n ; i++)
	    scanf("%d",&x[p][i]);
	for (int i=1 ; i<=m ; i++)
	    scanf("%d",&x[q][i]);
	for (int qq=0 ; qq<=Q ; qq++){
		p=0,q=1;
		for (int i=1 ; i<=n ; i++)
		    y[p][i]=x[p][i];
		for (int i=1 ; i<=m ; i++)
		    y[q][i]=x[q][i];
		
		if (qq!=0){
			scanf("%d%d",&k1,&k2);
			for (int i=1 ; i<=k1 ; ++i)
			    scanf("%d%d",&u,&v),y[p][u]=v;
			for (int i=1 ; i<=k2 ; ++i)
			    scanf("%d%d",&u,&v),y[q][u]=v;
		}
		if (y[p][1]>y[q][1]) {
			int t=p;
			p=q,q=t;
			t=n;
			n=m,m=t;
		}//prepare
		
	//	cnt=0;
	//	for (int i=1 ; i<=n ; i++) t[++cnt]=y[p][i];
	//	sort(t+1,t+cnt+1);
		int flag=1;
		for (int i=1 ; i<=m ; i++){
			int tmp=-1;
			for (int j=1 ; j<=n ; j++){
				if (y[q][i]>y[p][j]){
					tmp=j;
					break;
			}
			}
		//	tmp=lower_bound(t+1,t+cnt+1,y[q][i])-;
			if (tmp==-1){
				flag=0;
				break;
			}
		}	        
		if (y[p][1]==y[q][1] || y[p][n]>=y[q][m]) flag=0;
		printf("%d",flag);
	}
	return 0;
}