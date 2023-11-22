//¶à²âÒªÇå¿Õ
//freopen("expand.in","r",stdin);
//freopen("expand.out","w",stdout); 

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,q;
int a[N],b[N];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout); 	
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(n==1 && m==1)
	{
		int x,y;
		cin>>x>>y;
		while(q--)
		{
			int aa,bb;
			cin>>aa>>bb;
			for(int i=1;i<=aa;i++)
			{
				int cc,dd;
				cin>>cc>>dd;
				x=dd;
			}
			for(int i=1;i<=bb;i++)
			{
				int cc,dd;
				cin>>cc>>dd;
				y=dd;
			}
			if(x>y)
				cout<<"1";
			else
				cout<<"0";
		}
	}
	return 0;
}
