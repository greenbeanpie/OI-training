#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<bool,int> PII;
int n,m;
PII a[100010];
int p[200010];
int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	p[x]=y;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int hornex,MythicHornet,i;
	cin>>hornex>>MythicHornet;
	while(MythicHornet--){
		cin>>n>>m;
		for(i=1;i<=n;i++)a[i]={0,i};
		for(i=1;i<=2*n+6;i++)p[i]=i;
		while(m--){
			char ch;
			int x,y;
			cin>>ch>>x;
			if(ch=='+'||ch=='-'){
				cin>>y;
				a[x]=a[y];
				if(ch=='-')a[x].x=!a[x].x;
			}
			else{
				if(ch=='T')a[x]={0,n+1};
				if(ch=='F')a[x]={0,n+2};
				if(ch=='U')a[x]={0,n+3};
			}
		}
		for(i=1;i<=n;i++)
			if(!a[i].x){
				merge(i,a[i].y);
				merge(i+n+3,a[i].y+n+3);
			}
			else{
				merge(i,a[i].y+n+3);
				merge(i+n+3,a[i].y);
			}
		
		int cnt=0;
		for(i=1;i<=n;i++){
			int t=find(i);
			if(t==find(n+3+i)||t==find(n+3)||t==find(2*n+6))cnt++;
		}
		cout<<cnt<<'\n';
	}
}