#include <bits/stdc++.h>
using namespace std;
int n,m,mid,a[1000100];
bool DFS(int l,int r)
{
	if(l>r)return false;
	mid=(l+r)/2;
	if(a[mid]==m)return true;
	else if(a[mid]<m)return DFS(mid+1,r);
	else return DFS(l,mid-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(DFS(1,n))
	{
		while(a[mid]==a[mid-1])mid--;
		printf("%d\n",mid);
	}
	else printf("%d\n",0);
	return 0;
}
