//
// Created by 袁鑫浩 on 2022/8/8.
//
// low_bit操作
#include <iostream>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        int res = 0;
        while (x) x -= lowbit(x), res++;

        cout << res << endl;
    }
    return 0;
}