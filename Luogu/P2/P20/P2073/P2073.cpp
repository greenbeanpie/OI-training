#include <bits/stdc++.h>
using namespace std;

struct flower{
    long long w,c;
    
};
bool operator < (flower a,flower b){
    return a.c<b.c;
}

int main(){
    freopen("P2073.in","r",stdin);
    int o;
    set<flower> a;
    flower temp;
    while(cin >> o){
        if(o==-1){
            break;
        }
        switch (o){
            case 1:{
                cin >> temp.w >> temp.c;
                a.insert(temp);
                break;
            }
            case 2: {
                if(a.empty()){
                    break;
                }
                a.erase(--a.end());
                break;
            }
            case 3:
            {
                if(a.empty()){
                    break;
                }
                a.erase(a.begin());
                break;
            }
        }
    }
    long long sumw=0,sumc=0;
    for(set<flower>::iterator it=a.begin();it!=a.end();++it){
        sumw+=(*it).w;
        sumc+=(*it).c;
    }
    
    cout << sumw << " " << sumc;
}