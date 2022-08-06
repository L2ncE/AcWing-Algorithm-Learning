//
// Created by 袁鑫浩 on 2022/8/6.
//
//
// Created by 袁鑫浩 on 2022/8/6.
//
#include <iostream>
#include <vector>

using namespace std;

// 判断是否有 A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i])
            return A[i] > B[i];

    return true;
}

// C = A - B
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    // 已经保证 A.size()>B.size()
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        // B有这一位才会减去B[i]
        if (i < B.size()) t -= B[i];
        // 将t大于0或小于0两种情况合二为一
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    // 去掉前导0
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;

    cin >> a >> b; // a = "123456"
    // A = [6, 5, 4, 3, 2, 1]
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> C;

    if (cmp(A, B)) C = sub(A, B);
    else C = sub(B, A), cout << '-';

    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl;

    return 0;
}