#include<bits/stdc++.h>
using namespace std;
#define LL long long
string s[3010];
char ss[3010][3010];
int sum[3010][30],ans[3010];
int getnum(char ch)
{
	return int(ch-'a')+1;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int cnnt=0;
		for(int j=0;j<m;j++)
			sum[i][getnum(s[i][j])]++;
		for(int j=26;j>=1;j--)
		{
			for(int k=1;k<=sum[i][j];k++)
			{
				ss[i][cnnt]=char(j-1+'a');
				cnnt++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int l=1;l<=n;l++)
		{
			int cnt=0;
			if(l==i) continue;
			for(int j=1;j<=26;j++)
			{
				for(int k=1;k<=sum[i][j];k++)
				{
					while(getnum(ss[l][cnt])==j) cnt++;
					if(getnum(ss[l][cnt])<j) {flag=0;break;}
					if(getnum(ss[l][cnt])>j) {flag=2;break;}
				}
				if(flag!=1) break;
			}
			if(flag==2) flag=1;
			if(!flag) break;		
		}
		ans[i]=flag;
	}
	for(int i=1;i<=n;i++) cout<<ans[i];
	cout<<endl;
	return 0;
}
