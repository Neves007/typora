#include <iostream>
#include <stdio.h>
#include <vector>   //引入
using namespace std;
void printMassage(string code, string name, vector<int> v, string caption){
    cout<<code<<"  |  " << name << " = [";  //代码  |  变量内容  | 说明
    for(int i=0; i<v.size(); i++){
         if(i<v.size()-1){
            cout<<v[i]<<", ";
         }
         else
            cout<<v[i];
    }
    cout<<"] | "<<caption<<endl;  //说明
}

int main()
{
    cout<<"\n\n******************* vector初始化 *******************\n"<<endl;
    vector<int> a(5);
    printMassage("vector<int> a(5);", "a", a, "a=大小等于5的整型向量");
    vector<int> b(5,1);
    printMassage("vector<int> b(5,1);", "b", b, "b=大小等于5的整型向量，初值为1");
    vector<int> c(b);
    printMassage("vector<int> c(b);", "c", c, "用b复制赋值给c");
    vector<int> d(b.begin(),b.begin()+3);
    printMassage("vector<int> d(b.begin(),b.begin()+3);", "d", d, "把b的前3个数赋值给d");


    int *point=&b[0];
    cout<<"\nint *point=&b[0];  |  自定义指针操作 *point="<<*(point)<<" 但是容易指出去"<<endl;
    vector<int> e(point,point+3);
    printMassage("int *point=&b[0]; vector<int> e(point,point+3);", "e", e, "与上面是同样的道理");


    cout<<"\n\n\n******************* 访问vector属性 *******************\n"<<endl;



    cout<<"b.empty(); | "<<"b.empty()="<<b.empty()<<" | 判断是否清空了，其实就是判断size是否为0"<<endl;
    cout<<"b.size(); | "<<"b.size()="<<b.size()<<" | b 中有效元素的个数"<<endl;

    cout<<"b.front(); | "<<b.front()<<" | b开头的数值"<<endl;
    cout<<"b.back(); | "<<b.back()<<" | b末尾的数值"<<endl;
    printf("b.begin() |  %p  | 返回b开头的地址\n",b.begin());
    printf("b.end() |  %p  | 返回b末尾的地址\n",b.end());
    //cout<<"b.begin(); | "<< (void*)(b.begin())<<" | b末尾的数值"<<endl;
    //cout<<"b.end(); | "<<b.end()<<" | b末尾的数值"<<endl;



    cout<<"\n\n\n******************* 修改vector *******************\n"<<endl;
    b.assign(3,2);
    printMassage("b.assign(3,2);", "b",b,"将b设置为大小为3,数值全是2的向量（此时b的capacity还是不变还是5）");
    b.resize(4);
    printMassage("b.resize(4); ", "b",b,"将b的现有元素个数调至4个，多则删，少则补0");
    b.resize(5,3);
    printMassage("b.resize(5,3); ", "b",b,"将b的现有元素个数调至5个，多则删，少则补3");
    b.reserve(100);
    cout<<"b.reserve(100); "<<" | b.capacity()="<<b.capacity()<<" | 将b的容量（capacity）扩充至100"<<endl;

    a.assign(b.begin(), b.begin()+2);
    printMassage("a.assign(b.begin(), b.begin()+2);", "a", a, "将a设置为b向量前2个数,（此时b的capacity还是不变还是5）");
    a.clear();
    printMassage("a.clear()","a",a,"清空(size为零，capacity不变)");
    a.pop_back();
    cout<<"a.pop_back(); | "<<"a.size()="<<a.size()<<" | 如果a是空向量认执行pop操作，a的size还是减1，等于八位0-1,没有空异常判断，此时a不为空"<<endl;

    a.push_back(5);
    a.push_back(5);
    printMassage("a.push_back(5);","a",a,"在a末尾添加一个元素（因为上次a的size为-1，所以push了两次）");

    a.insert(a.begin()+1,2);
    printMassage("a.insert(a.begin()+1,2);","a",a,"在a第一个元素a[0]后面插入2");

    a.insert(a.begin(),3,3);
    printMassage("a.insert(a.begin()+1,2);","a",a,"在a第一个元素a[0]前面插入3个3");

    a.insert(a.begin()+1,b.begin(),b.begin()+2);
    printMassage("a.insert(a.begin()+1,b.begin(),b.begin()+2);", "a", a, "把b[0]到b[1]插入到a[0]后面。（b只要是连续存储的数据类型就行，数组，堆栈...）");



    c.erase(c.begin(), c.begin()+2);
    printMassage("c.erase(c.begin(), c.begin()+2);","c",c,"删除c[0]~c[1]的元素(2个元素)");





}
