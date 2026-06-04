# Core Questions

What is the class supposed to do?
What should `update(price)` return?
What should happen before enough data has been received?

# Implementation Thinking

What state must the class keep between updates?
Would you split out a helper for the moving average?
How would you compute a rolling average efficiently?

# Design Choices

Should `update` return an `int` or an enum?
Where should the warm-up logic live?
What should happen if fast and slow averages are equal?
How would you handle invalid window sizes?

## Edge Cases

- Fast window larger than slow window.
- Window size is zero or negative.
- Constant prices.
- Exact crossover tick.
- Not enough data yet.

## Testing

- What tests would you write first?
- How would you test the warm-up period?
- How would you test a buy-to-sell transition?
- What would you expect from the sample price series in `main.cpp`?

## Strong Signals

- Explains the problem clearly.
- Mentions rolling state and warm-up behavior.
- Suggests a helper class or clean decomposition.
- Thinks in tests and edge cases.
- Explains tradeoffs in simple language.

## Weak Signals

- Jumps straight to syntax.
- Ignores initial data/warm-up.
- Recomputes everything each tick without noticing.
- Has trouble explaining design choices.
- Focuses on language trivia instead of implementation.

## Good Follow-Ups

- How would you generalize this for more indicators?
- How would you adapt it for EMA instead of SMA?
- How would you make it easier to unit test?

