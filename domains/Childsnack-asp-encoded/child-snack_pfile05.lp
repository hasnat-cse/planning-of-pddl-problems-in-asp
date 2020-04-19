#const steps=4.

%objects
child(child1; child2; child3; child4; child5; child6; child7; child8; child9; child10).
bread_portion(bread1; bread2; bread3; bread4; bread5; bread6; bread7; bread8; bread9; bread10).
content_portion(content1; content2; content3; content4; content5; content6; content7; content8; content9; content10).
tray(tray1; tray2; tray3).
place(kitchen; table1; table2; table3).
sandwich(sandw1; sandw2; sandw3; sandw4; sandw5; sandw6; sandw6; sandw7; sandw8; sandw9; sandw10; sandw11; sandw12; sandw13).

%predicates
no_gluten_bread(bread6).
no_gluten_bread(bread2).
no_gluten_bread(bread8).
no_gluten_bread(bread7).
no_gluten_content(content5).
no_gluten_content(content6).
no_gluten_content(content2).
no_gluten_content(content8).
allergic_gluten(child9).
allergic_gluten(child2).
allergic_gluten(child3).
allergic_gluten(child7).
not_allergic_gluten(child1).
not_allergic_gluten(child10).
not_allergic_gluten(child4).
not_allergic_gluten(child5).
not_allergic_gluten(child6).
not_allergic_gluten(child8).


%init
at(tray1, kitchen, 0).
at(tray2, kitchen, 0).
at(tray3, kitchen, 0).
at_kitchen_bread(bread1, 0).
at_kitchen_bread(bread2, 0).
at_kitchen_bread(bread3, 0).
at_kitchen_bread(bread4, 0).
at_kitchen_bread(bread5, 0).
at_kitchen_bread(bread6, 0).
at_kitchen_bread(bread7, 0).
at_kitchen_bread(bread8, 0).
at_kitchen_bread(bread9, 0).
at_kitchen_bread(bread10, 0).
at_kitchen_content(content1, 0).
at_kitchen_content(content2, 0).
at_kitchen_content(content3, 0).
at_kitchen_content(content4, 0).
at_kitchen_content(content5, 0).
at_kitchen_content(content6, 0).
at_kitchen_content(content7, 0).
at_kitchen_content(content8, 0).
at_kitchen_content(content9, 0).
at_kitchen_content(content10, 0).
waiting(child1, table1, 0).
waiting(child2, table1, 0).
waiting(child3, table1, 0).
waiting(child4, table3, 0).
waiting(child5, table2, 0).
waiting(child6, table2, 0).
waiting(child7, table1, 0).
waiting(child8, table2, 0).
waiting(child9, table2, 0).
waiting(child10, table1, 0).
notexist(sandw1, 0).
notexist(sandw2, 0).
notexist(sandw3, 0).
notexist(sandw4, 0).
notexist(sandw5, 0).
notexist(sandw6, 0).
notexist(sandw7, 0).
notexist(sandw8, 0).
notexist(sandw9, 0).
notexist(sandw10, 0).
notexist(sandw11, 0).
notexist(sandw12, 0).
notexist(sandw13, 0).


%goal
goal(T):- time(T),
	served(child1, T),
	served(child2, T),
	served(child3, T),
	served(child4, T),
	served(child5, T),
	served(child6, T),
	served(child7, T),
	served(child8, T),
	served(child9, T),
	served(child10, T).

