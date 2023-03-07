#include <bits/stdc++.h>
using namespace std;

long long quickpower(long long a,long long b){
    if(floor(log10(a))+floor(log10(b))>=18){
        return -1;
    }
    long long answer=1,base=b;
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    while(base){
        if(base&1){
            answer=answer*a;
        }
        a=a*a;
        base=base>>1;
    }
    return answer;
}

int main(){
    long long a,b;
    cin >> a >> b;
    set<long long> ans;
    if(a==1){
        cout << 1;
        return 0;
    }
    long long temp;
    int j;
    ans.insert(1);
    for(int i=2;i<=a;i++){
        for(j=b;;j++){
            temp=quickpower(i,j);
            if(temp>a||temp<0){
                break;
            }
            ans.insert(temp);
        }
        if(j==b){
            break;
        }
    }
    cout << ans.size();
    return 0;
}