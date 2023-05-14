#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int T=0;T<t;T++){
		int n,m;
		char c;
		cin >> n >> m >> c;
		bool mmap[n][m];
		pair<int,int> vis[n][m],start,end;
		for(int i=0;i<n;i++){// 输入
			for(int j=0;j<m;j++){
				char c;
				cin >> c;
				if(c=='#'){
					mmap[i][j]=0;
				}
				else{
					mmap[i][j]=1;
					if(c=='S'){
						start={i,j};
					}
					else if(c=='T'){
						end={i,j};
					}
				}
			}
		}
		queue<pair<int,int> > q;
		if(c=='K'){
			vis[start.first][start.second]={0,0};
		}
        else if(c=='N'){
            vis[start.first][start.second]={0,1};
        }
        else if(c=='R'){
            vis[start.first][start.second]={0,2};
        }
        else{
            vis[start.first][start.second]={0,3};
        }
        q.push(vis[start.first][start.second]);
        
	}
	return 0;
}