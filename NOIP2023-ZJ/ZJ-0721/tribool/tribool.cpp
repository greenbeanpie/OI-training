#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int c, t, n, m;
int a[N];
int b[N];
int main(){
	freopen("tribool.in", "r", stdin);
	freopem("tribool.out", "w", stdout);
	cin >> c >> t;
	if(c == 3 || c == 4){
		while(t--){
			int tot = 0;
			cin >> n >> m;
			memset(a, 0, sizeof(a));
			memset(a, 0, sizeof(b));
			for (int i = 1; i <= m; i++){
				string v; 
				int temp;
				cin >> v;
				cin >> temp;
				if(v == "U")
					a[temp] = 3;
			}
			for (int i = 1; i <= n; i++){
				if(a[i] == 3)
					tot++;
			}
			cout << tot << endl;
		}
	}
	else if(c == 5 || c == 6){
		while(t--){
			int tot = 0;
			cin >> n >> m;
			memset(a, 1, sizeof(b));
			memset(b, 1, sizeof(b));
			for (int i = 1; i <= m; i++){
				string v;
				int temp_i, temp_j, temp_k;
				cin >> v;
				if(v == "U"){
					cin >> temp_k;
					a[temp_k] = 3;
				}
				else{
					cin >> temp_i >> temp_j;
					a[temp_i] = a[temp_j];
				}	
			}
			for (int i = 1; i <= n; i++){
				if(a[i] == 3)
					tot++;
			}
			cout << tot << endl;
		}
	}
	
	return 0;
}