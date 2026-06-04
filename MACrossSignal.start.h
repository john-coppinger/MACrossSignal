#pragma once

/*

Implement the logic to determine whether to buy, sell, or hold 
based on a trivial moving average crossover strategy.
Logic for update() should:
1. Calculate the fast and slow moving averages based on the provided window sizes.
2. Compare the fast and slow moving averages to determine the signal:
   - If the fast moving average is above the slow moving average, return 1 (buy signal).
   - If the fast moving average is below the slow moving average, return -1 (sell signal).
   - Otherwise, return 0 (hold signal).

*/

class MACrossSignal
{
public:
    // TODO Add whatever you need to the constructor
	MACrossSignal(int fast_window_length, int slow_window_length)
	{ }

    // TODO Implement the signal logic described above
	int update(double price)
	{
        return 0;
    }
};
