% IPC5 Domain: TPP Propositional

% Non conflicting Parallel actions are allowed

#show load/8.
#show unload/8.
#show drive/4.
#show buy/8.


time(0..steps).

% actions
{load(G,Tr,M,L1,L2,L3,L4,T)} :-
        goods(G), truck(Tr), market(M), level(L1), level(L2), level(L3), level(L4), time(T),
        at(Tr,M,T),
        loaded(G,Tr,L3,T),
	ready_to_load(G,M,L2,T),
	next(L2,L1),
	next(L4,L3),
	not driving(Tr,T),
        not goal(T).

{unload(G,Tr,D,L1,L2,L3,L4,T)} :-
        goods(G), truck(Tr), depot(D), level(L1), level(L2), level(L3), level(L4), time(T),
        at(Tr,D,T),
        loaded(G,Tr,L2,T),
	stored(G,L3,T),
	next(L2,L1),
	next(L4,L3),
	not driving(Tr,T),
        not goal(T).

{drive(Tr,From,To,T)} :-
	truck(Tr), place(From), place(To), time(T),
        at(Tr,From,T),
	connected(From,To),
        not goal(T).
		

{buy(Tr,G,M,L1,L2,L3,L4,T)} :-
        truck(Tr), goods(G), market(M), level(L1), level(L2), level(L3), level(L4), time(T),
        at(Tr,M,T),
        on_sale(G,M,L2,T),
	ready_to_load(G,M,L3,T),
	next(L2,L1),
	next(L4,L3),
	not driving(Tr,T),
        not goal(T).


%auxiliary predicates		
change_truck(G,Tr,T):-
	goods(G), truck(Tr), time(T),
	load(G,Tr,M,L1,L2,L3,L4,T).

change_truck(G,Tr,T):-
	goods(G), truck(Tr), time(T),
	unload(G,Tr,D,L1,L2,L3,L4,T).
	
change_market(G,M,T):-
	goods(G), market(M), time(T),
	load(G,Tr,M,L1,L2,L3,L4,T).

change_market(G,M,T):-
	goods(G), market(M), time(T),
	buy(Tr,G,M,L1,L2,L3,L4,T).
	
driving(Tr,T):-
	truck(Tr), time(T),
	drive(Tr,From,To,T).
	
change_depot(G,T):-
	goods(G), time(T),
	unload(G,Tr,D,L1,L2,L3,L4,T).

buying(G,M,T):-
	goods(G), market(M), time(T),
	buy(Tr,G,M,L1,L2,L3,L4,T).


%fluents
loaded(G,Tr,L4,T+1):-
		truck(Tr), goods(G), level(L4), time(T),
		loaded(G,Tr,L3,T),
		load(G,Tr,M,L1,L2,L3,L4,T).

ready_to_load(G,M,L1,T+1):-
		goods(G), market(M), level(L1), time(T),
		ready_to_load(G,M,L2,T),
		load(G,Tr,M,L1,L2,L3,L4,T).
		
		
loaded(G,Tr,L1,T+1):-
		goods(G), truck(Tr), level(L1), time(T),
		loaded(G,Tr,L2,T),
		unload(G,Tr,D,L1,L2,L3,L4,T).
		
stored(G,L4,T+1):-
		goods(G), level(L4), time(T),
		stored(G,L3,T),
		unload(G,Tr,D,L1,L2,L3,L4,T).
		
		
at(Tr,To,T+1):-
		truck(Tr), place(To), time(T),
		at(Tr,From,T),
		drive(Tr,From,To,T).
		
		
on_sale(G,M,L1,T+1):-
		goods(G), market(M), level(L1), time(T),
		on_sale(G,M,L2,T),
		buy(Tr,G,M,L1,L2,L3,L4,T).
		
ready_to_load(G,M,L4,T+1):-
		goods(G), market(M), level(L4), time(T),
		ready_to_load(G,M,L3,T),
		buy(Tr,G,M,L1,L2,L3,L4,T).
		


%frame axioms
loaded(G,Tr,L4,T+1):-
		truck(Tr), goods(G), level(L4), time(T),
		loaded(G,Tr,L4,T),
		not change_truck(G,Tr,T).

ready_to_load(G,M,L1,T+1):-
		goods(G), market(M), level(L1), time(T),
		ready_to_load(G,M,L1,T),
		not change_market(G,M,T).
		
stored(G,L4,T+1):-
		goods(G), level(L4), time(T),
		stored(G,L4,T), 
		not change_depot(G,T).

at(Tr,To,T+1):-
		truck(Tr), place(To), time(T),
		at(Tr,To,T),
		not driving(Tr,T).

on_sale(G,M,L1,T+1):-
		goods(G), market(M), level(L1), time(T),
		on_sale(G,M,L1,T),
		not buying(G,M,T).


%goal
goal(T+1):-  time(T), goal(T).

goal :- time(T), goal(T).
:- not goal.


%constraints
% Same truck at two different places
:- truck(Tr), place(From), place(To), time(T), From != To,
	at(Tr,From,T), at(Tr,To,T).

% Same truck loaded with same good at two different level
:- truck(Tr), goods(G), level(L1), level(L2), time(T), L1 != L2,
	loaded(G,Tr,L1,T), loaded(G,Tr,L2,T).

% Same market is ready-to-load with same good at two different level
:- market(M), goods(G), level(L1), level(L2), time(T), L1 != L2,
	ready_to_load(G,M,L1,T), ready_to_load(G,M,L2,T).

% Same good is on-sale in same market at two different level
:- market(M), goods(G), level(L1), level(L2), time(T), L1 != L2,
	on_sale(G,M,L1,T), on_sale(G,M,L2,T).

% Same good is stored in at two different level
:- goods(G), level(L1), level(L2), time(T), L1 != L2,
	stored(G,L1,T), stored(G,L2,T).

% Two different trucks are loading same goods from same market at same time
:- market(M), goods(G), truck(Tr1), truck(Tr2), time(T), Tr1!=Tr2,
	load(G,Tr1,M,_,_,_,_,T), load(G,Tr2,M,_,_,_,_,T).


