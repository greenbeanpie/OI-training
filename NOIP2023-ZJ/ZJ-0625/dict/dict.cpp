#include <bits/stdc++.h.>
using namespace std;
const int maxm = 3010;
int n,m;
int exc[3010][maxm],exc2[3010][maxm];
string str[maxm];
string pre(int x) {
	int len = str[x].length();
	exc[x][len - 1] = len - 1;
	for(int i = len - 2;i >= 0;i --)
		exc[x][i] = (str[x][i]<str[x][exc[x][i+1]]?i:exc[x][i+1]);
	string tmp = str[x],ans = tmp;
	for(int i = 0;i < len;i++) {
		swap(tmp[i],tmp[exc[x][i]]);
		if(tmp < ans) ans = tmp;
		swap(tmp[i],tmp[exc[x][i]]);		
	}
	return ans;
}
string pre2(int x) {
	int len = str[x].length();
	exc2[x][len - 1] = len - 1;
	for(int i = len - 2;i >= 0;i --)
		exc2[x][i] = (str[x][i]>str[x][exc2[x][i+1]]?i:exc2[x][i+1]);
	string tmp = str[x],ans = tmp;
	for(int i = 0;i<len;i++) {
		swap(tmp[i],tmp[exc2[x][i]]);
		if(tmp > ans) ans = tmp;
		swap(tmp[i],tmp[exc2[x][i]]);
	}
	return ans;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	if(n == 1) {
		cout << 1;
		return 0;
	}
	switch(m) {
		case 1:
			for(int i=1;i<=n;i++) cin >> str[i];
			for(int i=1;i<=n;i++) {
				bool flag = true;
				for(int j=1;j<=n;j++)
					if(str[j] < str[i]) {
						flag = false;
						break;
					}
				cout << flag;
			}
			break;
		case 2:
			for(int i=1;i<=n;i++) cin >> str[i];
			for(int i=1;i<=n;i++) {
				bool flag = true;
				for(int j=1;j<=n;j++) {
					if(j == i) continue;
					string tmp = str[i];
					swap(tmp[0],tmp[1]);
					{
//					printf("\n\n%s %s %s\n",str[i].c_str(),str[j].c_str(),tmp.c_str());
//					if(tmp <= str[j]) {
//						if(tmp < str[i]) {
//							flag = false;
//							break;
//						}
//					}else {
//						if(str[j] < str[i]) {
//							flag = false;
//							break;
//						}
//					}
					}
					if((str[i] <= tmp ? str[i] : tmp) > str[j]) {
						flag = false;
						break;
					}
				}
				cout << flag;
			}
			break;
		default:
			for(int i=1;i<=n;i++) cin >> str[i];
			for(int i=1;i<=n;i++) {
				string tmp1 = pre(i);
				bool flag = true;
				for(int j=1;j<=n;j++) {
					if(j == i) continue;
					string tmp2 = pre2(j);
//					printf("\n\n%s %s\n\n",tmp1.c_str(),tmp2.c_str());
					if(tmp1 > tmp2) {
						flag = false;
						break;
					}
				}
				cout << flag;
			}
			break;
	}
}