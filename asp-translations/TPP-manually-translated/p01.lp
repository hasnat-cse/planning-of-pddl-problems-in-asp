#const steps=5.

%objects
goods(goods1).
truck(truck1).
market(market1).
depot(depot1).
level(level0; level1).
place(market1; depot1).

%predicates
next(level1, level0).
connected(depot1, market1).
connected(market1, depot1).

%init
ready_to_load(goods1, market1, level0, 0).
stored(goods1, level0, 0).
loaded(goods1, truck1, level0, 0).
on_sale(goods1, market1, level1, 0).
at(truck1, depot1, 0).

%goal
goal(T):- time(T), stored(goods1, level1, T).