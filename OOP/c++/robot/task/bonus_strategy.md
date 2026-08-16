# Bonus: Strategy Pattern — Swappable Movement Behavior

Start from your working `fleet_command_simulator` solution (mandatory task) and add
a **Strategy pattern** on top of it: instead of every `Robot` reacting to obstacles
the same fixed way, let each robot be configured with a swappable movement strategy.

## Requirements

1. Define a `MovementStrategy` abstract base class with one pure virtual method:
   `bool shouldMove(int distanceReading)` — decides whether to proceed given the
   latest sensor reading.
2. Implement at least two concrete strategies:
   - `CautiousStrategy`: refuses to move if the reading is below a large safety
     margin (e.g. 80cm) — stops well before anything Aggressive would.
   - `AggressiveStrategy`: only refuses to move if the reading is below a small
     margin (e.g. 20cm) — pushes closer to obstacles before stopping.
3. Give `Robot` a `MovementStrategy*` (or equivalent) member, injected through its
   constructor, and have `move()` delegate its go/no-go decision to
   `strategy->shouldMove(reading)` instead of a hardcoded threshold.
4. In `main()`, build the same fleet as before but give different robots different
   strategies (e.g. `DeliveryRobot` gets `CautiousStrategy`, `GuardRobot` gets
   `AggressiveStrategy`) and re-run the same command list. Confirm the two robots
   now behave differently against the exact same scripted sensor readings.

This is composition again (`Robot` HAS-A `MovementStrategy`) — the point is to see
how swapping a robot's behavior at runtime doesn't require touching `Robot`,
`DeliveryRobot`, `CleaningRobot`, or `GuardRobot` at all, only the strategy object
passed in.
