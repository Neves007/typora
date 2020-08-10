游戏规则如下：从1开始往上数数，当遇到3的倍数的时候，说fizz，当遇到5的倍数，说buzz，当遇到15的倍数，就说fizzbuzz，其他情况下则正常数数。

```python

def fizz_buzz_encode(i):
    if   i % 15 == 0: return 3
    elif i % 5  == 0: return 2
    elif i % 3  == 0: return 1
    else:             return 0
    
def fizz_buzz_decode(i, prediction):
    return [str(i), "fizz", "buzz", "fizzbuzz"][prediction]

print(fizz_buzz_decode(1, fizz_buzz_encode(1)))
print(fizz_buzz_decode(2, fizz_buzz_encode(2)))
print(fizz_buzz_decode(5, fizz_buzz_encode(5)))
print(fizz_buzz_decode(12, fizz_buzz_encode(12)))
print(fizz_buzz_decode(15, fizz_buzz_encode(15)))
```

我们想让神经网络学会这个规律。

我们首先定义模型的输入与输出(训练数据)

```python
import numpy as np
import torch

NUM_DIGITS = 10

# 返回一个十位的二进制数
def binary_encode(i, num_digits):
    return np.array([i >> d & 1 for d in range(num_digits)][::-1])

trX = torch.Tensor([binary_encode(i, NUM_DIGITS) for i in range(101, 2 ** NUM_DIGITS)])  # 101-1024的二进制 923*10
trY = torch.LongTensor([fizz_buzz_encode(i) for i in range(101, 2 ** NUM_DIGITS)])  # 101-1024的二进制 923*1
```

然后我们用PyTorch定义模型

```python
#Define the model
NUM_HIDDEN = 100
model = torch.nn.Sequential(
    torch.nn.Linear(NUM_DIGITS, NUM_HIDDEN), #10-->100
    torch.nn.ReLU(),  #relu
    torch.nn.Linear(NUM_HIDDEN, 4) #100-->4
)
```

- 为了让我们的模型学会FizzBuzz这个游戏，我们需要定义一个损失函数，和一个优化算法。
- 这个优化算法会不断优化（降低）损失函数，使得模型的在该任务上取得尽可能低的损失值。
- 损失值低往往表示我们的模型表现好，损失值高表示我们的模型表现差。
- 由于FizzBuzz游戏本质上是一个分类问题，我们选用Cross Entropyy Loss函数。
- 优化函数我们选用Stochastic Gradient Descent。

```python
loss_fn = torch.nn.CrossEntropyLoss()  # 分类问题常用函数
optimizer = torch.optim.SGD(model.parameters(), lr = 0.05)  # 优化
```

训练

```python
# Start training it
BATCH_SIZE = 128
for epoch in range(10000):
    for start in range(0, len(trX), BATCH_SIZE):
        end = start + BATCH_SIZE  # 128个数据构成一批数据
        batchX = trX[start:end]  #  start到end-1的数据
        batchY = trY[start:end]

        y_pred = model(batchX)
        loss = loss_fn(y_pred, batchY)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

    # Find loss on training data
    loss = loss_fn(model(trX), trY).item()
    print('Epoch:', epoch, 'Loss:', loss)
```

最后我们用训练好的模型尝试在1到100这些数字上玩FizzBuzz游戏

```python
# Output now
testX = torch.Tensor([binary_encode(i, NUM_DIGITS) for i in range(1, 101)])  # 测试数据
with torch.no_grad():  # 不需要保存grad
    testY = model(testX)  # 丢进模型里
predictions = zip(range(1, 101), list(testY.max(1)[1].data.tolist()))

print([fizz_buzz_decode(i, x) for (i, x) in predictions])
```

