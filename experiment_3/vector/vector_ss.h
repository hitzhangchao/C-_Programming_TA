#ifndef VECTOR_SS_H
#define VECTOR_SS_H

using namespace std;

template<class T>
class vector_ss
{
private:
	int v_size;	//记录当前数组大小,实际v_size这个地方不放数组的元素
	int b_size; //数组空间的大小
	T* buf;     //存放数组空间首地址

public:
	void push_back(T t)//在数组末尾插入元素
	{
		buf[v_size] = t;
		v_size++;
	}

	T pop_back()//删除并返回末尾元素
	{
		//return buf[--v_size];
		T tmp = buf[v_size-1];
		v_size--;
		return tmp;
	}

	T front()//返回数组首元素
	{
		return buf[0];
	}

	void clear()//清空数组
	{
		v_size = 0;
		b_size = 128;
		delete[] buf;  //释放掉了buf数组内存空间，但是buf这个指针还是在的
		buf = new T[b_size];
	}

	bool empty()//返回数组是否为空
	{
		return(v_size == 0);
	}

	void insert(int pos, T data)//在数组的第pos个位置插入data
	{
		for (int i = v_size; i >= pos; i--)
			buf[i + 1] = buf[i];

		buf[pos] = data;
		v_size++;
	}

	void erase(int pos)//删除pos位置的数据
	{
		for (int i = pos; i < v_size; i++)
			buf[i] = buf[i + 1];
		v_size--;
	}

	void erase(int begin, int end)//删除从begin位置到end位置的数据
	{
		for (int i = begin; i <= v_size; i++)
			buf[i] = buf[i + end + 1 - begin];

		v_size -= (end + 1 - begin);
	}

	const int& size() const { return v_size; };                //返回数组大小
	const vector_ss& operator= (const vector_ss &v)//重载赋值函数（为什么要重载？）
	{
		v_size = v.size();
		b_size = v.b_size;

		buf = new T[b_size];
		for (int i = 0; i < v_size; i++)
			buf[i] = v[i];

		return *this;
	}

	const T& operator() (int i) const{ return buf[i]; };       //重载()
	T& operator[] (int n){ return buf[n]; };                   //重载[]
	const T& operator[] (int n) const{ return buf[n]; };       //重载[]，常成员函数

	void display()//打印数组元素
	{
		for (int i = 0; i < v_size; i++)
			cout << buf[i] << " ";
		cout << endl;
	}

public:
	vector_ss()
	{
		v_size = 0;
		b_size = 128;
		buf = new T[b_size];
	}

	vector_ss(int n)                //构造函数，产生一个大小为n的数组
	{
		v_size = n;
		b_size = n * 2;
		buf = new T[b_size];
	}

	vector_ss(int n, T t)           //构造函数，产生一个大小为n的数组，且每个元素值均为t
	{
		v_size = n;
		b_size = n * 2;
		buf = new T[b_size];
		for (int i = 0; i < n; i++)
			buf[i] = t;
	}

	vector_ss(const vector_ss &v)   //拷贝建立构造函数
	{
		v_size = v.v_size;
		b_size = v.b_size;
		buf = new T[b_size];

		for (int i = 0; i < v_size; i++)
			buf[i] = v.buf[i];
	}

	vector_ss(const vector_ss &v, int start, int end)  //拷贝构造函数，数组元素为v的start位置到end位置的元素
	{
		v_size = end + 1 - start;
		b_size = v.b_size;
		buf = new T[b_size];

		for (int i = 0; i < v_size; i++)
			buf[i] = v.buf[start + i];
	}

	~vector_ss()  //析构函数，释放内存
	{
		delete []buf;
		buf = NULL;
	}
};

#endif
