#include <bits/stdc++.h>
using namespace std;
long long a,b,p;
long long quickpower(long long a,long long b){
    if(b==0)
    {
        return 1;
    }
    long long answer=1;
    while(b)
    {
        if(b&1)
        {
            answer=answer*a%p;
        } 
        a=a*a%p;
        b>>=1;
    } 
    return answer;
}

int main(){
    freopen("P1226.in","r",stdin);
    
    cin >> a >> b >> p;
    cout << a << "^" << b << " " << "mod" << " " << p << "=";
    cout << quickpower(a,b)%p;
    return 0;
}