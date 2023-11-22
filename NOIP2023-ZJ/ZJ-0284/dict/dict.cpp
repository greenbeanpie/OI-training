#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[3050][3050];
int jh[3050][5];
int lst[3050][30];
int fir_x[3050][30];
int fir_d[3050][30];
bool xiao(int x,int y)
{
	for (int j=1;j<=m;j++)
	{
		if (s[x][j]<s[y][j]) return true;
		if (s[x][j]==s[y][j]) continue;
		if (s[x][j]>s[y][j]) return false;
	}
	return false;
}
bool check(int x)
{
	for (int i=1;i<=n;i++)
	{
		if (i!=x)
		{
			//bian da
			for (int c=26;c>=1;c--)
			{
			//	cout<<char(c+96)<<i<<' '<<lst[i][c]<<' '<<fir_d[i][c]<<endl;
				
				if (lst[i][c]>fir_d[i][c]&&fir_d[i][c]<=m&&c>int(s[i][fir_d[i][c]])-96 )
				{
					
					jh[i][0]=lst[i][c];
					jh[i][1]=fir_d[i][c];
					swap(s[i][lst[i][c]],s[i][fir_d[i][c]]);
					break;
				}
			}
		}else
		{
			//bian xiao
			for (int c=1;c<=26;c++)
			{
			//	cout<<char(c+96)<<i<<' '<<lst[i][c]<<' '<<fir_x[i][c]<<endl;
				if (lst[i][c]>fir_x[i][c]&&fir_x[i][c]<=m&&c<int(s[i][fir_x[i][c]])-96)
				{
				//	cout<<'!';
					jh[i][0]=lst[i][c];
					jh[i][1]=fir_x[i][c];
					swap(s[i][lst[i][c]],s[i][fir_x[i][c]]);
					break;
				}
			}
		}
	}
/*	cout<<x<<endl;
	for (int i=1;i<=n;i++,cout<<endl)
		for (int j=1;j<=m;j++)
			cout<<s[i][j];
	system("pause");*/
	bool flag=true;
	for (int i=1;i<=n;i++)
		if (xiao(i,x)) 
		{
			//cout<<'?'<<i;
			flag=false;
			break;
		}
	for (int i=1;i<=n;i++)
	{
		if (jh[i][0]!=0&&jh[i][1]!=0)
		{
			swap(s[i][jh[i][0]],s[i][jh[i][1]]);
			jh[i][0]=0;
			jh[i][1]=0;
		}
	}
	return flag;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(fir_x,127/3,sizeof(fir_x));
	memset(fir_d,127/3,sizeof(fir_d));
	int pre;
	for (int i=1;i<=n;i++)
	{
		pre=0;
		for (int j=1;j<=m;j++)
		{
			int ch=int(s[i][j])-96;
			for (int c=pre;c<ch;c++)
				fir_x[i][c]=min(fir_x[i][c],j);
			pre=max(pre,ch);
		}
	}
	
//	cout<<'!'<<fir_d[1][15]<<endl;
	for (int i=1;i<=n;i++)
	{
		pre=0;
		for (int j=1;j<=m;j++)
		{
			int ch=int(s[i][j])-96;
		//	cout<<i<<' '<<j<<' '<<ch<<endl;
			for (int c=max(ch+1,pre);c<=26;c++)
			{
				fir_d[i][c]=min(fir_d[i][c],j);
		//		cout<<char(c+96)<<' '<<fir_d[i][c]<<endl;
		//		system("pause");
			}
		//	system("pause");
			pre=max(pre,ch);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=m;j>=1;j--)
		{
			int c=int(s[i][j])-96;
			lst[i][c]=max(lst[i][c],j);
		}
	}
	/*
	for (int i=1;i<=n;i++,cout<<endl)
		for (int j=1;j<=m;j++)
			cout<<s[i][j];*/
	for (int i=1;i<=n;i++)
		printf("%d",check(i)?1:0);
	//	check(i);
	return 0;
}
