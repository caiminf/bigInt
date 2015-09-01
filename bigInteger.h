//此程序用于熟悉一般类的操作
//私有函数reverse必须声明为const，否在在类内被operator+等const函数中被调用时会报错，详见博客
//对输入输出操作符的重载中，传入和返回的参数都是引用类型的

#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_
#include <iostream>
#include <string>
namespace BIGINTEGER
{
	using std::string;
	class BigInteger
	{
	private:
		string strNum;
		string reverse(string str) const;
		string mulOneDigit(int a, string b) const;
	public:
		BigInteger();
		BigInteger(int num);
		BigInteger(string num);
		~BigInteger();

		//operator overloading
		//operator +
		BigInteger operator+(const BigInteger & b) const;

		//operator *
		BigInteger operator*(const BigInteger & b) const;

		//friends
		friend BigInteger operator+(int a, const BigInteger & b);
		friend BigInteger operator*(int a, const BigInteger & b);
		friend std::ostream & operator<<(std::ostream & os, const BigInteger & v);
		friend std::istream & operator>>(std::istream & is, BigInteger & v);
	};
}

#endif