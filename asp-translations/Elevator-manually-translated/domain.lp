% IPC2 Domain: Elevator

% Non conflicting Parallel actions are allowed

#show board/3.
#show depart/3.
#show up/3.
#show down/3.


time(0..steps).

% actions
{board(F,P,T)} :-
        floor(F), passenger(P), time(T),
        lift_at(F,T),
	origin(P,F),
	not lift_moving(T),
        not goal(T).

{depart(F,P,T)} :-
        floor(F), passenger(P), time(T),
        lift_at(F,T),
	destin(P,F),
	boarded(P,T),
	not lift_moving(T),
        not goal(T).

{up(F1,F2,T)} :-
	floor(F1), floor(F2), time(T),
	lift_at(F1,T),
	above(F1,F2),
        not goal(T).

{down(F1,F2,T)} :-
	floor(F1), floor(F2), time(T),
	lift_at(F1,T),
	above(F2,F1),
        not goal(T).


%auxiliary predicates		
lift_moving(T):-
	time(T),
	up(F1,F2,T).

lift_moving(T):-
	time(T),
	down(F1,F2,T).


departing(P,T):-
	passenger(P), time(T),
	depart(F,P,T).


%fluents
boarded(P,T+1):-
	passenger(P), time(T),
	lift_at(F,T),
	board(F,P,T).

served(P,T+1):- 
	passenger(P), time(T),
	boarded(P,T),
	depart(F,P,T).

lift_at(F2,T+1):-
	floor(F2), time(T),
	lift_at(F1,T),
	up(F1,F2,T).

lift_at(F2,T+1):-
	floor(F2), time(T),
	lift_at(F1,T),
	down(F1,F2,T).


%frame axioms
boarded(P,T+1):-
	passenger(P), time(T),
	boarded(P,T),
	not departing(P,T).

lift_at(F,T+1):-
	floor(F), time(T),
	lift_at(F,T),
	not lift_moving(T).

served(P,T+1):-
	passenger(P), time(T),
	served(P,T).


%goal
goal(T+1):-  time(T), goal(T).

goal :- time(T), goal(T).
:- not goal.


%constraints
% lift in two different floors
:- floor(F1), floor(F2), time(T), F1 != F2,
	lift_at(F1,T), lift_at(F2,T).

