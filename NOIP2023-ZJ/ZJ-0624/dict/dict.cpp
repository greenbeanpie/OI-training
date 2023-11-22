#include<bits/stdc++.h>
using namespace std;
const int N=3010;
char ch[N];
int ans[30],k[N];
string s1[N],s2[N];
int n,m;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch);
		for(int i=1;i<=26;i++) ans[i]=0;
		for(int j=0;j<m;j++)
		{
			ans[ch[j]-'a'+1]++;
		}
		for(int j=1;j<=26;j++)
		{
			while(ans[j]>0)
			{
				ans[j]--;
				s1[i]=s1[i]+char('a'+j-1);
				s2[i]=char('a'+j-1)+s2[i];
			}
		}
	}
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=false;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(s2[j]<s1[i])
			{
				printf("0");
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			printf("1");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}