#const steps=6.

%objects
passenger(p0; p1).
floor(f0; f1; f2; f3).

%predicates
above(f0, f1).
above(f0, f2).
above(f0, f3).

above(f1, f2).
above(f1, f3).

above(f2, f3).

origin(p0, f3).
destin(p0, f2).

origin(p1, f1).
destin(p1, f3).

%init
lift_at(f0, 0).

%goal
goal(T):- time(T),
	served(p0, T),
	served(p1, T).
