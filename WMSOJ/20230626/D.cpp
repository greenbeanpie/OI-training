#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int b[N],c[N],s[N];
signed main()
{
#ifdef CODESPACE
    freopen("D.in", "r", stdin);
#endif
#ifndef CODESPACE
    freopen("car.in", "r", stdin);
    freopen("car.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string a;
    cin >> a;
    
    b[0]=c[0]=s[0]=0;
    for(int i=1;i<=a.size();i++){
        b[i]=b[i-1];
        c[i]=c[i-1];
        s[i]=s[i-1];
        if(a[i-1]=='B'){
            b[i]++;
        }
        else if(a[i-1]=='C'){
            c[i]++;
        }
        else{
            s[i]++;
        }
    }
    if(n<=8){
        int tb,tc,ts;
        int maxans=1;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<=a.size();j++){
                tb=b[j]-b[i],tc=c[j]-c[i],ts=s[j]-s[i];
                if((tb!=tc&&tc!=ts&&tb!=ts)||(tb==0&&tc==0)||(tc==0&&ts==0)||(tb==0&&ts==0)){
                    maxans=max(maxans,j-i);
                }
            }
        }
        cout << maxans;
    }
    else{
        int tb,tc,ts;
        int maxans=1;
        for(int i=0;i<=3;i++){
            for(int j=i+1;j<=a.size();j++){
                tb=b[j]-b[i],tc=c[j]-c[i],ts=s[j]-s[i];
                if((tb!=tc&&tc!=ts&&tb!=ts)||(tb==0&&tc==0)||(tc==0&&ts==0)||(tb==0&&ts==0)){
                    maxans=max(maxans,j-i);
                }
            }
        }
        for(int i=0;i<a.size()-3;i++){
            for(int j=a.size()-3;j<=a.size();j++){
                tb=b[j]-b[i],tc=c[j]-c[i],ts=s[j]-s[i];
                if((tb!=tc&&tc!=ts&&tb!=ts)||(tb==0&&tc==0)||(tc==0&&ts==0)||(tb==0&&ts==0)){
                    maxans=max(maxans,j-i);
                }
            }
        }
        cout << maxans;
    }
    return 0;
}