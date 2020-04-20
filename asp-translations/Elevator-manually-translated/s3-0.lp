#const steps=8.

%objects
passenger(p0; p1; p2).
floor(f0; f1; f2; f3; f4; f5).

%predicates
above(f0, f1).
above(f0, f2).
above(f0, f3).
above(f0, f4).
above(f0, f5).

above(f1, f2).
above(f1, f3).
above(f1, f4).
above(f1, f5).

above(f2, f3).
above(f2, f4).
above(f2, f5).

above(f3, f4).
above(f3, f5).

above(f4, f5).

origin(p0, f1).
destin(p0, f4).

origin(p1, f3).
destin(p1, f1).

origin(p2, f5).
destin(p2, f1).

%init
lift_at(f0, 0).

%goal
goal(T):- time(T),
	served(p0, T),
	served(p1, T),
	served(p2, T).
