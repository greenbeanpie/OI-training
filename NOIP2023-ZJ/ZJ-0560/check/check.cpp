#include<bits/stdc++.h>
using namespace std;
char test[3005];
char com[3005];
int main() {
    int n = 3000;
    bool p = true;
    freopen("dict.out","r", stdin);
    for(int i = 1 ; i <= n; i++) test[i] = getchar();
    fclose(stdin);
    freopen("dict.ans", "r", stdin);
    for(int i = 1; i <= n; i++) com[i] = getchar();
    fclose(stdin);
    for(int i = 1; i <= n; i++) if(test[i] != com[i]) p = false;
    if(!p) printf("DIFF");
    else printf("SAME");

    return 0;

}
