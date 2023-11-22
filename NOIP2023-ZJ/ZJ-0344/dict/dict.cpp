#include <bits/stdc++.h>
using namespace std;
const int MAXN=3005;
int n,m;
struct Data {
	string s;
	int chars[26];
};
Data s[MAXN];
void init(string& str, int* arr) {
	for(int i=0; i<str.length(); i++) {
		arr[str[i] - 'a']++;
	}
}
bool cmp(string& s1, string&s2) {
	for(int i=0; i<m; i++) {
		if (s1[i] < s2[i])
			return true;
		else if (s1[i] > s2[i])
			return false;
	}
	return false;
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> s[i].s;
		//init(s[i].s, s[i].chars);
	}

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (m == 1) {
		int t=0;
		for(int i=0; i<n; i++) {
			if (s[t].s >= s[i].s) {
				t = i;
			}
		}
		for(int i=0; i<n; i++)
			cout<<(i == t ? 1 : 0);
		cout << endl;
	} else if (m==2) {
		for(int i=0; i<n; i++) {
			int t=0;
			for(int j=0; j<n; j++) {
				if (j==i) continue;
				if (cmp(s[i].s, s[j].s)) {
					t++;
					continue;
				}
				swap(s[j].s[0], s[j].s[1]);
				if (cmp(s[i].s, s[j].s)) t++;
				swap(s[j].s[0], s[j].s[1]);
			}
			if (t==n-1) {
				cout<<1;
				continue;
			}
			reverse(s[i].s.begin(), s[i].s.end());
			t=0;
			for(int j=0; j<n; j++) {
				if (j==i) continue;
				if (cmp(s[i].s, s[j].s)) {
					t++;
					continue;
				}
				swap(s[j].s[0], s[j].s[1]);
				if (cmp(s[i].s, s[j].s)) t++;
				swap(s[j].s[0], s[j].s[1]);
			}
			if (t==n-1) {
				cout<<1;
				continue;
			}
			cout<<0;
		}
		cout<<endl;
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
