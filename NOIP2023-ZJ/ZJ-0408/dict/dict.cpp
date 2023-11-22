#include<bits/stdc++.h>
using namespace std;
int N,M;
bool ans[3003];
struct NODE
{
	int id;
	char S[3003];
	bool operator < (const NODE X) const
	{
		return strcmp(S+1,X.S+1);
	}
}que[6006];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdi o(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i)
	{
		que[i].id=i;
		cin>>(que[i].S+1);
		sort(que[i].S+1,que[i].S+M+1);
		que[i+N].id=i+N;
		for(int j=1;j<=M;++j)
		{
			que[i+N].S[j]=que[i].S[M-j+1];
		}
	}
	sort(que+1,que+2*N+1);
	int cnt=0;
	for(int i=2*N;i>0;--i)
	{
		if(que[i].id>N) cnt++;
		else
		{
			if(cnt>=N)
			{
				ans[que[i].id]=1;
			}
		}
	}
	for(int i=1;i<=N;++i) cout<<ans;
	return 0;
}