#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3003, S = 30;
int n, m, ord[N][S];
string s[N];
int id(char &a){
    return a - 'a' + 1;
}
bool gt(int x, int y){ //!=
    int a[S], b[S];
    for(int i = 1; i <= 26; ++ i) a[i] = ord[x][i], b[i] = ord[y][i];
    for(int i = 1, j = 26; ; ){
        while(!a[i]) ++ i;
        while(!b[j]) j --;
        if(i < j) return 0;
        if(i > j) return 1;
        if(a[i] < b[j]) return 0;
        if(a[i] > b[j]) return 1;
        a[i] = b[j] = 0;
    }
}
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(n == 1) return putchar('1'), 0;
    for(int i = 1; i <= n; ++ i){
        cin >> s[i];
        for(int j = 0; j < m; ++ j) ++ ord[i][id(s[i][j])];
    }
    for(int i = 1; i <= n; ++ i){
        bool tf = 1;
        for(int j = 1; j <= n; ++ j) if(i != j && gt(i, j)) tf = 0;
        cout << tf;
    }
    return 0;
}
