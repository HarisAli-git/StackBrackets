#include <iostream>
using namespace std;
template <class T>
class stack{
	T* s;
	int maxsize;
	int stack_pointer;
public:
	bool isBalanced(T* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[' )
			{
				push(arr[i]);
			}
			else
			{
				if (!isEmpty())
				{
					T d;
				top(d);
				if (arr[i] == '}')
				{
					if (d != '{')
						return false;
					else
						pop();
				}
				else if (arr[i] == ']')
				{
					if (d != '[')
						return false;
					else
						pop();
				}
				else
				{
					if (d != '(')
						return false;
					else
						pop();
				}
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
	stack(int size = 5)
	{
		maxsize = size;
		s = new T[size];
		stack_pointer = -1;
	}
	void push (T& d)
	{
		if (stack_pointer + 1 != maxsize)
		{
			s[++stack_pointer] = d;
		}
		else
			cout<<"\nStack is full";
	}
	bool isEmpty()
	{
		return stack_pointer == -1;
	}
	void top(T& d)
	{
		if (!isEmpty())
		{
			d = s[stack_pointer];
		}
		else
			cout<<"\nStack is Empty";
	}
	void pop()
	{
		if (!isEmpty())
		{
			stack_pointer--;
		}
		else
			cout<<"\nStack is Empty";
	}
	~stack()
	{
		delete[] s;
		s = NULL;
	}
};
