#include <bits/stdc++.h>
using namespace std;

namespace Main{
	#define int long long
	const int N=1e6+5;
	vector<pair<int,int>> op1,op2;
	int main(){
		int n;
		cin >> n;
		string s;
		cin >> s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='+' || s[i]=='-'){
				op1.emplace_back(i,-1);
			}
			else if(s[i]=='*' || s[i]=='/'){
				op2.emplace_back(i,-1);
			}
		}
		int cur=0;
		for(int i=0;i<op2.size();i++){
			op2[i].second=++cur;
		}
		for(int i=0;i<op1.size();i++){
			op1[i].second=++cur;
		}
		int pt1=0,pt2=0;
		for(int i=0;i<s.size();i++){
			cout << s[i];
			if(s[i]=='+' || s[i]=='-'){
				cout << "[" << op1[pt1++].second << "]";
			}
			else if(s[i]=='*' || s[i]=='/'){
				cout << "[" << op2[pt2++].second << "]";
			}
		}
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	freopen("arithmetic.in","r",stdin);
//	freopen("arithmetic.out","w",stdout);
	Main::main();
	return 0;
}
