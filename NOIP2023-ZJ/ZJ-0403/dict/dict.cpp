#include<bits/stdc++.h>
using namespace std;
const int maxn = 3010;
int N,M;
int num[maxn][27],firs[maxn],las[maxn];
int main()
{
	cin.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>N>>M; char a;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++) 
		{
			cin>>a;
			num[i][a-'a']++;
		}
		for(int j=0;j<26;j++)	
		{
			if(num[i][j])
			{
				if(!firs[i]) firs[i] = j+1;
				las[i] = j+1;
			}
		}
	}
	if(N == 1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=N;i++)
	{
		bool is = true;
		for(int j=1;j<=N;j++)
		{
			if(i == j) continue;
			if(las[j] <= firs[i])
			{
//				if(i == 437) cout<<endl<<j<<' '<<las[j]<<' '<<i<<' '<<firs[i]<<endl;
//				if(i == 437) for(int k=0;k<=26;k++) cout<<num[i][k]; if(i == 437)cout<<endl;
				is = false;
				break;
			}
		}	
		if(is) cout<<1;
		else cout<<0;
	}
	return 0;
}