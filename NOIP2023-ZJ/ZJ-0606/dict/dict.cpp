#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<string> mi;
vector<string> ma;
string s, ans = "";

bool cmp(char a, char b){
	return a < b;
}

string sol(string ss){
	vector<char> v;
	for(int i = 0; i < m; i ++)
		v.push_back(ss[i]);
	sort(v.begin(), v.end(), cmp);
	for(int i = 0 ; i < m; i ++)
		ss[i] = v[i];
	return ss;
}

string t(string ss){
	string tt = "";
	for(int i = m - 1; i >= 0; i --)
		tt += s[i];
	return tt;
}

bool check(int i){
	for(int j = 0; j < n; j ++)
		if(i == j)
			continue;
		else
			if(mi[i] > ma[j])
				return false;
	return true;
}

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	if(n == 1){
		for(int i = 1; i <= m; i ++)
			cout << 1;
		puts("");
		return 0;
	}
	
	for(int i = 1; i <= n; i ++){
		cin >> s;
		s = sol(s);
		//cout << s << endl;
		mi.push_back(s);
		ma.push_back(t(s));
	}
	for(int i = 0; i < n; i ++){
		if(check(i))
			ans += "1";
		else
			ans += "0";
	}
	cout << ans;
	return 0;
}
