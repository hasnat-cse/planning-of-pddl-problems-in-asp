#const steps=4.

%objects
child(child1; child2; child3; child4; child5; child6; child7; child8; child9; child10; child11; child12; child13; child14; child15; child16; child17; child18; child19).
bread_portion(bread1; bread2; bread3; bread4; bread5; bread6; bread7; bread8; bread9; bread10; bread11; bread12; bread13; bread14; bread15; bread16; bread17; bread18; bread19).
content_portion(content1; content2; content3; content4; content5; content6; content7; content8; content9; content10; content11; content12; content13; content14; content15; content16; content17; content18; content19).
tray(tray1; tray2; tray3; tray4).
place(kitchen; table1; table2; table3).
sandwich(sandw1; sandw2; sandw3; sandw4; sandw5; sandw6; sandw6; sandw7; sandw8; sandw9; sandw10; sandw11; sandw12; sandw13; sandw14; sandw15; sandw16; sandw17; sandw18; sandw19; sandw20; sandw21; sandw22; sandw23; sandw24; sandw25).

%predicates
no_gluten_bread(bread12).
no_gluten_bread(bread4).
no_gluten_bread(bread17).
no_gluten_bread(bread15).
no_gluten_bread(bread8).
no_gluten_bread(bread10).
no_gluten_bread(bread3).
no_gluten_content(content5).
no_gluten_content(content6).
no_gluten_content(content12).
no_gluten_content(content4).
no_gluten_content(content15).
no_gluten_content(content1).
no_gluten_content(content3).
allergic_gluten(child2).
allergic_gluten(child5).
allergic_gluten(child14).
allergic_gluten(child7).
allergic_gluten(child8).
allergic_gluten(child9).
allergic_gluten(child6).
not_allergic_gluten(child12).
not_allergic_gluten(child1).
not_allergic_gluten(child10).
not_allergic_gluten(child3).
not_allergic_gluten(child4).
not_allergic_gluten(child17).
not_allergic_gluten(child15).
not_allergic_gluten(child13).
not_allergic_gluten(child18).
not_allergic_gluten(child19).
not_allergic_gluten(child11).
not_allergic_gluten(child16).


%init
at(tray1, kitchen, 0).
at(tray2, kitchen, 0).
at(tray3, kitchen, 0).
at(tray4, kitchen, 0).
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
at_kitchen_bread(bread11, 0).
at_kitchen_bread(bread12, 0).
at_kitchen_bread(bread13, 0).
at_kitchen_bread(bread14, 0).
at_kitchen_bread(bread15, 0).
at_kitchen_bread(bread16, 0).
at_kitchen_bread(bread17, 0).
at_kitchen_bread(bread18, 0).
at_kitchen_bread(bread19, 0).
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
at_kitchen_content(content11, 0).
at_kitchen_content(content12, 0).
at_kitchen_content(content13, 0).
at_kitchen_content(content14, 0).
at_kitchen_content(content15, 0).
at_kitchen_content(content16, 0).
at_kitchen_content(content17, 0).
at_kitchen_content(content18, 0).
at_kitchen_content(content19, 0).
waiting(child1, table1, 0).
waiting(child2, table2, 0).
waiting(child3, table1, 0).
waiting(child4, table1, 0).
waiting(child5, table3, 0).
waiting(child6, table3, 0).
waiting(child7, table2, 0).
waiting(child8, table3, 0).
waiting(child9, table2, 0).
waiting(child10, table2, 0).
waiting(child11, table2, 0).
waiting(child12, table2, 0).
waiting(child13, table3, 0).
waiting(child14, table1, 0).
waiting(child15, table2, 0).
waiting(child16, table2, 0).
waiting(child17, table2, 0).
waiting(child18, table1, 0).
waiting(child19, table3, 0).
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
notexist(sandw14, 0).
notexist(sandw15, 0).
notexist(sandw16, 0).
notexist(sandw17, 0).
notexist(sandw18, 0).
notexist(sandw19, 0).
notexist(sandw20, 0).
notexist(sandw21, 0).
notexist(sandw22, 0).
notexist(sandw23, 0).
notexist(sandw24, 0).
notexist(sandw25, 0).


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
	served(child10, T),
	served(child11, T),
	served(child12, T),
	served(child13, T),
	served(child14, T),
	served(child15, T),
	served(child16, T),
	served(child17, T),
	served(child18, T),
	served(child19, T).

