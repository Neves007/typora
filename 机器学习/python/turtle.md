https://blog.csdn.net/sandalphon4869/article/details/99443949

# 创建画布

```
turtle.screensize(canvwidth=None, canvheight=None, bg=None)
```



# 画笔

```
turtle.pd()  #下笔
turtle.pu()  #抬笔
turtle.pensize(width=None)  #粗细
turtle.isdown() #是否下落
```



# 颜色

```
turtle.pencolor(*args)  #笔的颜色
#填充
turtle.begin_fill()  
turtle.fillcolor(*args)  # 填充颜色
turtle.end_fill()
```

```
import turtle
turtle.color("black", "red")
turtle.begin_fill()
turtle.circle(80)
turtle.end_fill()
turtle.done()
```

![image-20200329201714665](C:\Users\22145\AppData\Roaming\Typora\typora-user-images\image-20200329201714665.png)

# 绘画基础

## 海龟移动

```
turtle.goto(x, y=None)  # 海龟移动到一个绝对坐标,如果画笔已落下将会画线。不改变海龟的朝向。
turtle.fd(distance)  # 海龟前进 distance 指定的距离，方向为海龟的朝向
turtle.bk(distance)  # 海龟后退 distance 指定的距离，方向与海龟的朝向相反。不改变海龟的朝向
turtle.setx(x)
turtle.sety(y)
turtle.home()  # 海龟移至初始坐标 (0,0)，并设置朝向为初始方向
```

## 海龟方向

```
turtle.towards(x, y=None)  # 朝向x，y
turtle.right(angle)  # 右转
turtle.left(angle)  # 左转
turtle.degrees(fullcircle=360.0) #设置一个圆周为多少 “度”。默认值为 360 度。
turtle.radians() # 设置角度的度量单位为弧度。其值等于 度÷180×π。
```



## 海龟状态

```
turtle.pos() # 当前的坐标
```

