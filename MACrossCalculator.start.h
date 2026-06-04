#pragma once

/*

Implement the logic to determine whether to buy, sell, or hold 
based on a trivial moving average crossover strategy.
Logic for update() should:
1. Calculate the fast and slow moving averages based on the provided window sizes.
2. Compare the fast and slow moving averages to determine the signal:
   - If the fast moving average is above the slow moving average, return `Signal::Buy`.
   - If the fast moving average is below the slow moving average, return `Signal::Sell`.
   - Otherwise, return `Signal::Hold`.

*/


enum class Signal { Hold, Buy, Sell };

class MACrossCalculator
{
public:
    // TODO Add whatever you need to the constructor
	MACrossCalculator(int fast_window_length, int slow_window_length)
	{ }

    // TODO Implement the signal generation logic described above
	Signal update(double price)
	{
        return Signal::Hold;
    }
};
