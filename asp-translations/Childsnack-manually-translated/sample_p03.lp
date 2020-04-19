#const steps=4.

%objects
child(child1; child2; child3).
bread_portion(bread1; bread2; bread3).
content_portion(content1; content2; content3).
tray(tray1; tray2).
place(kitchen; table1; table2).
sandwich(sandw1; sandw2; sandw3).

%predicates
no_gluten_bread(bread1).
no_gluten_content(content1).
allergic_gluten(child2).
not_allergic_gluten(child1).
not_allergic_gluten(child3).

%init
at(tray1, kitchen, 0).
at(tray2, kitchen, 0).
at_kitchen_bread(bread1, 0).
at_kitchen_bread(bread2, 0).
at_kitchen_bread(bread3, 0).
at_kitchen_content(content1, 0).
at_kitchen_content(content2, 0).
at_kitchen_content(content3, 0).
waiting(child1, table1, 0).
waiting(child2, table2, 0).
waiting(child3, table1, 0).
notexist(sandw1, 0).
notexist(sandw2, 0).
notexist(sandw3, 0).

%goal
goal(T):- time(T),
	served(child1, T),
	served(child2, T),
	served(child3, T).
