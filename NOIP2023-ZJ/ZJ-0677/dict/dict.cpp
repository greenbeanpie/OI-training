#include<bits/stdc++.h>
#define debug cout<<"hello";
#define debug2 cout<<"nihao";
#define debug3 cout<<"here";
#define debug4 cout<<"where";
using namespace std;
set<char> k;
char s[3100][3100];
int cnt[3100][27];
int n,m;
bool mycmp(int i1,int i2)
{
	for(int i=1;i<=m;i++)
	{
		if(s[i1][i]<s[i2][i]) return true;
		else if(s[i1][i]>s[i2][i]) return false;
	}
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	memset(cnt,0,sizeof(cnt));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>s[i][j];
		}
	}
	//debug
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<s[i][j];
		}
		cout<<endl;
	}*/
	/*for(int i=1;i<=n;i++)
	{
		s[i]+='a';
		for(int j=m;j>=1;j--)
		{
			s[i][j]=s[i][j-1];
		}
	}*/
	//debug
	int firstmax=1,secondmax=n;
	if(mycmp(n,1))
	{
		firstmax=n;
		secondmax=1;
	}
	//debug
	//cout<<s[firstmax]<<endl;
	for(int i=2;i<=n;i++)
	{
		//cout<<s[i]<<' '<<s[firstmax]<<' '<<s[secondmax]<<endl;
		//cout<<mycmp(i,first)
		if(mycmp(i,firstmax))
		{
			//debug3
			secondmax=firstmax;
			firstmax=i;
		}
		else if(mycmp(i,secondmax))
		{
			//debug4
			secondmax=i;
		}
		//else debug2
	} 
	//cout<<firstmax<<' '<<secondmax<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt[i][s[i][j]-'a'+1]++;
		}
	}
	//debug
	int relmax;
	int flag;
	bool ops=false;
	//debug2
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<s[i][j]<<' ';
		}
		cout<<endl;
	}*/
	//debug2
	//cout<<firstmax<<' '<<secondmax<<endl;
	//cout<<"are you ok"<<endl;
	for(int i=1;i<=n;i++)
	{
		ops=false;
		flag=1;
		if(i==firstmax)
		{
			relmax=secondmax;
			//debug
		}
		else
		{
			relmax=firstmax;
		}
		for(int j=1;j<=26;j++)
		{
			if(ops) break;
			int q=cnt[i][j];
			while(q!=0)
			{
				
				q--;
				if(j<s[relmax][flag]-'a'+1)
				{
					cout<<"1";
					ops=true;
					break;
				}
				else if(j==s[relmax][flag]-'a'+1)
				{
					flag++;
				}
				else
				{
					cout<<"0";
					ops=true;
					break;
				}
			}
		}
		if(!ops) cout<<"1";
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=26;j++)
		{
			cout<<cnt[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//cout<<mycmp(1,2);
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/