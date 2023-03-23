#include <bits/stdc++.h>
using namespace std;
#define int long long
int temp;

signed main(){
    ios::sync_with_stdio(false);
    
    int n,m;
    cin >> n >>m;
    set<int> a;
    vector<int> b[n];
    int temp;
    for(int i=0;i<n;i++){
    	cin >> temp;
    	a.insert(temp);
    	b[i].push_back(temp);
    }
    string o;
    bool flag=false;
    for(int i=0;i<m;i++){
    	cin >> o;
    	if(o=="INSERT"){
    		int j,k;
    		cin >> j >> k;
    		int size1=a.size();
    		a.insert(k);
    		int size2=a.size();
    		if(size1==size2){
    			flag=true;
    		}
    		b[j].push_back(k);
    	}
    	else if(o=="MIN_GAP"){
    		int x=0,mininum=1e10;
    		while(x<n){
    			auto y=b[x].begin();
    			y++;
    			while(y!=b[x].end()){
    				mininum=min(mininum,abs(*y-*(--y)));
    				y++;
    				y++;
    			}
    			if(x<n-1){
    				mininum=min(mininum,abs(*y-*b[x+1].begin()));
    			}
    			x++;
    		}
    		cout << mininum << endl;
    	}
    	else {
    		if(flag){
    			cout << 0 << endl;
    		}
    		else{
    			int mininum=1e10;
    			for(auto i=++a.begin();i!=a.end();i++){
    				mininum=min(mininum,abs(*i-*(--i)++));
    			}
    			cout << mininum << endl;
    		}
    	}
    }
    return 0;
}
