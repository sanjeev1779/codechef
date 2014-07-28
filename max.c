#include <iostream>

using namespace std;

int main()
{
	float savings;
	int withdraw;

	scanf("%i", &withdraw);
	scanf("%f", &savings);


	if (withdraw%5 != 0 || withdraw+0.5 > savings)
	{
		printf("%f\n", savings);
	}
	else
	{
		savings = savings - withdraw - 0.5;
		printf("%f\n", savings);
	}
}
