#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,ans[N];
string w[N],s[N],bad[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(ans,0,sizeof ans);
	cin>>n>>m;
	for(int i=0;i<n;++i){cin>>w[i];s[i]=w[i];bad[i]=w[i];}
	if(n==1) cout<<"1";
	else //n>1
	{
		if(m==1)
		{
			for(int i=0;i<n;++i)
			{
				bool flag=true;
				for(int j=0;j<n;++j)
					if(i!=j&&w[i]>=w[j]) flag=false;  //ATTENTION:wi>=wj
				if(flag) ans[i]=1;
			}
			for(int i=0;i<n;i++) cout<<ans[i];
		}
		if(m==2)
		{
			for(int i=0;i<n;++i)
			{
				if(s[i][0]>s[i][1]) swap(s[i][0],s[i][1]);
				else swap(bad[i][0],bad[i][1]);
			}
			for(int i=0;i<n;++i)
			{
				bool flag=true;
				for(int j=0;j<n;++j)
					if(i!=j&&s[i]>=bad[j]) flag=false;
				if(flag) ans[i]=1;
			}
			for(int i=0;i<n;++i) cout<<ans[i];
		} 
		//---------------------70pts!!!------------------------------
		if(m>2) //n!=1&&m>2
		{
			for(int i=0;i<n;++i)
			{
				char ch[N];
				for(int j=0;j<m;++j) ch[j]=w[i][j];
				sort(ch,ch+m);
				for(int j=0;j<m;++j) {s[i][j]=ch[j];bad[i][j]=ch[m-j-1];}
			}
			for(int i=0;i<n;++i)
			{
				bool flag=true;
				for(int j=0;j<n;++j)
					if(i!=j&&s[i]>=bad[j]) flag=false;
				if(flag) ans[i]=1;
			}
			for(int i=0;i<n;++i) cout<<ans[i];
		}
	}
	return 0;
}
