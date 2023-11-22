#include<bits/stdc++.h>
using namespace std;
int n,m;
string st[3010],MAX[3010],MIN[3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}else if(m==1){
		char c[3010];
		int _MIN=1e7+7;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			_MIN=min(int(c[i]),_MIN);
		}
		for(int i=1;i<=n;i++){
			if(int(c[i])==_MIN){
				cout<<1;
		    }else{
		    	cout<<0;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>st[i];
		MAX[i]=st[i];
		MIN[i]=st[i];
    }
    for(int i=1;i<=n;i++){
    	for(int j=0;j<m;j++){
    		for(int r=j;r<m;r++){
    			if(MAX[i][j]<=MAX[i][r]){
    				swap(MAX[i][j],MAX[i][r]);
				}
				if(MIN[i][j]>=MIN[i][r]){
					swap(MIN[i][j],MIN[i][r]);
				}
			}
		}
	}
    for(int i=1;i<=n;i++){
    	int cnt=0;
    	for(int j=1;j<=n;j++){
    		if(i==j)continue;
    		if(MIN[i]<MAX[j]){
    			cnt++;
		    }
		}
		if(cnt==n-1)cout<<1;
		else cout<<0;
	}
	return 0;
}
