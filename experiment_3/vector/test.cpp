#include <iostream>
#include "vector_ss.h"

using namespace std;

int main()
{
	vector_ss<char> v1;
	cout << v1.size() << endl;

	for (int i = 0; i < 10; i++)
		v1.push_back('a' + i);
	v1.display();

	vector_ss<char> v2(v1,2,5);    //用v1中2~5这段元素为v2赋值
	v2.display();

	v1.erase(2, 4);
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";    //测试[]重载
	cout << endl;

	v1.insert(2, 'c');
	v1.display();

	v1.clear();
	v1.display();
	cout << v1.size() << endl;

	vector_ss<char> v3;
	v3 = v2;
	v3.display();

	vector_ss<double> v4(5,5);
	v4.display();

	system("pause");
	return 0;
}
