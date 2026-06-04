#include "MACrossCalculator.h"
#include <iostream>

using namespace std;

int main()
{
	MACrossCalculator calc(5, 10);

	vector<double> prices = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
	                          110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
							  118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108,
							  107, 106, 105, 104, 103, 102, 101, 100
							};

	for (double price : prices)
	{
		Signal action = calc.update(price);
		if (action == Signal::Buy)
			cout << "Buy at " << price << endl;
		else if (action == Signal::Sell)
			cout << "Sell at " << price << endl;
	}
}
