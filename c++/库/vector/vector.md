# vector初始化

| 代码 | 值 | 解释 |
| ---- | ---- | ---- |
|vector<int> a(5);  |  a = [0, 0, 0, 0, 0] | a=大小等于5的整型向量|
|vector<int> b(5,1);  |  b = [1, 1, 1, 1, 1] | b=大小等于5的整型向量，初值为1|
|vector<int> c(b);  |  c = [1, 1, 1, 1, 1] | 用b复制赋值给c|
|vector<int> d(b.begin(),b.begin()+3);  |  d = [1, 1, 1] | 把b的前3个数赋值给d|
|int *point=&b[0]; vector<int> e(point,point+3);  |  e = [1, 1, 1] | 与上面是同样的道理，自定义指针操作 *point=1 但是容易指出去|



# 访问vector属性

| 代码 | 值 | 解释 |
| ---- | ---- | ---- |
|b.empty(); | b.empty()=0 | 判断是否清空了，其实就是判断size是否为0|
|b.size(); | b.size()=5 | b 中有效元素的个数|
|b.front(); | b.front()=1 | b开头的数值|
|b.back(); |b.back()= 1 | b末尾的数值|
|b.begin() | b.begin() = 00AE6D48  | 返回b开头的地址|
|b.end() | b.end() = 00AE6D5C  | 返回b末尾的地址|



# 修改vector
| 代码 | 值 | 解释 |
| ---- | ---- | ---- |
|b.assign(3,2);  |  b = [2, 2, 2] | 将b设置为大小为3,数值全是2的向量（此时b的capacity还是不变还是5）|
|b.resize(4);   |  b = [2, 2, 2, 0] | 将b的现有元素个数调至4个，多则删，少则补0|
|b.resize(5,3);   |  b = [2, 2, 2, 0, 3] | 将b的现有元素个数调至5个，多则删，少则补3|
|b.reserve(100);  | b.capacity()=100 | 将b的容量（capacity）扩充至100|
|a.assign(b.begin(), b.begin()+2);  |  a = [2, 2] | 将a设置为b向量前2个数,（此时b的capacity还是不变还是5）|
|a.clear()  |  a = [] | 清空(size为零，capacity不变)|
|a.pop_back(); | a.size()=4294967295 | 如果a是空向量认执行pop操作，a的size还是减1，等于八位0-1,没有空异常判断，此时a不为 空|
|a.push_back(5);  |  a = [5] | 在a末尾添加一个元素（因为上次a的size为-1，所以push了两次）|
|a.insert(a.begin()+1,2);  |  a = [5, 2] | 在a第一个元素a[0]后面插入2|
|a.insert(a.begin()+1,2);  |  a = [3, 3, 3, 5, 2] | 在a第一个元素a[0]前面插入3个3|
|a.insert(a.begin()+1,b.begin(),b.begin()+2);  |  a = [3, 2, 2, 3, 3, 5, 2] | 把b[0]到b[1]插入到a[0]后面。（b只要是连续存储的数据类型就行，数组，堆栈...）|
|c.erase(c.begin(), c.begin()+2);  |  c = [1, 1, 1] | 删除c[0]~c[1]的元素(2个元素)|
