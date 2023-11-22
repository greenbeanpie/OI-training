#include<bits/stdc++.h>
#define N 3005
using namespace std;
int n,m,num,f[30];
string st,min_max;
string minn[N],maxx[N];
inline int read()
{
	int aa=0,op=1;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-') op=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		aa=aa*10+(int)(ch-'0');
		ch=getchar();
	}
	return aa*op;
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(); m=read();
	if (n==1)
	{
		printf("1");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>st;
		for (int j=1;j<=26;j++) f[j]=0;
		for (int j=0;j<m;j++) f[st[j]-'a'+1]++;
		maxx[i]=""; minn[i]="";
		for (int j=1;j<=26;j++)
		  for (int k=1;k<=f[j];k++)
			{
				minn[i]=minn[i]+(char)(j+'a'-1);
				maxx[i]=(char)(j+'a'-1)+maxx[i];
			}
		if (maxx[i]<min_max||i==1)
		{
			min_max=maxx[i];
			num=i;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (minn[i]<min_max||num==i) printf("1");
		  else printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
