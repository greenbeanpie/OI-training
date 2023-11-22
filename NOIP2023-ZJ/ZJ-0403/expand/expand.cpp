#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int C,N,M,Q;
int l[maxn],l2[maxn],l3[maxn],l4[maxn];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>C>>N>>M>>Q;
	for(int i=1;i<=N;i++) cin>>l[i],l3[i]=l[i];
	for(int i=1;i<=M;i++) cin>>l2[i],l4[i]=l2[i];
	if(C == 1 || C == 2)
	{
		if((l3[1] > l4[1] && l3[N] > l4[M]) || (l3[1] < l4[1] && l3[N] < l4[M])) cout<<1;
		else cout<<0;
		int a,b,c,d;
		while(Q--)
		{
			cin>>a>>b;
			l3[1] = l[1]; l3[N] = l[N]; l4[1] = l2[1]; l4[M] = l2[M]; 
			for(int i=1;i<=a;i++)cin>>c>>d,l3[c] = d;
			for(int i=1;i<=b;i++)cin>>c>>d,l4[c] = d;
			if((l3[1] > l4[1] && l3[N] > l4[M]) || (l3[1] < l4[1] && l3[N] < l4[M])) cout<<1;
			else cout<<0;
		}
	}
	else 
	{
		for(int i=1;i<=1+Q;i++) cout<<0;
	}
	return 0;
}