#include <bits/stdc++.h>
using namespace std;
#define int long long
bool join[1030]={0};
bool compete(int team1,int team2,int num){
    bool join1=false,join2=false;
    for(int i=team1;i<team1+pow(2,num);i++){
        if(!join[i]){
            join1=true;
            break;
        }
    }
    for(int i=team2;i<team2+pow(2,num);i++){
        if(!join[i]){
            join2=true;
            break;
        }
    }
    if(join1!=join2){
        return true;
    }
    else{
        return false;
    }
}
signed main(){
    int n,m;
    cin >> n >> m;
    int temp;
    for(int i=0;i<m;i++){
        cin >> temp;
        join[temp]=1;
    }
    int sum=0;
    for(int i=n;i>0;i--){
        for(int j=1;j<=pow(2,n);j+=pow(2,n-i+1)){
            if(compete(j,j+pow(2,n-i),n-i)){
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}