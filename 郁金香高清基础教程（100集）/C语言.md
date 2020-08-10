# 字符指针

https://blog.csdn.net/hhmy77/article/details/100176359

```C
char s[]="asd";
char *p=s; //此时p指向s 
printf("字符串内容:%s p的地址:%d p的值:%d s的地址:%d \n",p,&p,p,s);
// 在我的电脑上输出结果为字符串内容:asd p的地址:6487576 p的值:6487568 s的地址:6487568
```

```C
//p指向"asd",此时"asd"是字符串常量，p->"asd"
//也就是说p仅仅指向这个字符串，只能打印出里面的内容，不能修改字符串里面的值
char* p="asd";
printf("%s\n",p); //打印asd
printf("%c",*p);//打印a
*p=‘A'; //报错，此时不能修改值
————————————————
版权声明：本文为CSDN博主「hhmy77」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/hhmy77/article/details/100176359
```

