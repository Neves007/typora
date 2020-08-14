#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{

    string s1 = "how to use string??";
    string s2 = "??";
    string s3 = "use";
    string s4 = "to";
    cout << "\nstring s1 = \"how to use string\";"<< "\nstring s2 = \"??\";"<< "\nstring s3 = \"use\";"<< "\nstring s4 = \"to\";"<<endl;
    cout << "\n\n###########  访问  ###########"<< endl;
    cout << "s1.length() |"<<s1.length()<<" | 字符串s的长度"<< endl;
    cout << "s1.c_str() |"<<s1.c_str()<<" | 转换成c语言类型：string to char"<< endl;
    cout << "s1[0] |"<<s1[0]<<" | 访问字符串中的字符"<< endl;
    cout << "s1.substr(2, 6) |"<<s1.substr(2, 6)<<" | 从s[2]开始提取6个字符串。pos 越界，会抛出异常； len 越界，会提取从 pos 到字符串结尾处的所有字符。"<< endl;
    cout << "s1.find(s2,1) |"<<s1.find(s2,1)<<" | 在s1[1]-s[末尾]查找s2，返回第一次出现的下标，没有出现返回-1。"<< endl;
    cout << "s1.rfind(s2,1) |"<<s1.rfind(s3,7)<<" | 在s[0]-s[7]查找从s3，返回第一次出现的下标，没有出现返回-1。如果s1[7]-s[9]是字符串s3，这是可以找到的。"<< endl;
    cout << "s1.find_first_of(s4); |"<<s1.find_first_of(s4)<<" |  s1 和 s4 共同具有的字符是 ’0’，该字符在 s1 中首次出现的下标是1"<< endl;



    cout << "\n###########  修改  ###########"<< endl;
    cout << "s1+s2 |"<<s1+s2<<" | 字符串的拼接，s1 s2不变"<< endl;
    s1.insert(6, s2);
    cout << "s1.insert(6, s2); |"<<s1<<" | 在s1[6]开始（s1[5]后面）插入字符串"<< endl;
    s1.erase(6,2);
    cout << "s1.erase(6,2);|"<<s1<<" | 从s1[6]开始删除2个字节"<< endl;





    return 0;
}
