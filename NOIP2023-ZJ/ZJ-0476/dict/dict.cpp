#include<bits/stdc++.h>
#define ll long long
#define N 10005
#define M 30
using namespace std;
int n,m,a[N];
int Min,lMin;
int cs[N][M];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cs[i][0]=111885443;
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		for (int j=0;j<m;j++)
		{
			int kk=st[j]-96;
			cs[i][0]=min(cs[i][0],kk);
			cs[i][kk]+=1;
		}
	}
	if (n>=2)
	{
		for (int i=26;i>=1;i--)
			if (cs[1][i]==cs[2][i]) continue;
			else if (cs[1][i]>cs[2][i])
			{
				Min=2;
				lMin=1;
				break;
			}
			else
			{
				Min=1;
				lMin=2;
				break;
			}
		for (int i=3;i<=n;i++)
		{
			bool p=false;
			for (int j=26;j>=1;j--)
				if (cs[Min][j]==cs[i][j]) continue;
			else if (cs[Min][j]>cs[i][j])
			{
				lMin=Min;
				Min=i;
				p=true;
				break;
			}
			else break;
			if (p==false)
			{
				for (int j=26;j>=1;j--)
				if (cs[lMin][j]==cs[i][j]) continue;
				else if (cs[lMin][j]>cs[i][j])
				{
					lMin=i;
					break;
				}
				else break;
			}
		}
		//find max min
	}
	else//condition n=1
	{
		cout<<1;
		return 0;
	}
	//cout<<Min<<" r p + +"<<lMin<<" rp + +"<<endl;
	string stmin="",stlmin="";
	for (int j=26;j>=1;j--)
		for (int k=1;k<=cs[Min][j];k++)
		stmin+=(j+96);
	for (int j=26;j>=1;j--)
		for (int k=1;k<=cs[lMin][j];k++)
		stlmin+=(j+96);
	for (int i=1;i<=n;i++)//weather i could succeed or not
	{
		if (i!=Min)//when i is not the max
		{
			string stnow="";
			for (int j=cs[i][0];j<=26;j++)
				for (int k=1;k<=cs[i][j];k++)
				stnow+=(j+96);
			if (stnow<stmin) cout<<1;
			else cout<<0;
		}
		else
		{
			string stnow="";
			for (int j=cs[i][0];j<=26;j++)
				for (int k=1;k<=cs[i][j];k++)
				stnow+=(j+96);
			if (stnow<stlmin) cout<<1;
			else cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//long long!! empty!!
