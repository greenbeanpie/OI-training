#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+(ch^48),ch=getchar();
	return x*f;
}
const int N=3e3+5;
//int n,len,cp[N];
//string st[N],ts[N];
//string work(string l)
//{
//	for(int i=0;i<len;++i)
//		cp[i]=int(l[i]);
//	sort(cp,cp+len);
//	for(int i=0;i<len;++i)
//		l[i]=char(cp[i]);
////	cout<<"l:"<<l<<'\n';
//	return l;
//}
int n,len,t[300],cnt;
string st[N],ts[N];
string work(string l)
{
	for(char i='a';i<='z';++i)
		t[i]=0;
	for(int i=0;i<len;++i)
		++t[l[i]];
	cnt=-1;
	for(char i='a';i<='z';++i)
		while(t[i]--)
			l[++cnt]=i;
//	cout<<"l:"<<l<<'\n';
	return l;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>len;
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>ts[i];
		st[i]=work(ts[i]);
		for(int j=0;j<len;++j)
			ts[i][len-j-1]=st[i][j];
	}
//	for(int j=1;j<=n;++j)
//		cout<<st[j]<<' '<<t[j]<<' ';
//	puts("");
	bool flag;
	for(int i=1;i<=n;++i)
	{
		flag=true;
//		t[i]=st[i];
//		for(int j=1;j<=n;++j)
//			cout<<i<<':'<<t[j]<<' ';
//		puts("");
		for(int j=1;j<=n;++j)
			if(j!=i)
			{
				if(ts[j]<=st[i])
				{
//					cout<<t[j]<<'>'<<t[i]<<'\n';
					flag=false;
					break;
				}
			}
//		t[i]=ts[i];
		if(flag==false)
			printf("0");
		else
			printf("1");
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/