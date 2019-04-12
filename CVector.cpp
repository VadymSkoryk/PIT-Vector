// CVector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template<class A>
class CVector
{
private:
	A *Data;
	int VectorSize;
public:
	CVector();
	CVector(int newSize);
	CVector(const CVector &v);
	~CVector();
	////////////

	///////////
	void operator=(const CVector &b);
	template<typename A>
	friend bool operator==(const CVector<A>& a, const CVector<A>& b);
	template<typename A>
	friend ostream& operator<<(ostream&, CVector<A>&);
	template<typename A>
	friend istream& operator>>(istream&, CVector<A>&);
    ///////////
	template<typename A>
	friend CVector<A> operator+(CVector<A>&, CVector<A>&);
	template<typename A>
	friend CVector<A>& operator+(CVector<A>&, A);
	template<typename A>
	friend CVector<A>& operator+(A, CVector<A>&);
	///////////
	template<typename A>
	friend CVector<A>& operator*(CVector<A>&, CVector<A>&);
	template<typename A>
	friend CVector<A>& operator*(CVector<A>&, A);
	template<typename A>
	friend CVector<A>& operator*(A, CVector<A>&);
	//////////
	template <typename A>
	friend CVector<A>& operator-(CVector<A>&, CVector<A>&);
	template <typename A>
	friend CVector<A>& operator-(CVector<A>&, A);
	/////////////
	template <typename A>
	friend CVector<A>& operator/(CVector<A>&,CVector<A>&);




};


template<typename A>
CVector<A> operator+(CVector<A>& a, CVector<A>& b)
{

	try {

		if (a.VectorSize != b.VectorSize)
		{
			throw 223;
		}
		else
		{
			CVector<A> ex(a.VectorSize);
			
			for (int i = 0; i < a.VectorSize; i++)
			{
				ex.Data[i] = a.Data[i] + b.Data[i];
			}
			return ex;
		}
	}
	catch (int i)
	{
		cout << "Ошибка: " << i << "Problema s dlinnoi";
		return a;
	}

	
}

template<class A>
CVector<A>::CVector()
{
	VectorSize = 0;
	Data = nullptr;
	
	cout << "\nDefault Construct";
}

template<class A>
CVector<A>::CVector(int newSize)
{
	Data = new A[newSize];
	if (Data == nullptr)
		exception;
	VectorSize = newSize;
	cout << "\nStandart Construct";
}

template<class A>
CVector<A>::CVector(const CVector &v)
{
	cout << "Copy Construct";
	VectorSize = v.VectorSize;
	Data = new A[VectorSize];
	for (int i = 0; i < VectorSize; i++) {
		Data[i] = v.Data[i];
	}
}

template<class A>
CVector<A>::~CVector()
{
	cout << "\nDestoryed";
	delete[]Data;
	VectorSize = 0;
}

template<class A>
void CVector<A>::operator=(const CVector & b)
{
	cout << "\nOperator=";
	if (this == &b)
		return;
	delete[]Data;
	if (nullptr == b.Data)
	{
		Data = nullptr;
		VectorSize=0;
		return;
	}
	Data = new A[b.VectorSize];
	VectorSize = b.VectorSize;
	for (int i = 0; i < VectorSize; i++)
		Data[i] = b.Data[i];
}



template<typename A>
bool operator==(const CVector<A>& a, const CVector<A>& b)
{
	if (a.VectorSize != b.VectorSize)
		return false;
	for (int i = 0; i < a.VectorSize; i++)
	{
		if (a.Data[i] != b.Data[i])
			return false;

	}
	return true;

}

template<typename A>
ostream & operator<<(ostream & stream, CVector<A>& V)
{
	// TODO: вставьте здесь оператор return
	stream << "\nVector{" << V.VectorSize << "] at " << V.Data << "=";
	for (int i = 0; i < V.VectorSize; i++)
		stream << V.Data[i] << ' ';
	return stream;

}

template<typename A>
istream & operator>>(istream & stream, CVector<A>& V)
{
	// TODO: вставьте здесь оператор return
	cout << endl << "Input vector (" << V.VectorSize << ") " << endl;
	for (int i = 0; i < V.VectorSize; i++)
		stream >> V.Data[i];
	return stream;

}



template<typename A>
CVector<A>& operator+(CVector<A>& a, A b)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < a.VectorSize; i++)
		a.Data[i] += b;
	return a;
}

template<typename A>
CVector<A>& operator+(A b, CVector<A>& a)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < a.VectorSize; i++)
		a.Data[i] += b;
	return a;
}

template<typename A>
CVector<A>& operator*(CVector<A>& a, CVector<A>& b)
{ 
	CVector<A> v(a.VectorSize);
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < v.VectorSize; i++)
		v.Data[i] = a.Data[i] * b.Data[i];
	return v;
}

template<typename A>
CVector<A>& operator*(CVector<A>& a, A b)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < a.VectorSize; i++)
		a.Data[i] = a.Data[i] * b;
	return a;
}

template<typename A>
CVector<A>& operator*(A b, CVector<A>& a)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < a.VectorSize; i++)
		a.Data[i] = a.Data[i] * b;
	return a;
}

template<typename A>
CVector<A>& operator-(CVector<A>& a, CVector<A>& b)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < a.VectorSize; i++)
		a.Data[i] -= b.Data[i];
	return a;
}

template<typename A>
CVector<A>& operator-(CVector<A>& a, A d)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < a.VectorSize; i++)
		a.Data[i] -= d;
	return a;
}

template<typename A>
CVector<A>& operator/(CVector<A>& a, CVector<A>& b)
{
	// TODO: вставьте здесь оператор return
	
	for (int i = 0; i < a.VectorSize; i++)
		a.Data[i] = a.Data[i] / b.Data[i];
	return a;
}


int main()
{
	CVector<int> a(2);
	CVector<int> b(2);
	cin >> a >> b;
	CVector<int> d = a;
	CVector<int> e = a + b;
	CVector<int> p = a - b;
	
	cout << a<<e ;

	system("pause");
}
