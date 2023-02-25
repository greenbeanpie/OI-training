#include <bits/stdc++.h>
using namespace std;
bool isp[100000005];
int prime[100000005]={0};
int main(){
    std::ios::sync_with_stdio(0);
    int n,len=0,x;
    for(int i=2;i<=100000005;i++){
        if(!isp[i]){
            prime[++len]=i;
        }
        for(int j=1;j<=len&&i*prime[j]<=n;j++){
            isp[i*prime[j]]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    cin >> n;
    cout << prime[n];
    return 0;
}