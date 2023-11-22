#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch,smax[5005],smin[5005];
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	memset(smin,'z',sizeof(smin));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			cin>>ch;
			if (smax[i]<ch) smax[i]=ch;
			if (smin[i]>ch) smin[i]=ch;
		}
	for (int i=1;i<=n;i++){
		int p=0;
		for (int j=1;j<=n;j++)
			if (j!=i&&smin[i]>=smax[j]){
				cout<<0;
				p=1;
				break;
			}
		if (p==0) cout<<1;
	}
	return 0;
}