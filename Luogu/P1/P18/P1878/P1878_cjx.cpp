#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef pair<int,pair<int,int> >PIP;
int n,a[N];
bool sex[N],vis[N];
priority_queue<PIP,vector<PIP>,greater<PIP> >q;
vector<pair<int,int> >v;
int main(){
	#ifdef CODESPACE
		freopen("P1878.in","r",stdin);
		freopen("P1878_cjx.out","w",stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++){
		char p;
		cin>>p;
		if(p=='B')	p='0';
		else p='1';
		sex[i]=p-'0';
	}
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		if(sex[i]^sex[i+1]){
			q.push(make_pair(abs(a[i]-a[i+1]),make_pair(i,i+1)));
		}
	}
	while(q.size()){
		int x=q.top().second.first,y=q.top().second.second;
		q.pop();
		if(vis[x]||vis[y])	continue;
		v.push_back(make_pair(x,y));
		vis[x]=vis[y]=1;
		while(vis[x]&&x>0)	x--;
		while(vis[y]&&y<=n)	y++;
		if(x<1||y>n)	continue;
		if(sex[x]^sex[y]) q.push(make_pair(abs(a[x]-a[y]),make_pair(x,y)));
	}
	cout<<v.size()<<"\n";
	for(auto i:v){
		cout<<i.first<<" "<<i.second<<"\n";
	}
	return 0;
}
