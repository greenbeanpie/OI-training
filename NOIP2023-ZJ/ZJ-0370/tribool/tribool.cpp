#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int inf=1e9+7;
const int N=100005;
int qwq,T,n,m,minn,p[N],tmp[N],xa[N],xb[N];
char tagc[N];
bool check(){
	for (int i=1;i<=n;i++) {
		tmp[i]=p[i];
	}
	for (int i=1;i<=m;i++) {
		if (tagc[i]=='T') tmp[xa[i]]=1;
		if (tagc[i]=='F') tmp[xa[i]]=0;
		if (tagc[i]=='U') tmp[xa[i]]=2;
		if (tagc[i]=='+') tmp[xa[i]]=tmp[xb[i]];
		if (tagc[i]=='-') {
			if (tmp[xb[i]]==2) tmp[xa[i]]=2;
						else   tmp[xa[i]]=1-tmp[xb[i]]; 
		}
	}
	for (int i=1;i<=n;i++) {
		/*
		if (i==n) {
			cout<<"i="<<i<<" p[i]="<<p[i]<<" tmp[i]="<<tmp[i]<<endl;
			for (int j=1;j<=n;j++) cout<<p[j]<<" ";cout<<endl;
			for (int j=1;j<=n;j++) cout<<tmp[j]<<" "; cout<<endl;
		}
		*/
		if (p[i]!=tmp[i]) return 0;
	}
	return 1;
}
void dfs(int x,int unkn) {
	if (unkn>=minn) return ;
	if (x==n) {
		if (check()) minn=unkn;
		return ;
	}
	for (int i=0;i<3;i++) { //0:F,1:T,2:U
		p[x+1]=i;
		if (i==2) dfs(x+1,unkn+1);
			else  dfs(x+1,unkn);
		p[x+1]=0;
	}
	return ;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>qwq>>T;
	if (qwq==3||qwq==4) {
		while (T--) {
			cin>>n>>m;
			for (int i=1;i<=n;i++) p[i]=-1;
			for (int i=1;i<=m;i++) {
				cin>>tagc[i];
				if (tagc[i]=='+'||tagc[i]=='-') cin>>xa[i]>>xb[i];
										else    cin>>xa[i];	
			}
			for (int i=1;i<=m;i++) {
				if (tagc[i]=='F') p[xa[i]]=0;
				if (tagc[i]=='T') p[xa[i]]=1;
				if (tagc[i]=='U') p[xa[i]]=2;
			}
			int ans=0;
			for (int i=1;i<=n;i++) 
				if (p[i]==2) ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
	else if (qwq==5||qwq==6) {
		while (T--) {
			cin>>n>>m; 
			int ans=0;
			for (int i=1;i<=n;i++) p[i]=0;
			for (int i=1;i<=m;i++) {
				cin>>tagc[i];
				if (tagc[i]=='+'||tagc[i]=='-') cin>>xa[i]>>xb[i];
											else cin>>xa[i];
			}
			int t; if (m<=1000) t=m;
							else t=686;
			for (int j=1;j<=t;j++)
			for (int i=1;i<=m;i++) {
				if (tagc[i]=='U') p[xa[i]]=2;
							else  p[xa[i]]=p[xb[i]];
			}
			for (int i=1;i<=n;i++) 
				if (p[i]==2) ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
	else {
		while (T--) {
			cin>>n>>m;
			minn=inf;
			for (int i=1;i<=m;i++) {
				cin>>tagc[i];
				if (tagc[i]=='+'||tagc[i]=='-') cin>>xa[i]>>xb[i];
										else    cin>>xa[i];	
			}
			dfs(0,0);
			cout<<minn<<'\n';
		}
		return 0;		
	}
	return 0;
}

/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2

0
3
1


3 3
5 5
U 2
T 4
U 5
F 1
F 5
3 2
T 1
F 1
7 6
U 5
U 4
U 3
U 2
T 6
F 5



1
0
3



2 9
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
10 10
- 7 5
+ 5 1
+ 1 7
+ 2 3
+ 3 4
+ 4 6
+ 6 8
- 8 9
+ 9 10
- 10 2
10 10
- 1 1
U 1
T 7
U 8
- 9 6
U 3
- 9 3
- 6 3
+ 9 3
- 9 8
10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2



1
4
6
3
5
5


2 1
10 10
- 1 1
U 1
T 7
U 8
- 9 6
U 3
- 9 3
- 6 3
+ 9 3
- 9 8

5





	if (qwq==5||qwq==6) {
		while (T--) {
			cin>>n>>m; 
			int ans=0;
			for (int i=1;i<=n;i++) p[i]=0;
			for (int i=1;i<=m;i++) {
				cin>>tagc[i];
				if (tagc[i]=='+'||tagc[i]=='-') cin>>xa[i]>>xb[i];
											else cin>>xa[i];
			}
			for (int i=1;i<=m;i++) {
				if (tagc[i]=='U') p[xa[i]]=2;
							else  p[xa[i]]=p[xb[i]];
			}
			for (int i=1;i<=n;i++) 
				if (p[i]==2) ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
*/
