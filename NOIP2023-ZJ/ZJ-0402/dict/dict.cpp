#include<bits/stdc++.h>
const int N = 3005;
int n, m; std::string s[N];
int ord[N];
bool cmp(int i, int j){
    return s[i] < s[j];
}
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        std::cin >> s[i];
        std::sort(s[i].begin(), s[i].end(), std::greater<int>());
    }
    if(n == 1) return printf("1\n"), 0;
    for(int i=1; i<=n; i++)
        ord[i] = i;
    std::sort(ord+1, ord+n+1, cmp);
    for(int i=1; i<=n; i++){
        auto t = s[i];
        std::sort(t.begin(), t.end());
        if(ord[1] == i){
            printf("%d", s[ord[2]]>t);
        }else{
            printf("%d", s[ord[1]]>t);
        }
    }
    printf("\n");
    return 0;
}
