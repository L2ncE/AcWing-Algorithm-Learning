//
// Created by 袁鑫浩 on 2022/8/20.
//
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool state[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) printf("%d ", path[i]);
        puts("");

        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!state[i]) {
            path[u] = i;       // 把 i 填入数字排列的位置上
            state[i] = true;   // 表示该数字用过了 不能再用
            dfs(u + 1);        // 这个位置的数填好 递归到右面一个位置
            state[i] = false;  // 恢复现场 该数字后续可用
        }
    }
}

int main() {
    scanf("%d", &n);

    dfs(0);

    return 0;
}
