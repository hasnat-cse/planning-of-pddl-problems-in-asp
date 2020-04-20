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

constant(constant("p3")).
has(constant("p3"), type("passenger")).

constant(constant("p4")).
has(constant("p4"), type("passenger")).

constant(constant("p5")).
has(constant("p5"), type("passenger")).

constant(constant("p6")).
has(constant("p6"), type("passenger")).

constant(constant("p7")).
has(constant("p7"), type("passenger")).

constant(constant("p8")).
has(constant("p8"), type("passenger")).

constant(constant("p9")).
has(constant("p9"), type("passenger")).

constant(constant("p10")).
has(constant("p10"), type("passenger")).

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

constant(constant("f6")).
has(constant("f6"), type("floor")).

constant(constant("f7")).
has(constant("f7"), type("floor")).

constant(constant("f8")).
has(constant("f8"), type("floor")).

constant(constant("f9")).
has(constant("f9"), type("floor")).

constant(constant("f10")).
has(constant("f10"), type("floor")).

constant(constant("f11")).
has(constant("f11"), type("floor")).

constant(constant("f12")).
has(constant("f12"), type("floor")).

constant(constant("f13")).
has(constant("f13"), type("floor")).

constant(constant("f14")).
has(constant("f14"), type("floor")).

constant(constant("f15")).
has(constant("f15"), type("floor")).

constant(constant("f16")).
has(constant("f16"), type("floor")).

constant(constant("f17")).
has(constant("f17"), type("floor")).

constant(constant("f18")).
has(constant("f18"), type("floor")).

constant(constant("f19")).
has(constant("f19"), type("floor")).

constant(constant("f20")).
has(constant("f20"), type("floor")).

constant(constant("f21")).
has(constant("f21"), type("floor")).

% initial state
initialState(variable(("above", constant("f0"), constant("f1"))), value(variable(("above", constant("f0"), constant("f1"))), true)).
initialState(variable(("above", constant("f0"), constant("f2"))), value(variable(("above", constant("f0"), constant("f2"))), true)).
initialState(variable(("above", constant("f0"), constant("f3"))), value(variable(("above", constant("f0"), constant("f3"))), true)).
initialState(variable(("above", constant("f0"), constant("f4"))), value(variable(("above", constant("f0"), constant("f4"))), true)).
initialState(variable(("above", constant("f0"), constant("f5"))), value(variable(("above", constant("f0"), constant("f5"))), true)).
initialState(variable(("above", constant("f0"), constant("f6"))), value(variable(("above", constant("f0"), constant("f6"))), true)).
initialState(variable(("above", constant("f0"), constant("f7"))), value(variable(("above", constant("f0"), constant("f7"))), true)).
initialState(variable(("above", constant("f0"), constant("f8"))), value(variable(("above", constant("f0"), constant("f8"))), true)).
initialState(variable(("above", constant("f0"), constant("f9"))), value(variable(("above", constant("f0"), constant("f9"))), true)).
initialState(variable(("above", constant("f0"), constant("f10"))), value(variable(("above", constant("f0"), constant("f10"))), true)).
initialState(variable(("above", constant("f0"), constant("f11"))), value(variable(("above", constant("f0"), constant("f11"))), true)).
initialState(variable(("above", constant("f0"), constant("f12"))), value(variable(("above", constant("f0"), constant("f12"))), true)).
initialState(variable(("above", constant("f0"), constant("f13"))), value(variable(("above", constant("f0"), constant("f13"))), true)).
initialState(variable(("above", constant("f0"), constant("f14"))), value(variable(("above", constant("f0"), constant("f14"))), true)).
initialState(variable(("above", constant("f0"), constant("f15"))), value(variable(("above", constant("f0"), constant("f15"))), true)).
initialState(variable(("above", constant("f0"), constant("f16"))), value(variable(("above", constant("f0"), constant("f16"))), true)).
initialState(variable(("above", constant("f0"), constant("f17"))), value(variable(("above", constant("f0"), constant("f17"))), true)).
initialState(variable(("above", constant("f0"), constant("f18"))), value(variable(("above", constant("f0"), constant("f18"))), true)).
initialState(variable(("above", constant("f0"), constant("f19"))), value(variable(("above", constant("f0"), constant("f19"))), true)).
initialState(variable(("above", constant("f0"), constant("f20"))), value(variable(("above", constant("f0"), constant("f20"))), true)).
initialState(variable(("above", constant("f0"), constant("f21"))), value(variable(("above", constant("f0"), constant("f21"))), true)).
initialState(variable(("above", constant("f1"), constant("f2"))), value(variable(("above", constant("f1"), constant("f2"))), true)).
initialState(variable(("above", constant("f1"), constant("f3"))), value(variable(("above", constant("f1"), constant("f3"))), true)).
initialState(variable(("above", constant("f1"), constant("f4"))), value(variable(("above", constant("f1"), constant("f4"))), true)).
initialState(variable(("above", constant("f1"), constant("f5"))), value(variable(("above", constant("f1"), constant("f5"))), true)).
initialState(variable(("above", constant("f1"), constant("f6"))), value(variable(("above", constant("f1"), constant("f6"))), true)).
initialState(variable(("above", constant("f1"), constant("f7"))), value(variable(("above", constant("f1"), constant("f7"))), true)).
initialState(variable(("above", constant("f1"), constant("f8"))), value(variable(("above", constant("f1"), constant("f8"))), true)).
initialState(variable(("above", constant("f1"), constant("f9"))), value(variable(("above", constant("f1"), constant("f9"))), true)).
initialState(variable(("above", constant("f1"), constant("f10"))), value(variable(("above", constant("f1"), constant("f10"))), true)).
initialState(variable(("above", constant("f1"), constant("f11"))), value(variable(("above", constant("f1"), constant("f11"))), true)).
initialState(variable(("above", constant("f1"), constant("f12"))), value(variable(("above", constant("f1"), constant("f12"))), true)).
initialState(variable(("above", constant("f1"), constant("f13"))), value(variable(("above", constant("f1"), constant("f13"))), true)).
initialState(variable(("above", constant("f1"), constant("f14"))), value(variable(("above", constant("f1"), constant("f14"))), true)).
initialState(variable(("above", constant("f1"), constant("f15"))), value(variable(("above", constant("f1"), constant("f15"))), true)).
initialState(variable(("above", constant("f1"), constant("f16"))), value(variable(("above", constant("f1"), constant("f16"))), true)).
initialState(variable(("above", constant("f1"), constant("f17"))), value(variable(("above", constant("f1"), constant("f17"))), true)).
initialState(variable(("above", constant("f1"), constant("f18"))), value(variable(("above", constant("f1"), constant("f18"))), true)).
initialState(variable(("above", constant("f1"), constant("f19"))), value(variable(("above", constant("f1"), constant("f19"))), true)).
initialState(variable(("above", constant("f1"), constant("f20"))), value(variable(("above", constant("f1"), constant("f20"))), true)).
initialState(variable(("above", constant("f1"), constant("f21"))), value(variable(("above", constant("f1"), constant("f21"))), true)).
initialState(variable(("above", constant("f2"), constant("f3"))), value(variable(("above", constant("f2"), constant("f3"))), true)).
initialState(variable(("above", constant("f2"), constant("f4"))), value(variable(("above", constant("f2"), constant("f4"))), true)).
initialState(variable(("above", constant("f2"), constant("f5"))), value(variable(("above", constant("f2"), constant("f5"))), true)).
initialState(variable(("above", constant("f2"), constant("f6"))), value(variable(("above", constant("f2"), constant("f6"))), true)).
initialState(variable(("above", constant("f2"), constant("f7"))), value(variable(("above", constant("f2"), constant("f7"))), true)).
initialState(variable(("above", constant("f2"), constant("f8"))), value(variable(("above", constant("f2"), constant("f8"))), true)).
initialState(variable(("above", constant("f2"), constant("f9"))), value(variable(("above", constant("f2"), constant("f9"))), true)).
initialState(variable(("above", constant("f2"), constant("f10"))), value(variable(("above", constant("f2"), constant("f10"))), true)).
initialState(variable(("above", constant("f2"), constant("f11"))), value(variable(("above", constant("f2"), constant("f11"))), true)).
initialState(variable(("above", constant("f2"), constant("f12"))), value(variable(("above", constant("f2"), constant("f12"))), true)).
initialState(variable(("above", constant("f2"), constant("f13"))), value(variable(("above", constant("f2"), constant("f13"))), true)).
initialState(variable(("above", constant("f2"), constant("f14"))), value(variable(("above", constant("f2"), constant("f14"))), true)).
initialState(variable(("above", constant("f2"), constant("f15"))), value(variable(("above", constant("f2"), constant("f15"))), true)).
initialState(variable(("above", constant("f2"), constant("f16"))), value(variable(("above", constant("f2"), constant("f16"))), true)).
initialState(variable(("above", constant("f2"), constant("f17"))), value(variable(("above", constant("f2"), constant("f17"))), true)).
initialState(variable(("above", constant("f2"), constant("f18"))), value(variable(("above", constant("f2"), constant("f18"))), true)).
initialState(variable(("above", constant("f2"), constant("f19"))), value(variable(("above", constant("f2"), constant("f19"))), true)).
initialState(variable(("above", constant("f2"), constant("f20"))), value(variable(("above", constant("f2"), constant("f20"))), true)).
initialState(variable(("above", constant("f2"), constant("f21"))), value(variable(("above", constant("f2"), constant("f21"))), true)).
initialState(variable(("above", constant("f3"), constant("f4"))), value(variable(("above", constant("f3"), constant("f4"))), true)).
initialState(variable(("above", constant("f3"), constant("f5"))), value(variable(("above", constant("f3"), constant("f5"))), true)).
initialState(variable(("above", constant("f3"), constant("f6"))), value(variable(("above", constant("f3"), constant("f6"))), true)).
initialState(variable(("above", constant("f3"), constant("f7"))), value(variable(("above", constant("f3"), constant("f7"))), true)).
initialState(variable(("above", constant("f3"), constant("f8"))), value(variable(("above", constant("f3"), constant("f8"))), true)).
initialState(variable(("above", constant("f3"), constant("f9"))), value(variable(("above", constant("f3"), constant("f9"))), true)).
initialState(variable(("above", constant("f3"), constant("f10"))), value(variable(("above", constant("f3"), constant("f10"))), true)).
initialState(variable(("above", constant("f3"), constant("f11"))), value(variable(("above", constant("f3"), constant("f11"))), true)).
initialState(variable(("above", constant("f3"), constant("f12"))), value(variable(("above", constant("f3"), constant("f12"))), true)).
initialState(variable(("above", constant("f3"), constant("f13"))), value(variable(("above", constant("f3"), constant("f13"))), true)).
initialState(variable(("above", constant("f3"), constant("f14"))), value(variable(("above", constant("f3"), constant("f14"))), true)).
initialState(variable(("above", constant("f3"), constant("f15"))), value(variable(("above", constant("f3"), constant("f15"))), true)).
initialState(variable(("above", constant("f3"), constant("f16"))), value(variable(("above", constant("f3"), constant("f16"))), true)).
initialState(variable(("above", constant("f3"), constant("f17"))), value(variable(("above", constant("f3"), constant("f17"))), true)).
initialState(variable(("above", constant("f3"), constant("f18"))), value(variable(("above", constant("f3"), constant("f18"))), true)).
initialState(variable(("above", constant("f3"), constant("f19"))), value(variable(("above", constant("f3"), constant("f19"))), true)).
initialState(variable(("above", constant("f3"), constant("f20"))), value(variable(("above", constant("f3"), constant("f20"))), true)).
initialState(variable(("above", constant("f3"), constant("f21"))), value(variable(("above", constant("f3"), constant("f21"))), true)).
initialState(variable(("above", constant("f4"), constant("f5"))), value(variable(("above", constant("f4"), constant("f5"))), true)).
initialState(variable(("above", constant("f4"), constant("f6"))), value(variable(("above", constant("f4"), constant("f6"))), true)).
initialState(variable(("above", constant("f4"), constant("f7"))), value(variable(("above", constant("f4"), constant("f7"))), true)).
initialState(variable(("above", constant("f4"), constant("f8"))), value(variable(("above", constant("f4"), constant("f8"))), true)).
initialState(variable(("above", constant("f4"), constant("f9"))), value(variable(("above", constant("f4"), constant("f9"))), true)).
initialState(variable(("above", constant("f4"), constant("f10"))), value(variable(("above", constant("f4"), constant("f10"))), true)).
initialState(variable(("above", constant("f4"), constant("f11"))), value(variable(("above", constant("f4"), constant("f11"))), true)).
initialState(variable(("above", constant("f4"), constant("f12"))), value(variable(("above", constant("f4"), constant("f12"))), true)).
initialState(variable(("above", constant("f4"), constant("f13"))), value(variable(("above", constant("f4"), constant("f13"))), true)).
initialState(variable(("above", constant("f4"), constant("f14"))), value(variable(("above", constant("f4"), constant("f14"))), true)).
initialState(variable(("above", constant("f4"), constant("f15"))), value(variable(("above", constant("f4"), constant("f15"))), true)).
initialState(variable(("above", constant("f4"), constant("f16"))), value(variable(("above", constant("f4"), constant("f16"))), true)).
initialState(variable(("above", constant("f4"), constant("f17"))), value(variable(("above", constant("f4"), constant("f17"))), true)).
initialState(variable(("above", constant("f4"), constant("f18"))), value(variable(("above", constant("f4"), constant("f18"))), true)).
initialState(variable(("above", constant("f4"), constant("f19"))), value(variable(("above", constant("f4"), constant("f19"))), true)).
initialState(variable(("above", constant("f4"), constant("f20"))), value(variable(("above", constant("f4"), constant("f20"))), true)).
initialState(variable(("above", constant("f4"), constant("f21"))), value(variable(("above", constant("f4"), constant("f21"))), true)).
initialState(variable(("above", constant("f5"), constant("f6"))), value(variable(("above", constant("f5"), constant("f6"))), true)).
initialState(variable(("above", constant("f5"), constant("f7"))), value(variable(("above", constant("f5"), constant("f7"))), true)).
initialState(variable(("above", constant("f5"), constant("f8"))), value(variable(("above", constant("f5"), constant("f8"))), true)).
initialState(variable(("above", constant("f5"), constant("f9"))), value(variable(("above", constant("f5"), constant("f9"))), true)).
initialState(variable(("above", constant("f5"), constant("f10"))), value(variable(("above", constant("f5"), constant("f10"))), true)).
initialState(variable(("above", constant("f5"), constant("f11"))), value(variable(("above", constant("f5"), constant("f11"))), true)).
initialState(variable(("above", constant("f5"), constant("f12"))), value(variable(("above", constant("f5"), constant("f12"))), true)).
initialState(variable(("above", constant("f5"), constant("f13"))), value(variable(("above", constant("f5"), constant("f13"))), true)).
initialState(variable(("above", constant("f5"), constant("f14"))), value(variable(("above", constant("f5"), constant("f14"))), true)).
initialState(variable(("above", constant("f5"), constant("f15"))), value(variable(("above", constant("f5"), constant("f15"))), true)).
initialState(variable(("above", constant("f5"), constant("f16"))), value(variable(("above", constant("f5"), constant("f16"))), true)).
initialState(variable(("above", constant("f5"), constant("f17"))), value(variable(("above", constant("f5"), constant("f17"))), true)).
initialState(variable(("above", constant("f5"), constant("f18"))), value(variable(("above", constant("f5"), constant("f18"))), true)).
initialState(variable(("above", constant("f5"), constant("f19"))), value(variable(("above", constant("f5"), constant("f19"))), true)).
initialState(variable(("above", constant("f5"), constant("f20"))), value(variable(("above", constant("f5"), constant("f20"))), true)).
initialState(variable(("above", constant("f5"), constant("f21"))), value(variable(("above", constant("f5"), constant("f21"))), true)).
initialState(variable(("above", constant("f6"), constant("f7"))), value(variable(("above", constant("f6"), constant("f7"))), true)).
initialState(variable(("above", constant("f6"), constant("f8"))), value(variable(("above", constant("f6"), constant("f8"))), true)).
initialState(variable(("above", constant("f6"), constant("f9"))), value(variable(("above", constant("f6"), constant("f9"))), true)).
initialState(variable(("above", constant("f6"), constant("f10"))), value(variable(("above", constant("f6"), constant("f10"))), true)).
initialState(variable(("above", constant("f6"), constant("f11"))), value(variable(("above", constant("f6"), constant("f11"))), true)).
initialState(variable(("above", constant("f6"), constant("f12"))), value(variable(("above", constant("f6"), constant("f12"))), true)).
initialState(variable(("above", constant("f6"), constant("f13"))), value(variable(("above", constant("f6"), constant("f13"))), true)).
initialState(variable(("above", constant("f6"), constant("f14"))), value(variable(("above", constant("f6"), constant("f14"))), true)).
initialState(variable(("above", constant("f6"), constant("f15"))), value(variable(("above", constant("f6"), constant("f15"))), true)).
initialState(variable(("above", constant("f6"), constant("f16"))), value(variable(("above", constant("f6"), constant("f16"))), true)).
initialState(variable(("above", constant("f6"), constant("f17"))), value(variable(("above", constant("f6"), constant("f17"))), true)).
initialState(variable(("above", constant("f6"), constant("f18"))), value(variable(("above", constant("f6"), constant("f18"))), true)).
initialState(variable(("above", constant("f6"), constant("f19"))), value(variable(("above", constant("f6"), constant("f19"))), true)).
initialState(variable(("above", constant("f6"), constant("f20"))), value(variable(("above", constant("f6"), constant("f20"))), true)).
initialState(variable(("above", constant("f6"), constant("f21"))), value(variable(("above", constant("f6"), constant("f21"))), true)).
initialState(variable(("above", constant("f7"), constant("f8"))), value(variable(("above", constant("f7"), constant("f8"))), true)).
initialState(variable(("above", constant("f7"), constant("f9"))), value(variable(("above", constant("f7"), constant("f9"))), true)).
initialState(variable(("above", constant("f7"), constant("f10"))), value(variable(("above", constant("f7"), constant("f10"))), true)).
initialState(variable(("above", constant("f7"), constant("f11"))), value(variable(("above", constant("f7"), constant("f11"))), true)).
initialState(variable(("above", constant("f7"), constant("f12"))), value(variable(("above", constant("f7"), constant("f12"))), true)).
initialState(variable(("above", constant("f7"), constant("f13"))), value(variable(("above", constant("f7"), constant("f13"))), true)).
initialState(variable(("above", constant("f7"), constant("f14"))), value(variable(("above", constant("f7"), constant("f14"))), true)).
initialState(variable(("above", constant("f7"), constant("f15"))), value(variable(("above", constant("f7"), constant("f15"))), true)).
initialState(variable(("above", constant("f7"), constant("f16"))), value(variable(("above", constant("f7"), constant("f16"))), true)).
initialState(variable(("above", constant("f7"), constant("f17"))), value(variable(("above", constant("f7"), constant("f17"))), true)).
initialState(variable(("above", constant("f7"), constant("f18"))), value(variable(("above", constant("f7"), constant("f18"))), true)).
initialState(variable(("above", constant("f7"), constant("f19"))), value(variable(("above", constant("f7"), constant("f19"))), true)).
initialState(variable(("above", constant("f7"), constant("f20"))), value(variable(("above", constant("f7"), constant("f20"))), true)).
initialState(variable(("above", constant("f7"), constant("f21"))), value(variable(("above", constant("f7"), constant("f21"))), true)).
initialState(variable(("above", constant("f8"), constant("f9"))), value(variable(("above", constant("f8"), constant("f9"))), true)).
initialState(variable(("above", constant("f8"), constant("f10"))), value(variable(("above", constant("f8"), constant("f10"))), true)).
initialState(variable(("above", constant("f8"), constant("f11"))), value(variable(("above", constant("f8"), constant("f11"))), true)).
initialState(variable(("above", constant("f8"), constant("f12"))), value(variable(("above", constant("f8"), constant("f12"))), true)).
initialState(variable(("above", constant("f8"), constant("f13"))), value(variable(("above", constant("f8"), constant("f13"))), true)).
initialState(variable(("above", constant("f8"), constant("f14"))), value(variable(("above", constant("f8"), constant("f14"))), true)).
initialState(variable(("above", constant("f8"), constant("f15"))), value(variable(("above", constant("f8"), constant("f15"))), true)).
initialState(variable(("above", constant("f8"), constant("f16"))), value(variable(("above", constant("f8"), constant("f16"))), true)).
initialState(variable(("above", constant("f8"), constant("f17"))), value(variable(("above", constant("f8"), constant("f17"))), true)).
initialState(variable(("above", constant("f8"), constant("f18"))), value(variable(("above", constant("f8"), constant("f18"))), true)).
initialState(variable(("above", constant("f8"), constant("f19"))), value(variable(("above", constant("f8"), constant("f19"))), true)).
initialState(variable(("above", constant("f8"), constant("f20"))), value(variable(("above", constant("f8"), constant("f20"))), true)).
initialState(variable(("above", constant("f8"), constant("f21"))), value(variable(("above", constant("f8"), constant("f21"))), true)).
initialState(variable(("above", constant("f9"), constant("f10"))), value(variable(("above", constant("f9"), constant("f10"))), true)).
initialState(variable(("above", constant("f9"), constant("f11"))), value(variable(("above", constant("f9"), constant("f11"))), true)).
initialState(variable(("above", constant("f9"), constant("f12"))), value(variable(("above", constant("f9"), constant("f12"))), true)).
initialState(variable(("above", constant("f9"), constant("f13"))), value(variable(("above", constant("f9"), constant("f13"))), true)).
initialState(variable(("above", constant("f9"), constant("f14"))), value(variable(("above", constant("f9"), constant("f14"))), true)).
initialState(variable(("above", constant("f9"), constant("f15"))), value(variable(("above", constant("f9"), constant("f15"))), true)).
initialState(variable(("above", constant("f9"), constant("f16"))), value(variable(("above", constant("f9"), constant("f16"))), true)).
initialState(variable(("above", constant("f9"), constant("f17"))), value(variable(("above", constant("f9"), constant("f17"))), true)).
initialState(variable(("above", constant("f9"), constant("f18"))), value(variable(("above", constant("f9"), constant("f18"))), true)).
initialState(variable(("above", constant("f9"), constant("f19"))), value(variable(("above", constant("f9"), constant("f19"))), true)).
initialState(variable(("above", constant("f9"), constant("f20"))), value(variable(("above", constant("f9"), constant("f20"))), true)).
initialState(variable(("above", constant("f9"), constant("f21"))), value(variable(("above", constant("f9"), constant("f21"))), true)).
initialState(variable(("above", constant("f10"), constant("f11"))), value(variable(("above", constant("f10"), constant("f11"))), true)).
initialState(variable(("above", constant("f10"), constant("f12"))), value(variable(("above", constant("f10"), constant("f12"))), true)).
initialState(variable(("above", constant("f10"), constant("f13"))), value(variable(("above", constant("f10"), constant("f13"))), true)).
initialState(variable(("above", constant("f10"), constant("f14"))), value(variable(("above", constant("f10"), constant("f14"))), true)).
initialState(variable(("above", constant("f10"), constant("f15"))), value(variable(("above", constant("f10"), constant("f15"))), true)).
initialState(variable(("above", constant("f10"), constant("f16"))), value(variable(("above", constant("f10"), constant("f16"))), true)).
initialState(variable(("above", constant("f10"), constant("f17"))), value(variable(("above", constant("f10"), constant("f17"))), true)).
initialState(variable(("above", constant("f10"), constant("f18"))), value(variable(("above", constant("f10"), constant("f18"))), true)).
initialState(variable(("above", constant("f10"), constant("f19"))), value(variable(("above", constant("f10"), constant("f19"))), true)).
initialState(variable(("above", constant("f10"), constant("f20"))), value(variable(("above", constant("f10"), constant("f20"))), true)).
initialState(variable(("above", constant("f10"), constant("f21"))), value(variable(("above", constant("f10"), constant("f21"))), true)).
initialState(variable(("above", constant("f11"), constant("f12"))), value(variable(("above", constant("f11"), constant("f12"))), true)).
initialState(variable(("above", constant("f11"), constant("f13"))), value(variable(("above", constant("f11"), constant("f13"))), true)).
initialState(variable(("above", constant("f11"), constant("f14"))), value(variable(("above", constant("f11"), constant("f14"))), true)).
initialState(variable(("above", constant("f11"), constant("f15"))), value(variable(("above", constant("f11"), constant("f15"))), true)).
initialState(variable(("above", constant("f11"), constant("f16"))), value(variable(("above", constant("f11"), constant("f16"))), true)).
initialState(variable(("above", constant("f11"), constant("f17"))), value(variable(("above", constant("f11"), constant("f17"))), true)).
initialState(variable(("above", constant("f11"), constant("f18"))), value(variable(("above", constant("f11"), constant("f18"))), true)).
initialState(variable(("above", constant("f11"), constant("f19"))), value(variable(("above", constant("f11"), constant("f19"))), true)).
initialState(variable(("above", constant("f11"), constant("f20"))), value(variable(("above", constant("f11"), constant("f20"))), true)).
initialState(variable(("above", constant("f11"), constant("f21"))), value(variable(("above", constant("f11"), constant("f21"))), true)).
initialState(variable(("above", constant("f12"), constant("f13"))), value(variable(("above", constant("f12"), constant("f13"))), true)).
initialState(variable(("above", constant("f12"), constant("f14"))), value(variable(("above", constant("f12"), constant("f14"))), true)).
initialState(variable(("above", constant("f12"), constant("f15"))), value(variable(("above", constant("f12"), constant("f15"))), true)).
initialState(variable(("above", constant("f12"), constant("f16"))), value(variable(("above", constant("f12"), constant("f16"))), true)).
initialState(variable(("above", constant("f12"), constant("f17"))), value(variable(("above", constant("f12"), constant("f17"))), true)).
initialState(variable(("above", constant("f12"), constant("f18"))), value(variable(("above", constant("f12"), constant("f18"))), true)).
initialState(variable(("above", constant("f12"), constant("f19"))), value(variable(("above", constant("f12"), constant("f19"))), true)).
initialState(variable(("above", constant("f12"), constant("f20"))), value(variable(("above", constant("f12"), constant("f20"))), true)).
initialState(variable(("above", constant("f12"), constant("f21"))), value(variable(("above", constant("f12"), constant("f21"))), true)).
initialState(variable(("above", constant("f13"), constant("f14"))), value(variable(("above", constant("f13"), constant("f14"))), true)).
initialState(variable(("above", constant("f13"), constant("f15"))), value(variable(("above", constant("f13"), constant("f15"))), true)).
initialState(variable(("above", constant("f13"), constant("f16"))), value(variable(("above", constant("f13"), constant("f16"))), true)).
initialState(variable(("above", constant("f13"), constant("f17"))), value(variable(("above", constant("f13"), constant("f17"))), true)).
initialState(variable(("above", constant("f13"), constant("f18"))), value(variable(("above", constant("f13"), constant("f18"))), true)).
initialState(variable(("above", constant("f13"), constant("f19"))), value(variable(("above", constant("f13"), constant("f19"))), true)).
initialState(variable(("above", constant("f13"), constant("f20"))), value(variable(("above", constant("f13"), constant("f20"))), true)).
initialState(variable(("above", constant("f13"), constant("f21"))), value(variable(("above", constant("f13"), constant("f21"))), true)).
initialState(variable(("above", constant("f14"), constant("f15"))), value(variable(("above", constant("f14"), constant("f15"))), true)).
initialState(variable(("above", constant("f14"), constant("f16"))), value(variable(("above", constant("f14"), constant("f16"))), true)).
initialState(variable(("above", constant("f14"), constant("f17"))), value(variable(("above", constant("f14"), constant("f17"))), true)).
initialState(variable(("above", constant("f14"), constant("f18"))), value(variable(("above", constant("f14"), constant("f18"))), true)).
initialState(variable(("above", constant("f14"), constant("f19"))), value(variable(("above", constant("f14"), constant("f19"))), true)).
initialState(variable(("above", constant("f14"), constant("f20"))), value(variable(("above", constant("f14"), constant("f20"))), true)).
initialState(variable(("above", constant("f14"), constant("f21"))), value(variable(("above", constant("f14"), constant("f21"))), true)).
initialState(variable(("above", constant("f15"), constant("f16"))), value(variable(("above", constant("f15"), constant("f16"))), true)).
initialState(variable(("above", constant("f15"), constant("f17"))), value(variable(("above", constant("f15"), constant("f17"))), true)).
initialState(variable(("above", constant("f15"), constant("f18"))), value(variable(("above", constant("f15"), constant("f18"))), true)).
initialState(variable(("above", constant("f15"), constant("f19"))), value(variable(("above", constant("f15"), constant("f19"))), true)).
initialState(variable(("above", constant("f15"), constant("f20"))), value(variable(("above", constant("f15"), constant("f20"))), true)).
initialState(variable(("above", constant("f15"), constant("f21"))), value(variable(("above", constant("f15"), constant("f21"))), true)).
initialState(variable(("above", constant("f16"), constant("f17"))), value(variable(("above", constant("f16"), constant("f17"))), true)).
initialState(variable(("above", constant("f16"), constant("f18"))), value(variable(("above", constant("f16"), constant("f18"))), true)).
initialState(variable(("above", constant("f16"), constant("f19"))), value(variable(("above", constant("f16"), constant("f19"))), true)).
initialState(variable(("above", constant("f16"), constant("f20"))), value(variable(("above", constant("f16"), constant("f20"))), true)).
initialState(variable(("above", constant("f16"), constant("f21"))), value(variable(("above", constant("f16"), constant("f21"))), true)).
initialState(variable(("above", constant("f17"), constant("f18"))), value(variable(("above", constant("f17"), constant("f18"))), true)).
initialState(variable(("above", constant("f17"), constant("f19"))), value(variable(("above", constant("f17"), constant("f19"))), true)).
initialState(variable(("above", constant("f17"), constant("f20"))), value(variable(("above", constant("f17"), constant("f20"))), true)).
initialState(variable(("above", constant("f17"), constant("f21"))), value(variable(("above", constant("f17"), constant("f21"))), true)).
initialState(variable(("above", constant("f18"), constant("f19"))), value(variable(("above", constant("f18"), constant("f19"))), true)).
initialState(variable(("above", constant("f18"), constant("f20"))), value(variable(("above", constant("f18"), constant("f20"))), true)).
initialState(variable(("above", constant("f18"), constant("f21"))), value(variable(("above", constant("f18"), constant("f21"))), true)).
initialState(variable(("above", constant("f19"), constant("f20"))), value(variable(("above", constant("f19"), constant("f20"))), true)).
initialState(variable(("above", constant("f19"), constant("f21"))), value(variable(("above", constant("f19"), constant("f21"))), true)).
initialState(variable(("above", constant("f20"), constant("f21"))), value(variable(("above", constant("f20"), constant("f21"))), true)).
initialState(variable(("origin", constant("p0"), constant("f17"))), value(variable(("origin", constant("p0"), constant("f17"))), true)).
initialState(variable(("destin", constant("p0"), constant("f10"))), value(variable(("destin", constant("p0"), constant("f10"))), true)).
initialState(variable(("origin", constant("p1"), constant("f17"))), value(variable(("origin", constant("p1"), constant("f17"))), true)).
initialState(variable(("destin", constant("p1"), constant("f13"))), value(variable(("destin", constant("p1"), constant("f13"))), true)).
initialState(variable(("origin", constant("p2"), constant("f1"))), value(variable(("origin", constant("p2"), constant("f1"))), true)).
initialState(variable(("destin", constant("p2"), constant("f15"))), value(variable(("destin", constant("p2"), constant("f15"))), true)).
initialState(variable(("origin", constant("p3"), constant("f0"))), value(variable(("origin", constant("p3"), constant("f0"))), true)).
initialState(variable(("destin", constant("p3"), constant("f6"))), value(variable(("destin", constant("p3"), constant("f6"))), true)).
initialState(variable(("origin", constant("p4"), constant("f3"))), value(variable(("origin", constant("p4"), constant("f3"))), true)).
initialState(variable(("destin", constant("p4"), constant("f1"))), value(variable(("destin", constant("p4"), constant("f1"))), true)).
initialState(variable(("origin", constant("p5"), constant("f8"))), value(variable(("origin", constant("p5"), constant("f8"))), true)).
initialState(variable(("destin", constant("p5"), constant("f7"))), value(variable(("destin", constant("p5"), constant("f7"))), true)).
initialState(variable(("origin", constant("p6"), constant("f16"))), value(variable(("origin", constant("p6"), constant("f16"))), true)).
initialState(variable(("destin", constant("p6"), constant("f3"))), value(variable(("destin", constant("p6"), constant("f3"))), true)).
initialState(variable(("origin", constant("p7"), constant("f7"))), value(variable(("origin", constant("p7"), constant("f7"))), true)).
initialState(variable(("destin", constant("p7"), constant("f4"))), value(variable(("destin", constant("p7"), constant("f4"))), true)).
initialState(variable(("origin", constant("p8"), constant("f20"))), value(variable(("origin", constant("p8"), constant("f20"))), true)).
initialState(variable(("destin", constant("p8"), constant("f10"))), value(variable(("destin", constant("p8"), constant("f10"))), true)).
initialState(variable(("origin", constant("p9"), constant("f2"))), value(variable(("origin", constant("p9"), constant("f2"))), true)).
initialState(variable(("destin", constant("p9"), constant("f0"))), value(variable(("destin", constant("p9"), constant("f0"))), true)).
initialState(variable(("origin", constant("p10"), constant("f21"))), value(variable(("origin", constant("p10"), constant("f21"))), true)).
initialState(variable(("destin", constant("p10"), constant("f8"))), value(variable(("destin", constant("p10"), constant("f8"))), true)).
initialState(variable(("lift-at", constant("f0"))), value(variable(("lift-at", constant("f0"))), true)).

initialState(X, value(X, false)) :- variable(X), not initialState(X, value(X, true)).

% goal
goal(variable(("served", constant("p0"))), value(variable(("served", constant("p0"))), true)).
goal(variable(("served", constant("p1"))), value(variable(("served", constant("p1"))), true)).
goal(variable(("served", constant("p2"))), value(variable(("served", constant("p2"))), true)).
goal(variable(("served", constant("p3"))), value(variable(("served", constant("p3"))), true)).
goal(variable(("served", constant("p4"))), value(variable(("served", constant("p4"))), true)).
goal(variable(("served", constant("p5"))), value(variable(("served", constant("p5"))), true)).
goal(variable(("served", constant("p6"))), value(variable(("served", constant("p6"))), true)).
goal(variable(("served", constant("p7"))), value(variable(("served", constant("p7"))), true)).
goal(variable(("served", constant("p8"))), value(variable(("served", constant("p8"))), true)).
goal(variable(("served", constant("p9"))), value(variable(("served", constant("p9"))), true)).
goal(variable(("served", constant("p10"))), value(variable(("served", constant("p10"))), true)).
