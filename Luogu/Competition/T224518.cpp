#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int o,l=0,d;
        for(int j=0;j<n;j++){
            cin >> o;
            if(o==1){
                l*=2;
            }
            else{
                cin >> d;
                l+=d;
            }
        }
        int t=floor(1.0*log2(l))+1;
        if(l==0){
        	cout << 0 << endl;
            continue;
		}
        while(t>0){
        	int temp=pow(2,t-1); 
            if(temp<=l){
                l-=temp;
                cout << 1;
                
            }
            else{
                cout << 0;
            }
            t--;
        }
        cout << endl;
    }
}