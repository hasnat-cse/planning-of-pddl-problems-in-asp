#const steps=11.

%objects
goods(goods1; goods2; goods3; goods4; goods5; goods6; goods7; goods8; goods9; goods10).
truck(truck1; truck2; truck3).
market(market1; market2; market3).
depot(depot1).
level(level0; level1; level2).
place(market1; market2; market3; depot1).

%predicates
next(level1, level0).
next(level2, level1).
connected(market1, market3).
connected(market2, market3).
connected(market3, market1).
connected(market3, market2).
connected(depot1, market2).
connected(market2, depot1).

%init
ready_to_load(goods1, market1, level0, 0).
ready_to_load(goods1, market2, level0, 0).
ready_to_load(goods1, market3, level0, 0).
ready_to_load(goods2, market1, level0, 0).
ready_to_load(goods2, market2, level0, 0).
ready_to_load(goods2, market3, level0, 0).
ready_to_load(goods3, market1, level0, 0).
ready_to_load(goods3, market2, level0, 0).
ready_to_load(goods3, market3, level0, 0).
ready_to_load(goods4, market1, level0, 0).
ready_to_load(goods4, market2, level0, 0).
ready_to_load(goods4, market3, level0, 0).
ready_to_load(goods5, market1, level0, 0).
ready_to_load(goods5, market2, level0, 0).
ready_to_load(goods5, market3, level0, 0).
ready_to_load(goods6, market1, level0, 0).
ready_to_load(goods6, market2, level0, 0).
ready_to_load(goods6, market3, level0, 0).
ready_to_load(goods7, market1, level0, 0).
ready_to_load(goods7, market2, level0, 0).
ready_to_load(goods7, market3, level0, 0).
ready_to_load(goods8, market1, level0, 0).
ready_to_load(goods8, market2, level0, 0).
ready_to_load(goods8, market3, level0, 0).
ready_to_load(goods9, market1, level0, 0).
ready_to_load(goods9, market2, level0, 0).
ready_to_load(goods9, market3, level0, 0).
ready_to_load(goods10, market1, level0, 0).
ready_to_load(goods10, market2, level0, 0).
ready_to_load(goods10, market3, level0, 0).
stored(goods1, level0, 0).
stored(goods2, level0, 0).
stored(goods3, level0, 0).
stored(goods4, level0, 0).
stored(goods5, level0, 0).
stored(goods6, level0, 0).
stored(goods7, level0, 0).
stored(goods8, level0, 0).
stored(goods9, level0, 0).
stored(goods10, level0, 0).
loaded(goods1, truck1, level0, 0).
loaded(goods1, truck2, level0, 0).
loaded(goods1, truck3, level0, 0).
loaded(goods2, truck1, level0, 0).
loaded(goods2, truck2, level0, 0).
loaded(goods2, truck3, level0, 0).
loaded(goods3, truck1, level0, 0).
loaded(goods3, truck2, level0, 0).
loaded(goods3, truck3, level0, 0).
loaded(goods4, truck1, level0, 0).
loaded(goods4, truck2, level0, 0).
loaded(goods4, truck3, level0, 0).
loaded(goods5, truck1, level0, 0).
loaded(goods5, truck2, level0, 0).
loaded(goods5, truck3, level0, 0).
loaded(goods6, truck1, level0, 0).
loaded(goods6, truck2, level0, 0).
loaded(goods6, truck3, level0, 0).
loaded(goods7, truck1, level0, 0).
loaded(goods7, truck2, level0, 0).
loaded(goods7, truck3, level0, 0).
loaded(goods8, truck1, level0, 0).
loaded(goods8, truck2, level0, 0).
loaded(goods8, truck3, level0, 0).
loaded(goods9, truck1, level0, 0).
loaded(goods9, truck2, level0, 0).
loaded(goods10, truck3, level0, 0).
loaded(goods10, truck1, level0, 0).
loaded(goods10, truck2, level0, 0).
loaded(goods10, truck3, level0, 0).
on_sale(goods1, market1, level1, 0).
on_sale(goods2, market1, level0, 0).
on_sale(goods3, market1, level1, 0).
on_sale(goods4, market1, level1, 0).
on_sale(goods5, market1, level2, 0).
on_sale(goods6, market1, level0, 0).
on_sale(goods7, market1, level2, 0).
on_sale(goods8, market1, level0, 0).
on_sale(goods9, market1, level0, 0).
on_sale(goods10, market1, level0, 0).
on_sale(goods1, market2, level1, 0).
on_sale(goods2, market2, level2, 0).
on_sale(goods3, market2, level1, 0).
on_sale(goods4, market2, level1, 0).
on_sale(goods5, market2, level0, 0).
on_sale(goods6, market2, level1, 0).
on_sale(goods7, market2, level0, 0).
on_sale(goods8, market2, level2, 0).
on_sale(goods9, market2, level1, 0).
on_sale(goods10, market2, level1, 0).
on_sale(goods1, market3, level0, 0).
on_sale(goods2, market3, level0, 0).
on_sale(goods3, market3, level0, 0).
on_sale(goods4, market3, level0, 0).
on_sale(goods5, market3, level0, 0).
on_sale(goods6, market3, level0, 0).
on_sale(goods7, market3, level0, 0).
on_sale(goods8, market3, level0, 0).
on_sale(goods9, market3, level0, 0).
on_sale(goods10, market3, level0, 0).
at(truck1, depot1, 0).
at(truck2, depot1, 0).
at(truck3, depot1, 0).



%goal
goal(T):- time(T),
	stored(goods1, level2, T),
	stored(goods2, level1, T),
	stored(goods3, level2, T),
	stored(goods4, level2, T),
	stored(goods5, level2, T),
	stored(goods6, level1, T),
	stored(goods7, level2, T),
	stored(goods8, level2, T),
	stored(goods9, level1, T),
	stored(goods10, level1, T).


