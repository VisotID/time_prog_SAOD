#include <iostream>
#include "Time.h"

int main()
{
	int* mass = Arr_create_m<int>(100000000,1,9999);
	Time_tot<int>(100000000, 0, 100000000 - 1, mass);
}
