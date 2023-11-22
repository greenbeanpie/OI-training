#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 3010;
char minc[MAX_N];
priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> heap;

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    string tw;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> tw;
        char ic=127,ac=0;
        for(auto it:tw) {
            ic=min(ic,it);
            ac=max(ac,it);
        }
        minc[i]=ic;
        heap.push(make_pair(ac,i));
    }
    bool flag=false;
    for(int i=1; i<=n; i++) {
        pair<int,int> cac;
        if(heap.top().second==i) {
            cac=heap.top();
            heap.pop();
            flag=true;
        }
        if(minc[i]<heap.top().first) {
            cout << 1;
        }else{
            cout << 0;
        }
        if(flag) {
            heap.push(cac);
            flag=false;
        }
    }
    cout << endl;
    return 0;
}
