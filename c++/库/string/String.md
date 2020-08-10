# String

```c++
    string s1 = "how to use string??";
    string s2 = "??";
    string s3 = "use";
    string s4 = "to";
```



## 访问

| 代码 | 值   | 含义 |
| ---- | ---- | ---- |
|s1.length() |19 | 字符串s的长度|
|s1.c_str() |how to use string?? | 转换成c语言类型：string to char|
|s1[0] |h | 访问字符串中的字符|
|s1.substr(2, 6) |w to u | 从s[2]开始提取6个字符串。pos 越界，会抛出异常； len 越界，会提取从 pos 到字符串结尾处的所有字 符。|
|s1.find(s2,1) |17 | 在s1[1]-s[末尾]查找s2，返回第一次出现的下标，没有出现返回-1。|
|s1.rfind(s2,1) |7 | 在s[0]-s[7]查找从s3，返回第一次出现的下标，没有出现返回-1。如果s1[7]-s[9]是字符串s3，这是可以找到的 。|
|s1.find_first_of(s4); |1 |  s1 和 s4 共同具有的字符是 ’0’，该字符在 s1 中首次出现的下标是1|



## 修改

| 代码 | 值   | 含义 |
| ---- | ---- | ---- |
|s1+s2 |how to use string???? | 字符串的拼接，s1 s2不变|
|s1.insert(6, s2); |how to?? use string?? | 在s1[6]开始（s1[5]后面）插入字符串|
|s1.erase(6,2);|how to use string?? | 从s1[6]开始删除2个字节|

