# 属性

| 属性名  | 用法       | 含义     |
| ------- | ---------- | -------- |
| Index   | df.index   | 行的名字 |
| columns | df.columns | 列的名字 |
| values  | df.values  | 每个值   |
| T       | df.T       | 转置     |

# 方法

| 方法名      | 用法                   | 含义                              |
| ----------- | ---------------------- | --------------------------------- |
| describe    | df.describe()          | 运算数字形式的数据                |
| sort_index  | df.sort_index          | 排序                              |
| sort_values | df.sort_values(by='c') | 按照C列的数据对每一行的值排序的值 |
|             |                        |                                   |

# 创建

```python

s = pd.Series([1,3,6,np.nan,44,1])
dates = pd.date_range('20160101',periods=6) #打印从2016-1-1到1016-1-6的序列
df = pd.DataFrame(np.random.randn(6,4),index=dates,columns=['a','b','c']) #dataframe 有名称的数据，
df2 = pd.DataFrame({'A' : 1.,                          
                    'B' : pd.Timestamp('20130102'),
                    'C' : pd.Series(1,index=list(range(4)),dtype='float32'),
                    'D' : np.array([3] * 4,dtype='int32'),
                    'E' : pd.Categorical(["test","train","test","train"]),
                    'F' : 'foo'})       # 以字典的形式，一列一列的定义，
```

# 查看

```python
print(df2.dtypes)  #查看df2的数据类型

print(df.index)  #查看df2的行
print(df.columns)  #查看df2的列
print(df.values)  #查看df2的值
print(df.describe())  #查看df2的统计特征  列
print(df.T)  #查看df2的转置
print(df.sort_index(axis=1, ascending=False)) #查看df2按索引的排序，列，递减
print(df.sort_values(by='B')) #查看df2按B列的值排序，
```

## 选择数据

```python
dates = pd.date_range('20130101', periods=6)
df = pd.DataFrame(np.random.randn(6,4), index=dates, columns=['A', 'B', 'C', 'D'])

print(df['A'], df.A)  # 选择A列
print(df[0:3], df['20130102':'20130104'])  # 选择多行

 #按标签筛选
print(df.loc['20130102'])  #选择行
print(df.loc[:,['A','B']])  #选择所有行的A B列
print(df.loc['20130102', ['A','B']]) # 选择这一行的 A B 列

# 按数字筛选
print(df.iloc[3])  #选择df的第3行
print(df.iloc[3, 1]) #选择df的第3行第一位
print(df.iloc[3:5,0:2]) #选择df的第3行到第5行，第0位到底3位
print(df.iloc[[1,2,4],[0,2]])  #选择df的第 1，2，4行，的第0位 2 位

# 行按数字，列按标签筛选
print(df.ix[:3, ['A', 'C']])


# 布尔筛选
print(df[df.A > 0])  # 只对比A但是其他的也要显示
```

# 修改数据

```python
dates = pd.date_range('20130101', periods=6)
df = pd.DataFrame(np.arange(24).reshape((6,4)), index=dates, columns=['A', 'B', 'C', 'D'])

df.iloc[2,2] = 1111  # 按数字索引改
df.loc['2013-01-03', 'D'] = 2222  # 按标签索引改
df.B[df.A>0] = 0  # B当中 A列>0的这些值改为0，
df['F'] = np.nan # 加一个F这一列，他的值全为nan
df['G']  = pd.Series([1,2,3,4,5,6], index=pd.date_range('20130101', periods=6)) # 加一个G这一列，他的值为一个序列，
```

# 处理丢失数据

```python
dates = pd.date_range('20130101', periods=6)
df = pd.DataFrame(np.arange(24).reshape((6,4)), index=dates, columns=['A', 'B', 'C', 'D'])

df.iloc[0,1] = np.nan  
df.iloc[1,2] = np.nan
print(df.dropna(axis=0, how='any'))   # how='any':丢掉有nun的行    how='all':丢掉全是nun的行
print(df.fillna(value=0))  # 把nun填充0

print(pd.isnull(df))  # 检查有没有nun数据
print(np.any(pd.isnull(df) == True) # 有nun就返回true
```

# 数据读取

```python
# read from
data = pd.read_csv('student.csv')  # sep:处理分割信息
print(data)

# save to
data.to_pickle('student.pickle')
```

# 合并concat 按索引合并

```python
# concatenating
# ignore index
df1 = pd.DataFrame(np.ones((3,4))*0, columns=['a','b','c','d'])
df2 = pd.DataFrame(np.ones((3,4))*1, columns=['a','b','c','d'])
df3 = pd.DataFrame(np.ones((3,4))*2, columns=['a','b','c','d'])
res = pd.concat([df1, df2, df3], axis=0, ignore_index=True)  #纵向合并，并且忽略索引避免索引重复

# join, ('inner', 'outer')
df1 = pd.DataFrame(np.ones((3,4))*0, columns=['a','b','c','d'], index=[1,2,3])
df2 = pd.DataFrame(np.ones((3,4))*1, columns=['b','c','d', 'e'], index=[2,3,4])
res = pd.concat([df1, df2], axis=1, join='outer')  # 不相同的部分用nun代替
res = pd.concat([df1, df2], axis=1, join='inner')  # 只合并相同列，不相同的部分去掉

# join_axes
res = pd.concat([df1, df2], axis=1, join_axes=[df1.index])  # 按照df1的行合并，有的填充，没有的nun，但是df1没有的行去掉

# append
df1 = pd.DataFrame(np.oes((3,4))*0, columns=['a','b','c','d']) 
df2 = pd.DataFrame(np.ones((3,4))*1, columns=['a','b','c','d'])
df3 = pd.DataFrame(np.ones((3,4))*1, columns=['b','c','d', 'e'], index=[2,3,4])
res = df1.append(df2, ignore_index=True) #往下加数据。
res = df1.append([df2, df3]) 

s1 = pd.Series([1,2,3,4], index=['a','b','c','d'])
res = df1.append(s1, ignore_index=True)  # 添加一行序列

print(res)
```

# 合并merge 按值合并

```python

    # merging two df by key/keys. (may be used in database)
    # simple example
    left = pd.DataFrame({'key': ['K0', 'K1', 'K2', 'K3'],
                                      'A': ['A0', 'A1', 'A2', 'A3'],
                                      'B': ['B0', 'B1', 'B2', 'B3']})
    right = pd.DataFrame({'key': ['K0', 'K1', 'K2', 'K3'],
                                        'C': ['C0', 'C1', 'C2', 'C3'],
                                        'D': ['D0', 'D1', 'D2', 'D3']})
    print(left)
    print(right)
    res = pd.merge(left, right, on='key')   #按key这一列的值合并
    print(res)

    # consider two keys
    left = pd.DataFrame({'key1': ['K0', 'K0', 'K1', 'K2'],
                                 'key2': ['K0', 'K1', 'K0', 'K1'],
                                 'A': ['A0', 'A1', 'A2', 'A3'],
                                 'B': ['B0', 'B1', 'B2', 'B3']})
    right = pd.DataFrame({'key1': ['K0', 'K1', 'K1', 'K2'],
                                  'key2': ['K0', 'K0', 'K0', 'K0'],
                                  'C': ['C0', 'C1', 'C2', 'C3'],
                                  'D': ['D0', 'D1', 'D2', 'D3']})
    print(left)
    print(right)
    res = pd.merge(left, right, on=['key1', 'key2'], how='inner')  # 合并考虑两个key，相同的合并起来，不同的丢掉。
    # how = ['left', 'right', 'outer', 'inner']
    res = pd.merge(left, right, on=['key1', 'key2'], how='left')  # 合并考虑两个key，以left为主，相同的合并，不同的nun，超出的去掉
    #outer：相同的合并，不同的nun
    print(res)

    # indicator
    df1 = pd.DataFrame({'col1':[0,1], 'col_left':['a','b']}) 
    df2 = pd.DataFrame({'col1':[1,2,2],'col_right':[2,2,2]})
    print(df1)
    print(df2)
    res = pd.merge(df1, df2, on='col1', how='outer', indicator=True) # 考虑 col1，合并，合并方式显示出来。
    # give the indicator a custom name
    res = pd.merge(df1, df2, on='col1', how='outer', indicator='indicator_column')# 考虑 col1，合并，合并方式显示出来。在给他起一个名字。


    # merged by index
    left = pd.DataFrame({'A': ['A0', 'A1', 'A2'],
                                      'B': ['B0', 'B1', 'B2']},
                                      index=['K0', 'K1', 'K2'])
    right = pd.DataFrame({'C': ['C0', 'C2', 'C3'],
                                         'D': ['D0', 'D2', 'D3']},
                                          index=['K0', 'K2', 'K3'])
    print(left)
    print(right)
    # left_index and right_index
    res = pd.merge(left, right, left_index=True, right_index=True, how='outer')  #对比index合并
    res = pd.merge(left, right, left_index=True, right_index=True, how='inner')

    # handle overlapping
    boys = pd.DataFrame({'k': ['K0', 'K1', 'K2'], 'age': [1, 2, 3]})
    girls = pd.DataFrame({'k': ['K0', 'K0', 'K3'], 'age': [4, 5, 6]})
    res = pd.merge(boys, girls, on='k', suffixes=['_boy', '_girl'], how='inner')  #处理名字相同但是内涵不同的数据，age
    print(res)
```

# 显示 matplotlib

```python
from __future__ import print_function
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# plot data

# Series
data = pd.Series(np.random.randn(1000), index=np.arange(1000))  # 生成1000个数据的序列
data = data.cumsum()  #累加
##data.plot()

# DataFrame
data = pd.DataFrame(np.random.randn(1000, 4), index=np.arange(1000), columns=list("ABCD"))  # 生成一个表格数据
data = data.cumsum()   #  累加
# plot methods:
# 'bar', 'hist', 'box', 'kde', 'area', scatter', hexbin', 'pie'
ax = data.plot.scatter(x='A', y='B', color='DarkBlue', label="Class 1")  #
data.plot.scatter(x='A', y='C', color='LightGreen', label='Class 2', ax=ax)

plt.show()
```

