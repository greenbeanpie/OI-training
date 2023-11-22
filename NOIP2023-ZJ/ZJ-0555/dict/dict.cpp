#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define For(i,x,y) for(int i=x;i<=y;i++)
#define FOR(i,x,y) for(int i=x;i>=y;i--)

const int N=3e3+4;
int n,len;
char ch[N];
string st[N],stc[N];
inline bool cmp(char x,char y){return x>y;}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	IOS;
	cin>>n>>len;
	For(i,1,n)cin>>st[i];
	For(i,1,n)stc[i]=st[i];
	For(i,1,n)
	{
		For(j,1,len)ch[j]=st[i][j-1];
		sort(ch+1,ch+len+1);
		For(j,1,len)st[i][j-1]=ch[j];
		For(j,1,len)stc[i][len-j]=ch[j];
	}
	For(i,1,n)
	{
		bool p=1;
		For(j,1,n)
			if(i!=j)
				if(st[i]>=stc[j])
				{
					p=0;
					break;
				}
		cout<<p;
	}

	return 0;
}
