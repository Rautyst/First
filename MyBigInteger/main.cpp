#include "big_int.h"
using namespace std;

int main()
{
	try
	{
		MyBigInt first{ "98954975473789543577598378954354789375347857353"};
		MyBigInt second{ "49234294279"};
		cout << first << " + " << second << " = " << first + second << '\n';
		cout << first << " - " << second << " = " << first - second << '\n';
		cout << first << " * " << second << " = " << first * second << '\n';
		cout << first << " / " << second << " = " << first / second << '\n';
		cout << first << " % " << second << " = " << first % second << '\n';

		cout << "\n\n\n";

		first = { "84568424057392345372454782227893848573857347859735734754879384737457379873457834578349549" };
		second = { "4923429427423923480432809432348909" };
		cout << first << " + " << second << " = " << first + second << '\n';
		cout << first << " - " << second << " = " << first - second << '\n';
		cout << first << " * " << second << " = " << first * second << '\n';
		cout << first << " / " << second << " = " << first / second << '\n';
		cout << first << " % " << second << " = " << first % second << '\n';

		
		cout << "\n\n\n";

		clock_t start = clock();
	
		first = { "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999" };
		cout << first * first * first * first * first * first * first * first * first * first << '\n';

		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);
	}
	catch (std::runtime_error ex)
	{
		cout << "\nRUNTIME ERROR: " << ex.what() << '\n';
	}
	catch (...)
	{
		cout << "\nSOMETHING WRONG!\n";
	}
	return 0;
}