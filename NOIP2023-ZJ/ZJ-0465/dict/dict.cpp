#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,m;
char a[N][N];
char mx[N],mn[N];
int pos_mx[N],pos_mn[N];

bool check(int x,int y){
	for(int i=1;i<=m;i++){
		if(a[x][i]<a[y][i]) return 1;
		if(a[x][i]>a[y][i]) return 0;
	}
	return 1;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		mx[i]='a',mn[i]='z';
		pos_mx[i]=1,pos_mn[i]=1;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>=mx[i]){
				mx[i]=a[i][j];
				pos_mx[i]=j;
			}
			if(a[i][j]<=mn[i]){
				mn[i]=a[i][j];
				pos_mn[i]=j;
			}
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n<=26&&m<=1){
		char mn='z';
		for(int i=1;i<=n;i++) mn=min(a[i][1],mn);
		for(int i=1;i<=n;i++) cout<<(a[i][1]==mn);
		return 0;
	}
	for(int i=1;i<=n;i++){
		char t=mn[i];bool flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(t>mx[j]){
				flag=0;
				break;
			}
			else if(t==mx[j]){
				swap(a[j][1],a[j][pos_mx[j]]);
				swap(a[i][1],a[i][pos_mn[i]]);
				flag=check(i,j);
				swap(a[j][1],a[j][pos_mx[j]]);
				swap(a[i][1],a[i][pos_mn[i]]);				
			}
		}
		cout<<flag;
	}
	return 0;
}
