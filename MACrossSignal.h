#pragma once
#include <vector>

class SmaCalculator
{
private:
	std::vector<double> _window;
	int _index = 0;
	double _sum = 0.0;
	double _avg = 0.0;

public:
	SmaCalculator(int window_size):
		_window(window_size, 0.0)
	{}

	double add(double value)
	{
		double evict = _window[_index];
		_window[_index] = value;
		_index = (_index + 1) % _window.size();
		_sum = _sum - evict + value;
		_avg = _sum / _window.size();
		return _avg;
	 }
};

class MACrossSignal
{
private:
	int _count = 0;
	int _slow_window_size;
	SmaCalculator _fast_sma;
	SmaCalculator _slow_sma;

public:
	MACrossSignal(int fast_window_size, int slow_window_size):
		_slow_window_size(slow_window_size),
		_fast_sma(fast_window_size),
		_slow_sma(slow_window_size)
	{ }

	int update(double price)
	{
		double fast = _fast_sma.add(price);
		double slow = _slow_sma.add(price);

		if(_count++ < _slow_window_size)
		{
			return 0; // not enough data yet
		}

		if (fast > slow)
			return 1; // buy signal
		else if (fast < slow)
			return -1; // sell signal
		else
			return 0; // no signal
	}
};
