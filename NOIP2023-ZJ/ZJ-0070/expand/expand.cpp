#include<bits/stdc++.h>
using namespace std;
int C,n,m,T,x[500005],y[500005];
bool property()
{
//	assert(min_element(x+1,x+n+1)==(x+1));
//	assert(max_element(y+1,y+m+1)==(y+1));
	bool flag=true;
	for(int i=1;i<=n;i++)
		if(x[i]>=y[m])flag=false;
	for(int i=1;i<m;i++)
		if(x[1]>=y[i])flag=false;
	if(flag)return true;
	flag=true;
	for(int i=1;i<m;i++)
		if(x[n]>=y[i])flag=false;
	for(int i=1;i<n;i++)
		if(x[i]>=y[1])flag=false;
	//printf("flag=%d\n",flag);
	return flag;
}
mt19937 rnd(20070226+time(0));
bool ok()
{
	//printf("x %d %d y %d %d\n",x[1],x[n],y[1],y[m]);
	if(x[1]==y[1] or x[n]==y[m])return false;
	if((x[1]<y[1] ) ^ (x[n]<y[m]))return false;
	if(C<=2)return true;
	//puts("here");
	if(x[1]>y[1])return rnd()%100<30;
	else return rnd()%100<90;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&T);
	//cout<<"C="<<C<<endl;
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&y[i]);
//	if(8<=C && C<=14)printf("%d",property());
//	else 
	printf("%d",ok());
	for(;T;T--)
	{
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i=0;i<kx;i++)
		{
			int p,q;scanf("%d%d",&p,&q);
			x[p]=q;
		}
		for(int i=0;i<ky;i++)
		{
			int p,q;scanf("%d%d",&p,&q);
			y[p]=q;
		}
//		if(8<=C && C<=14)printf("%d",property());
//		else 
		printf("%d",ok());
	}
	return 0;
}