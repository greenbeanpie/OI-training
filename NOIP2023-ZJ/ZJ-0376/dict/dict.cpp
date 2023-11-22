#include<bits/stdc++.h>
using namespace std;
const int N=3020;
string in[N];
string b[N];
string c[N];
bool check[N];
string mm,mm1;
int n,m,st;
struct node{
	int ap[30];
	int icon;
}e[N];
bool che(int x,int y)
{
	for(int i=st+1;i<26;i++)
	{
		if(e[x].ap[i]>e[y].ap[i])
		{
			return 0;
		}
		if(e[x].ap[i]<e[y].ap[i]){
			return 1;
		}
	}
	return 1;
}
bool cheppp(int x,int y)
{
	int ttt=25;
	int sss=0;
	while(e[y].ap[ttt]==0) ttt--;
	while(e[x].ap[sss]==0) sss++;
	//cout<<in[x]<<" "<<in[y]<<" "<<ttt<<" "<<sss<<endl;
    if(sss<ttt) return 1;
    return 0;
}
int main(){
	
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>in[i];
		for(int j=0;j<m;j++)
		{
			e[i].icon=i;
			e[i].ap[in[i][j]-'a']++;
		}
	}
	st=28;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int t=0;t<26;t++)
		{
			if(e[i].ap[t]){
				cnt=t;
			}
		}
		st=min(cnt,st);
	}
	int maxnnum=0,maxn=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int t=0;t<26;t++)
		{
			if(e[i].ap[t]){
				cnt=t;
			}
		}
		if(cnt>st) continue;
		if(e[i].ap[st])
		{
			if(!maxnnum)
			{
				maxnnum=i;
				maxn=e[i].ap[st];
			}
			if(e[i].ap[st]<maxn)
			{
				maxnnum=i;
				maxn=e[i].ap[st];
			}
			if(e[i].ap[st]==maxn)
			{
				if(che(i,maxnnum))
				{
					maxnnum=i;maxn=e[i].ap[st];
				}
			}
		}
	}
	st=28;
	for(int i=1;i<=n;i++)
	{
	    int cnt=0;
		if(i==maxnnum) continue;
		for(int t=0;t<26;t++)
		{
			if(e[i].ap[t]){
				cnt=t;
			}
		}
		st=min(cnt,st);
	}
	int maxnnum1=0,maxn1=0;
	for(int i=1;i<=n;i++)
	{
		if(i==maxnnum) continue;
		int cnt=0;
		for(int t=0;t<26;t++)
		{
			if(e[i].ap[t]){
				cnt=t;
			}
		}
		if(cnt>st) continue;
		if(e[i].ap[st])
		{
			if(!maxnnum1)
			{
				maxnnum1=i;
				maxn1=e[i].ap[st];
			}
			if(e[i].ap[st]<maxn)
			{
				maxnnum1=i;
				maxn1=e[i].ap[st];
			}
			if(e[i].ap[st]==maxn1)
			{
				if(che(i,maxnnum1))
				{
					maxnnum1=i;maxn1=e[i].ap[st];
				}
			}
		}
	}
	//cout<<maxnnum<<" "<<maxnnum1<<endl;
	//cout<<in[maxnnum]<<" "<<in[maxnnum1]<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i==maxnnum)
		{
			//cout<<in[i]<<" "<<in[maxnnum1]<<endl;
			printf("%d",cheppp(i,maxnnum1));
		}
		else{
			//cout<<in[i]<<" "<<in[maxnnum]<<endl;
			printf("%d",cheppp(i,maxnnum));
		}
	}
	cout<<endl;
	
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(e[i].ap[j])
			{
				cout<<char(j+'a')<<" "<<e[i].ap[j]<<endl;
			}
		}
	}*/
	
	return 0;
}
