%---------------------------------------
% domain
%---------------------------------------

% utils
boolean(true).
boolean(false).

% types
type(type("place")).
inherits(type("place"), type("object")).
type(type("locatable")).
inherits(type("locatable"), type("object")).
type(type("level")).
inherits(type("level"), type("object")).
type(type("object")).
type(type("depot")).
inherits(type("depot"), type("place")).
type(type("market")).
inherits(type("market"), type("place")).
type(type("truck")).
inherits(type("truck"), type("locatable")).
type(type("goods")).
inherits(type("goods"), type("locatable")).

has(X, type(T2)) :- has(X, type(T1)), inherits(type(T1), type(T2)).

% variables
variable(variable(("loaded", X1, X2, X3))) :- has(X1, type("goods")), has(X2, type("truck")), has(X3, type("level")).
variable(variable(("ready-to-load", X1, X2, X3))) :- has(X1, type("goods")), has(X2, type("market")), has(X3, type("level")).
variable(variable(("stored", X1, X2))) :- has(X1, type("goods")), has(X2, type("level")).
variable(variable(("on-sale", X1, X2, X3))) :- has(X1, type("goods")), has(X2, type("market")), has(X3, type("level")).
variable(variable(("next", X1, X2))) :- has(X1, type("level")), has(X2, type("level")).
variable(variable(("at", X1, X2))) :- has(X1, type("truck")), has(X2, type("place")).
variable(variable(("connected", X1, X2))) :- has(X1, type("place")), has(X2, type("place")).

contains(X, value(X, B)) :- variable(X), boolean(B).

% actions
action(action(("drive", X1, X2, X3))) :- has(X1, type("truck")), has(X2, type("place")), has(X3, type("place")).
precondition(action(("drive", X1, X2, X3)), variable(("at", X1, X2)), value(variable(("at", X1, X2)), true)) :- action(action(("drive", X1, X2, X3))).
precondition(action(("drive", X1, X2, X3)), variable(("connected", X2, X3)), value(variable(("connected", X2, X3)), true)) :- action(action(("drive", X1, X2, X3))).
postcondition(action(("drive", X1, X2, X3)), effect(unconditional), variable(("at", X1, X2)), value(variable(("at", X1, X2)), false)) :- action(action(("drive", X1, X2, X3))).
postcondition(action(("drive", X1, X2, X3)), effect(unconditional), variable(("at", X1, X3)), value(variable(("at", X1, X3)), true)) :- action(action(("drive", X1, X2, X3))).

action(action(("load", X1, X2, X3, X4, X5, X6, X7))) :- has(X1, type("goods")), has(X2, type("truck")), has(X3, type("market")), has(X4, type("level")), has(X5, type("level")), has(X6, type("level")), has(X7, type("level")).
precondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), variable(("at", X2, X3)), value(variable(("at", X2, X3)), true)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), variable(("loaded", X1, X2, X6)), value(variable(("loaded", X1, X2, X6)), true)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), variable(("ready-to-load", X1, X3, X5)), value(variable(("ready-to-load", X1, X3, X5)), true)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), variable(("next", X5, X4)), value(variable(("next", X5, X4)), true)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), variable(("next", X7, X6)), value(variable(("next", X7, X6)), true)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("loaded", X1, X2, X7)), value(variable(("loaded", X1, X2, X7)), true)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("loaded", X1, X2, X6)), value(variable(("loaded", X1, X2, X6)), false)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("ready-to-load", X1, X3, X4)), value(variable(("ready-to-load", X1, X3, X4)), true)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("load", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("ready-to-load", X1, X3, X5)), value(variable(("ready-to-load", X1, X3, X5)), false)) :- action(action(("load", X1, X2, X3, X4, X5, X6, X7))).

action(action(("unload", X1, X2, X3, X4, X5, X6, X7))) :- has(X1, type("goods")), has(X2, type("truck")), has(X3, type("depot")), has(X4, type("level")), has(X5, type("level")), has(X6, type("level")), has(X7, type("level")).
precondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), variable(("at", X2, X3)), value(variable(("at", X2, X3)), true)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), variable(("loaded", X1, X2, X5)), value(variable(("loaded", X1, X2, X5)), true)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), variable(("stored", X1, X6)), value(variable(("stored", X1, X6)), true)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), variable(("next", X5, X4)), value(variable(("next", X5, X4)), true)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), variable(("next", X7, X6)), value(variable(("next", X7, X6)), true)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("loaded", X1, X2, X4)), value(variable(("loaded", X1, X2, X4)), true)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("loaded", X1, X2, X5)), value(variable(("loaded", X1, X2, X5)), false)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("stored", X1, X7)), value(variable(("stored", X1, X7)), true)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("unload", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("stored", X1, X6)), value(variable(("stored", X1, X6)), false)) :- action(action(("unload", X1, X2, X3, X4, X5, X6, X7))).

action(action(("buy", X1, X2, X3, X4, X5, X6, X7))) :- has(X1, type("truck")), has(X2, type("goods")), has(X3, type("market")), has(X4, type("level")), has(X5, type("level")), has(X6, type("level")), has(X7, type("level")).
precondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), variable(("at", X1, X3)), value(variable(("at", X1, X3)), true)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), variable(("on-sale", X2, X3, X5)), value(variable(("on-sale", X2, X3, X5)), true)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), variable(("ready-to-load", X2, X3, X6)), value(variable(("ready-to-load", X2, X3, X6)), true)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), variable(("next", X5, X4)), value(variable(("next", X5, X4)), true)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).
precondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), variable(("next", X7, X6)), value(variable(("next", X7, X6)), true)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("on-sale", X2, X3, X4)), value(variable(("on-sale", X2, X3, X4)), true)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("on-sale", X2, X3, X5)), value(variable(("on-sale", X2, X3, X5)), false)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("ready-to-load", X2, X3, X7)), value(variable(("ready-to-load", X2, X3, X7)), true)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).
postcondition(action(("buy", X1, X2, X3, X4, X5, X6, X7)), effect(unconditional), variable(("ready-to-load", X2, X3, X6)), value(variable(("ready-to-load", X2, X3, X6)), false)) :- action(action(("buy", X1, X2, X3, X4, X5, X6, X7))).

%---------------------------------------
% problem
%---------------------------------------

% objects
constant(constant("goods1")).
has(constant("goods1"), type("goods")).

constant(constant("goods2")).
has(constant("goods2"), type("goods")).

constant(constant("goods3")).
has(constant("goods3"), type("goods")).

constant(constant("goods4")).
has(constant("goods4"), type("goods")).

constant(constant("goods5")).
has(constant("goods5"), type("goods")).

constant(constant("goods6")).
has(constant("goods6"), type("goods")).

constant(constant("goods7")).
has(constant("goods7"), type("goods")).

constant(constant("truck1")).
has(constant("truck1"), type("truck")).

constant(constant("truck2")).
has(constant("truck2"), type("truck")).

constant(constant("market1")).
has(constant("market1"), type("market")).

constant(constant("market2")).
has(constant("market2"), type("market")).

constant(constant("depot1")).
has(constant("depot1"), type("depot")).

constant(constant("level0")).
has(constant("level0"), type("level")).

constant(constant("level1")).
has(constant("level1"), type("level")).

constant(constant("level2")).
has(constant("level2"), type("level")).

% initial state
initialState(variable(("next", constant("level1"), constant("level0"))), value(variable(("next", constant("level1"), constant("level0"))), true)).
initialState(variable(("next", constant("level2"), constant("level1"))), value(variable(("next", constant("level2"), constant("level1"))), true)).
initialState(variable(("ready-to-load", constant("goods1"), constant("market1"), constant("level0"))), value(variable(("ready-to-load", constant("goods1"), constant("market1"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods1"), constant("market2"), constant("level0"))), value(variable(("ready-to-load", constant("goods1"), constant("market2"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods2"), constant("market1"), constant("level0"))), value(variable(("ready-to-load", constant("goods2"), constant("market1"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods2"), constant("market2"), constant("level0"))), value(variable(("ready-to-load", constant("goods2"), constant("market2"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods3"), constant("market1"), constant("level0"))), value(variable(("ready-to-load", constant("goods3"), constant("market1"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods3"), constant("market2"), constant("level0"))), value(variable(("ready-to-load", constant("goods3"), constant("market2"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods4"), constant("market1"), constant("level0"))), value(variable(("ready-to-load", constant("goods4"), constant("market1"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods4"), constant("market2"), constant("level0"))), value(variable(("ready-to-load", constant("goods4"), constant("market2"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods5"), constant("market1"), constant("level0"))), value(variable(("ready-to-load", constant("goods5"), constant("market1"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods5"), constant("market2"), constant("level0"))), value(variable(("ready-to-load", constant("goods5"), constant("market2"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods6"), constant("market1"), constant("level0"))), value(variable(("ready-to-load", constant("goods6"), constant("market1"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods6"), constant("market2"), constant("level0"))), value(variable(("ready-to-load", constant("goods6"), constant("market2"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods7"), constant("market1"), constant("level0"))), value(variable(("ready-to-load", constant("goods7"), constant("market1"), constant("level0"))), true)).
initialState(variable(("ready-to-load", constant("goods7"), constant("market2"), constant("level0"))), value(variable(("ready-to-load", constant("goods7"), constant("market2"), constant("level0"))), true)).
initialState(variable(("stored", constant("goods1"), constant("level0"))), value(variable(("stored", constant("goods1"), constant("level0"))), true)).
initialState(variable(("stored", constant("goods2"), constant("level0"))), value(variable(("stored", constant("goods2"), constant("level0"))), true)).
initialState(variable(("stored", constant("goods3"), constant("level0"))), value(variable(("stored", constant("goods3"), constant("level0"))), true)).
initialState(variable(("stored", constant("goods4"), constant("level0"))), value(variable(("stored", constant("goods4"), constant("level0"))), true)).
initialState(variable(("stored", constant("goods5"), constant("level0"))), value(variable(("stored", constant("goods5"), constant("level0"))), true)).
initialState(variable(("stored", constant("goods6"), constant("level0"))), value(variable(("stored", constant("goods6"), constant("level0"))), true)).
initialState(variable(("stored", constant("goods7"), constant("level0"))), value(variable(("stored", constant("goods7"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods1"), constant("truck1"), constant("level0"))), value(variable(("loaded", constant("goods1"), constant("truck1"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods1"), constant("truck2"), constant("level0"))), value(variable(("loaded", constant("goods1"), constant("truck2"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods2"), constant("truck1"), constant("level0"))), value(variable(("loaded", constant("goods2"), constant("truck1"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods2"), constant("truck2"), constant("level0"))), value(variable(("loaded", constant("goods2"), constant("truck2"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods3"), constant("truck1"), constant("level0"))), value(variable(("loaded", constant("goods3"), constant("truck1"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods3"), constant("truck2"), constant("level0"))), value(variable(("loaded", constant("goods3"), constant("truck2"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods4"), constant("truck1"), constant("level0"))), value(variable(("loaded", constant("goods4"), constant("truck1"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods4"), constant("truck2"), constant("level0"))), value(variable(("loaded", constant("goods4"), constant("truck2"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods5"), constant("truck1"), constant("level0"))), value(variable(("loaded", constant("goods5"), constant("truck1"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods5"), constant("truck2"), constant("level0"))), value(variable(("loaded", constant("goods5"), constant("truck2"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods6"), constant("truck1"), constant("level0"))), value(variable(("loaded", constant("goods6"), constant("truck1"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods6"), constant("truck2"), constant("level0"))), value(variable(("loaded", constant("goods6"), constant("truck2"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods7"), constant("truck1"), constant("level0"))), value(variable(("loaded", constant("goods7"), constant("truck1"), constant("level0"))), true)).
initialState(variable(("loaded", constant("goods7"), constant("truck2"), constant("level0"))), value(variable(("loaded", constant("goods7"), constant("truck2"), constant("level0"))), true)).
initialState(variable(("connected", constant("market1"), constant("market2"))), value(variable(("connected", constant("market1"), constant("market2"))), true)).
initialState(variable(("connected", constant("market2"), constant("market1"))), value(variable(("connected", constant("market2"), constant("market1"))), true)).
initialState(variable(("connected", constant("depot1"), constant("market2"))), value(variable(("connected", constant("depot1"), constant("market2"))), true)).
initialState(variable(("connected", constant("market2"), constant("depot1"))), value(variable(("connected", constant("market2"), constant("depot1"))), true)).
initialState(variable(("on-sale", constant("goods1"), constant("market1"), constant("level1"))), value(variable(("on-sale", constant("goods1"), constant("market1"), constant("level1"))), true)).
initialState(variable(("on-sale", constant("goods2"), constant("market1"), constant("level2"))), value(variable(("on-sale", constant("goods2"), constant("market1"), constant("level2"))), true)).
initialState(variable(("on-sale", constant("goods3"), constant("market1"), constant("level1"))), value(variable(("on-sale", constant("goods3"), constant("market1"), constant("level1"))), true)).
initialState(variable(("on-sale", constant("goods4"), constant("market1"), constant("level2"))), value(variable(("on-sale", constant("goods4"), constant("market1"), constant("level2"))), true)).
initialState(variable(("on-sale", constant("goods5"), constant("market1"), constant("level2"))), value(variable(("on-sale", constant("goods5"), constant("market1"), constant("level2"))), true)).
initialState(variable(("on-sale", constant("goods6"), constant("market1"), constant("level2"))), value(variable(("on-sale", constant("goods6"), constant("market1"), constant("level2"))), true)).
initialState(variable(("on-sale", constant("goods7"), constant("market1"), constant("level2"))), value(variable(("on-sale", constant("goods7"), constant("market1"), constant("level2"))), true)).
initialState(variable(("on-sale", constant("goods1"), constant("market2"), constant("level0"))), value(variable(("on-sale", constant("goods1"), constant("market2"), constant("level0"))), true)).
initialState(variable(("on-sale", constant("goods2"), constant("market2"), constant("level0"))), value(variable(("on-sale", constant("goods2"), constant("market2"), constant("level0"))), true)).
initialState(variable(("on-sale", constant("goods3"), constant("market2"), constant("level1"))), value(variable(("on-sale", constant("goods3"), constant("market2"), constant("level1"))), true)).
initialState(variable(("on-sale", constant("goods4"), constant("market2"), constant("level0"))), value(variable(("on-sale", constant("goods4"), constant("market2"), constant("level0"))), true)).
initialState(variable(("on-sale", constant("goods5"), constant("market2"), constant("level0"))), value(variable(("on-sale", constant("goods5"), constant("market2"), constant("level0"))), true)).
initialState(variable(("on-sale", constant("goods6"), constant("market2"), constant("level0"))), value(variable(("on-sale", constant("goods6"), constant("market2"), constant("level0"))), true)).
initialState(variable(("on-sale", constant("goods7"), constant("market2"), constant("level0"))), value(variable(("on-sale", constant("goods7"), constant("market2"), constant("level0"))), true)).
initialState(variable(("at", constant("truck1"), constant("depot1"))), value(variable(("at", constant("truck1"), constant("depot1"))), true)).
initialState(variable(("at", constant("truck2"), constant("depot1"))), value(variable(("at", constant("truck2"), constant("depot1"))), true)).

initialState(X, value(X, false)) :- variable(X), not initialState(X, value(X, true)).

% goal
goal(variable(("stored", constant("goods1"), constant("level1"))), value(variable(("stored", constant("goods1"), constant("level1"))), true)).
goal(variable(("stored", constant("goods2"), constant("level1"))), value(variable(("stored", constant("goods2"), constant("level1"))), true)).
goal(variable(("stored", constant("goods3"), constant("level1"))), value(variable(("stored", constant("goods3"), constant("level1"))), true)).
goal(variable(("stored", constant("goods4"), constant("level2"))), value(variable(("stored", constant("goods4"), constant("level2"))), true)).
goal(variable(("stored", constant("goods5"), constant("level2"))), value(variable(("stored", constant("goods5"), constant("level2"))), true)).
goal(variable(("stored", constant("goods6"), constant("level1"))), value(variable(("stored", constant("goods6"), constant("level1"))), true)).
goal(variable(("stored", constant("goods7"), constant("level2"))), value(variable(("stored", constant("goods7"), constant("level2"))), true)).
