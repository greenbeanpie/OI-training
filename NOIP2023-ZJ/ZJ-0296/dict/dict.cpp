#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,t[3001];
string a,a1[3001],a2[3001];
char ch;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		a="";ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		while(ch>='a'&&ch<='z') 
		{
			a+=ch;
			ch=getchar();
		}
		for (int j=1;j<=m;j++) t[a[j-1]]++;
		for (int j=1;j<=26;j++)
		{
			for (int k=1;k<=t[j+'a'-1];k++) 
				a1[i]+=j+'a'-1;
		}
		for (int j=26;j>=1;j--)
		{
			for (int k=1;k<=t[j+'a'-1];k++) 
				a2[i]+=j+'a'-1;
		}
		for (int j=1;j<=26;j++) t[j+'a'-1]=0;
//		cout<<a1[i]<<" "<<a2[i]<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		int qz=1;
		for (int j=1;j<=n;j++)
		{
//			cout<<a1[i]<<" "<<a2[j]<<endl;
			if (i!=j&&a1[i]>=a2[j]) qz=0;
		}
		cout<<qz;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
