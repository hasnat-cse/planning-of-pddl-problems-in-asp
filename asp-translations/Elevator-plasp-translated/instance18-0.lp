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

constant(constant("p11")).
has(constant("p11"), type("passenger")).

constant(constant("p12")).
has(constant("p12"), type("passenger")).

constant(constant("p13")).
has(constant("p13"), type("passenger")).

constant(constant("p14")).
has(constant("p14"), type("passenger")).

constant(constant("p15")).
has(constant("p15"), type("passenger")).

constant(constant("p16")).
has(constant("p16"), type("passenger")).

constant(constant("p17")).
has(constant("p17"), type("passenger")).

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

constant(constant("f22")).
has(constant("f22"), type("floor")).

constant(constant("f23")).
has(constant("f23"), type("floor")).

constant(constant("f24")).
has(constant("f24"), type("floor")).

constant(constant("f25")).
has(constant("f25"), type("floor")).

constant(constant("f26")).
has(constant("f26"), type("floor")).

constant(constant("f27")).
has(constant("f27"), type("floor")).

constant(constant("f28")).
has(constant("f28"), type("floor")).

constant(constant("f29")).
has(constant("f29"), type("floor")).

constant(constant("f30")).
has(constant("f30"), type("floor")).

constant(constant("f31")).
has(constant("f31"), type("floor")).

constant(constant("f32")).
has(constant("f32"), type("floor")).

constant(constant("f33")).
has(constant("f33"), type("floor")).

constant(constant("f34")).
has(constant("f34"), type("floor")).

constant(constant("f35")).
has(constant("f35"), type("floor")).

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
initialState(variable(("above", constant("f0"), constant("f22"))), value(variable(("above", constant("f0"), constant("f22"))), true)).
initialState(variable(("above", constant("f0"), constant("f23"))), value(variable(("above", constant("f0"), constant("f23"))), true)).
initialState(variable(("above", constant("f0"), constant("f24"))), value(variable(("above", constant("f0"), constant("f24"))), true)).
initialState(variable(("above", constant("f0"), constant("f25"))), value(variable(("above", constant("f0"), constant("f25"))), true)).
initialState(variable(("above", constant("f0"), constant("f26"))), value(variable(("above", constant("f0"), constant("f26"))), true)).
initialState(variable(("above", constant("f0"), constant("f27"))), value(variable(("above", constant("f0"), constant("f27"))), true)).
initialState(variable(("above", constant("f0"), constant("f28"))), value(variable(("above", constant("f0"), constant("f28"))), true)).
initialState(variable(("above", constant("f0"), constant("f29"))), value(variable(("above", constant("f0"), constant("f29"))), true)).
initialState(variable(("above", constant("f0"), constant("f30"))), value(variable(("above", constant("f0"), constant("f30"))), true)).
initialState(variable(("above", constant("f0"), constant("f31"))), value(variable(("above", constant("f0"), constant("f31"))), true)).
initialState(variable(("above", constant("f0"), constant("f32"))), value(variable(("above", constant("f0"), constant("f32"))), true)).
initialState(variable(("above", constant("f0"), constant("f33"))), value(variable(("above", constant("f0"), constant("f33"))), true)).
initialState(variable(("above", constant("f0"), constant("f34"))), value(variable(("above", constant("f0"), constant("f34"))), true)).
initialState(variable(("above", constant("f0"), constant("f35"))), value(variable(("above", constant("f0"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f1"), constant("f22"))), value(variable(("above", constant("f1"), constant("f22"))), true)).
initialState(variable(("above", constant("f1"), constant("f23"))), value(variable(("above", constant("f1"), constant("f23"))), true)).
initialState(variable(("above", constant("f1"), constant("f24"))), value(variable(("above", constant("f1"), constant("f24"))), true)).
initialState(variable(("above", constant("f1"), constant("f25"))), value(variable(("above", constant("f1"), constant("f25"))), true)).
initialState(variable(("above", constant("f1"), constant("f26"))), value(variable(("above", constant("f1"), constant("f26"))), true)).
initialState(variable(("above", constant("f1"), constant("f27"))), value(variable(("above", constant("f1"), constant("f27"))), true)).
initialState(variable(("above", constant("f1"), constant("f28"))), value(variable(("above", constant("f1"), constant("f28"))), true)).
initialState(variable(("above", constant("f1"), constant("f29"))), value(variable(("above", constant("f1"), constant("f29"))), true)).
initialState(variable(("above", constant("f1"), constant("f30"))), value(variable(("above", constant("f1"), constant("f30"))), true)).
initialState(variable(("above", constant("f1"), constant("f31"))), value(variable(("above", constant("f1"), constant("f31"))), true)).
initialState(variable(("above", constant("f1"), constant("f32"))), value(variable(("above", constant("f1"), constant("f32"))), true)).
initialState(variable(("above", constant("f1"), constant("f33"))), value(variable(("above", constant("f1"), constant("f33"))), true)).
initialState(variable(("above", constant("f1"), constant("f34"))), value(variable(("above", constant("f1"), constant("f34"))), true)).
initialState(variable(("above", constant("f1"), constant("f35"))), value(variable(("above", constant("f1"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f2"), constant("f22"))), value(variable(("above", constant("f2"), constant("f22"))), true)).
initialState(variable(("above", constant("f2"), constant("f23"))), value(variable(("above", constant("f2"), constant("f23"))), true)).
initialState(variable(("above", constant("f2"), constant("f24"))), value(variable(("above", constant("f2"), constant("f24"))), true)).
initialState(variable(("above", constant("f2"), constant("f25"))), value(variable(("above", constant("f2"), constant("f25"))), true)).
initialState(variable(("above", constant("f2"), constant("f26"))), value(variable(("above", constant("f2"), constant("f26"))), true)).
initialState(variable(("above", constant("f2"), constant("f27"))), value(variable(("above", constant("f2"), constant("f27"))), true)).
initialState(variable(("above", constant("f2"), constant("f28"))), value(variable(("above", constant("f2"), constant("f28"))), true)).
initialState(variable(("above", constant("f2"), constant("f29"))), value(variable(("above", constant("f2"), constant("f29"))), true)).
initialState(variable(("above", constant("f2"), constant("f30"))), value(variable(("above", constant("f2"), constant("f30"))), true)).
initialState(variable(("above", constant("f2"), constant("f31"))), value(variable(("above", constant("f2"), constant("f31"))), true)).
initialState(variable(("above", constant("f2"), constant("f32"))), value(variable(("above", constant("f2"), constant("f32"))), true)).
initialState(variable(("above", constant("f2"), constant("f33"))), value(variable(("above", constant("f2"), constant("f33"))), true)).
initialState(variable(("above", constant("f2"), constant("f34"))), value(variable(("above", constant("f2"), constant("f34"))), true)).
initialState(variable(("above", constant("f2"), constant("f35"))), value(variable(("above", constant("f2"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f3"), constant("f22"))), value(variable(("above", constant("f3"), constant("f22"))), true)).
initialState(variable(("above", constant("f3"), constant("f23"))), value(variable(("above", constant("f3"), constant("f23"))), true)).
initialState(variable(("above", constant("f3"), constant("f24"))), value(variable(("above", constant("f3"), constant("f24"))), true)).
initialState(variable(("above", constant("f3"), constant("f25"))), value(variable(("above", constant("f3"), constant("f25"))), true)).
initialState(variable(("above", constant("f3"), constant("f26"))), value(variable(("above", constant("f3"), constant("f26"))), true)).
initialState(variable(("above", constant("f3"), constant("f27"))), value(variable(("above", constant("f3"), constant("f27"))), true)).
initialState(variable(("above", constant("f3"), constant("f28"))), value(variable(("above", constant("f3"), constant("f28"))), true)).
initialState(variable(("above", constant("f3"), constant("f29"))), value(variable(("above", constant("f3"), constant("f29"))), true)).
initialState(variable(("above", constant("f3"), constant("f30"))), value(variable(("above", constant("f3"), constant("f30"))), true)).
initialState(variable(("above", constant("f3"), constant("f31"))), value(variable(("above", constant("f3"), constant("f31"))), true)).
initialState(variable(("above", constant("f3"), constant("f32"))), value(variable(("above", constant("f3"), constant("f32"))), true)).
initialState(variable(("above", constant("f3"), constant("f33"))), value(variable(("above", constant("f3"), constant("f33"))), true)).
initialState(variable(("above", constant("f3"), constant("f34"))), value(variable(("above", constant("f3"), constant("f34"))), true)).
initialState(variable(("above", constant("f3"), constant("f35"))), value(variable(("above", constant("f3"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f4"), constant("f22"))), value(variable(("above", constant("f4"), constant("f22"))), true)).
initialState(variable(("above", constant("f4"), constant("f23"))), value(variable(("above", constant("f4"), constant("f23"))), true)).
initialState(variable(("above", constant("f4"), constant("f24"))), value(variable(("above", constant("f4"), constant("f24"))), true)).
initialState(variable(("above", constant("f4"), constant("f25"))), value(variable(("above", constant("f4"), constant("f25"))), true)).
initialState(variable(("above", constant("f4"), constant("f26"))), value(variable(("above", constant("f4"), constant("f26"))), true)).
initialState(variable(("above", constant("f4"), constant("f27"))), value(variable(("above", constant("f4"), constant("f27"))), true)).
initialState(variable(("above", constant("f4"), constant("f28"))), value(variable(("above", constant("f4"), constant("f28"))), true)).
initialState(variable(("above", constant("f4"), constant("f29"))), value(variable(("above", constant("f4"), constant("f29"))), true)).
initialState(variable(("above", constant("f4"), constant("f30"))), value(variable(("above", constant("f4"), constant("f30"))), true)).
initialState(variable(("above", constant("f4"), constant("f31"))), value(variable(("above", constant("f4"), constant("f31"))), true)).
initialState(variable(("above", constant("f4"), constant("f32"))), value(variable(("above", constant("f4"), constant("f32"))), true)).
initialState(variable(("above", constant("f4"), constant("f33"))), value(variable(("above", constant("f4"), constant("f33"))), true)).
initialState(variable(("above", constant("f4"), constant("f34"))), value(variable(("above", constant("f4"), constant("f34"))), true)).
initialState(variable(("above", constant("f4"), constant("f35"))), value(variable(("above", constant("f4"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f5"), constant("f22"))), value(variable(("above", constant("f5"), constant("f22"))), true)).
initialState(variable(("above", constant("f5"), constant("f23"))), value(variable(("above", constant("f5"), constant("f23"))), true)).
initialState(variable(("above", constant("f5"), constant("f24"))), value(variable(("above", constant("f5"), constant("f24"))), true)).
initialState(variable(("above", constant("f5"), constant("f25"))), value(variable(("above", constant("f5"), constant("f25"))), true)).
initialState(variable(("above", constant("f5"), constant("f26"))), value(variable(("above", constant("f5"), constant("f26"))), true)).
initialState(variable(("above", constant("f5"), constant("f27"))), value(variable(("above", constant("f5"), constant("f27"))), true)).
initialState(variable(("above", constant("f5"), constant("f28"))), value(variable(("above", constant("f5"), constant("f28"))), true)).
initialState(variable(("above", constant("f5"), constant("f29"))), value(variable(("above", constant("f5"), constant("f29"))), true)).
initialState(variable(("above", constant("f5"), constant("f30"))), value(variable(("above", constant("f5"), constant("f30"))), true)).
initialState(variable(("above", constant("f5"), constant("f31"))), value(variable(("above", constant("f5"), constant("f31"))), true)).
initialState(variable(("above", constant("f5"), constant("f32"))), value(variable(("above", constant("f5"), constant("f32"))), true)).
initialState(variable(("above", constant("f5"), constant("f33"))), value(variable(("above", constant("f5"), constant("f33"))), true)).
initialState(variable(("above", constant("f5"), constant("f34"))), value(variable(("above", constant("f5"), constant("f34"))), true)).
initialState(variable(("above", constant("f5"), constant("f35"))), value(variable(("above", constant("f5"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f6"), constant("f22"))), value(variable(("above", constant("f6"), constant("f22"))), true)).
initialState(variable(("above", constant("f6"), constant("f23"))), value(variable(("above", constant("f6"), constant("f23"))), true)).
initialState(variable(("above", constant("f6"), constant("f24"))), value(variable(("above", constant("f6"), constant("f24"))), true)).
initialState(variable(("above", constant("f6"), constant("f25"))), value(variable(("above", constant("f6"), constant("f25"))), true)).
initialState(variable(("above", constant("f6"), constant("f26"))), value(variable(("above", constant("f6"), constant("f26"))), true)).
initialState(variable(("above", constant("f6"), constant("f27"))), value(variable(("above", constant("f6"), constant("f27"))), true)).
initialState(variable(("above", constant("f6"), constant("f28"))), value(variable(("above", constant("f6"), constant("f28"))), true)).
initialState(variable(("above", constant("f6"), constant("f29"))), value(variable(("above", constant("f6"), constant("f29"))), true)).
initialState(variable(("above", constant("f6"), constant("f30"))), value(variable(("above", constant("f6"), constant("f30"))), true)).
initialState(variable(("above", constant("f6"), constant("f31"))), value(variable(("above", constant("f6"), constant("f31"))), true)).
initialState(variable(("above", constant("f6"), constant("f32"))), value(variable(("above", constant("f6"), constant("f32"))), true)).
initialState(variable(("above", constant("f6"), constant("f33"))), value(variable(("above", constant("f6"), constant("f33"))), true)).
initialState(variable(("above", constant("f6"), constant("f34"))), value(variable(("above", constant("f6"), constant("f34"))), true)).
initialState(variable(("above", constant("f6"), constant("f35"))), value(variable(("above", constant("f6"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f7"), constant("f22"))), value(variable(("above", constant("f7"), constant("f22"))), true)).
initialState(variable(("above", constant("f7"), constant("f23"))), value(variable(("above", constant("f7"), constant("f23"))), true)).
initialState(variable(("above", constant("f7"), constant("f24"))), value(variable(("above", constant("f7"), constant("f24"))), true)).
initialState(variable(("above", constant("f7"), constant("f25"))), value(variable(("above", constant("f7"), constant("f25"))), true)).
initialState(variable(("above", constant("f7"), constant("f26"))), value(variable(("above", constant("f7"), constant("f26"))), true)).
initialState(variable(("above", constant("f7"), constant("f27"))), value(variable(("above", constant("f7"), constant("f27"))), true)).
initialState(variable(("above", constant("f7"), constant("f28"))), value(variable(("above", constant("f7"), constant("f28"))), true)).
initialState(variable(("above", constant("f7"), constant("f29"))), value(variable(("above", constant("f7"), constant("f29"))), true)).
initialState(variable(("above", constant("f7"), constant("f30"))), value(variable(("above", constant("f7"), constant("f30"))), true)).
initialState(variable(("above", constant("f7"), constant("f31"))), value(variable(("above", constant("f7"), constant("f31"))), true)).
initialState(variable(("above", constant("f7"), constant("f32"))), value(variable(("above", constant("f7"), constant("f32"))), true)).
initialState(variable(("above", constant("f7"), constant("f33"))), value(variable(("above", constant("f7"), constant("f33"))), true)).
initialState(variable(("above", constant("f7"), constant("f34"))), value(variable(("above", constant("f7"), constant("f34"))), true)).
initialState(variable(("above", constant("f7"), constant("f35"))), value(variable(("above", constant("f7"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f8"), constant("f22"))), value(variable(("above", constant("f8"), constant("f22"))), true)).
initialState(variable(("above", constant("f8"), constant("f23"))), value(variable(("above", constant("f8"), constant("f23"))), true)).
initialState(variable(("above", constant("f8"), constant("f24"))), value(variable(("above", constant("f8"), constant("f24"))), true)).
initialState(variable(("above", constant("f8"), constant("f25"))), value(variable(("above", constant("f8"), constant("f25"))), true)).
initialState(variable(("above", constant("f8"), constant("f26"))), value(variable(("above", constant("f8"), constant("f26"))), true)).
initialState(variable(("above", constant("f8"), constant("f27"))), value(variable(("above", constant("f8"), constant("f27"))), true)).
initialState(variable(("above", constant("f8"), constant("f28"))), value(variable(("above", constant("f8"), constant("f28"))), true)).
initialState(variable(("above", constant("f8"), constant("f29"))), value(variable(("above", constant("f8"), constant("f29"))), true)).
initialState(variable(("above", constant("f8"), constant("f30"))), value(variable(("above", constant("f8"), constant("f30"))), true)).
initialState(variable(("above", constant("f8"), constant("f31"))), value(variable(("above", constant("f8"), constant("f31"))), true)).
initialState(variable(("above", constant("f8"), constant("f32"))), value(variable(("above", constant("f8"), constant("f32"))), true)).
initialState(variable(("above", constant("f8"), constant("f33"))), value(variable(("above", constant("f8"), constant("f33"))), true)).
initialState(variable(("above", constant("f8"), constant("f34"))), value(variable(("above", constant("f8"), constant("f34"))), true)).
initialState(variable(("above", constant("f8"), constant("f35"))), value(variable(("above", constant("f8"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f9"), constant("f22"))), value(variable(("above", constant("f9"), constant("f22"))), true)).
initialState(variable(("above", constant("f9"), constant("f23"))), value(variable(("above", constant("f9"), constant("f23"))), true)).
initialState(variable(("above", constant("f9"), constant("f24"))), value(variable(("above", constant("f9"), constant("f24"))), true)).
initialState(variable(("above", constant("f9"), constant("f25"))), value(variable(("above", constant("f9"), constant("f25"))), true)).
initialState(variable(("above", constant("f9"), constant("f26"))), value(variable(("above", constant("f9"), constant("f26"))), true)).
initialState(variable(("above", constant("f9"), constant("f27"))), value(variable(("above", constant("f9"), constant("f27"))), true)).
initialState(variable(("above", constant("f9"), constant("f28"))), value(variable(("above", constant("f9"), constant("f28"))), true)).
initialState(variable(("above", constant("f9"), constant("f29"))), value(variable(("above", constant("f9"), constant("f29"))), true)).
initialState(variable(("above", constant("f9"), constant("f30"))), value(variable(("above", constant("f9"), constant("f30"))), true)).
initialState(variable(("above", constant("f9"), constant("f31"))), value(variable(("above", constant("f9"), constant("f31"))), true)).
initialState(variable(("above", constant("f9"), constant("f32"))), value(variable(("above", constant("f9"), constant("f32"))), true)).
initialState(variable(("above", constant("f9"), constant("f33"))), value(variable(("above", constant("f9"), constant("f33"))), true)).
initialState(variable(("above", constant("f9"), constant("f34"))), value(variable(("above", constant("f9"), constant("f34"))), true)).
initialState(variable(("above", constant("f9"), constant("f35"))), value(variable(("above", constant("f9"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f10"), constant("f22"))), value(variable(("above", constant("f10"), constant("f22"))), true)).
initialState(variable(("above", constant("f10"), constant("f23"))), value(variable(("above", constant("f10"), constant("f23"))), true)).
initialState(variable(("above", constant("f10"), constant("f24"))), value(variable(("above", constant("f10"), constant("f24"))), true)).
initialState(variable(("above", constant("f10"), constant("f25"))), value(variable(("above", constant("f10"), constant("f25"))), true)).
initialState(variable(("above", constant("f10"), constant("f26"))), value(variable(("above", constant("f10"), constant("f26"))), true)).
initialState(variable(("above", constant("f10"), constant("f27"))), value(variable(("above", constant("f10"), constant("f27"))), true)).
initialState(variable(("above", constant("f10"), constant("f28"))), value(variable(("above", constant("f10"), constant("f28"))), true)).
initialState(variable(("above", constant("f10"), constant("f29"))), value(variable(("above", constant("f10"), constant("f29"))), true)).
initialState(variable(("above", constant("f10"), constant("f30"))), value(variable(("above", constant("f10"), constant("f30"))), true)).
initialState(variable(("above", constant("f10"), constant("f31"))), value(variable(("above", constant("f10"), constant("f31"))), true)).
initialState(variable(("above", constant("f10"), constant("f32"))), value(variable(("above", constant("f10"), constant("f32"))), true)).
initialState(variable(("above", constant("f10"), constant("f33"))), value(variable(("above", constant("f10"), constant("f33"))), true)).
initialState(variable(("above", constant("f10"), constant("f34"))), value(variable(("above", constant("f10"), constant("f34"))), true)).
initialState(variable(("above", constant("f10"), constant("f35"))), value(variable(("above", constant("f10"), constant("f35"))), true)).
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
initialState(variable(("above", constant("f11"), constant("f22"))), value(variable(("above", constant("f11"), constant("f22"))), true)).
initialState(variable(("above", constant("f11"), constant("f23"))), value(variable(("above", constant("f11"), constant("f23"))), true)).
initialState(variable(("above", constant("f11"), constant("f24"))), value(variable(("above", constant("f11"), constant("f24"))), true)).
initialState(variable(("above", constant("f11"), constant("f25"))), value(variable(("above", constant("f11"), constant("f25"))), true)).
initialState(variable(("above", constant("f11"), constant("f26"))), value(variable(("above", constant("f11"), constant("f26"))), true)).
initialState(variable(("above", constant("f11"), constant("f27"))), value(variable(("above", constant("f11"), constant("f27"))), true)).
initialState(variable(("above", constant("f11"), constant("f28"))), value(variable(("above", constant("f11"), constant("f28"))), true)).
initialState(variable(("above", constant("f11"), constant("f29"))), value(variable(("above", constant("f11"), constant("f29"))), true)).
initialState(variable(("above", constant("f11"), constant("f30"))), value(variable(("above", constant("f11"), constant("f30"))), true)).
initialState(variable(("above", constant("f11"), constant("f31"))), value(variable(("above", constant("f11"), constant("f31"))), true)).
initialState(variable(("above", constant("f11"), constant("f32"))), value(variable(("above", constant("f11"), constant("f32"))), true)).
initialState(variable(("above", constant("f11"), constant("f33"))), value(variable(("above", constant("f11"), constant("f33"))), true)).
initialState(variable(("above", constant("f11"), constant("f34"))), value(variable(("above", constant("f11"), constant("f34"))), true)).
initialState(variable(("above", constant("f11"), constant("f35"))), value(variable(("above", constant("f11"), constant("f35"))), true)).
initialState(variable(("above", constant("f12"), constant("f13"))), value(variable(("above", constant("f12"), constant("f13"))), true)).
initialState(variable(("above", constant("f12"), constant("f14"))), value(variable(("above", constant("f12"), constant("f14"))), true)).
initialState(variable(("above", constant("f12"), constant("f15"))), value(variable(("above", constant("f12"), constant("f15"))), true)).
initialState(variable(("above", constant("f12"), constant("f16"))), value(variable(("above", constant("f12"), constant("f16"))), true)).
initialState(variable(("above", constant("f12"), constant("f17"))), value(variable(("above", constant("f12"), constant("f17"))), true)).
initialState(variable(("above", constant("f12"), constant("f18"))), value(variable(("above", constant("f12"), constant("f18"))), true)).
initialState(variable(("above", constant("f12"), constant("f19"))), value(variable(("above", constant("f12"), constant("f19"))), true)).
initialState(variable(("above", constant("f12"), constant("f20"))), value(variable(("above", constant("f12"), constant("f20"))), true)).
initialState(variable(("above", constant("f12"), constant("f21"))), value(variable(("above", constant("f12"), constant("f21"))), true)).
initialState(variable(("above", constant("f12"), constant("f22"))), value(variable(("above", constant("f12"), constant("f22"))), true)).
initialState(variable(("above", constant("f12"), constant("f23"))), value(variable(("above", constant("f12"), constant("f23"))), true)).
initialState(variable(("above", constant("f12"), constant("f24"))), value(variable(("above", constant("f12"), constant("f24"))), true)).
initialState(variable(("above", constant("f12"), constant("f25"))), value(variable(("above", constant("f12"), constant("f25"))), true)).
initialState(variable(("above", constant("f12"), constant("f26"))), value(variable(("above", constant("f12"), constant("f26"))), true)).
initialState(variable(("above", constant("f12"), constant("f27"))), value(variable(("above", constant("f12"), constant("f27"))), true)).
initialState(variable(("above", constant("f12"), constant("f28"))), value(variable(("above", constant("f12"), constant("f28"))), true)).
initialState(variable(("above", constant("f12"), constant("f29"))), value(variable(("above", constant("f12"), constant("f29"))), true)).
initialState(variable(("above", constant("f12"), constant("f30"))), value(variable(("above", constant("f12"), constant("f30"))), true)).
initialState(variable(("above", constant("f12"), constant("f31"))), value(variable(("above", constant("f12"), constant("f31"))), true)).
initialState(variable(("above", constant("f12"), constant("f32"))), value(variable(("above", constant("f12"), constant("f32"))), true)).
initialState(variable(("above", constant("f12"), constant("f33"))), value(variable(("above", constant("f12"), constant("f33"))), true)).
initialState(variable(("above", constant("f12"), constant("f34"))), value(variable(("above", constant("f12"), constant("f34"))), true)).
initialState(variable(("above", constant("f12"), constant("f35"))), value(variable(("above", constant("f12"), constant("f35"))), true)).
initialState(variable(("above", constant("f13"), constant("f14"))), value(variable(("above", constant("f13"), constant("f14"))), true)).
initialState(variable(("above", constant("f13"), constant("f15"))), value(variable(("above", constant("f13"), constant("f15"))), true)).
initialState(variable(("above", constant("f13"), constant("f16"))), value(variable(("above", constant("f13"), constant("f16"))), true)).
initialState(variable(("above", constant("f13"), constant("f17"))), value(variable(("above", constant("f13"), constant("f17"))), true)).
initialState(variable(("above", constant("f13"), constant("f18"))), value(variable(("above", constant("f13"), constant("f18"))), true)).
initialState(variable(("above", constant("f13"), constant("f19"))), value(variable(("above", constant("f13"), constant("f19"))), true)).
initialState(variable(("above", constant("f13"), constant("f20"))), value(variable(("above", constant("f13"), constant("f20"))), true)).
initialState(variable(("above", constant("f13"), constant("f21"))), value(variable(("above", constant("f13"), constant("f21"))), true)).
initialState(variable(("above", constant("f13"), constant("f22"))), value(variable(("above", constant("f13"), constant("f22"))), true)).
initialState(variable(("above", constant("f13"), constant("f23"))), value(variable(("above", constant("f13"), constant("f23"))), true)).
initialState(variable(("above", constant("f13"), constant("f24"))), value(variable(("above", constant("f13"), constant("f24"))), true)).
initialState(variable(("above", constant("f13"), constant("f25"))), value(variable(("above", constant("f13"), constant("f25"))), true)).
initialState(variable(("above", constant("f13"), constant("f26"))), value(variable(("above", constant("f13"), constant("f26"))), true)).
initialState(variable(("above", constant("f13"), constant("f27"))), value(variable(("above", constant("f13"), constant("f27"))), true)).
initialState(variable(("above", constant("f13"), constant("f28"))), value(variable(("above", constant("f13"), constant("f28"))), true)).
initialState(variable(("above", constant("f13"), constant("f29"))), value(variable(("above", constant("f13"), constant("f29"))), true)).
initialState(variable(("above", constant("f13"), constant("f30"))), value(variable(("above", constant("f13"), constant("f30"))), true)).
initialState(variable(("above", constant("f13"), constant("f31"))), value(variable(("above", constant("f13"), constant("f31"))), true)).
initialState(variable(("above", constant("f13"), constant("f32"))), value(variable(("above", constant("f13"), constant("f32"))), true)).
initialState(variable(("above", constant("f13"), constant("f33"))), value(variable(("above", constant("f13"), constant("f33"))), true)).
initialState(variable(("above", constant("f13"), constant("f34"))), value(variable(("above", constant("f13"), constant("f34"))), true)).
initialState(variable(("above", constant("f13"), constant("f35"))), value(variable(("above", constant("f13"), constant("f35"))), true)).
initialState(variable(("above", constant("f14"), constant("f15"))), value(variable(("above", constant("f14"), constant("f15"))), true)).
initialState(variable(("above", constant("f14"), constant("f16"))), value(variable(("above", constant("f14"), constant("f16"))), true)).
initialState(variable(("above", constant("f14"), constant("f17"))), value(variable(("above", constant("f14"), constant("f17"))), true)).
initialState(variable(("above", constant("f14"), constant("f18"))), value(variable(("above", constant("f14"), constant("f18"))), true)).
initialState(variable(("above", constant("f14"), constant("f19"))), value(variable(("above", constant("f14"), constant("f19"))), true)).
initialState(variable(("above", constant("f14"), constant("f20"))), value(variable(("above", constant("f14"), constant("f20"))), true)).
initialState(variable(("above", constant("f14"), constant("f21"))), value(variable(("above", constant("f14"), constant("f21"))), true)).
initialState(variable(("above", constant("f14"), constant("f22"))), value(variable(("above", constant("f14"), constant("f22"))), true)).
initialState(variable(("above", constant("f14"), constant("f23"))), value(variable(("above", constant("f14"), constant("f23"))), true)).
initialState(variable(("above", constant("f14"), constant("f24"))), value(variable(("above", constant("f14"), constant("f24"))), true)).
initialState(variable(("above", constant("f14"), constant("f25"))), value(variable(("above", constant("f14"), constant("f25"))), true)).
initialState(variable(("above", constant("f14"), constant("f26"))), value(variable(("above", constant("f14"), constant("f26"))), true)).
initialState(variable(("above", constant("f14"), constant("f27"))), value(variable(("above", constant("f14"), constant("f27"))), true)).
initialState(variable(("above", constant("f14"), constant("f28"))), value(variable(("above", constant("f14"), constant("f28"))), true)).
initialState(variable(("above", constant("f14"), constant("f29"))), value(variable(("above", constant("f14"), constant("f29"))), true)).
initialState(variable(("above", constant("f14"), constant("f30"))), value(variable(("above", constant("f14"), constant("f30"))), true)).
initialState(variable(("above", constant("f14"), constant("f31"))), value(variable(("above", constant("f14"), constant("f31"))), true)).
initialState(variable(("above", constant("f14"), constant("f32"))), value(variable(("above", constant("f14"), constant("f32"))), true)).
initialState(variable(("above", constant("f14"), constant("f33"))), value(variable(("above", constant("f14"), constant("f33"))), true)).
initialState(variable(("above", constant("f14"), constant("f34"))), value(variable(("above", constant("f14"), constant("f34"))), true)).
initialState(variable(("above", constant("f14"), constant("f35"))), value(variable(("above", constant("f14"), constant("f35"))), true)).
initialState(variable(("above", constant("f15"), constant("f16"))), value(variable(("above", constant("f15"), constant("f16"))), true)).
initialState(variable(("above", constant("f15"), constant("f17"))), value(variable(("above", constant("f15"), constant("f17"))), true)).
initialState(variable(("above", constant("f15"), constant("f18"))), value(variable(("above", constant("f15"), constant("f18"))), true)).
initialState(variable(("above", constant("f15"), constant("f19"))), value(variable(("above", constant("f15"), constant("f19"))), true)).
initialState(variable(("above", constant("f15"), constant("f20"))), value(variable(("above", constant("f15"), constant("f20"))), true)).
initialState(variable(("above", constant("f15"), constant("f21"))), value(variable(("above", constant("f15"), constant("f21"))), true)).
initialState(variable(("above", constant("f15"), constant("f22"))), value(variable(("above", constant("f15"), constant("f22"))), true)).
initialState(variable(("above", constant("f15"), constant("f23"))), value(variable(("above", constant("f15"), constant("f23"))), true)).
initialState(variable(("above", constant("f15"), constant("f24"))), value(variable(("above", constant("f15"), constant("f24"))), true)).
initialState(variable(("above", constant("f15"), constant("f25"))), value(variable(("above", constant("f15"), constant("f25"))), true)).
initialState(variable(("above", constant("f15"), constant("f26"))), value(variable(("above", constant("f15"), constant("f26"))), true)).
initialState(variable(("above", constant("f15"), constant("f27"))), value(variable(("above", constant("f15"), constant("f27"))), true)).
initialState(variable(("above", constant("f15"), constant("f28"))), value(variable(("above", constant("f15"), constant("f28"))), true)).
initialState(variable(("above", constant("f15"), constant("f29"))), value(variable(("above", constant("f15"), constant("f29"))), true)).
initialState(variable(("above", constant("f15"), constant("f30"))), value(variable(("above", constant("f15"), constant("f30"))), true)).
initialState(variable(("above", constant("f15"), constant("f31"))), value(variable(("above", constant("f15"), constant("f31"))), true)).
initialState(variable(("above", constant("f15"), constant("f32"))), value(variable(("above", constant("f15"), constant("f32"))), true)).
initialState(variable(("above", constant("f15"), constant("f33"))), value(variable(("above", constant("f15"), constant("f33"))), true)).
initialState(variable(("above", constant("f15"), constant("f34"))), value(variable(("above", constant("f15"), constant("f34"))), true)).
initialState(variable(("above", constant("f15"), constant("f35"))), value(variable(("above", constant("f15"), constant("f35"))), true)).
initialState(variable(("above", constant("f16"), constant("f17"))), value(variable(("above", constant("f16"), constant("f17"))), true)).
initialState(variable(("above", constant("f16"), constant("f18"))), value(variable(("above", constant("f16"), constant("f18"))), true)).
initialState(variable(("above", constant("f16"), constant("f19"))), value(variable(("above", constant("f16"), constant("f19"))), true)).
initialState(variable(("above", constant("f16"), constant("f20"))), value(variable(("above", constant("f16"), constant("f20"))), true)).
initialState(variable(("above", constant("f16"), constant("f21"))), value(variable(("above", constant("f16"), constant("f21"))), true)).
initialState(variable(("above", constant("f16"), constant("f22"))), value(variable(("above", constant("f16"), constant("f22"))), true)).
initialState(variable(("above", constant("f16"), constant("f23"))), value(variable(("above", constant("f16"), constant("f23"))), true)).
initialState(variable(("above", constant("f16"), constant("f24"))), value(variable(("above", constant("f16"), constant("f24"))), true)).
initialState(variable(("above", constant("f16"), constant("f25"))), value(variable(("above", constant("f16"), constant("f25"))), true)).
initialState(variable(("above", constant("f16"), constant("f26"))), value(variable(("above", constant("f16"), constant("f26"))), true)).
initialState(variable(("above", constant("f16"), constant("f27"))), value(variable(("above", constant("f16"), constant("f27"))), true)).
initialState(variable(("above", constant("f16"), constant("f28"))), value(variable(("above", constant("f16"), constant("f28"))), true)).
initialState(variable(("above", constant("f16"), constant("f29"))), value(variable(("above", constant("f16"), constant("f29"))), true)).
initialState(variable(("above", constant("f16"), constant("f30"))), value(variable(("above", constant("f16"), constant("f30"))), true)).
initialState(variable(("above", constant("f16"), constant("f31"))), value(variable(("above", constant("f16"), constant("f31"))), true)).
initialState(variable(("above", constant("f16"), constant("f32"))), value(variable(("above", constant("f16"), constant("f32"))), true)).
initialState(variable(("above", constant("f16"), constant("f33"))), value(variable(("above", constant("f16"), constant("f33"))), true)).
initialState(variable(("above", constant("f16"), constant("f34"))), value(variable(("above", constant("f16"), constant("f34"))), true)).
initialState(variable(("above", constant("f16"), constant("f35"))), value(variable(("above", constant("f16"), constant("f35"))), true)).
initialState(variable(("above", constant("f17"), constant("f18"))), value(variable(("above", constant("f17"), constant("f18"))), true)).
initialState(variable(("above", constant("f17"), constant("f19"))), value(variable(("above", constant("f17"), constant("f19"))), true)).
initialState(variable(("above", constant("f17"), constant("f20"))), value(variable(("above", constant("f17"), constant("f20"))), true)).
initialState(variable(("above", constant("f17"), constant("f21"))), value(variable(("above", constant("f17"), constant("f21"))), true)).
initialState(variable(("above", constant("f17"), constant("f22"))), value(variable(("above", constant("f17"), constant("f22"))), true)).
initialState(variable(("above", constant("f17"), constant("f23"))), value(variable(("above", constant("f17"), constant("f23"))), true)).
initialState(variable(("above", constant("f17"), constant("f24"))), value(variable(("above", constant("f17"), constant("f24"))), true)).
initialState(variable(("above", constant("f17"), constant("f25"))), value(variable(("above", constant("f17"), constant("f25"))), true)).
initialState(variable(("above", constant("f17"), constant("f26"))), value(variable(("above", constant("f17"), constant("f26"))), true)).
initialState(variable(("above", constant("f17"), constant("f27"))), value(variable(("above", constant("f17"), constant("f27"))), true)).
initialState(variable(("above", constant("f17"), constant("f28"))), value(variable(("above", constant("f17"), constant("f28"))), true)).
initialState(variable(("above", constant("f17"), constant("f29"))), value(variable(("above", constant("f17"), constant("f29"))), true)).
initialState(variable(("above", constant("f17"), constant("f30"))), value(variable(("above", constant("f17"), constant("f30"))), true)).
initialState(variable(("above", constant("f17"), constant("f31"))), value(variable(("above", constant("f17"), constant("f31"))), true)).
initialState(variable(("above", constant("f17"), constant("f32"))), value(variable(("above", constant("f17"), constant("f32"))), true)).
initialState(variable(("above", constant("f17"), constant("f33"))), value(variable(("above", constant("f17"), constant("f33"))), true)).
initialState(variable(("above", constant("f17"), constant("f34"))), value(variable(("above", constant("f17"), constant("f34"))), true)).
initialState(variable(("above", constant("f17"), constant("f35"))), value(variable(("above", constant("f17"), constant("f35"))), true)).
initialState(variable(("above", constant("f18"), constant("f19"))), value(variable(("above", constant("f18"), constant("f19"))), true)).
initialState(variable(("above", constant("f18"), constant("f20"))), value(variable(("above", constant("f18"), constant("f20"))), true)).
initialState(variable(("above", constant("f18"), constant("f21"))), value(variable(("above", constant("f18"), constant("f21"))), true)).
initialState(variable(("above", constant("f18"), constant("f22"))), value(variable(("above", constant("f18"), constant("f22"))), true)).
initialState(variable(("above", constant("f18"), constant("f23"))), value(variable(("above", constant("f18"), constant("f23"))), true)).
initialState(variable(("above", constant("f18"), constant("f24"))), value(variable(("above", constant("f18"), constant("f24"))), true)).
initialState(variable(("above", constant("f18"), constant("f25"))), value(variable(("above", constant("f18"), constant("f25"))), true)).
initialState(variable(("above", constant("f18"), constant("f26"))), value(variable(("above", constant("f18"), constant("f26"))), true)).
initialState(variable(("above", constant("f18"), constant("f27"))), value(variable(("above", constant("f18"), constant("f27"))), true)).
initialState(variable(("above", constant("f18"), constant("f28"))), value(variable(("above", constant("f18"), constant("f28"))), true)).
initialState(variable(("above", constant("f18"), constant("f29"))), value(variable(("above", constant("f18"), constant("f29"))), true)).
initialState(variable(("above", constant("f18"), constant("f30"))), value(variable(("above", constant("f18"), constant("f30"))), true)).
initialState(variable(("above", constant("f18"), constant("f31"))), value(variable(("above", constant("f18"), constant("f31"))), true)).
initialState(variable(("above", constant("f18"), constant("f32"))), value(variable(("above", constant("f18"), constant("f32"))), true)).
initialState(variable(("above", constant("f18"), constant("f33"))), value(variable(("above", constant("f18"), constant("f33"))), true)).
initialState(variable(("above", constant("f18"), constant("f34"))), value(variable(("above", constant("f18"), constant("f34"))), true)).
initialState(variable(("above", constant("f18"), constant("f35"))), value(variable(("above", constant("f18"), constant("f35"))), true)).
initialState(variable(("above", constant("f19"), constant("f20"))), value(variable(("above", constant("f19"), constant("f20"))), true)).
initialState(variable(("above", constant("f19"), constant("f21"))), value(variable(("above", constant("f19"), constant("f21"))), true)).
initialState(variable(("above", constant("f19"), constant("f22"))), value(variable(("above", constant("f19"), constant("f22"))), true)).
initialState(variable(("above", constant("f19"), constant("f23"))), value(variable(("above", constant("f19"), constant("f23"))), true)).
initialState(variable(("above", constant("f19"), constant("f24"))), value(variable(("above", constant("f19"), constant("f24"))), true)).
initialState(variable(("above", constant("f19"), constant("f25"))), value(variable(("above", constant("f19"), constant("f25"))), true)).
initialState(variable(("above", constant("f19"), constant("f26"))), value(variable(("above", constant("f19"), constant("f26"))), true)).
initialState(variable(("above", constant("f19"), constant("f27"))), value(variable(("above", constant("f19"), constant("f27"))), true)).
initialState(variable(("above", constant("f19"), constant("f28"))), value(variable(("above", constant("f19"), constant("f28"))), true)).
initialState(variable(("above", constant("f19"), constant("f29"))), value(variable(("above", constant("f19"), constant("f29"))), true)).
initialState(variable(("above", constant("f19"), constant("f30"))), value(variable(("above", constant("f19"), constant("f30"))), true)).
initialState(variable(("above", constant("f19"), constant("f31"))), value(variable(("above", constant("f19"), constant("f31"))), true)).
initialState(variable(("above", constant("f19"), constant("f32"))), value(variable(("above", constant("f19"), constant("f32"))), true)).
initialState(variable(("above", constant("f19"), constant("f33"))), value(variable(("above", constant("f19"), constant("f33"))), true)).
initialState(variable(("above", constant("f19"), constant("f34"))), value(variable(("above", constant("f19"), constant("f34"))), true)).
initialState(variable(("above", constant("f19"), constant("f35"))), value(variable(("above", constant("f19"), constant("f35"))), true)).
initialState(variable(("above", constant("f20"), constant("f21"))), value(variable(("above", constant("f20"), constant("f21"))), true)).
initialState(variable(("above", constant("f20"), constant("f22"))), value(variable(("above", constant("f20"), constant("f22"))), true)).
initialState(variable(("above", constant("f20"), constant("f23"))), value(variable(("above", constant("f20"), constant("f23"))), true)).
initialState(variable(("above", constant("f20"), constant("f24"))), value(variable(("above", constant("f20"), constant("f24"))), true)).
initialState(variable(("above", constant("f20"), constant("f25"))), value(variable(("above", constant("f20"), constant("f25"))), true)).
initialState(variable(("above", constant("f20"), constant("f26"))), value(variable(("above", constant("f20"), constant("f26"))), true)).
initialState(variable(("above", constant("f20"), constant("f27"))), value(variable(("above", constant("f20"), constant("f27"))), true)).
initialState(variable(("above", constant("f20"), constant("f28"))), value(variable(("above", constant("f20"), constant("f28"))), true)).
initialState(variable(("above", constant("f20"), constant("f29"))), value(variable(("above", constant("f20"), constant("f29"))), true)).
initialState(variable(("above", constant("f20"), constant("f30"))), value(variable(("above", constant("f20"), constant("f30"))), true)).
initialState(variable(("above", constant("f20"), constant("f31"))), value(variable(("above", constant("f20"), constant("f31"))), true)).
initialState(variable(("above", constant("f20"), constant("f32"))), value(variable(("above", constant("f20"), constant("f32"))), true)).
initialState(variable(("above", constant("f20"), constant("f33"))), value(variable(("above", constant("f20"), constant("f33"))), true)).
initialState(variable(("above", constant("f20"), constant("f34"))), value(variable(("above", constant("f20"), constant("f34"))), true)).
initialState(variable(("above", constant("f20"), constant("f35"))), value(variable(("above", constant("f20"), constant("f35"))), true)).
initialState(variable(("above", constant("f21"), constant("f22"))), value(variable(("above", constant("f21"), constant("f22"))), true)).
initialState(variable(("above", constant("f21"), constant("f23"))), value(variable(("above", constant("f21"), constant("f23"))), true)).
initialState(variable(("above", constant("f21"), constant("f24"))), value(variable(("above", constant("f21"), constant("f24"))), true)).
initialState(variable(("above", constant("f21"), constant("f25"))), value(variable(("above", constant("f21"), constant("f25"))), true)).
initialState(variable(("above", constant("f21"), constant("f26"))), value(variable(("above", constant("f21"), constant("f26"))), true)).
initialState(variable(("above", constant("f21"), constant("f27"))), value(variable(("above", constant("f21"), constant("f27"))), true)).
initialState(variable(("above", constant("f21"), constant("f28"))), value(variable(("above", constant("f21"), constant("f28"))), true)).
initialState(variable(("above", constant("f21"), constant("f29"))), value(variable(("above", constant("f21"), constant("f29"))), true)).
initialState(variable(("above", constant("f21"), constant("f30"))), value(variable(("above", constant("f21"), constant("f30"))), true)).
initialState(variable(("above", constant("f21"), constant("f31"))), value(variable(("above", constant("f21"), constant("f31"))), true)).
initialState(variable(("above", constant("f21"), constant("f32"))), value(variable(("above", constant("f21"), constant("f32"))), true)).
initialState(variable(("above", constant("f21"), constant("f33"))), value(variable(("above", constant("f21"), constant("f33"))), true)).
initialState(variable(("above", constant("f21"), constant("f34"))), value(variable(("above", constant("f21"), constant("f34"))), true)).
initialState(variable(("above", constant("f21"), constant("f35"))), value(variable(("above", constant("f21"), constant("f35"))), true)).
initialState(variable(("above", constant("f22"), constant("f23"))), value(variable(("above", constant("f22"), constant("f23"))), true)).
initialState(variable(("above", constant("f22"), constant("f24"))), value(variable(("above", constant("f22"), constant("f24"))), true)).
initialState(variable(("above", constant("f22"), constant("f25"))), value(variable(("above", constant("f22"), constant("f25"))), true)).
initialState(variable(("above", constant("f22"), constant("f26"))), value(variable(("above", constant("f22"), constant("f26"))), true)).
initialState(variable(("above", constant("f22"), constant("f27"))), value(variable(("above", constant("f22"), constant("f27"))), true)).
initialState(variable(("above", constant("f22"), constant("f28"))), value(variable(("above", constant("f22"), constant("f28"))), true)).
initialState(variable(("above", constant("f22"), constant("f29"))), value(variable(("above", constant("f22"), constant("f29"))), true)).
initialState(variable(("above", constant("f22"), constant("f30"))), value(variable(("above", constant("f22"), constant("f30"))), true)).
initialState(variable(("above", constant("f22"), constant("f31"))), value(variable(("above", constant("f22"), constant("f31"))), true)).
initialState(variable(("above", constant("f22"), constant("f32"))), value(variable(("above", constant("f22"), constant("f32"))), true)).
initialState(variable(("above", constant("f22"), constant("f33"))), value(variable(("above", constant("f22"), constant("f33"))), true)).
initialState(variable(("above", constant("f22"), constant("f34"))), value(variable(("above", constant("f22"), constant("f34"))), true)).
initialState(variable(("above", constant("f22"), constant("f35"))), value(variable(("above", constant("f22"), constant("f35"))), true)).
initialState(variable(("above", constant("f23"), constant("f24"))), value(variable(("above", constant("f23"), constant("f24"))), true)).
initialState(variable(("above", constant("f23"), constant("f25"))), value(variable(("above", constant("f23"), constant("f25"))), true)).
initialState(variable(("above", constant("f23"), constant("f26"))), value(variable(("above", constant("f23"), constant("f26"))), true)).
initialState(variable(("above", constant("f23"), constant("f27"))), value(variable(("above", constant("f23"), constant("f27"))), true)).
initialState(variable(("above", constant("f23"), constant("f28"))), value(variable(("above", constant("f23"), constant("f28"))), true)).
initialState(variable(("above", constant("f23"), constant("f29"))), value(variable(("above", constant("f23"), constant("f29"))), true)).
initialState(variable(("above", constant("f23"), constant("f30"))), value(variable(("above", constant("f23"), constant("f30"))), true)).
initialState(variable(("above", constant("f23"), constant("f31"))), value(variable(("above", constant("f23"), constant("f31"))), true)).
initialState(variable(("above", constant("f23"), constant("f32"))), value(variable(("above", constant("f23"), constant("f32"))), true)).
initialState(variable(("above", constant("f23"), constant("f33"))), value(variable(("above", constant("f23"), constant("f33"))), true)).
initialState(variable(("above", constant("f23"), constant("f34"))), value(variable(("above", constant("f23"), constant("f34"))), true)).
initialState(variable(("above", constant("f23"), constant("f35"))), value(variable(("above", constant("f23"), constant("f35"))), true)).
initialState(variable(("above", constant("f24"), constant("f25"))), value(variable(("above", constant("f24"), constant("f25"))), true)).
initialState(variable(("above", constant("f24"), constant("f26"))), value(variable(("above", constant("f24"), constant("f26"))), true)).
initialState(variable(("above", constant("f24"), constant("f27"))), value(variable(("above", constant("f24"), constant("f27"))), true)).
initialState(variable(("above", constant("f24"), constant("f28"))), value(variable(("above", constant("f24"), constant("f28"))), true)).
initialState(variable(("above", constant("f24"), constant("f29"))), value(variable(("above", constant("f24"), constant("f29"))), true)).
initialState(variable(("above", constant("f24"), constant("f30"))), value(variable(("above", constant("f24"), constant("f30"))), true)).
initialState(variable(("above", constant("f24"), constant("f31"))), value(variable(("above", constant("f24"), constant("f31"))), true)).
initialState(variable(("above", constant("f24"), constant("f32"))), value(variable(("above", constant("f24"), constant("f32"))), true)).
initialState(variable(("above", constant("f24"), constant("f33"))), value(variable(("above", constant("f24"), constant("f33"))), true)).
initialState(variable(("above", constant("f24"), constant("f34"))), value(variable(("above", constant("f24"), constant("f34"))), true)).
initialState(variable(("above", constant("f24"), constant("f35"))), value(variable(("above", constant("f24"), constant("f35"))), true)).
initialState(variable(("above", constant("f25"), constant("f26"))), value(variable(("above", constant("f25"), constant("f26"))), true)).
initialState(variable(("above", constant("f25"), constant("f27"))), value(variable(("above", constant("f25"), constant("f27"))), true)).
initialState(variable(("above", constant("f25"), constant("f28"))), value(variable(("above", constant("f25"), constant("f28"))), true)).
initialState(variable(("above", constant("f25"), constant("f29"))), value(variable(("above", constant("f25"), constant("f29"))), true)).
initialState(variable(("above", constant("f25"), constant("f30"))), value(variable(("above", constant("f25"), constant("f30"))), true)).
initialState(variable(("above", constant("f25"), constant("f31"))), value(variable(("above", constant("f25"), constant("f31"))), true)).
initialState(variable(("above", constant("f25"), constant("f32"))), value(variable(("above", constant("f25"), constant("f32"))), true)).
initialState(variable(("above", constant("f25"), constant("f33"))), value(variable(("above", constant("f25"), constant("f33"))), true)).
initialState(variable(("above", constant("f25"), constant("f34"))), value(variable(("above", constant("f25"), constant("f34"))), true)).
initialState(variable(("above", constant("f25"), constant("f35"))), value(variable(("above", constant("f25"), constant("f35"))), true)).
initialState(variable(("above", constant("f26"), constant("f27"))), value(variable(("above", constant("f26"), constant("f27"))), true)).
initialState(variable(("above", constant("f26"), constant("f28"))), value(variable(("above", constant("f26"), constant("f28"))), true)).
initialState(variable(("above", constant("f26"), constant("f29"))), value(variable(("above", constant("f26"), constant("f29"))), true)).
initialState(variable(("above", constant("f26"), constant("f30"))), value(variable(("above", constant("f26"), constant("f30"))), true)).
initialState(variable(("above", constant("f26"), constant("f31"))), value(variable(("above", constant("f26"), constant("f31"))), true)).
initialState(variable(("above", constant("f26"), constant("f32"))), value(variable(("above", constant("f26"), constant("f32"))), true)).
initialState(variable(("above", constant("f26"), constant("f33"))), value(variable(("above", constant("f26"), constant("f33"))), true)).
initialState(variable(("above", constant("f26"), constant("f34"))), value(variable(("above", constant("f26"), constant("f34"))), true)).
initialState(variable(("above", constant("f26"), constant("f35"))), value(variable(("above", constant("f26"), constant("f35"))), true)).
initialState(variable(("above", constant("f27"), constant("f28"))), value(variable(("above", constant("f27"), constant("f28"))), true)).
initialState(variable(("above", constant("f27"), constant("f29"))), value(variable(("above", constant("f27"), constant("f29"))), true)).
initialState(variable(("above", constant("f27"), constant("f30"))), value(variable(("above", constant("f27"), constant("f30"))), true)).
initialState(variable(("above", constant("f27"), constant("f31"))), value(variable(("above", constant("f27"), constant("f31"))), true)).
initialState(variable(("above", constant("f27"), constant("f32"))), value(variable(("above", constant("f27"), constant("f32"))), true)).
initialState(variable(("above", constant("f27"), constant("f33"))), value(variable(("above", constant("f27"), constant("f33"))), true)).
initialState(variable(("above", constant("f27"), constant("f34"))), value(variable(("above", constant("f27"), constant("f34"))), true)).
initialState(variable(("above", constant("f27"), constant("f35"))), value(variable(("above", constant("f27"), constant("f35"))), true)).
initialState(variable(("above", constant("f28"), constant("f29"))), value(variable(("above", constant("f28"), constant("f29"))), true)).
initialState(variable(("above", constant("f28"), constant("f30"))), value(variable(("above", constant("f28"), constant("f30"))), true)).
initialState(variable(("above", constant("f28"), constant("f31"))), value(variable(("above", constant("f28"), constant("f31"))), true)).
initialState(variable(("above", constant("f28"), constant("f32"))), value(variable(("above", constant("f28"), constant("f32"))), true)).
initialState(variable(("above", constant("f28"), constant("f33"))), value(variable(("above", constant("f28"), constant("f33"))), true)).
initialState(variable(("above", constant("f28"), constant("f34"))), value(variable(("above", constant("f28"), constant("f34"))), true)).
initialState(variable(("above", constant("f28"), constant("f35"))), value(variable(("above", constant("f28"), constant("f35"))), true)).
initialState(variable(("above", constant("f29"), constant("f30"))), value(variable(("above", constant("f29"), constant("f30"))), true)).
initialState(variable(("above", constant("f29"), constant("f31"))), value(variable(("above", constant("f29"), constant("f31"))), true)).
initialState(variable(("above", constant("f29"), constant("f32"))), value(variable(("above", constant("f29"), constant("f32"))), true)).
initialState(variable(("above", constant("f29"), constant("f33"))), value(variable(("above", constant("f29"), constant("f33"))), true)).
initialState(variable(("above", constant("f29"), constant("f34"))), value(variable(("above", constant("f29"), constant("f34"))), true)).
initialState(variable(("above", constant("f29"), constant("f35"))), value(variable(("above", constant("f29"), constant("f35"))), true)).
initialState(variable(("above", constant("f30"), constant("f31"))), value(variable(("above", constant("f30"), constant("f31"))), true)).
initialState(variable(("above", constant("f30"), constant("f32"))), value(variable(("above", constant("f30"), constant("f32"))), true)).
initialState(variable(("above", constant("f30"), constant("f33"))), value(variable(("above", constant("f30"), constant("f33"))), true)).
initialState(variable(("above", constant("f30"), constant("f34"))), value(variable(("above", constant("f30"), constant("f34"))), true)).
initialState(variable(("above", constant("f30"), constant("f35"))), value(variable(("above", constant("f30"), constant("f35"))), true)).
initialState(variable(("above", constant("f31"), constant("f32"))), value(variable(("above", constant("f31"), constant("f32"))), true)).
initialState(variable(("above", constant("f31"), constant("f33"))), value(variable(("above", constant("f31"), constant("f33"))), true)).
initialState(variable(("above", constant("f31"), constant("f34"))), value(variable(("above", constant("f31"), constant("f34"))), true)).
initialState(variable(("above", constant("f31"), constant("f35"))), value(variable(("above", constant("f31"), constant("f35"))), true)).
initialState(variable(("above", constant("f32"), constant("f33"))), value(variable(("above", constant("f32"), constant("f33"))), true)).
initialState(variable(("above", constant("f32"), constant("f34"))), value(variable(("above", constant("f32"), constant("f34"))), true)).
initialState(variable(("above", constant("f32"), constant("f35"))), value(variable(("above", constant("f32"), constant("f35"))), true)).
initialState(variable(("above", constant("f33"), constant("f34"))), value(variable(("above", constant("f33"), constant("f34"))), true)).
initialState(variable(("above", constant("f33"), constant("f35"))), value(variable(("above", constant("f33"), constant("f35"))), true)).
initialState(variable(("above", constant("f34"), constant("f35"))), value(variable(("above", constant("f34"), constant("f35"))), true)).
initialState(variable(("origin", constant("p0"), constant("f19"))), value(variable(("origin", constant("p0"), constant("f19"))), true)).
initialState(variable(("destin", constant("p0"), constant("f34"))), value(variable(("destin", constant("p0"), constant("f34"))), true)).
initialState(variable(("origin", constant("p1"), constant("f9"))), value(variable(("origin", constant("p1"), constant("f9"))), true)).
initialState(variable(("destin", constant("p1"), constant("f7"))), value(variable(("destin", constant("p1"), constant("f7"))), true)).
initialState(variable(("origin", constant("p2"), constant("f5"))), value(variable(("origin", constant("p2"), constant("f5"))), true)).
initialState(variable(("destin", constant("p2"), constant("f7"))), value(variable(("destin", constant("p2"), constant("f7"))), true)).
initialState(variable(("origin", constant("p3"), constant("f10"))), value(variable(("origin", constant("p3"), constant("f10"))), true)).
initialState(variable(("destin", constant("p3"), constant("f12"))), value(variable(("destin", constant("p3"), constant("f12"))), true)).
initialState(variable(("origin", constant("p4"), constant("f33"))), value(variable(("origin", constant("p4"), constant("f33"))), true)).
initialState(variable(("destin", constant("p4"), constant("f1"))), value(variable(("destin", constant("p4"), constant("f1"))), true)).
initialState(variable(("origin", constant("p5"), constant("f14"))), value(variable(("origin", constant("p5"), constant("f14"))), true)).
initialState(variable(("destin", constant("p5"), constant("f31"))), value(variable(("destin", constant("p5"), constant("f31"))), true)).
initialState(variable(("origin", constant("p6"), constant("f14"))), value(variable(("origin", constant("p6"), constant("f14"))), true)).
initialState(variable(("destin", constant("p6"), constant("f7"))), value(variable(("destin", constant("p6"), constant("f7"))), true)).
initialState(variable(("origin", constant("p7"), constant("f23"))), value(variable(("origin", constant("p7"), constant("f23"))), true)).
initialState(variable(("destin", constant("p7"), constant("f22"))), value(variable(("destin", constant("p7"), constant("f22"))), true)).
initialState(variable(("origin", constant("p8"), constant("f24"))), value(variable(("origin", constant("p8"), constant("f24"))), true)).
initialState(variable(("destin", constant("p8"), constant("f18"))), value(variable(("destin", constant("p8"), constant("f18"))), true)).
initialState(variable(("origin", constant("p9"), constant("f16"))), value(variable(("origin", constant("p9"), constant("f16"))), true)).
initialState(variable(("destin", constant("p9"), constant("f28"))), value(variable(("destin", constant("p9"), constant("f28"))), true)).
initialState(variable(("origin", constant("p10"), constant("f35"))), value(variable(("origin", constant("p10"), constant("f35"))), true)).
initialState(variable(("destin", constant("p10"), constant("f8"))), value(variable(("destin", constant("p10"), constant("f8"))), true)).
initialState(variable(("origin", constant("p11"), constant("f15"))), value(variable(("origin", constant("p11"), constant("f15"))), true)).
initialState(variable(("destin", constant("p11"), constant("f33"))), value(variable(("destin", constant("p11"), constant("f33"))), true)).
initialState(variable(("origin", constant("p12"), constant("f26"))), value(variable(("origin", constant("p12"), constant("f26"))), true)).
initialState(variable(("destin", constant("p12"), constant("f31"))), value(variable(("destin", constant("p12"), constant("f31"))), true)).
initialState(variable(("origin", constant("p13"), constant("f19"))), value(variable(("origin", constant("p13"), constant("f19"))), true)).
initialState(variable(("destin", constant("p13"), constant("f5"))), value(variable(("destin", constant("p13"), constant("f5"))), true)).
initialState(variable(("origin", constant("p14"), constant("f18"))), value(variable(("origin", constant("p14"), constant("f18"))), true)).
initialState(variable(("destin", constant("p14"), constant("f30"))), value(variable(("destin", constant("p14"), constant("f30"))), true)).
initialState(variable(("origin", constant("p15"), constant("f5"))), value(variable(("origin", constant("p15"), constant("f5"))), true)).
initialState(variable(("destin", constant("p15"), constant("f3"))), value(variable(("destin", constant("p15"), constant("f3"))), true)).
initialState(variable(("origin", constant("p16"), constant("f1"))), value(variable(("origin", constant("p16"), constant("f1"))), true)).
initialState(variable(("destin", constant("p16"), constant("f16"))), value(variable(("destin", constant("p16"), constant("f16"))), true)).
initialState(variable(("origin", constant("p17"), constant("f31"))), value(variable(("origin", constant("p17"), constant("f31"))), true)).
initialState(variable(("destin", constant("p17"), constant("f34"))), value(variable(("destin", constant("p17"), constant("f34"))), true)).
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
goal(variable(("served", constant("p11"))), value(variable(("served", constant("p11"))), true)).
goal(variable(("served", constant("p12"))), value(variable(("served", constant("p12"))), true)).
goal(variable(("served", constant("p13"))), value(variable(("served", constant("p13"))), true)).
goal(variable(("served", constant("p14"))), value(variable(("served", constant("p14"))), true)).
goal(variable(("served", constant("p15"))), value(variable(("served", constant("p15"))), true)).
goal(variable(("served", constant("p16"))), value(variable(("served", constant("p16"))), true)).
goal(variable(("served", constant("p17"))), value(variable(("served", constant("p17"))), true)).
