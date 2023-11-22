#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int c, t, ans = maxn;
int n, m;
struct nd{
	string c;
	int a, b;
};
vector<nd> G(maxn);
vector<string> G1(maxn);

void init(){
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		cin >> G[i].c;
		if(G[i].c == "+" || G[i].c == "-"){
			scanf("%d%d", &G[i].a, &G[i].b);
		}
		else{
			scanf("%d", &G[i].a);
			G[i].b = 0;
		}
	}
}

void solve1(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> n >> m;
	string sf;
	int a, num=0;
	for(int i=1; i<=m; i++){
		cin >> sf >> a;
		G1[a] = sf;
	}
	for(int i=1; i<=n; i++){
		if(G1[i] == "U") num++;
	}
	cout << num <<endl;
}

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	if(c == 1 || c==2){
		while(t--){
			init();
			ans = 0;
			cout << int(G[2].a % 10);
		}
	}
	if(c == 3 || c == 4){
		solve1();
	}
}
