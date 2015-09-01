#include "bigInteger.h"

namespace BIGINTEGER
{
	string BigInteger::reverse(string str) const
	{
		string result = "";
		int len = str.length();
		for (int i = 0; i < len; i++){
			result = str[i] + result;
		}
		return result;
	}
	string BigInteger::mulOneDigit(int a, string b) const
	{
		int len = b.length();
		string result = "";
		int carrier = 0;
		for (int i = len - 1; i >= 0; i--){
			int temp = (b[i] - '0') * a + carrier;
			carrier = temp / 10;
			result = char(temp % 10 + '0') + result;
		}
		if (carrier > 0){
			result = char(carrier + '0') + result;
		}
		return result;
	}
	BigInteger::BigInteger()
	{
		strNum = "0";
	}
	BigInteger::BigInteger(int num)
	{
		while (num){
			int temp = num % 10;
			strNum = char(temp + '0') + strNum;
			num /= 10;
		}
	}
	BigInteger::BigInteger(string num)
	{
		strNum = num;
	}
	BigInteger::~BigInteger(){}
	BigInteger BigInteger::operator+(const BigInteger & b) const
	{
		string str1 = reverse(this->strNum),
			str2 = reverse(b.strNum);
		int len1 = str1.length(),
			len2 = str2.length();
		
		if (len1 < len2){
			std::swap(len1, len2);
			std::swap(str1, str2);
		}
		string reverseResult = "";
		int carrier = 0;
		for (int i = 0; i < len1; i++){
			char digit1 = str1[i],
				digit2 = i >= len2 ? '0' : str2[i];
			int digitResult = digit1 - '0' + digit2 - '0' + carrier;
			if (digitResult <= 9){
				reverseResult += char(digitResult + '0');
				carrier = 0;
			}
			else{
				reverseResult += char(digitResult - 10 + '0');
				carrier = 1;
			}
		}
		if (carrier != 0){
			reverseResult += '1';
		}
		return BigInteger(reverse(reverseResult));
	}
	BigInteger BigInteger::operator*(const BigInteger & b) const
	{
		string str1 = this->strNum,
			str2 = b.strNum;
		int len1 = str1.length(),
			len2 = str2.length();

		if (len1 < len2){
			std::swap(len1, len2);
			std::swap(str1, str2);
		}
		BigInteger result("0");
		for (int i = len2 - 1; i >= 0; i--){
			string tempResult = mulOneDigit((str2[i] - '0'), str1);
			for (int j = 0; j < len2 - 1 - i; j++){
				tempResult += '0';
			}
			result = result + BigInteger(tempResult);
		}
		return result;
	}

	BigInteger operator+(int a, const BigInteger & b)
	{
		return b + a;
	}
	BigInteger operator*(int a, const BigInteger & b){
		return b * a;
	}
	std::ostream & operator<<(std::ostream & os, const BigInteger & v)
	{
		os << v.strNum;
		return os;
	}
	std::istream & operator>>(std::istream & is, BigInteger & v)
	{
		is >> v.strNum;
		return is;
	}
}