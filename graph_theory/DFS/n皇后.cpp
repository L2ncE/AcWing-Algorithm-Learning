//
// Created by 袁鑫浩 on 2022/8/20.
//
#include <iostream>

using namespace std;
const int N = 20;//对角线元素 2n-1 取20防止越界
int n;
char g[N][N]; //存储图
bool row[N], col[N], dg[N], udg[N]; //udg 副对角线 /
//英语单词 column 列   diagonal 主角线 \
//row 行

void dfs(int x, int y, int s) {  //xy为坐标 (x,y) s为 n皇后放置个数

    if (y == n) { //当x走到行末尾的时候
        y = 0;    //转到下一行的第一个
        x++;
    }

    if (x == n) { //走到最后一行 且n皇后都放好的时候
        if (s == n) { // 如果找到方案的话
            for (int i = 0; i < n; i++) {
                puts(g[i]);//puts输出二维数组 输出每一行如何就会自动换行
            }//puts遍历字符串这个语法不懂看下
            puts("");
        }
        return; //返回调用函数进行执行
    }

    dfs(x, y + 1, s);//不放皇后  并且访问右节点

    // 判断皇后能否放在这格
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
        g[x][y] = 'Q';//放皇后 然后把
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;

        dfs(x, y + 1, s + 1);//放置皇后，找下一层的

        //回溯的时候 记得恢复现场 ↓
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.'; //初始化全部空格子
        }
    }
    dfs(0, 0, 0); //从(0,0)开始找

    return 0;
}
