//�˳���������Ϥһ����Ĳ���
//˽�к���reverse��������Ϊconst�����������ڱ�operator+��const�����б�����ʱ�ᱨ���������
//����������������������У�����ͷ��صĲ��������������͵�

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