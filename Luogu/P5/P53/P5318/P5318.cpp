#include <bits/stdc++.h>
using namespace std;
#define mian main
#define itn int
#define tni int
#define tin int
#define nti int
#define nit int
#define int long long

int sum=0;
int count(int page){
    if(page<10){
        return (1+page)*page/2;
    }
    int temp=pow(10,floor(log10(page)));
    sum+=(page/temp)*(page%temp);
    sum+=(page/temp)*(page/temp-1)/2*temp;
    page/=10;
    sum+=count(page);
    return sum;
}

signed main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << count(n);
    return 0;
}