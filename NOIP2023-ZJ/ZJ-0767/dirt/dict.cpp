#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LL long long
#define pii pair<int,int>
using namespace std;
const int N=3e3+10;
int n,m;
int a[N][30];
char b[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[i][j];
			a[i][int(b[i][j]-'a')+1]++;
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=false;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int p1=1,p2=26;
			while(p1<=26&&p2>0){
				while(!a[i][p1]&&p1<=26)p1++;
				while(!a[j][p2]&&p2>0)p2--;
				if(p1<p2){
					break;
				}
				if(p1>p2){
					flag=true;
					break;
				}
				if(p1==p2){
					flag=true;
					break;
				}
			}
			if(flag){
				cout<<"0";
				break;
			}
		}
		if(!flag)cout<<"1";
	} 
	cout<<'\n';
	return 0;
}
