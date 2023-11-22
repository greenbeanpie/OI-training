#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[3005][3005];
string mx[3010],mnn[3005];
int cnt;
int mn;
int ans[3005];
string mxx;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	mn = 100;
	if(n == 1){
		cout << "1";
		return 0;
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			cin >> s[i][1];
			if(mn > s[i][1] -'a'+1){
				mn =  s[i][1]-'a'+1;
			}
		}	
		for(int i = 1;i <= n;i++){
			if(mn == s[i][1]-'a'+1){
				cout << "1";
			}else{
				cout << "0";
			}
		}
	}else{
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> s[i][j];
			}
			sort(s[i]+1,s[i]+1+m);
			for(int j = 1;j <= m;j++){
				mnn[i][j] = s[i][j];
//				cout << mnn[i][j];
			}
//			cout << "\n";
			for(int j = 1;j <= m;j++){
				mx[i][j] = s[i][m-j+1];
			}
		}
		for(int i = 1;i <= m;i++){
			mxx[i] = mx[1][i];
		}
		for(int i = 2;i <= n;i++){
			bool flag = 1;
			for(int j = 1;j <= m;j++){
				if(mxx[j] == mx[i][j]) continue;
				if(mxx[j] < mx[i][j]) break;
				else{
					flag = 0;
					break;
				}
			}
			if(!flag){
				for(int j = 1;j <= m;j++){
					mxx[j] = mx[i][j];
				}
			}
		}
		for(int i = 1;i <= n;i++){
			bool flag = 1;
			for(int j = 1;j <= m;j++){
				if(mnn[i][j] == mxx[j]) continue;
				if(mnn[i][j] < mxx[j]) break;
				else{
					flag = 0;
					break;
				}
			}
			
			if(flag) ans[i] = 1;
		}
		for(int i = 1;i <= n;i++) cout << ans[i];
	}
	return 0;
}
