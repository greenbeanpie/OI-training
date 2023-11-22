#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,bk;
string smx[3001],smn[3001],ans,smxmn="#";
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		char c;
		cin>>c;
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		char str[3002];
		for(int j=0;j<m;++j)
			cin>>str[j];
		sort(str,str+m);
		for(int j=m-1;j>=0;--j)
			smx[i]+=str[j];
		if(smx[i]<smxmn or smxmn=="#")
		{
			smxmn=smx[i];
			bk=i;
		}
		for(int j=0;j<m;++j)
			smn[i]+=str[j];
	}
	for(int i=1;i<=n;++i)
	{
		if(i==bk)
		{
			bool f=true;
			for(int j=1;j<=n;++j)
			{
				if(i==j)
					continue;
				if(smn[i]>=smx[j])
				{
					f=false;
					ans+='0';
					break;
				}
			}
			if(f)
				ans+='1';
		}
		else
		{
			if(smn[i]>=smxmn)
				ans+='0';
			else
				ans+='1';
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
