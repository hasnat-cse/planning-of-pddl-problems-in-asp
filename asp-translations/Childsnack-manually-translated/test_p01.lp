#const steps=4.

%objects
child(child1).
bread_portion(bread1).
content_portion(content1).
tray(tray1).
place(kitchen; table1).
sandwich(sandw1).

%predicates
no_gluten_bread(bread1).
no_gluten_content(content1).
allergic_gluten(child1).

%init
at(tray1, kitchen, 0).
at_kitchen_bread(bread1, 0).
at_kitchen_content(content1, 0).
waiting(child1, table1, 0).
notexist(sandw1, 0).

%goal
goal(T):- time(T),
	served(child1, T).
