#include<bits/stdc++.h>
using namespace std;
int N,M;
struct word{char ma = 0,mi = 0x7f;}str[3010];
char in;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> N >> M;
	for(int i = 1;i <= N;++i){
		for(int j = 1;j <= M;++j){
			cin >> in;
			str[i].ma = max(in,str[i].ma);
			str[i].mi = min(in,str[i].mi);
		}
	}
	for(int i = 1;i <= N;++i){
		bool res = 1;
		for(int j = 1;j <= N;++j){
			if(j == i) continue;
			if(str[i].mi >= str[j].ma){res = 0;break;}
		}
		cout << (res?1:0);
	}
	return 0;
}
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
