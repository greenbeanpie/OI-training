#include <bits/stdc++.h>
using namespace std;
int n, m;
char dic[3005][3005];
char best[3005][3005];
char worst[3005][3005];
void deal(int x) {
    sort(dic[x], dic[x] + m);
    for (int i = 0; i < m; i++) {
        best[x][i] = dic[x][i];
        worst[x][m - i - 1] = dic[x][i];
    }
}
//smaller?
bool cmp(int x, int y) {
    for (int i = 0; i < m; i++) {
        if (best[x][i] < worst[y][i]) {
            return true;
        }else if (best[x][i] > worst[y][i]) {
            return false;
        }
    }
    return true;
}
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    
    scanf("%d %d", &n, &m);

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (m == 1) {
        char ch;
        char mc = 'z';
        int mi;
        for (int i = 0; i < n; i++) {
            cin >> ch;
            if (ch <= mc) {
                mc = ch;
                mi = i;
            }
        }
        //cout << mc << endl;
        //cout << mi << endl;
        for (int i = 0; i < mi; i++) {
            cout << 0;
        }
        cout << 1;
        for (int i = mi + 1; i < n; i++) {
            cout << 0;
        }
        return 0;
    }
    
    
    bool f = 0;
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dic[i][j];
        }
        deal(i);
    }
    */
   for (int i = 0; i < n; i++) {
        scanf("%s", &dic[i]);
        deal(i);
    }
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << best[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << worst[i][j];
        }
        cout << endl;
    }
    */
    
    for (int i = 0; i < n; i++) {
        f = 1;
        for (int j = 0; j < n && j != i; j++) {
            if (!cmp(i, j)) {
                printf("%d", 0);
                f = 0;
                break;
            }
        }
        if (f) {
            printf("%d", 1);
        }
    }

    
    fclose(stdin);
    fclose(stdout);
    return 0;
}