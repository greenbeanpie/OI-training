#include<bits/stdc++.h>
using namespace std;
char s[3001][3001],c;
int n,m,maxn[3001],minn[3001];
bool f=0;
int num[3001][27];
bool check(int x,int y){
	if(minn[x]<maxn[y]) return 1;
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		minn[i]=0x3f3f3f3f;
		for(int j=0;j<m;j++){
			cin>>c;
			num[i][c-'a']++;
			maxn[i]=max(maxn[i],c-'a');
			minn[i]=min(minn[i],c-'a');
		}
	}
		
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=1;j<=n;j++){
			if(i!=j&&check(i,j)==0){
				cout<<"0";
				f=1;
				break;
			}
		}
		if(f==0) cout<<"1";
	}
		
	return 0;
}
