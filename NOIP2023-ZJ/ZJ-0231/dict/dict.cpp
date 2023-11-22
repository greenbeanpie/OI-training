#include <bits/stdc++.h>
const int N = 3005;

using namespace std;
int ans[N];
int n,m;
string s[N];
string t[N];
bool cmp(char x, char y){
	return x > y;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		t[i] = s[i];
		sort(s[i].begin(),s[i].end(),cmp);
		sort(t[i].begin(),t[i].end());
	}
	for(int i = 1; i <= n; i++){
		bool f = 1;
		for(int j = 1; j <= n && f; j++){
			if(i == j) continue;
			if(t[i] > s[j]) f = 0;
		}
		ans[i] = f;
	}
	for(int i = 1; i <= n; i++) printf("%d",ans[i]);
	return 0;
}