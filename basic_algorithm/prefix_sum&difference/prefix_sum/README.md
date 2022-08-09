## 前缀和

先用for循环生成出s数组，然后直接s[r] - s[l-1]

PS：s[0]定义为 0 

```c++
S[i] = a[1] + a[2] + ... a[i]
a[l] + ... + a[r] = S[r] - S[l - 1]
```