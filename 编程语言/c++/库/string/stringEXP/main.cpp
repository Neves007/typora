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
    cout << "\n\n###########  ����  ###########"<< endl;
    cout << "s1.length() |"<<s1.length()<<" | �ַ���s�ĳ���"<< endl;
    cout << "s1.c_str() |"<<s1.c_str()<<" | ת����c�������ͣ�string to char"<< endl;
    cout << "s1[0] |"<<s1[0]<<" | �����ַ����е��ַ�"<< endl;
    cout << "s1.substr(2, 6) |"<<s1.substr(2, 6)<<" | ��s[2]��ʼ��ȡ6���ַ�����pos Խ�磬���׳��쳣�� len Խ�磬����ȡ�� pos ���ַ�����β���������ַ���"<< endl;
    cout << "s1.find(s2,1) |"<<s1.find(s2,1)<<" | ��s1[1]-s[ĩβ]����s2�����ص�һ�γ��ֵ��±꣬û�г��ַ���-1��"<< endl;
    cout << "s1.rfind(s2,1) |"<<s1.rfind(s3,7)<<" | ��s[0]-s[7]���Ҵ�s3�����ص�һ�γ��ֵ��±꣬û�г��ַ���-1�����s1[7]-s[9]���ַ���s3�����ǿ����ҵ��ġ�"<< endl;
    cout << "s1.find_first_of(s4); |"<<s1.find_first_of(s4)<<" |  s1 �� s4 ��ͬ���е��ַ��� ��0�������ַ��� s1 ���״γ��ֵ��±���1"<< endl;



    cout << "\n###########  �޸�  ###########"<< endl;
    cout << "s1+s2 |"<<s1+s2<<" | �ַ�����ƴ�ӣ�s1 s2����"<< endl;
    s1.insert(6, s2);
    cout << "s1.insert(6, s2); |"<<s1<<" | ��s1[6]��ʼ��s1[5]���棩�����ַ���"<< endl;
    s1.erase(6,2);
    cout << "s1.erase(6,2);|"<<s1<<" | ��s1[6]��ʼɾ��2���ֽ�"<< endl;





    return 0;
}
