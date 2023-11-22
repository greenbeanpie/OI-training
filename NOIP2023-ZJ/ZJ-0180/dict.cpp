#include<bits/stdc++.h>
using namespace std;
struct node
{
	char ch[3009];
	int id;
	bool flag;
}p[6009];
int n,m;
int ans[3009];
bool cmp(node A,node B)
{
	for(int i=0;i<m;i++)
		if(A.ch[i]!=B.ch[i])return A.ch[i]<B.ch[i];
	return false;
}
node minn,minn2;
int cnt[27];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",p[i].ch);
		for(int j=0;j<m;j++) cnt[p[i].ch[j]-'a']++;
		int tot=0;
		for(int j=0;j<26;j++)
		{
			while(cnt[j]--) p[i].ch[tot++]=(char)(j+'a');
		}
		p[i+n].flag=1;
		p[i].id=p[i+n].id=i;
		for(int j=m-1;j>=0;--j)p[i+n].ch[m-j-1]=p[i].ch[j];
		for(int j=0;j<26;j++)cnt[j]=0; 
	}
	minn=p[n+1];minn2.ch[0]='{';
//	if(p[1].ch[0]<minn2.ch[0])cerr<<"sbcc++";
//	if(cmp(p[1],minn2))cerr<<"ok";
	for(int i=1;i<=n;i++)
		if(!cmp(minn,p[i+n])) 
		{
			minn2=minn;
			minn=p[i+n];
		}
		else if(!(cmp(minn2,p[i+n])))minn2=p[i+n];
	for(int i=1;i<=n;i++) 
		if((minn.id==i && cmp(p[i],minn2)) || cmp(p[i],minn))
			ans[i]=1;
	
	for(int i=1;i<=n;i++) putchar(ans[i]==1?'1':'0');
}
/*
4 7
abandon
bananaa
baannaa
notnotn

*/