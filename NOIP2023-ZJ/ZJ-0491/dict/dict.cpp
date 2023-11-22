//AC?
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
char str[3010];
char mn[3010][3010];
char mx[3010][3010];
bool sx(char x,char y){
	return x < y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			cin>>str[j];
		}
		sort(str + 1,str + m + 1,sx);
		for(ll j = 1;j <= m;j++){
			mn[i][j] = mx[i][m - j + 1] = str[j];
		}
	}
	for(ll i = 1;i <= n;i++){
		bool can = true;
		for(ll j = 1;j <= n;j++){
			if(i == j){
				continue;
			}
			can = false;
			for(ll k = 1;k <= m;k++){
				if(mn[i][k] < mx[j][k]){
					can = true;
					break;
				}
				else if(mn[i][k] > mx[j][k]){
					break;
				}
			}
			if(!can){
				break;
			}
		}
		if(can){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn

aabdnno
aaaabnn
aaaabnn
nnnoott

onndbaa
nnbaaaa
nnbaaaa
ttoonnn
*/