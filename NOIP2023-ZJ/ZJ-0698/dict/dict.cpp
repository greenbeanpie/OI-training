#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=3000+5,M=3000+5;

int n,m;
char w[N][N];

void solve1(){printf("1");exit(0);}
void solve2(){
	vector<int> app[50];
	int pos; bool flag=false;
	for(int i=1;i<=n;++i)
		app[w[i][1]-'a'].push_back(i);
	for(int i=0;i<26;++i)
		if((int)app[i].size()==1){
			pos=app[i][0],flag=true;
			break;
		}
	if(!flag){
		for(int i=1;i<=n;++i)
			printf("0");
	}
	else{
		for(int i=1;i<=n;++i)
			if(i==pos) printf("1");
			else printf("0");
	}
	exit(0);
}
void solve3(){
	vector<pair<int,int> > app[50];
	bool flag;
	for(int i=1;i<=n;++i){
		int x=w[i][1]-'a', y=w[i][2]-'a';
		if(x>y) swap(x,y);
		app[i].push_back(make_pair(x,y));
	}
	for(int i=1;i<=n;++i){
		flag=true;
		int x=app[i][0].first;
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			int fy=app[j][0].second;
			if(x>=fy){
				flag=false;
				break;
			}
		}
		if(flag) printf("1");
		else printf("0");
	}
	exit(0);
}
void solve4(){
	int sum[N][50],minn=inf,maxn=-1;
	bool flag;
	vector<int> app[N];
	for(int i=1;i<=n;++i){
		minn=inf,maxn=-1;
		for(int j=1;j<=m;++j){
			int x=w[i][j]-'a';
			sum[i][x]++;
			minn=min(minn,x);
			maxn=max(maxn,x);
		}
		app[i].push_back(minn);
		app[i].push_back(maxn);
	}
	for(int i=1;i<=n;++i){
		int iminn=app[i][0];
		flag=true;
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			int jmaxn=app[j][1];
			if(iminn>=jmaxn){
				flag=false; break;
			}
		}
		if(flag) printf("1");
		else printf("0");
	}
	exit(0);
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;++i) scanf("%s",w[i]+1);
	
	if(n==1) solve1();
	if(m==1) solve2();
	if(m==2) solve3();
	solve4();
	return 0;
}
