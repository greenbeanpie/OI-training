#include <bits/stdc++.h>
using namespace std;
struct N
{
	string s;
	int i;
}d[3005];
char s[3005];
bool cmp(N a,N b)
{
	return a.s<b.s;
}
bool res[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		d[i].s=s;
		d[i].i=i;
	}
	sort(d,d+n,cmp);
	res[d[0].i]=true;
	for(int i=1;i<n;i++)
	{
		sort(d[i].s.begin(),d[i].s.end());
		if(d[i].s<=d[0].s)
			res[d[i].i]=true;
	}
	for(int i=0;i<n;i++)
	{
		if(res[i])
			printf("1");
		else
			printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
