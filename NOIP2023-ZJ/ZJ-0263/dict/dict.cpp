#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m, p;
string s[N], S;
int buct[30][N];

signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		for(int j = 0; j < m; j++)
			buct[s[i][j] - 'a'][i]++;
	}
	
	for(int i = 1; i <= n; i++){
		string t = "";
		for(int j = 25; j >= 0; j--)
			for(int k = 1; k <= buct[j][i]; k++)
				t += char('a' + j);
		if( !p ){
			S = s[i];
			p = i;
		}
		else{
			for(int j = 0; j < m; j++){
				if( int(S[j]) != int(t[j]) ){
					if( int(S[j]) > int(t[j]) ){
						S = t;
						p = i;
					}
					break;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		string t = "";
		for(int j = 0; j < 26; j++)
			for(int k = 1; k <= buct[j][i]; k++)
				t += char('a' + j);
		
		bool flag = 0;
		for(int j = 0; j < m; j++){
			if( int(S[j]) != int(t[j]) ){
				if( int(S[j]) > int(t[j]) )
					flag = 1;
				break;
			}
		}
		cout << flag;
	}
	return 0;
}