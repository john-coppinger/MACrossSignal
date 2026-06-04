# MACrossSignal Interviewer Script

This script is designed for a quantitative analyst interview where the candidate has some C++ familiarity but is not expected to be a language expert.

The goal is to evaluate how the candidate thinks about implementation, state, edge cases, and testing while turning `MACrossSignal.start.h` into something resembling `MACrossSignal.h`.

## Interview Goal

- Assess problem decomposition.
- Assess how the candidate reasons about streaming data and stateful algorithms.
- Assess comfort with basic object-oriented design.
- Assess whether the candidate thinks clearly about warm-up behavior, edge cases, and testability.

## Suggested Interview Flow

### 1. Frame the problem

Start by asking the candidate to explain the intended behavior in their own words.

Questions:

- What is this class supposed to do?
- What behavior should `update(price)` produce?
- What does each signal value mean in this context?
- What happens during the first few updates before the moving averages are fully formed?

What to listen for:

- Clear explanation of a moving-average crossover signal.
- Recognition that the class is stateful across calls.
- Awareness that the first few data points may not produce a meaningful signal.

### 2. Identify the required state

Ask them to reason about what the class needs to remember between calls.

Questions:

- What state needs to live inside `MACrossSignal`?
- What do we need to store from the constructor?
- Would you keep the fast and slow moving average logic inside the class or split it out?

What to listen for:

- Storage for window sizes and rolling state.
- Recognition that a helper type may make the code simpler.
- Thoughtful discussion of encapsulation and reuse.

### 3. Discuss the algorithm

Move from the business idea to the implementation approach.

Questions:

- How would you compute a simple moving average efficiently as prices arrive one at a time?
- Would you recompute the average from scratch on every update?
- What data structure would you use for a rolling window?
- How can you keep the per-update cost low?

What to listen for:

- Use of a rolling sum and fixed-size window.
- Awareness of O(1) update cost.
- Comfort reasoning about a circular buffer or equivalent structure.

### 4. Explore design choices

This section is about how they structure the code.

Questions:

- Would you make a helper class for the moving average?
- If yes, what should that helper own?
- Would you expose the current averages for debugging?

What to listen for:

- Preference for small, focused components.
- Discussion of API clarity versus simplicity.
- Ability to explain tradeoffs rather than just naming a pattern.

### 5. Warm-up and initialization behavior

This is often where practical thinking shows up.

Questions:

- What should happen until enough data has arrived for the slow window?
- Should the system emit a signal immediately or wait?
- How would you represent "not enough data yet"?
- Should the fast and slow averages be compared before the windows are full?

What to listen for:

- A deliberate warm-up policy.
- Recognition that early values may be misleading.
- Clear separation between calculation and signal generation.

### 6. Edge cases and validation

Ask them to think beyond the happy path.

Questions:

- What if the fast window is larger than the slow window?
- What if a window size is zero or negative?
- What if the fast and slow averages are equal?
- What should happen if prices stay constant?
- What signal should be emitted at the exact crossover point?

What to listen for:

- Defensive thinking.
- Identification of ambiguous requirements.
- Willingness to clarify behavior instead of guessing.

### 7. Testing strategy

Shift toward how they would prove correctness.

Questions:

- What tests would you write first?
- How would you test the warm-up period?
- How would you test a crossover from buy to sell?
- How would you test the sample series in `main.cpp`?
- What outputs would you expect from that sequence of prices?

What to listen for:

- Concrete test cases.
- Awareness of expected outputs over time.
- Use of both deterministic examples and boundary tests.

### 8. Incremental implementation plan

This reveals how they approach coding under time pressure.

Questions:

- If you were implementing this live, what would you build first?
- Would you make a simple working version before optimizing?
- What is the smallest version that would still be useful?

What to listen for:

- A preference for small steps.
- Prioritization of correctness before cleverness.
- Ability to sequence work logically.

### 9. Maintainability and future change

End with a discussion of extension and future evolution.

Questions:

- How would you document this class for another developer?
- What would you change if we later wanted exponential moving averages instead of simple moving averages?
- How would you adapt the design if we wanted more than two signals?

What to listen for:

- Appreciation for extensibility.
- Good separation between strategy and mechanics.
- Ability to think one step beyond the current task.

## Evaluation Criteria

Use the following dimensions to guide your assessment.

- Problem understanding: Can they explain the task clearly?
- State management: Do they understand what must persist between updates?
- Algorithmic reasoning: Can they describe an efficient rolling average?
- Code organization: Do they make reasonable decomposition choices?
- Edge-case thinking: Do they identify ambiguous or risky behavior?
- Testing mindset: Do they know how to verify the implementation?
- Communication: Can they explain tradeoffs clearly and calmly?

## Strong Signals

- They ask clarifying questions about warm-up behavior and crossover semantics.
- They naturally describe maintaining a rolling sum instead of recalculating everything.
- They separate the moving-average calculation from the signal decision.
- They think in terms of tests and expected outputs, not just code.
- They explain tradeoffs in plain English.

## Weak Signals

- They jump straight into syntax without clarifying behavior.
- They ignore the first few values and warm-up behavior.
- They recompute averages from scratch without acknowledging the cost.
- They have trouble explaining why a helper class might be useful.
- They focus on language trivia instead of implementation choices.

## Optional Follow-Up Prompt

If the candidate finishes quickly, ask:

- How would you generalize this to a larger library of technical indicators?
- What would change if we needed to process multiple symbols at once?
- How would you make this easier to unit test?
