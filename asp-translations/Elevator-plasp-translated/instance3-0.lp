%---------------------------------------
% domain
%---------------------------------------

% utils
boolean(true).
boolean(false).

% types
type(type("passenger")).
inherits(type("passenger"), type("object")).
type(type("object")).
type(type("floor")).
inherits(type("floor"), type("object")).

has(X, type(T2)) :- has(X, type(T1)), inherits(type(T1), type(T2)).

% variables
variable(variable(("origin", X1, X2))) :- has(X1, type("passenger")), has(X2, type("floor")).
variable(variable(("destin", X1, X2))) :- has(X1, type("passenger")), has(X2, type("floor")).
variable(variable(("above", X1, X2))) :- has(X1, type("floor")), has(X2, type("floor")).
variable(variable(("boarded", X1))) :- has(X1, type("passenger")).
variable(variable(("not-boarded", X1))) :- has(X1, type("passenger")).
variable(variable(("served", X1))) :- has(X1, type("passenger")).
variable(variable(("not-served", X1))) :- has(X1, type("passenger")).
variable(variable(("lift-at", X1))) :- has(X1, type("floor")).

contains(X, value(X, B)) :- variable(X), boolean(B).

% actions
action(action(("board", X1, X2))) :- has(X1, type("floor")), has(X2, type("passenger")).
precondition(action(("board", X1, X2)), variable(("lift-at", X1)), value(variable(("lift-at", X1)), true)) :- action(action(("board", X1, X2))).
precondition(action(("board", X1, X2)), variable(("origin", X2, X1)), value(variable(("origin", X2, X1)), true)) :- action(action(("board", X1, X2))).
postcondition(action(("board", X1, X2)), effect(unconditional), variable(("boarded", X2)), value(variable(("boarded", X2)), true)) :- action(action(("board", X1, X2))).

action(action(("depart", X1, X2))) :- has(X1, type("floor")), has(X2, type("passenger")).
precondition(action(("depart", X1, X2)), variable(("lift-at", X1)), value(variable(("lift-at", X1)), true)) :- action(action(("depart", X1, X2))).
precondition(action(("depart", X1, X2)), variable(("destin", X2, X1)), value(variable(("destin", X2, X1)), true)) :- action(action(("depart", X1, X2))).
precondition(action(("depart", X1, X2)), variable(("boarded", X2)), value(variable(("boarded", X2)), true)) :- action(action(("depart", X1, X2))).
postcondition(action(("depart", X1, X2)), effect(unconditional), variable(("boarded", X2)), value(variable(("boarded", X2)), false)) :- action(action(("depart", X1, X2))).
postcondition(action(("depart", X1, X2)), effect(unconditional), variable(("served", X2)), value(variable(("served", X2)), true)) :- action(action(("depart", X1, X2))).

action(action(("up", X1, X2))) :- has(X1, type("floor")), has(X2, type("floor")).
precondition(action(("up", X1, X2)), variable(("lift-at", X1)), value(variable(("lift-at", X1)), true)) :- action(action(("up", X1, X2))).
precondition(action(("up", X1, X2)), variable(("above", X1, X2)), value(variable(("above", X1, X2)), true)) :- action(action(("up", X1, X2))).
postcondition(action(("up", X1, X2)), effect(unconditional), variable(("lift-at", X2)), value(variable(("lift-at", X2)), true)) :- action(action(("up", X1, X2))).
postcondition(action(("up", X1, X2)), effect(unconditional), variable(("lift-at", X1)), value(variable(("lift-at", X1)), false)) :- action(action(("up", X1, X2))).

action(action(("down", X1, X2))) :- has(X1, type("floor")), has(X2, type("floor")).
precondition(action(("down", X1, X2)), variable(("lift-at", X1)), value(variable(("lift-at", X1)), true)) :- action(action(("down", X1, X2))).
precondition(action(("down", X1, X2)), variable(("above", X2, X1)), value(variable(("above", X2, X1)), true)) :- action(action(("down", X1, X2))).
postcondition(action(("down", X1, X2)), effect(unconditional), variable(("lift-at", X2)), value(variable(("lift-at", X2)), true)) :- action(action(("down", X1, X2))).
postcondition(action(("down", X1, X2)), effect(unconditional), variable(("lift-at", X1)), value(variable(("lift-at", X1)), false)) :- action(action(("down", X1, X2))).

%---------------------------------------
% problem
%---------------------------------------

% objects
constant(constant("p0")).
has(constant("p0"), type("passenger")).

constant(constant("p1")).
has(constant("p1"), type("passenger")).

constant(constant("p2")).
has(constant("p2"), type("passenger")).

constant(constant("f0")).
has(constant("f0"), type("floor")).

constant(constant("f1")).
has(constant("f1"), type("floor")).

constant(constant("f2")).
has(constant("f2"), type("floor")).

constant(constant("f3")).
has(constant("f3"), type("floor")).

constant(constant("f4")).
has(constant("f4"), type("floor")).

constant(constant("f5")).
has(constant("f5"), type("floor")).

% initial state
initialState(variable(("above", constant("f0"), constant("f1"))), value(variable(("above", constant("f0"), constant("f1"))), true)).
initialState(variable(("above", constant("f0"), constant("f2"))), value(variable(("above", constant("f0"), constant("f2"))), true)).
initialState(variable(("above", constant("f0"), constant("f3"))), value(variable(("above", constant("f0"), constant("f3"))), true)).
initialState(variable(("above", constant("f0"), constant("f4"))), value(variable(("above", constant("f0"), constant("f4"))), true)).
initialState(variable(("above", constant("f0"), constant("f5"))), value(variable(("above", constant("f0"), constant("f5"))), true)).
initialState(variable(("above", constant("f1"), constant("f2"))), value(variable(("above", constant("f1"), constant("f2"))), true)).
initialState(variable(("above", constant("f1"), constant("f3"))), value(variable(("above", constant("f1"), constant("f3"))), true)).
initialState(variable(("above", constant("f1"), constant("f4"))), value(variable(("above", constant("f1"), constant("f4"))), true)).
initialState(variable(("above", constant("f1"), constant("f5"))), value(variable(("above", constant("f1"), constant("f5"))), true)).
initialState(variable(("above", constant("f2"), constant("f3"))), value(variable(("above", constant("f2"), constant("f3"))), true)).
initialState(variable(("above", constant("f2"), constant("f4"))), value(variable(("above", constant("f2"), constant("f4"))), true)).
initialState(variable(("above", constant("f2"), constant("f5"))), value(variable(("above", constant("f2"), constant("f5"))), true)).
initialState(variable(("above", constant("f3"), constant("f4"))), value(variable(("above", constant("f3"), constant("f4"))), true)).
initialState(variable(("above", constant("f3"), constant("f5"))), value(variable(("above", constant("f3"), constant("f5"))), true)).
initialState(variable(("above", constant("f4"), constant("f5"))), value(variable(("above", constant("f4"), constant("f5"))), true)).
initialState(variable(("origin", constant("p0"), constant("f1"))), value(variable(("origin", constant("p0"), constant("f1"))), true)).
initialState(variable(("destin", constant("p0"), constant("f4"))), value(variable(("destin", constant("p0"), constant("f4"))), true)).
initialState(variable(("origin", constant("p1"), constant("f3"))), value(variable(("origin", constant("p1"), constant("f3"))), true)).
initialState(variable(("destin", constant("p1"), constant("f1"))), value(variable(("destin", constant("p1"), constant("f1"))), true)).
initialState(variable(("origin", constant("p2"), constant("f5"))), value(variable(("origin", constant("p2"), constant("f5"))), true)).
initialState(variable(("destin", constant("p2"), constant("f1"))), value(variable(("destin", constant("p2"), constant("f1"))), true)).
initialState(variable(("lift-at", constant("f0"))), value(variable(("lift-at", constant("f0"))), true)).

initialState(X, value(X, false)) :- variable(X), not initialState(X, value(X, true)).

% goal
goal(variable(("served", constant("p0"))), value(variable(("served", constant("p0"))), true)).
goal(variable(("served", constant("p1"))), value(variable(("served", constant("p1"))), true)).
goal(variable(("served", constant("p2"))), value(variable(("served", constant("p2"))), true)).
