#include <iostream>
#include<new>

template<class T>
class my_unique_ptr
{
public:
	my_unique_ptr(T* p): ptr{p}
	{}
	~my_unique_ptr()
	{
		if (!nullpointer)
		{
			delete ptr;

		}
	}
	
	my_unique_ptr(const my_unique_ptr& other) = delete;

	T* release()
	{
		T* ptr2 = new T;
		ptr2 = ptr;
		ptr = nullptr;
		nullpointer = true;
		return ptr2;
	}

	T& operator* ()
	{
		return *ptr;
	}

	my_unique_ptr& operator= (my_unique_ptr& other) = delete;

private:
	bool nullpointer = false;
	T* ptr;
};





int main()
{
	int* ptr1;
	{
		my_unique_ptr<int> ptr2(new int(5));

		std::cout << *ptr2<<std::endl;
		ptr1 = ptr2.release();
	}
	std::cout << *ptr1;
	delete ptr1;

	return 0;
}