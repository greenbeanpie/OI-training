#include <iostream>
using namespace std;
int n, m, k, d, x, y, v;
int read(){
    int x = 0;
    char a = getchar();
    while(a < '0' || '9' < a) a = getchar();
    while('0' <= a && a <= '9') x = (x << 1) + (x << 3) + (a ^ 48), a = getchar();
    return x;
}
void write(int x){
    if(x > 9) write(x / 10);
    putchar(x | 48);
}
int main(){
    //freopen("run.in", "r", stdin);
    //freopen("run.out", "w", stdout);
    read();
    for(int t = read(); t >= 1; t --){
        n = read(), m = read(), k = read(), d = read();
        for(int i = 1; i <= m; ++ i){
            x = read(), y = read(), v = read();

        }
    }
    return 0;
}
