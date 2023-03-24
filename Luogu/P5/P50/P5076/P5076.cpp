#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("P5076.in","r",stdin);
    #endif
    int q;
    cin  >> q;
    multiset<int> t;
    t.insert(-2147483647);
    t.insert(2147483647);
    for(int i=0;i<q;i++){
        int op,x;
        cin >> op >> x;
        if(op==1){
            multiset<int>::iterator temp=t.lower_bound(x);
            int t2=0;
            for(set<int>::iterator i=t.begin();i!=temp;i++,t2++){}
            cout << t2 << endl;
        }
        else if(op==2){
            multiset<int>::iterator temp=t.begin();
            for(int i=0;i<x;i++,temp++){}
            cout << *temp << endl;
        }
        else if(op==3){
            multiset<int>::iterator temp=t.lower_bound(x);
            cout << *--temp << endl;
            
        }
        else if(op==4){
            multiset<int>::iterator temp=t.upper_bound(x);
            cout << *temp << endl;
            
        }
        else{
            t.insert(x);
        }
    }
    return 0;
}