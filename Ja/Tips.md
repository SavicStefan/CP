# Tips
1. nisam gledao kad nesto dodam koliko to doprinosi resenju	  	  
https://codeforces.com/problemset/problem/1238/E

2. nisam uvideo kako mozemo jednu dimeziju dp "eskivirati", ondosno kako mi utice na resenje, obicno bude neki sort (barem sam taj slucaj jedini vidjao) \
https://codeforces.com/problemset/problem/1316/E \
https://codeforces.com/problemset/problem/1437/C

3. uvek napisi zadatak u matematickom obliku sta se trazi mozda pomogne \
https://codeforces.com/contest/847/problem/D

4. gledati kako ono sto traze moze da se napise ili protumaci drugacije \
https://codeforces.com/contest/847/problem/D

5. x je period string-a s akko: s[i] = s[i + x], za i iz [1, |s| - x] <-> 
s[i ... |s| - x] == s[i + x ... |s|] 

6. x mod p, ili broj ostaje isti ili ga smanjuje za bar pola \
	r = x mod p     \
	x = kp + r     \
	k = 0 -> x = x mod p     \
 	k != 0 -> x mod p = r = 2r / r < (p + r) / 2 <= (kp + r) / 2 <= x / 2 

7. malo se vise udubiti u slozenost nekad \
https://codeforces.com/contest/786/problem/C

8. nisam proctio koliko query-a se pravi, od kog tipa \
https://codeforces.com/contest/707/problem/E

9. inline trick, ne znam kako radi, ali samo staviti __attribute__((always_inline)) na pocetak funckije \
https://codeforces.com/contest/1000/problem/F

10. ako treba nekada da izbrojimo koliko ima necega sa nekom osobinom, gledati koliko nema sa tom osobinom pa oduzeti od ukupno \
https://codeforces.com/problemset/problem/369/E

11. ne mora samo SQRT biti da delim niz na blokove, moze i batching, a i da nesto delimo u zadatku na light i heavy, i preko toga da radimo (ovo je cak i najtezi tip SQRT po meni) \
https://codeforces.com/contest/348/problem/C  \
https://codeforces.com/contest/506/problem/D

12. trick kod D&C \
https://codeforces.com/problemset/problem/834/D

13. parallel binary search moze kao preko rekurzije, a moze i kao u blogu \
https://oj.uz/problem/view/IZhO18_plan  \
https://www.spoj.com/problems/METEORS/

14. ako hocemo da dodamo edges od v do [l, r] ili obrnuto mozemo sa segmentnim \
https://robert1003.github.io/2020/02/14/graphs-and-segment-tree.html  \
https://codeforces.com/contest/787/problem/D

15. nekad greedy gledati samo naprimer sta ako ovo koristim A puta, i prema tome praviti resenje \
http://codeforces.com/contest/799/problem/E

16. opcije (treba malo bolje pogledati) \
https://codeforces.com/contest/867/problem/E

17. gledati kad bi nesto menjao naivno koliko operacija napravim  \
https://oj.uz/problem/view/POI13_kon

18. gledati koliko cu naprimer taj broj updejtovati ili deliti i videti da nije mnogo i da moze naivno sa optimizacijom \
https://oj.uz/problem/view/JOI15_sterilizing

19. value for greatest common divisor in case if it decreases becomes at most half of the previous value \ 
https://codeforces.com/contest/475/problem/D	

20. gledati nekad koliko max i min necega, i probati sa tim smanjiti slozenost ili neki dp omoguciti \
https://atcoder.jp/contests/abc164/tasks/abc164_e

21. u stablu moze biti jedan ili dva centroida, ako ima dva oni su povezani \
https://codeforces.com/problemset/problem/1406/C

22. 0-1 bfs \
https://codeforces.com/problemset/problem/1063/B

23. Dfs tree undirected graph je stablo koje ima ili nema dodatne ivice koje spajaju cvor sa njegovi pretkom \
https://codeforces.com/problemset/problem/263/D

24. Ako hocu distance u directed graphu samo idem sve dok je d[u] > d[v] + 1 \
https://codeforces.com/problemset/problem/1320/B  \
https://atcoder.jp/contests/abc132/tasks/abc132_e

25. Mogu ici i od nazad u directed graph-u \
https://codeforces.com/problemset/problem/721/C

26. find x than minimize this sum |x - ai|, x = median of a \
https://atcoder.jp/contests/abc127/tasks/abc127_f

27. za najdalji cvor od x je jedan od krajeva diametra tog stabla (kvalifikacije1_2022_5)

28. gledati upper bound resenja \
https://codeforces.com/problemset/problem/1307/D

29. Izaberi dva puta koja se ne seku da im je proizvod najveci \
https://codeforces.com/contest/14/problem/D

30.  There is theorem that a graph admits an orientation to a strongly connected digraph if and only if every edge is part of what a cycle. To znaci i da ako graph nema bridges, svaki cvor pripada barem jednom cycle      \
https://codeforces.com/problemset/problem/118/E

31. Ternary for integers (f-ja mora biti prvo striktno rastuca pa striktno opadajuca ili obrnuto)                         \
https://codeforces.com/blog/entry/52010?#comment-360867        
https://codeforces.com/blog/entry/11497

32. Podeliti zadatak na pola       \
https://codeforces.com/problemset/problem/888/E

33. Kad je bitan redosled izabranih obicno ide DP + bitmask, je l gledam i za svaki moguci redosled          \
https://codeforces.com/contest/1185/problem/G1

34. Dato je n tacaka nadji najamanju euklidsku distancu izmadju dve razlicite tacke        \
http://people.csail.mit.edu/indyk/6.838-old/handouts/lec17.pdf         \
https://codeforces.com/problemset/problem/429/D

35. Broj manjih na intervalu (ordered_set + Fenwick)        \
https://codeforces.com/problemset/problem/785/E

36. Dobra primena persisent        \
https://codeforces.com/problemset/problem/893/F

37. Kako povezivati graph pomocu segmentnog stabla       \
https://codeforces.com/problemset/problem/786/B 

38. M^x * M^y = M^(x + y), gde je M matrica     \
https://codeforces.com/problemset/problem/718/C

39. Pazi na negativne brojeve sa mod-om      \
https://codeforces.com/problemset/problem/316/E2

40. Resenje za problem D    \
https://codeforces.com/blog/entry/99031

41. Kad treba da nadjem min or samo krenem da je 11111.1111 i onda skidam od najvec do najmanje bita      \
https://codeforces.com/contest/1624/problem/G 
