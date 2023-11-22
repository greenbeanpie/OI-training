#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
const int N=3005;
char s[N][N],s1[N];
string x[N],mins,mins2;
int n,m,minid,minid2;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("1\n");
		fclose(stdin);fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			s[i][j]=getchar();
			if(s[i][j]=='\n')	s[i][j]=getchar();
		}
		sort(s[i],s[i]+m);
//		if(s[i][1]==s[i][m])
//			allsame[i]=true;
		for(int j=0;j<m;j++)
			s1[j]=s[i][m-j-1];
		x[i]=s1;
//		cout<<x[i]<<endl;
	}
//	sort(&x[1],&x[n+1],cmp);
	for(int i=0;i<=m;i++)
		mins+="z";
//	cout<<mins<<endl;
	for(int i=1;i<=n;i++)
	{
		if(x[i]<mins)
		{
			mins2=mins;
			minid2=minid;
			mins=x[i];
			minid=i;
		}else
			if(x[i]==mins)
			{
				mins2=mins;
				minid2=i;
			}
		
	}
//	cout<<mins<<endl;

	for(int i=1;i<=n;i++)
	{
		if((s[i]<mins && i!=minid)||(i==minid && s[i]<mins2))
			printf("1");else
			printf("0");
	}
	printf("\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
