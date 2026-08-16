"""
TASK: Fleet Command Simulator (Mandatory)

Build a small warehouse fleet command simulator from scratch, using
everything covered in this session: abstraction, composition,
inheritance, and polymorphism.

You are NOT given any classes to start from -- design and implement
them yourself. Below is the full spec. An answer is available in
answer/fleet_command_simulator.py if you get stuck, but try first.

------------------------------------------------------------------------
1. Components (composition)
------------------------------------------------------------------------
- Motor: has a "private" _speed (0-100, clamped) and a spin(speed) method
  that validates/clamps the value and prints what it's doing.
- DistanceSensor: has a "private" _max_range and a fixed, scripted
  sequence of readings (no random module -- deterministic output only)
  and a get_reading() method that cycles through the sequence, clamped
  to _max_range, and prints the reading.

------------------------------------------------------------------------
2. Robot (abstraction + composition)
------------------------------------------------------------------------
- Robot is an ABSTRACT base class (ABC, with an @abstractmethod
  perform_task()).
- Robot HAS-A Motor and HAS-A DistanceSensor (composition, not inherited
  fields) plus its own id and battery_level (starts at 100).
- Robot provides two concrete, shared methods used by every subclass:
    - check_obstacle(): reads the DistanceSensor and returns True if the
      distance is below a safe threshold (e.g. 50cm).
    - move(): calls check_obstacle() first. If blocked, it stops the
      motor and returns False without moving. Otherwise it spins the
      motor, drains some battery (e.g. 5%), and returns True.

------------------------------------------------------------------------
3. Robot types (inheritance)
------------------------------------------------------------------------
Create exactly these three concrete subclasses of Robot:
    - DeliveryRobot: perform_task() calls move(); if it succeeds, prints
      that it delivered a package.
    - CleaningRobot: perform_task() calls move(); if it succeeds, prints
      that it cleaned the floor.
    - GuardRobot: perform_task() calls move(); if it succeeds, prints
      that it patrolled its zone.

------------------------------------------------------------------------
4. Fleet dispatch (polymorphism)
------------------------------------------------------------------------
- Build a fleet: at least one of each robot type, e.g.
  [DeliveryRobot("D-1"), CleaningRobot("C-1"), GuardRobot("G-1")].
- Hardcode a command list in main -- a list of (robot_id, command)
  pairs, e.g. ("D-1", "run"), ("C-1", "run"), ("G-1", "run"),
  ("D-1", "run") -- with at least 2 robots receiving more than one
  command, so at least one robot's DistanceSensor eventually reports an
  obstacle and blocks a move().
- Loop over the command list, find the matching robot in the fleet by
  id, and call perform_task() on it POLYMORPHICALLY (through the
  abstract Robot type -- no if/else chain checking concrete type).

------------------------------------------------------------------------
5. Final report
------------------------------------------------------------------------
After all commands have run, print one line per robot in the fleet:
    "<id>: battery <battery_level>%, obstacle encountered: <yes|no>"
"obstacle encountered" is yes if that robot's move() ever returned False
(was blocked) at any point during the simulation.
"""


def main():
    pass


if __name__ == "__main__":
    main()
