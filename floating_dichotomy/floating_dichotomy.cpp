//
// Created by 袁鑫浩 on 2022/8/6.
//
// 给定一个浮点数 x，求它的三次方根
#include <iostream>

using namespace std;

int main()
{
    double x;
    cin >> x;

    double l = -100, r = 100;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }

    printf("%.6lf\n", l);
    return 0;
}