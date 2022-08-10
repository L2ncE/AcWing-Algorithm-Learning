//
// Created by 袁鑫浩 on 2022/8/10.
//
#include <iostream>

using namespace std;

const int N = 100010;

int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    while (m -- )
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M') p[find(a)] = find(b);
        else
        {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
/*
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        cnt[i] = 1;
    }

    while (m -- )
    {
        string op;
        int a, b;
        cin >> op;

        if (op == "C")
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }

    return 0;
}

 #include <iostream>

using namespace std;

const int N = 50010;

int n, m;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int res = 0;
    while (m -- )
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n) res ++ ;
        else
        {
            int px = find(x), py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3) res ++ ;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
*/