#include <bits/stdc++.h>
using namespace std;
vector<string> G(3005);
vector<int> Gmx(3005);
vector<string> Gmn(3005);
int n, m;

void solve1(){
	cout << 1;
}

void solve2(){
	int pos;
	string mn = "z";
	for(int i=1; i<=n; i++){
		if(G[i] < mn){
			mn = G[i], pos = i;
		}
	}
	for(int i=1; i<=n; i++){
		if(i == pos) cout << 1;
		else cout << 0;
	}
}

void solve3(){
	for(int i=1; i<=n; i++){
		if(G[i][0] > G[i][1]) Gmx[i] = 0;
		else Gmx[i] = 1;
	}
	for(int i=1; i<=n; i++){
//		cout << G[i] << " " << Gmx[i] << "\n";
		bool flag = true;
		for(int j=1; j<=n; j++){
			if(i != j){
				if(Gmx[i] == 1 && Gmx[j] == 1){
					if(G[i][0] >= G[j][1]){
						flag = false;
						cout << 0;
						break;
					}
				}
				if(Gmx[i] == 1 && Gmx[j] == 0){
					if(G[i][0] >= G[j][0]){
						flag = false;
						cout << 0;
						break;
					}
				}
				if(Gmx[i] == 0 && Gmx[j] == 1){
					if(G[i][1] >= G[j][1]){
						flag = false;
						cout << 0;
						break;
					}
				}
				if(Gmx[i] == 0 && Gmx[j] == 0){
//					cot << G[i] << " " << G[j] << "A";
					if(G[i][1] >= G[j][0]){
						flag = false;
						cout << 0;
						break;
					}
				}
			}
		}
		if(flag) cout << 1;
	}
}

void solve4(){
	for(int i=1; i<=n; i++){
		sort(Gmn[i].begin(), Gmn[i].end());
	}
	int num = 0;
	for(int i=1; i<=n; i++){
		bool flag = true;
		for(int j=1; j<=n && j!=i; j++){
			if(Gmn[i][0] >= Gmn[j][m-1]){
				flag = false;
				cout << 0;
				break;
			}
		}
		if(flag) cout << 1;
	}
//	for(int i = 1; i<=n; i++){
//		cout << int(G[i][0]) % 2;
//	}
}

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> G[i];
		Gmn[i] = G[i];
	}
	if(n <= 1) solve1();
	else if(m <= 1) solve2();
	else if(m <= 2) solve3();
	else solve4();
}

