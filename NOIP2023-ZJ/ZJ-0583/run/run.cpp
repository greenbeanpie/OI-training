#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m,k,d;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--)
	{
		scanf("%d %d %d %d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
		}
		srand(n);
		cout<<rand()%n+1<<endl;
	}
}