#include <iostream>
#include <vector>
using namespace std;

/* ���������ɨ���� */

int main()
{
	for (unsigned char i = 128; i < 255; i += 1)
	{
		cout << i << '\t' << int(i) << '\n';
	}
	return 0;
}