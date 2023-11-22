#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x;
int ans;
int a[114514],b[114514];
char v;
void perform()
{
	int i,j;
	for(int k=1;k<=m;k++)
	{
		cin>>v;
		if(v=='T')cin>>i,a[i]=1;
		else if(v=='U')cin>>i,a[i]=0;
		else if(v=='F')cin>>i,a[i]=-1;
		else if(v=='+')cin>>i>>j,a[i]=a[j];
		else if(v=='-')cin>>i>>j,a[i]=-a[j];
	}
}
void dfs()
{
	int an=0;
	if(x==n){
		for(int k=1;k<=m;k++)b[k]=a[k];
		perform();
		for(int k=1;k<=m;k++){
			if(a[k]==b[k])
			{
				if(a[k]==0)an++;
			}else{
				break;
			}
		}
		ans=max(ans,an);
		return;
	}
	x++;
	a[x]=0;
	dfs();
	a[x]=-1;
	dfs();
	a[x]=1;
	dfs();
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		dfs();
	}
	cout<<ans;
	return 0;
}