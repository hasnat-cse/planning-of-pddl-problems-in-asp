#const steps=4.

%objects
passenger(p0).
floor(f0; f1).

%predicates
above(f0, f1).
origin(p0, f1).
destin(p0, f0).

%init
lift_at(f0, 0).

%goal
goal(T):- time(T),
	served(p0, T).
