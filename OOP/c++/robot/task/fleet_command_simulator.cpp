/*
    TASK: Fleet Command Simulator (Mandatory)

    Build a small warehouse fleet command simulator from scratch, using
    everything covered in this session: abstraction, composition,
    inheritance, and polymorphism.

    You are NOT given any classes to start from — design and implement
    them yourself. Below is the full spec. An answer is available in
    answer/fleet_command_simulator.cpp if you get stuck, but try first.

    --------------------------------------------------------------------
    1. Components (composition)
    --------------------------------------------------------------------
    - Motor: has a private speed (0-100, clamped) and a spin(speed) method
      that validates/clamps the value and prints what it's doing.
    - DistanceSensor: has a private maxRange and a fixed, scripted sequence
      of readings (no rand()/random — deterministic output only) and a
      getReading() method that cycles through the sequence, clamped to
      maxRange, and prints the reading.

    --------------------------------------------------------------------
    2. Robot (abstraction + composition)
    --------------------------------------------------------------------
    - Robot is an ABSTRACT base class (a pure virtual performTask()).
    - Robot HAS-A Motor and HAS-A DistanceSensor (composition, not
      inherited fields) plus its own id and batteryLevel (starts at 100).
    - Robot provides two concrete, shared methods used by every subclass:
        - checkObstacle(): reads the DistanceSensor and returns true if
          the distance is below a safe threshold (e.g. 50cm).
        - move(): calls checkObstacle() first. If blocked, it stops the
          motor and returns false without moving. Otherwise it spins the
          motor, drains some battery (e.g. 5%), and returns true.

    --------------------------------------------------------------------
    3. Robot types (inheritance)
    --------------------------------------------------------------------
    Create exactly these three concrete subclasses of Robot:
        - DeliveryRobot: performTask() calls move(); if it succeeds,
          prints that it delivered a package.
        - CleaningRobot: performTask() calls move(); if it succeeds,
          prints that it cleaned the floor.
        - GuardRobot: performTask() calls move(); if it succeeds, prints
          that it patrolled its zone.

    --------------------------------------------------------------------
    4. Fleet dispatch (polymorphism)
    --------------------------------------------------------------------
    - Build a fleet: at least one of each robot type, e.g.
      { DeliveryRobot("D-1"), CleaningRobot("C-1"), GuardRobot("G-1") }.
    - Hardcode a command list in main() — a list of (robotId, command)
      pairs, e.g. {"D-1", "run"}, {"C-1", "run"}, {"G-1", "run"},
      {"D-1", "run"} — with at least 2 robots receiving more than one
      command, so at least one robot's DistanceSensor eventually reports
      an obstacle and blocks a move().
    - Loop over the command list, find the matching robot in the fleet
      by id, and call performTask() on it POLYMORPHICALLY (through the
      abstract Robot type — no if/else chain checking concrete type).

    --------------------------------------------------------------------
    5. Final report
    --------------------------------------------------------------------
    After all commands have run, print one line per robot in the fleet:
        "<id>: battery <batteryLevel>%, obstacle encountered: <yes|no>"
    "obstacle encountered" is yes if that robot's move() ever returned
    false (was blocked) at any point during the simulation.

    --------------------------------------------------------------------
    Clean up any heap-allocated robots before the program exits.
*/

int main() {
    return 0;
}
