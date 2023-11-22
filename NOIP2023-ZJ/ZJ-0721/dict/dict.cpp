#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
struct node{
	string minn;
	string maxx;
	int ma;
	int mi;
}a[N];
int haxi(string s){
	return (s[0] - 'a' + 1) * 50 + s[1] - 'a' + 1;
}
int n, m;
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n == 1){
		cout << "1" << endl;
		return 0;
	}
	else{
		if (m == 1){
			string temp = "z";
			for (int i = 1; i <= n; i++){
				string s;
				cin >> s;
				a[i].minn = s;
				temp = min(temp, s);
			}
			for (int i = 1; i <= n; i++){
				if(a[i].minn != temp)
					cout << "0";
				else
					cout << "1";
			}
		}
		else if(m == 2){
			int temp = 9999999;
			for (int i = 1; i <= n; i++){
				string s;
				cin >> s;
				if(s[0] > s[1]){
					a[i].ma = haxi(s);
					a[i].mi = (s[1] - 'a' + 1) * 50 + (s[0] - 'a' + 1);
				}
				else{
					a[i].mi = haxi(s);
					a[i].ma = (s[1] - 'a' + 1) * 50 + (s[0] - 'a' + 1);
				}
				temp = min(temp, a[i].ma);
			}
			for (int i = 1; i <= n; i++){
				if(a[i].mi < temp)
					cout << "1";
				else if(a[i].mi == temp && a[i].ma == a[i].mi)
					cout << "1";
				else
					cout << "0";
			}
		}
	}
	return 0;
}