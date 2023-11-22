#include<bits/stdc++.h>


using namespace std;
const int N=3030,M=30;
int a[N][M];
int n,m;
char s[N];
string mn[N],mx[N];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			a[i][(int)(s[j]-'a'+1)]++;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=26;i++) for(int j=1;j<=a[k][i];j++)
		{
			mn[k]+=(char)(i+'a'-1);
		}
		for(int i=26;i>=1;i--) for(int j=1;j<=a[k][i];j++)
		{
			mx[k]+=(char)(i+'a'-1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int fl=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(mn[i]>=mx[j])
			{
				fl=0;
				break;
			}
		}
		printf("%d",fl);
	}
	return 0;
}


//zsy dalao orz
//sjh dalao orz
//lzy dalao orz
//大佬们保佑我
//骗分出省一


/*

fuck ccf
fuck noip
fuck csp

我不干了

还有一个小时考试结束 

看我光速退役

*/
