#include <iostream>
#include <stdio.h>
#include <vector>   //����
using namespace std;
void printMassage(string code, string name, vector<int> v, string caption){
    cout<<code<<"  |  " << name << " = [";  //����  |  ��������  | ˵��
    for(int i=0; i<v.size(); i++){
         if(i<v.size()-1){
            cout<<v[i]<<", ";
         }
         else
            cout<<v[i];
    }
    cout<<"] | "<<caption<<endl;  //˵��
}

int main()
{
    cout<<"\n\n******************* vector��ʼ�� *******************\n"<<endl;
    vector<int> a(5);
    printMassage("vector<int> a(5);", "a", a, "a=��С����5����������");
    vector<int> b(5,1);
    printMassage("vector<int> b(5,1);", "b", b, "b=��С����5��������������ֵΪ1");
    vector<int> c(b);
    printMassage("vector<int> c(b);", "c", c, "��b���Ƹ�ֵ��c");
    vector<int> d(b.begin(),b.begin()+3);
    printMassage("vector<int> d(b.begin(),b.begin()+3);", "d", d, "��b��ǰ3������ֵ��d");


    int *point=&b[0];
    cout<<"\nint *point=&b[0];  |  �Զ���ָ����� *point="<<*(point)<<" ��������ָ��ȥ"<<endl;
    vector<int> e(point,point+3);
    printMassage("int *point=&b[0]; vector<int> e(point,point+3);", "e", e, "��������ͬ���ĵ���");


    cout<<"\n\n\n******************* ����vector���� *******************\n"<<endl;



    cout<<"b.empty(); | "<<"b.empty()="<<b.empty()<<" | �ж��Ƿ�����ˣ���ʵ�����ж�size�Ƿ�Ϊ0"<<endl;
    cout<<"b.size(); | "<<"b.size()="<<b.size()<<" | b ����ЧԪ�صĸ���"<<endl;

    cout<<"b.front(); | "<<b.front()<<" | b��ͷ����ֵ"<<endl;
    cout<<"b.back(); | "<<b.back()<<" | bĩβ����ֵ"<<endl;
    printf("b.begin() |  %p  | ����b��ͷ�ĵ�ַ\n",b.begin());
    printf("b.end() |  %p  | ����bĩβ�ĵ�ַ\n",b.end());
    //cout<<"b.begin(); | "<< (void*)(b.begin())<<" | bĩβ����ֵ"<<endl;
    //cout<<"b.end(); | "<<b.end()<<" | bĩβ����ֵ"<<endl;



    cout<<"\n\n\n******************* �޸�vector *******************\n"<<endl;
    b.assign(3,2);
    printMassage("b.assign(3,2);", "b",b,"��b����Ϊ��СΪ3,��ֵȫ��2����������ʱb��capacity���ǲ��仹��5��");
    b.resize(4);
    printMassage("b.resize(4); ", "b",b,"��b������Ԫ�ظ�������4��������ɾ������0");
    b.resize(5,3);
    printMassage("b.resize(5,3); ", "b",b,"��b������Ԫ�ظ�������5��������ɾ������3");
    b.reserve(100);
    cout<<"b.reserve(100); "<<" | b.capacity()="<<b.capacity()<<" | ��b��������capacity��������100"<<endl;

    a.assign(b.begin(), b.begin()+2);
    printMassage("a.assign(b.begin(), b.begin()+2);", "a", a, "��a����Ϊb����ǰ2����,����ʱb��capacity���ǲ��仹��5��");
    a.clear();
    printMassage("a.clear()","a",a,"���(sizeΪ�㣬capacity����)");
    a.pop_back();
    cout<<"a.pop_back(); | "<<"a.size()="<<a.size()<<" | ���a�ǿ�������ִ��pop������a��size���Ǽ�1�����ڰ�λ0-1,û�п��쳣�жϣ���ʱa��Ϊ��"<<endl;

    a.push_back(5);
    a.push_back(5);
    printMassage("a.push_back(5);","a",a,"��aĩβ���һ��Ԫ�أ���Ϊ�ϴ�a��sizeΪ-1������push�����Σ�");

    a.insert(a.begin()+1,2);
    printMassage("a.insert(a.begin()+1,2);","a",a,"��a��һ��Ԫ��a[0]�������2");

    a.insert(a.begin(),3,3);
    printMassage("a.insert(a.begin()+1,2);","a",a,"��a��һ��Ԫ��a[0]ǰ�����3��3");

    a.insert(a.begin()+1,b.begin(),b.begin()+2);
    printMassage("a.insert(a.begin()+1,b.begin(),b.begin()+2);", "a", a, "��b[0]��b[1]���뵽a[0]���档��bֻҪ�������洢���������;��У����飬��ջ...��");



    c.erase(c.begin(), c.begin()+2);
    printMassage("c.erase(c.begin(), c.begin()+2);","c",c,"ɾ��c[0]~c[1]��Ԫ��(2��Ԫ��)");





}
