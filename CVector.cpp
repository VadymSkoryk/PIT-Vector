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
	CVector(CVector &v);
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
	friend CVector<A>& operator+(CVector<A>&, CVector<A>&);
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
	template <typename D>
	friend CVector<A>& operator-(CVector<A>&, A);
	/////////////
	template <typename A>
	friend CVector<A>& operator/(CVector<A>&,CVector<A>&);




};


int main()
{
	CVector<int> a(3), b(2), c;
	CVector<int> d = a;
	CVector<int> e = a + b;
	CVector<int> p = a - 4;
	cin >> a>>b;
	cout<<a/b;

	system("pause");
}

template<class A>
CVector<A>::CVector()
{
	Data = nullptr;
	VectorSize = 0;
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
CVector<A>::CVector(CVector & v)
{
	*this = v;
	cout << "\n Copy Construct";
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
CVector<A>& operator+(CVector<A>& a, CVector<A>& b)
{
	// TODO: вставьте здесь оператор return
	if (a.VectorSize != b.VectorSize)
		throw 1;
	CVector<A> v(a.VectorSize);
	for (int i = 0; i < v.VectorSize; i++)
	{
		v.Data[i] = a.Data[i] + b.Data[i];
	}
	return v;
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
CVector<A>& operator-(CVector<A>&, A d)
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
