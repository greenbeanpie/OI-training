#include<bits/stdc++.h>
using namespace std;
int n,m,p1[30],p2[30],v1,v2;
string s1,s2,s[3001];
char w[3001][3001];
int a[3001][30];
int main()
{
	//ios::sysn_stdio(nullptr);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		for(int j=0;j<m;j++)cin>>w[1][j];
		cout<<1;
	}
	else 
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<m;j++)cin>>w[i][j];
			for(int j=0;j<m;j++)
			{
				a[i][w[i][j]-'a']++;
			//	b[w[i][j]-'a']++;
			}
			if(!v1)
			{
				v1=i;
				for(int j=0;j<26;j++)p1[j]=a[i][j];
			}
			else
			{
				int flag=1;
				for(int j=25;j>0;j--)
				{
					if(p1[j]<a[i][j])
					{
						flag=0;
						break;
					}
					if(p1[j]>a[i][j])break;
				}
				if(flag)
				{
					v1=i;
					for(int j=25;j>=0;j--)p1[j]=a[i][j];
				}
				else 
				{
					if(!v2)
					{
						v2=1;
						for(int j=25;j>=0;j--)p2[j]=a[i][j];
					}
					else
					{
						int flag2=1;
						for(int j=25;j>0;j--)
						{
							if(p2[j]<a[i][j])
							{
								flag2=0;
								break;
							}
							if(p2[j]>a[i][j])break;
						}
						if(flag2)
						{
							for(int j=25;j>=0;j--)p2[j]=a[i][j];
						}
					}
					
				}
			}//for(int j=0;j<26;j++)cout<<p1[j];
		//	cout<<endl;
		
		}
		for(int i=25;i>=0;i--)
		{
			while(p1[i])
			{
				s1=s1+(char)('a'+i);
				p1[i]--;
			}
			while(p2[i])
			{
				s2=s2+(char)('a'+i);
				p2[i]--;
			}
		}
	//	cout<<s1<<endl<<s2<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<26;j++)
			{
				while(a[i][j])
				{
					s[i]=s[i]+(char)('a'+j);
					a[i][j]--;
				}
			}
	//		cout<<s[i]<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=v1)
			{
				int flag=1;
				for(int j=0;j<m;j++)
				{
					if(s[i][j]>s1[j])
					{
						flag=0;
						break;
					}
					if(s[i][j]<s1[j])break;
				}
				if(flag)cout<<1;
				else cout<<0;
			}
			else
			{
				int flag=1;
				for(int j=0;j<m;j++)
				{
					if(s[i][j]>s2[j])
					{
						flag=0;
						break;
					}
				}
				if(flag)cout<<1;
				else cout<<0;
			}
		}
	}
//	cout<<s1;

}/*
4 7
abandon
bananaa
baannaa
notnotn*/
