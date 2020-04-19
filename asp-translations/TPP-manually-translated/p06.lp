#const steps=8.

%objects
goods(goods1; goods2; goods3; goods4; goods5; goods6).
truck(truck1; truck2).
market(market1; market2).
depot(depot1).
level(level0; level1; level2).
place(market1; market2; depot1).

%predicates
next(level1, level0).
next(level2, level1).
connected(market1, market2).
connected(market2, market1).
connected(depot1, market2).
connected(market2, depot1).

%init
ready_to_load(goods1, market1, level0, 0).
ready_to_load(goods1, market2, level0, 0).
ready_to_load(goods2, market1, level0, 0).
ready_to_load(goods2, market2, level0, 0).
ready_to_load(goods3, market1, level0, 0).
ready_to_load(goods3, market2, level0, 0).
ready_to_load(goods4, market1, level0, 0).
ready_to_load(goods4, market2, level0, 0).
ready_to_load(goods5, market1, level0, 0).
ready_to_load(goods5, market2, level0, 0).
ready_to_load(goods6, market1, level0, 0).
ready_to_load(goods6, market2, level0, 0).
stored(goods1, level0, 0).
stored(goods2, level0, 0).
stored(goods3, level0, 0).
stored(goods4, level0, 0).
stored(goods5, level0, 0).
stored(goods6, level0, 0).
loaded(goods1, truck1, level0, 0).
loaded(goods1, truck2, level0, 0).
loaded(goods2, truck1, level0, 0).
loaded(goods2, truck2, level0, 0).
loaded(goods3, truck1, level0, 0).
loaded(goods3, truck2, level0, 0).
loaded(goods4, truck1, level0, 0).
loaded(goods4, truck2, level0, 0).
loaded(goods5, truck1, level0, 0).
loaded(goods5, truck2, level0, 0).
loaded(goods6, truck1, level0, 0).
loaded(goods6, truck2, level0, 0).
on_sale(goods1, market1, level1, 0).
on_sale(goods2, market1, level2, 0).
on_sale(goods3, market1, level1, 0).
on_sale(goods4, market1, level2, 0).
on_sale(goods5, market1, level2, 0).
on_sale(goods6, market1, level2, 0).
on_sale(goods1, market2, level0, 0).
on_sale(goods2, market2, level0, 0).
on_sale(goods3, market2, level1, 0).
on_sale(goods4, market2, level0, 0).
on_sale(goods5, market2, level0, 0).
on_sale(goods6, market2, level0, 0).
at(truck1, depot1, 0).
at(truck2, depot1, 0).


%goal
goal(T):- time(T),
	stored(goods1, level1, T),
	stored(goods2, level2, T),
	stored(goods3, level1, T),
	stored(goods4, level1, T),
	stored(goods5, level1, T),
	stored(goods6, level1, T).

