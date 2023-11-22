#include<bits/stdc++.h>
using namespace std;
#define int long long
void file(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
}
signed main(){
    file();
    int c,t,cnt=0;
    cin>>c>>t;
    
    while(t--){
        cnt=0;
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        int x,y,z;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>z;
            if(z-y*d>0&&y<=k){
                cnt+=(z-y*d);
            }
        }
        cout<<cnt<<endl;
    }
}