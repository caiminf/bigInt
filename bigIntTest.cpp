#include <iostream>
#include "bigInteger.h"
using namespace std;
using namespace BIGINTEGER;

int main()
{
	while (1){
		BigInteger bigNum1, bigNum2;
		cin >> bigNum1 >> bigNum2;
		cout << "bigNum1 + bigNum2 = " << bigNum1 + bigNum2 << endl;
		cout << "bigNum1 * bigNum2 = " << bigNum1 * bigNum2 << endl;
	}
}