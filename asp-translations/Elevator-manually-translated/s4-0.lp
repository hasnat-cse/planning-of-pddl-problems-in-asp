#const steps=12.

%objects
passenger(p0; p1; p2; p3).
floor(f0; f1; f2; f3; f4; f5; f6; f7).

%predicates
above(f0, f1).
above(f0, f2).
above(f0, f3).
above(f0, f4).
above(f0, f5).
above(f0, f6).
above(f0, f7).

above(f1, f2).
above(f1, f3).
above(f1, f4).
above(f1, f5).
above(f1, f6).
above(f1, f7).

above(f2, f3).
above(f2, f4).
above(f2, f5).
above(f2, f6).
above(f2, f7).

above(f3, f4).
above(f3, f5).
above(f3, f6).
above(f3, f7).

above(f4, f5).
above(f4, f6).
above(f4, f7).

above(f5, f6).
above(f5, f7).

above(f6, f7).

origin(p0, f7).
destin(p0, f6).

origin(p1, f1).
destin(p1, f3).

origin(p2, f1).
destin(p2, f7).

origin(p3, f2).
destin(p3, f4).

%init
lift_at(f0, 0).

%goal
goal(T):- time(T),
	served(p0, T),
	served(p1, T),
	served(p2, T),
	served(p3, T).
