#include <bits/stdc++.h>
using namespace std;
const int MAXN=3001;
string s[MAXN];
int cnt[MAXN][27],_min[MAXN],_max[MAXN];
bool check(int x,int y){
	if (_min[x]<_max[y]) return true;
	return false;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		cin>>s[i];
		for(int j=0;j<m;++j){
			cnt[i][s[i][j]-'a'+1]++;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=26;++j){
			if (cnt[i][j]){
				if (!_min[i]){
					_min[i]=j;
				}
				_max[i]=j;
			}
		}
	}
	for(int i=1;i<=n;++i){
		bool flag=0;
		for(int j=1;j<=n;++j){
			if (j!=i){
				if (!check(i,j)){
					flag=1;
					printf("0");
					break;
				}
			}
		}
		if (!flag){
			printf("1");
		}
	}
	return 0;
}