#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
struct Node{
	int id;
	string mn;
	string mx;
}a[N];
struct Sort{
	int id;
	string c;
	bool operator < (const Sort &e)
	{
		return c<e.c;
	}
}px[N<<1];
int n,m;
int tong[35];
char c[N];
int flag[N];
bool ans[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c+1);
		a[i].id=i;
		for(int j=0;j<=26;j++)
			tong[j]=0;
		for(int j=1;j<=m;j++)
			tong[c[j]-'a']++;
		for(int j=1,k=0;j<=m;)
		{
			if(tong[k]!=0)
			{
				a[i].mn=a[i].mn+char(k+'a');
				a[i].mx=char(k+'a')+a[i].mx;
				tong[k]--;
				j++;
			}else k++;
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
			cout<<a[i].mn;
		cout<<endl;
			cout<<a[i].mx;
		cout<<endl<<endl;
	}
	*/
	for(int i=1;i<=n;i++)
	{
		px[(i-1)<<1].id=i;
		px[(i-1)<<1].c=a[i].mn;
		px[(i-1)<<1|1].id=i;
		px[(i-1)<<1|1].c=a[i].mx;
	}
	for(int i=1;i<=n;i++)
	{
		flag[i]=0;
		ans[i]=false;
	}
	sort(px,px+(n<<1));
	for(int i=0;i<(n<<1);i++)
	{
		flag[px[i].id]++;
		if(flag[px[i].id]==2) break;
		ans[px[i].id]=true;
	}
	for(int i=1;i<=n;i++)
		if(ans[i]) printf("1");
		else printf("0");
	return 0;
}
