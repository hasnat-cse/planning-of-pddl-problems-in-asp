% IPC8 Domain: Childsnack

% Non conflicting Parallel actions are allowed

#show make_sandwich_no_gluten/4.
#show make_sandwich/4.
#show put_on_tray/3.
#show serve_sandwich_no_gluten/5.
#show serve_sandwich/5.
#show move_tray/4.



time(0..steps).

% actions
{make_sandwich_no_gluten(S,B,C,T)} :-
        sandwich(S), bread_portion(B), content_portion(C), time(T),
        at_kitchen_bread(B,T),
        at_kitchen_content(C,T),
	no_gluten_bread(B),
	no_gluten_content(C),
	notexist(S,T),
        not goal(T).

{make_sandwich(S,B,C,T)} :-
        sandwich(S), bread_portion(B), content_portion(C), time(T),
        at_kitchen_bread(B,T),
        at_kitchen_content(C,T),
	notexist(S,T),
        not goal(T).

{put_on_tray(S,Tr,T)} :-
	sandwich(S), tray(Tr), time(T),
	at_kitchen_sandwich(S,T),
	at(Tr,kitchen,T),
	not tray_moving(Tr,T),
	not goal(T).

{serve_sandwich_no_gluten(S,C,Tr,P,T)} :-
	sandwich(S), child(C), tray(Tr), place(P), time(T),
	allergic_gluten(C),
	ontray(S,Tr,T),
	waiting(C,P,T),
	no_gluten_sandwich(S,T),
	at(Tr,P,T),
	not tray_moving(Tr,T),
	not goal(T).

{serve_sandwich(S,C,Tr,P,T)} :-
	sandwich(S), child(C), tray(Tr), place(P), time(T),
	not_allergic_gluten(C),
	ontray(S,Tr,T),
	waiting(C,P,T),
	at(Tr,P,T),
	not tray_moving(Tr,T),
	not goal(T).


{move_tray(Tr,P1,P2,T)} :-
	tray(Tr), place(P1), place(P2), time(T),
	at(Tr,P1,T),
	not goal(T).


%auxiliary predicates		
sandwich_made_with_bread(B,T):-
	bread_portion(B), time(T),
	make_sandwich_no_gluten(S,B,C,T).

sandwich_made_with_bread(B,T):-
	bread_portion(B), time(T),
	make_sandwich(S,B,C,T).


sandwich_made_with_content(C,T):-
	content_portion(C), time(T),
	make_sandwich_no_gluten(S,B,C,T).

sandwich_made_with_content(C,T):-
	content_portion(C), time(T),
	make_sandwich(S,B,C,T).


sandwich_made(S,T):-
	sandwich(S), time(T),
	make_sandwich_no_gluten(S,B,C,T).

sandwich_made(S,T):-
	sandwich(S), time(T),
	make_sandwich(S,B,C,T).


sandwich_put_on_tray(S,T):-
	sandwich(S), time(T),
	put_on_tray(S,Tr,T).


sandwich_served(S,T):-
	sandwich(S), time(T),
	serve_sandwich_no_gluten(S,C,Tr,P,T).


sandwich_served(S,T):-
	sandwich(S), time(T),
	serve_sandwich(S,C,Tr,P,T).
	
tray_moving(Tr,T):-
	tray(Tr), time(T),
	move_tray(Tr,P1,P2,T).
	


%fluents
at_kitchen_sandwich(S,T+1):-
	sandwich(S), time(T),
	notexist(S,T),
	make_sandwich_no_gluten(S,B,C,T).

no_gluten_sandwich(S,T+1):-
	sandwich(S), time(T),
	notexist(S,T),
	make_sandwich_no_gluten(S,B,C,T).


at_kitchen_sandwich(S,T+1):-
	sandwich(S), time(T),
	notexist(S,T),
	make_sandwich(S,B,C,T).


ontray(S,Tr,T+1):-
	sandwich(S), tray(Tr), time(T),
	at_kitchen_sandwich(S,T),
	put_on_tray(S,Tr,T).


served(C,T+1):-
	child(C), time(T),
	waiting(C,P,T),
	serve_sandwich_no_gluten(S,C,Tr,P,T).


served(C,T+1):-
	child(C), time(T),
	waiting(C,P,T),
	serve_sandwich(S,C,Tr,P,T).


at(Tr,P2,T+1):-
	tray(Tr), place(P2), time(T),
	at(Tr,P1,T),
	move_tray(Tr,P1,P2,T).



%frame axioms
at_kitchen_bread(B,T+1):-
	bread_portion(B), time(T),
	at_kitchen_bread(B,T),
	not sandwich_made_with_bread(B,T).

at_kitchen_content(C,T+1):-
	content_portion(C), time(T),
	at_kitchen_content(C,T),
	not sandwich_made_with_content(C,T).

notexist(S,T+1):-
	sandwich(S), time(T),
	notexist(S,T),
	not sandwich_made(S,T).


at_kitchen_sandwich(S,T+1):-
	sandwich(S), time(T),
	at_kitchen_sandwich(S,T),
	not sandwich_put_on_tray(S,T).


ontray(S,Tr,T+1):-
	sandwich(S), tray(Tr), time(T),
	ontray(S,Tr,T),
	not sandwich_served(S,T).

waiting(C,P,T+1):-
	child(C), place(P), time(T),
	waiting(C,P,T),
	not sandwich_served(C,T).


at(Tr,P1,T+1):-
	tray(Tr), place(P1), time(T),
	at(Tr,P1,T),
	not tray_moving(Tr,T).



served(C,T+1):-
	child(C), time(T),
	served(C,T).

no_gluten_sandwich(S,T+1):-
	sandwich(S), time(T),
	no_gluten_sandwich(S,T).


%goal
goal(T+1):-  time(T), goal(T).

goal :- time(T), goal(T).
:- not goal.


%constraints
% Same tray in two different places
:- tray(Tr), place(P1), place(P2), time(T), P1 != P2,
	at(Tr,P1,T), at(Tr,P2,T).

% Same sandwich on two different trays
:- sandwich(S), tray(Tr1), tray(Tr2), time(T), Tr1 != Tr2,
	ontray(S,Tr1,T), ontray(S,Tr2,T).

% Different sandwiches with same bread_portion
:- sandwich(S1), sandwich(S2), bread_portion(B), time(T), S1 != S2,
	make_sandwich(S1,B,_,T), make_sandwich(S2,B,_,T).

:- sandwich(S1), sandwich(S2), bread_portion(B), time(T), S1 != S2,
	make_sandwich_no_gluten(S1,B,_,T), make_sandwich(S2,B,_,T).

:- sandwich(S1), sandwich(S2), bread_portion(B), time(T), S1 != S2,
	make_sandwich_no_gluten(S1,B,_,T), make_sandwich_no_gluten(S2,B,_,T).


% Different sandwiches with same content_portion
:- sandwich(S1), sandwich(S2), content_portion(C), time(T), S1 != S2,
	make_sandwich(S1,_,C,T), make_sandwich(S2,_,C,T).

:- sandwich(S1), sandwich(S2), content_portion(C), time(T), S1 != S2,
	make_sandwich_no_gluten(S1,_,C,T), make_sandwich_no_gluten(S2,_,C,T).

:- sandwich(S1), sandwich(S2), content_portion(C), time(T), S1 != S2,
	make_sandwich_no_gluten(S1,_,C,T), make_sandwich(S2,_,C,T).


% Same sandwich both gluten and no_gluten version
:- sandwich(S1), sandwich(S2), bread_portion(B), time(T), S1 == S2,
	make_sandwich_no_gluten(S1,_,_,T), make_sandwich(S2,_,_,T).


% Different sandwiches to same child
:- sandwich(S1), sandwich(S2), child(C), time(T), S1 != S2,
	serve_sandwich(S1,C,_,_,T), serve_sandwich(S2,C,_,_,T).

:- sandwich(S1), sandwich(S2), child(C), time(T), S1 != S2,
	serve_sandwich_no_gluten(S1,C,_,_,T), serve_sandwich_no_gluten(S2,C,_,_,T).

:- sandwich(S1), sandwich(S2), child(C), time(T), S1 != S2,
	serve_sandwich_no_gluten(S1,C,_,_,T), serve_sandwich(S2,C,_,_,T).


% Same sandwiches to different child
:- sandwich(S), child(C1), child(C2), time(T), C1 != C2,
	serve_sandwich(S,C1,_,_,T), serve_sandwich(S,C2,_,_,T).

:- sandwich(S), child(C1), child(C2), time(T), C1 != C2,
	serve_sandwich_no_gluten(S,C1,_,_,T), serve_sandwich_no_gluten(S,C2,_,_,T).

:- sandwich(S), child(C1), child(C2), time(T), C1 != C2,
	serve_sandwich_no_gluten(S,C1,_,_,T), serve_sandwich(S,C2,_,_,T).


