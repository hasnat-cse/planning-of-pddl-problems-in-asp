%---------------------------------------
% domain
%---------------------------------------

% utils
boolean(true).
boolean(false).

% types
type(type("child")).
type(type("bread-portion")).
type(type("content-portion")).
type(type("sandwich")).
type(type("tray")).
type(type("place")).

has(X, type(T2)) :- has(X, type(T1)), inherits(type(T1), type(T2)).

% constants
constant(constant("kitchen")).
has(constant("kitchen"), type("place")).

% variables
variable(variable(("at_kitchen_bread", X1))) :- has(X1, type("bread-portion")).
variable(variable(("at_kitchen_content", X1))) :- has(X1, type("content-portion")).
variable(variable(("at_kitchen_sandwich", X1))) :- has(X1, type("sandwich")).
variable(variable(("no_gluten_bread", X1))) :- has(X1, type("bread-portion")).
variable(variable(("no_gluten_content", X1))) :- has(X1, type("content-portion")).
variable(variable(("ontray", X1, X2))) :- has(X1, type("sandwich")), has(X2, type("tray")).
variable(variable(("no_gluten_sandwich", X1))) :- has(X1, type("sandwich")).
variable(variable(("allergic_gluten", X1))) :- has(X1, type("child")).
variable(variable(("not_allergic_gluten", X1))) :- has(X1, type("child")).
variable(variable(("served", X1))) :- has(X1, type("child")).
variable(variable(("waiting", X1, X2))) :- has(X1, type("child")), has(X2, type("place")).
variable(variable(("at", X1, X2))) :- has(X1, type("tray")), has(X2, type("place")).
variable(variable(("notexist", X1))) :- has(X1, type("sandwich")).

contains(X, value(X, B)) :- variable(X), boolean(B).

% actions
action(action(("make_sandwich_no_gluten", X1, X2, X3))) :- has(X1, type("sandwich")), has(X2, type("bread-portion")), has(X3, type("content-portion")).
precondition(action(("make_sandwich_no_gluten", X1, X2, X3)), variable(("at_kitchen_bread", X2)), value(variable(("at_kitchen_bread", X2)), true)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
precondition(action(("make_sandwich_no_gluten", X1, X2, X3)), variable(("at_kitchen_content", X3)), value(variable(("at_kitchen_content", X3)), true)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
precondition(action(("make_sandwich_no_gluten", X1, X2, X3)), variable(("no_gluten_bread", X2)), value(variable(("no_gluten_bread", X2)), true)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
precondition(action(("make_sandwich_no_gluten", X1, X2, X3)), variable(("no_gluten_content", X3)), value(variable(("no_gluten_content", X3)), true)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
precondition(action(("make_sandwich_no_gluten", X1, X2, X3)), variable(("notexist", X1)), value(variable(("notexist", X1)), true)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
postcondition(action(("make_sandwich_no_gluten", X1, X2, X3)), effect(unconditional), variable(("at_kitchen_bread", X2)), value(variable(("at_kitchen_bread", X2)), false)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
postcondition(action(("make_sandwich_no_gluten", X1, X2, X3)), effect(unconditional), variable(("at_kitchen_content", X3)), value(variable(("at_kitchen_content", X3)), false)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
postcondition(action(("make_sandwich_no_gluten", X1, X2, X3)), effect(unconditional), variable(("at_kitchen_sandwich", X1)), value(variable(("at_kitchen_sandwich", X1)), true)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
postcondition(action(("make_sandwich_no_gluten", X1, X2, X3)), effect(unconditional), variable(("no_gluten_sandwich", X1)), value(variable(("no_gluten_sandwich", X1)), true)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).
postcondition(action(("make_sandwich_no_gluten", X1, X2, X3)), effect(unconditional), variable(("notexist", X1)), value(variable(("notexist", X1)), false)) :- action(action(("make_sandwich_no_gluten", X1, X2, X3))).

action(action(("make_sandwich", X1, X2, X3))) :- has(X1, type("sandwich")), has(X2, type("bread-portion")), has(X3, type("content-portion")).
precondition(action(("make_sandwich", X1, X2, X3)), variable(("at_kitchen_bread", X2)), value(variable(("at_kitchen_bread", X2)), true)) :- action(action(("make_sandwich", X1, X2, X3))).
precondition(action(("make_sandwich", X1, X2, X3)), variable(("at_kitchen_content", X3)), value(variable(("at_kitchen_content", X3)), true)) :- action(action(("make_sandwich", X1, X2, X3))).
precondition(action(("make_sandwich", X1, X2, X3)), variable(("notexist", X1)), value(variable(("notexist", X1)), true)) :- action(action(("make_sandwich", X1, X2, X3))).
postcondition(action(("make_sandwich", X1, X2, X3)), effect(unconditional), variable(("at_kitchen_bread", X2)), value(variable(("at_kitchen_bread", X2)), false)) :- action(action(("make_sandwich", X1, X2, X3))).
postcondition(action(("make_sandwich", X1, X2, X3)), effect(unconditional), variable(("at_kitchen_content", X3)), value(variable(("at_kitchen_content", X3)), false)) :- action(action(("make_sandwich", X1, X2, X3))).
postcondition(action(("make_sandwich", X1, X2, X3)), effect(unconditional), variable(("at_kitchen_sandwich", X1)), value(variable(("at_kitchen_sandwich", X1)), true)) :- action(action(("make_sandwich", X1, X2, X3))).
postcondition(action(("make_sandwich", X1, X2, X3)), effect(unconditional), variable(("notexist", X1)), value(variable(("notexist", X1)), false)) :- action(action(("make_sandwich", X1, X2, X3))).

action(action(("put_on_tray", X1, X2))) :- has(X1, type("sandwich")), has(X2, type("tray")).
precondition(action(("put_on_tray", X1, X2)), variable(("at_kitchen_sandwich", X1)), value(variable(("at_kitchen_sandwich", X1)), true)) :- action(action(("put_on_tray", X1, X2))).
precondition(action(("put_on_tray", X1, X2)), variable(("at", X2, constant("kitchen"))), value(variable(("at", X2, constant("kitchen"))), true)) :- action(action(("put_on_tray", X1, X2))).
postcondition(action(("put_on_tray", X1, X2)), effect(unconditional), variable(("at_kitchen_sandwich", X1)), value(variable(("at_kitchen_sandwich", X1)), false)) :- action(action(("put_on_tray", X1, X2))).
postcondition(action(("put_on_tray", X1, X2)), effect(unconditional), variable(("ontray", X1, X2)), value(variable(("ontray", X1, X2)), true)) :- action(action(("put_on_tray", X1, X2))).

action(action(("serve_sandwich_no_gluten", X1, X2, X3, X4))) :- has(X1, type("sandwich")), has(X2, type("child")), has(X3, type("tray")), has(X4, type("place")).
precondition(action(("serve_sandwich_no_gluten", X1, X2, X3, X4)), variable(("allergic_gluten", X2)), value(variable(("allergic_gluten", X2)), true)) :- action(action(("serve_sandwich_no_gluten", X1, X2, X3, X4))).
precondition(action(("serve_sandwich_no_gluten", X1, X2, X3, X4)), variable(("ontray", X1, X3)), value(variable(("ontray", X1, X3)), true)) :- action(action(("serve_sandwich_no_gluten", X1, X2, X3, X4))).
precondition(action(("serve_sandwich_no_gluten", X1, X2, X3, X4)), variable(("waiting", X2, X4)), value(variable(("waiting", X2, X4)), true)) :- action(action(("serve_sandwich_no_gluten", X1, X2, X3, X4))).
precondition(action(("serve_sandwich_no_gluten", X1, X2, X3, X4)), variable(("no_gluten_sandwich", X1)), value(variable(("no_gluten_sandwich", X1)), true)) :- action(action(("serve_sandwich_no_gluten", X1, X2, X3, X4))).
precondition(action(("serve_sandwich_no_gluten", X1, X2, X3, X4)), variable(("at", X3, X4)), value(variable(("at", X3, X4)), true)) :- action(action(("serve_sandwich_no_gluten", X1, X2, X3, X4))).
postcondition(action(("serve_sandwich_no_gluten", X1, X2, X3, X4)), effect(unconditional), variable(("ontray", X1, X3)), value(variable(("ontray", X1, X3)), false)) :- action(action(("serve_sandwich_no_gluten", X1, X2, X3, X4))).
postcondition(action(("serve_sandwich_no_gluten", X1, X2, X3, X4)), effect(unconditional), variable(("served", X2)), value(variable(("served", X2)), true)) :- action(action(("serve_sandwich_no_gluten", X1, X2, X3, X4))).

action(action(("serve_sandwich", X1, X2, X3, X4))) :- has(X1, type("sandwich")), has(X2, type("child")), has(X3, type("tray")), has(X4, type("place")).
precondition(action(("serve_sandwich", X1, X2, X3, X4)), variable(("not_allergic_gluten", X2)), value(variable(("not_allergic_gluten", X2)), true)) :- action(action(("serve_sandwich", X1, X2, X3, X4))).
precondition(action(("serve_sandwich", X1, X2, X3, X4)), variable(("waiting", X2, X4)), value(variable(("waiting", X2, X4)), true)) :- action(action(("serve_sandwich", X1, X2, X3, X4))).
precondition(action(("serve_sandwich", X1, X2, X3, X4)), variable(("ontray", X1, X3)), value(variable(("ontray", X1, X3)), true)) :- action(action(("serve_sandwich", X1, X2, X3, X4))).
precondition(action(("serve_sandwich", X1, X2, X3, X4)), variable(("at", X3, X4)), value(variable(("at", X3, X4)), true)) :- action(action(("serve_sandwich", X1, X2, X3, X4))).
postcondition(action(("serve_sandwich", X1, X2, X3, X4)), effect(unconditional), variable(("ontray", X1, X3)), value(variable(("ontray", X1, X3)), false)) :- action(action(("serve_sandwich", X1, X2, X3, X4))).
postcondition(action(("serve_sandwich", X1, X2, X3, X4)), effect(unconditional), variable(("served", X2)), value(variable(("served", X2)), true)) :- action(action(("serve_sandwich", X1, X2, X3, X4))).

action(action(("move_tray", X1, X2, X3))) :- has(X1, type("tray")), has(X2, type("place")), has(X3, type("place")).
precondition(action(("move_tray", X1, X2, X3)), variable(("at", X1, X2)), value(variable(("at", X1, X2)), true)) :- action(action(("move_tray", X1, X2, X3))).
postcondition(action(("move_tray", X1, X2, X3)), effect(unconditional), variable(("at", X1, X2)), value(variable(("at", X1, X2)), false)) :- action(action(("move_tray", X1, X2, X3))).
postcondition(action(("move_tray", X1, X2, X3)), effect(unconditional), variable(("at", X1, X3)), value(variable(("at", X1, X3)), true)) :- action(action(("move_tray", X1, X2, X3))).

%---------------------------------------
% problem
%---------------------------------------

% objects
constant(constant("child1")).
has(constant("child1"), type("child")).

constant(constant("child2")).
has(constant("child2"), type("child")).

constant(constant("child3")).
has(constant("child3"), type("child")).

constant(constant("child4")).
has(constant("child4"), type("child")).

constant(constant("child5")).
has(constant("child5"), type("child")).

constant(constant("child6")).
has(constant("child6"), type("child")).

constant(constant("child7")).
has(constant("child7"), type("child")).

constant(constant("child8")).
has(constant("child8"), type("child")).

constant(constant("child9")).
has(constant("child9"), type("child")).

constant(constant("child10")).
has(constant("child10"), type("child")).

constant(constant("child11")).
has(constant("child11"), type("child")).

constant(constant("child12")).
has(constant("child12"), type("child")).

constant(constant("child13")).
has(constant("child13"), type("child")).

constant(constant("child14")).
has(constant("child14"), type("child")).

constant(constant("child15")).
has(constant("child15"), type("child")).

constant(constant("child16")).
has(constant("child16"), type("child")).

constant(constant("bread1")).
has(constant("bread1"), type("bread-portion")).

constant(constant("bread2")).
has(constant("bread2"), type("bread-portion")).

constant(constant("bread3")).
has(constant("bread3"), type("bread-portion")).

constant(constant("bread4")).
has(constant("bread4"), type("bread-portion")).

constant(constant("bread5")).
has(constant("bread5"), type("bread-portion")).

constant(constant("bread6")).
has(constant("bread6"), type("bread-portion")).

constant(constant("bread7")).
has(constant("bread7"), type("bread-portion")).

constant(constant("bread8")).
has(constant("bread8"), type("bread-portion")).

constant(constant("bread9")).
has(constant("bread9"), type("bread-portion")).

constant(constant("bread10")).
has(constant("bread10"), type("bread-portion")).

constant(constant("bread11")).
has(constant("bread11"), type("bread-portion")).

constant(constant("bread12")).
has(constant("bread12"), type("bread-portion")).

constant(constant("bread13")).
has(constant("bread13"), type("bread-portion")).

constant(constant("bread14")).
has(constant("bread14"), type("bread-portion")).

constant(constant("bread15")).
has(constant("bread15"), type("bread-portion")).

constant(constant("bread16")).
has(constant("bread16"), type("bread-portion")).

constant(constant("content1")).
has(constant("content1"), type("content-portion")).

constant(constant("content2")).
has(constant("content2"), type("content-portion")).

constant(constant("content3")).
has(constant("content3"), type("content-portion")).

constant(constant("content4")).
has(constant("content4"), type("content-portion")).

constant(constant("content5")).
has(constant("content5"), type("content-portion")).

constant(constant("content6")).
has(constant("content6"), type("content-portion")).

constant(constant("content7")).
has(constant("content7"), type("content-portion")).

constant(constant("content8")).
has(constant("content8"), type("content-portion")).

constant(constant("content9")).
has(constant("content9"), type("content-portion")).

constant(constant("content10")).
has(constant("content10"), type("content-portion")).

constant(constant("content11")).
has(constant("content11"), type("content-portion")).

constant(constant("content12")).
has(constant("content12"), type("content-portion")).

constant(constant("content13")).
has(constant("content13"), type("content-portion")).

constant(constant("content14")).
has(constant("content14"), type("content-portion")).

constant(constant("content15")).
has(constant("content15"), type("content-portion")).

constant(constant("content16")).
has(constant("content16"), type("content-portion")).

constant(constant("tray1")).
has(constant("tray1"), type("tray")).

constant(constant("tray2")).
has(constant("tray2"), type("tray")).

constant(constant("tray3")).
has(constant("tray3"), type("tray")).

constant(constant("table1")).
has(constant("table1"), type("place")).

constant(constant("table2")).
has(constant("table2"), type("place")).

constant(constant("table3")).
has(constant("table3"), type("place")).

constant(constant("sandw1")).
has(constant("sandw1"), type("sandwich")).

constant(constant("sandw2")).
has(constant("sandw2"), type("sandwich")).

constant(constant("sandw3")).
has(constant("sandw3"), type("sandwich")).

constant(constant("sandw4")).
has(constant("sandw4"), type("sandwich")).

constant(constant("sandw5")).
has(constant("sandw5"), type("sandwich")).

constant(constant("sandw6")).
has(constant("sandw6"), type("sandwich")).

constant(constant("sandw7")).
has(constant("sandw7"), type("sandwich")).

constant(constant("sandw8")).
has(constant("sandw8"), type("sandwich")).

constant(constant("sandw9")).
has(constant("sandw9"), type("sandwich")).

constant(constant("sandw10")).
has(constant("sandw10"), type("sandwich")).

constant(constant("sandw11")).
has(constant("sandw11"), type("sandwich")).

constant(constant("sandw12")).
has(constant("sandw12"), type("sandwich")).

constant(constant("sandw13")).
has(constant("sandw13"), type("sandwich")).

constant(constant("sandw14")).
has(constant("sandw14"), type("sandwich")).

constant(constant("sandw15")).
has(constant("sandw15"), type("sandwich")).

constant(constant("sandw16")).
has(constant("sandw16"), type("sandwich")).

constant(constant("sandw17")).
has(constant("sandw17"), type("sandwich")).

constant(constant("sandw18")).
has(constant("sandw18"), type("sandwich")).

constant(constant("sandw19")).
has(constant("sandw19"), type("sandwich")).

constant(constant("sandw20")).
has(constant("sandw20"), type("sandwich")).

constant(constant("sandw21")).
has(constant("sandw21"), type("sandwich")).

% initial state
initialState(variable(("at", constant("tray1"), constant("kitchen"))), value(variable(("at", constant("tray1"), constant("kitchen"))), true)).
initialState(variable(("at", constant("tray2"), constant("kitchen"))), value(variable(("at", constant("tray2"), constant("kitchen"))), true)).
initialState(variable(("at", constant("tray3"), constant("kitchen"))), value(variable(("at", constant("tray3"), constant("kitchen"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread1"))), value(variable(("at_kitchen_bread", constant("bread1"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread2"))), value(variable(("at_kitchen_bread", constant("bread2"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread3"))), value(variable(("at_kitchen_bread", constant("bread3"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread4"))), value(variable(("at_kitchen_bread", constant("bread4"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread5"))), value(variable(("at_kitchen_bread", constant("bread5"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread6"))), value(variable(("at_kitchen_bread", constant("bread6"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread7"))), value(variable(("at_kitchen_bread", constant("bread7"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread8"))), value(variable(("at_kitchen_bread", constant("bread8"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread9"))), value(variable(("at_kitchen_bread", constant("bread9"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread10"))), value(variable(("at_kitchen_bread", constant("bread10"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread11"))), value(variable(("at_kitchen_bread", constant("bread11"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread12"))), value(variable(("at_kitchen_bread", constant("bread12"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread13"))), value(variable(("at_kitchen_bread", constant("bread13"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread14"))), value(variable(("at_kitchen_bread", constant("bread14"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread15"))), value(variable(("at_kitchen_bread", constant("bread15"))), true)).
initialState(variable(("at_kitchen_bread", constant("bread16"))), value(variable(("at_kitchen_bread", constant("bread16"))), true)).
initialState(variable(("at_kitchen_content", constant("content1"))), value(variable(("at_kitchen_content", constant("content1"))), true)).
initialState(variable(("at_kitchen_content", constant("content2"))), value(variable(("at_kitchen_content", constant("content2"))), true)).
initialState(variable(("at_kitchen_content", constant("content3"))), value(variable(("at_kitchen_content", constant("content3"))), true)).
initialState(variable(("at_kitchen_content", constant("content4"))), value(variable(("at_kitchen_content", constant("content4"))), true)).
initialState(variable(("at_kitchen_content", constant("content5"))), value(variable(("at_kitchen_content", constant("content5"))), true)).
initialState(variable(("at_kitchen_content", constant("content6"))), value(variable(("at_kitchen_content", constant("content6"))), true)).
initialState(variable(("at_kitchen_content", constant("content7"))), value(variable(("at_kitchen_content", constant("content7"))), true)).
initialState(variable(("at_kitchen_content", constant("content8"))), value(variable(("at_kitchen_content", constant("content8"))), true)).
initialState(variable(("at_kitchen_content", constant("content9"))), value(variable(("at_kitchen_content", constant("content9"))), true)).
initialState(variable(("at_kitchen_content", constant("content10"))), value(variable(("at_kitchen_content", constant("content10"))), true)).
initialState(variable(("at_kitchen_content", constant("content11"))), value(variable(("at_kitchen_content", constant("content11"))), true)).
initialState(variable(("at_kitchen_content", constant("content12"))), value(variable(("at_kitchen_content", constant("content12"))), true)).
initialState(variable(("at_kitchen_content", constant("content13"))), value(variable(("at_kitchen_content", constant("content13"))), true)).
initialState(variable(("at_kitchen_content", constant("content14"))), value(variable(("at_kitchen_content", constant("content14"))), true)).
initialState(variable(("at_kitchen_content", constant("content15"))), value(variable(("at_kitchen_content", constant("content15"))), true)).
initialState(variable(("at_kitchen_content", constant("content16"))), value(variable(("at_kitchen_content", constant("content16"))), true)).
initialState(variable(("no_gluten_bread", constant("bread10"))), value(variable(("no_gluten_bread", constant("bread10"))), true)).
initialState(variable(("no_gluten_bread", constant("bread3"))), value(variable(("no_gluten_bread", constant("bread3"))), true)).
initialState(variable(("no_gluten_bread", constant("bread14"))), value(variable(("no_gluten_bread", constant("bread14"))), true)).
initialState(variable(("no_gluten_bread", constant("bread13"))), value(variable(("no_gluten_bread", constant("bread13"))), true)).
initialState(variable(("no_gluten_bread", constant("bread6"))), value(variable(("no_gluten_bread", constant("bread6"))), true)).
initialState(variable(("no_gluten_bread", constant("bread8"))), value(variable(("no_gluten_bread", constant("bread8"))), true)).
initialState(variable(("no_gluten_content", constant("content4"))), value(variable(("no_gluten_content", constant("content4"))), true)).
initialState(variable(("no_gluten_content", constant("content16"))), value(variable(("no_gluten_content", constant("content16"))), true)).
initialState(variable(("no_gluten_content", constant("content5"))), value(variable(("no_gluten_content", constant("content5"))), true)).
initialState(variable(("no_gluten_content", constant("content10"))), value(variable(("no_gluten_content", constant("content10"))), true)).
initialState(variable(("no_gluten_content", constant("content3"))), value(variable(("no_gluten_content", constant("content3"))), true)).
initialState(variable(("no_gluten_content", constant("content11"))), value(variable(("no_gluten_content", constant("content11"))), true)).
initialState(variable(("allergic_gluten", constant("child2"))), value(variable(("allergic_gluten", constant("child2"))), true)).
initialState(variable(("allergic_gluten", constant("child3"))), value(variable(("allergic_gluten", constant("child3"))), true)).
initialState(variable(("allergic_gluten", constant("child16"))), value(variable(("allergic_gluten", constant("child16"))), true)).
initialState(variable(("allergic_gluten", constant("child5"))), value(variable(("allergic_gluten", constant("child5"))), true)).
initialState(variable(("allergic_gluten", constant("child6"))), value(variable(("allergic_gluten", constant("child6"))), true)).
initialState(variable(("allergic_gluten", constant("child11"))), value(variable(("allergic_gluten", constant("child11"))), true)).
initialState(variable(("not_allergic_gluten", constant("child12"))), value(variable(("not_allergic_gluten", constant("child12"))), true)).
initialState(variable(("not_allergic_gluten", constant("child1"))), value(variable(("not_allergic_gluten", constant("child1"))), true)).
initialState(variable(("not_allergic_gluten", constant("child10"))), value(variable(("not_allergic_gluten", constant("child10"))), true)).
initialState(variable(("not_allergic_gluten", constant("child4"))), value(variable(("not_allergic_gluten", constant("child4"))), true)).
initialState(variable(("not_allergic_gluten", constant("child14"))), value(variable(("not_allergic_gluten", constant("child14"))), true)).
initialState(variable(("not_allergic_gluten", constant("child7"))), value(variable(("not_allergic_gluten", constant("child7"))), true)).
initialState(variable(("not_allergic_gluten", constant("child8"))), value(variable(("not_allergic_gluten", constant("child8"))), true)).
initialState(variable(("not_allergic_gluten", constant("child9"))), value(variable(("not_allergic_gluten", constant("child9"))), true)).
initialState(variable(("not_allergic_gluten", constant("child15"))), value(variable(("not_allergic_gluten", constant("child15"))), true)).
initialState(variable(("not_allergic_gluten", constant("child13"))), value(variable(("not_allergic_gluten", constant("child13"))), true)).
initialState(variable(("waiting", constant("child1"), constant("table1"))), value(variable(("waiting", constant("child1"), constant("table1"))), true)).
initialState(variable(("waiting", constant("child2"), constant("table2"))), value(variable(("waiting", constant("child2"), constant("table2"))), true)).
initialState(variable(("waiting", constant("child3"), constant("table2"))), value(variable(("waiting", constant("child3"), constant("table2"))), true)).
initialState(variable(("waiting", constant("child4"), constant("table1"))), value(variable(("waiting", constant("child4"), constant("table1"))), true)).
initialState(variable(("waiting", constant("child5"), constant("table2"))), value(variable(("waiting", constant("child5"), constant("table2"))), true)).
initialState(variable(("waiting", constant("child6"), constant("table1"))), value(variable(("waiting", constant("child6"), constant("table1"))), true)).
initialState(variable(("waiting", constant("child7"), constant("table1"))), value(variable(("waiting", constant("child7"), constant("table1"))), true)).
initialState(variable(("waiting", constant("child8"), constant("table3"))), value(variable(("waiting", constant("child8"), constant("table3"))), true)).
initialState(variable(("waiting", constant("child9"), constant("table3"))), value(variable(("waiting", constant("child9"), constant("table3"))), true)).
initialState(variable(("waiting", constant("child10"), constant("table2"))), value(variable(("waiting", constant("child10"), constant("table2"))), true)).
initialState(variable(("waiting", constant("child11"), constant("table3"))), value(variable(("waiting", constant("child11"), constant("table3"))), true)).
initialState(variable(("waiting", constant("child12"), constant("table2"))), value(variable(("waiting", constant("child12"), constant("table2"))), true)).
initialState(variable(("waiting", constant("child13"), constant("table2"))), value(variable(("waiting", constant("child13"), constant("table2"))), true)).
initialState(variable(("waiting", constant("child14"), constant("table2"))), value(variable(("waiting", constant("child14"), constant("table2"))), true)).
initialState(variable(("waiting", constant("child15"), constant("table2"))), value(variable(("waiting", constant("child15"), constant("table2"))), true)).
initialState(variable(("waiting", constant("child16"), constant("table3"))), value(variable(("waiting", constant("child16"), constant("table3"))), true)).
initialState(variable(("notexist", constant("sandw1"))), value(variable(("notexist", constant("sandw1"))), true)).
initialState(variable(("notexist", constant("sandw2"))), value(variable(("notexist", constant("sandw2"))), true)).
initialState(variable(("notexist", constant("sandw3"))), value(variable(("notexist", constant("sandw3"))), true)).
initialState(variable(("notexist", constant("sandw4"))), value(variable(("notexist", constant("sandw4"))), true)).
initialState(variable(("notexist", constant("sandw5"))), value(variable(("notexist", constant("sandw5"))), true)).
initialState(variable(("notexist", constant("sandw6"))), value(variable(("notexist", constant("sandw6"))), true)).
initialState(variable(("notexist", constant("sandw7"))), value(variable(("notexist", constant("sandw7"))), true)).
initialState(variable(("notexist", constant("sandw8"))), value(variable(("notexist", constant("sandw8"))), true)).
initialState(variable(("notexist", constant("sandw9"))), value(variable(("notexist", constant("sandw9"))), true)).
initialState(variable(("notexist", constant("sandw10"))), value(variable(("notexist", constant("sandw10"))), true)).
initialState(variable(("notexist", constant("sandw11"))), value(variable(("notexist", constant("sandw11"))), true)).
initialState(variable(("notexist", constant("sandw12"))), value(variable(("notexist", constant("sandw12"))), true)).
initialState(variable(("notexist", constant("sandw13"))), value(variable(("notexist", constant("sandw13"))), true)).
initialState(variable(("notexist", constant("sandw14"))), value(variable(("notexist", constant("sandw14"))), true)).
initialState(variable(("notexist", constant("sandw15"))), value(variable(("notexist", constant("sandw15"))), true)).
initialState(variable(("notexist", constant("sandw16"))), value(variable(("notexist", constant("sandw16"))), true)).
initialState(variable(("notexist", constant("sandw17"))), value(variable(("notexist", constant("sandw17"))), true)).
initialState(variable(("notexist", constant("sandw18"))), value(variable(("notexist", constant("sandw18"))), true)).
initialState(variable(("notexist", constant("sandw19"))), value(variable(("notexist", constant("sandw19"))), true)).
initialState(variable(("notexist", constant("sandw20"))), value(variable(("notexist", constant("sandw20"))), true)).
initialState(variable(("notexist", constant("sandw21"))), value(variable(("notexist", constant("sandw21"))), true)).

initialState(X, value(X, false)) :- variable(X), not initialState(X, value(X, true)).

% goal
goal(variable(("served", constant("child1"))), value(variable(("served", constant("child1"))), true)).
goal(variable(("served", constant("child2"))), value(variable(("served", constant("child2"))), true)).
goal(variable(("served", constant("child3"))), value(variable(("served", constant("child3"))), true)).
goal(variable(("served", constant("child4"))), value(variable(("served", constant("child4"))), true)).
goal(variable(("served", constant("child5"))), value(variable(("served", constant("child5"))), true)).
goal(variable(("served", constant("child6"))), value(variable(("served", constant("child6"))), true)).
goal(variable(("served", constant("child7"))), value(variable(("served", constant("child7"))), true)).
goal(variable(("served", constant("child8"))), value(variable(("served", constant("child8"))), true)).
goal(variable(("served", constant("child9"))), value(variable(("served", constant("child9"))), true)).
goal(variable(("served", constant("child10"))), value(variable(("served", constant("child10"))), true)).
goal(variable(("served", constant("child11"))), value(variable(("served", constant("child11"))), true)).
goal(variable(("served", constant("child12"))), value(variable(("served", constant("child12"))), true)).
goal(variable(("served", constant("child13"))), value(variable(("served", constant("child13"))), true)).
goal(variable(("served", constant("child14"))), value(variable(("served", constant("child14"))), true)).
goal(variable(("served", constant("child15"))), value(variable(("served", constant("child15"))), true)).
goal(variable(("served", constant("child16"))), value(variable(("served", constant("child16"))), true)).
