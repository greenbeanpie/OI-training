#include<bits/stdc++.h>
using namespace std;

int t[3005][30], pre[3005][30];
int n, m;

bool solve(int x){
	for(int j=1; j<=26; j++){
		if(!t[x][j]) continue;
		for(int k=1; k<=n; k++){
			if(k==x) continue;
			if(pre[k][j]==m) return false;
		}
		return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin>>n>>m;
	char ch;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>ch;
			//t[i][j] = ch-'a'+1;
			t[i][ch-'a'+1]++;
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=26; j++){
			pre[i][j] = pre[i][j-1] + t[i][j];
		}
	}
	
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=26; j++){
//			cout<<pre[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	for(int i=1; i<=n; i++){
		if(solve(i)) cout<<1;
		else cout<<0;
	}
	return 0;
}

/*
4 7
abandon
bananaa
baannaa
notnotn
*/
