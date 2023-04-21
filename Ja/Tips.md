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

41. Kad treba da nadjem min or samo krenem da je 11111...1111 i onda skidam od najvec do najmanje bita      \
https://codeforces.com/contest/1624/problem/G 

42. Dobra fora sa segmentnim da ne radim ono sto sam ja radio    \
https://codeforces.com/problemset/problem/1621/E

43. Dobra zadataka sa medianom      \
https://codeforces.com/contest/1005/problem/E2

44. Meet in the middle - Meet in the middle is a search technique which is used when the input is small but not as small that brute force can be used. Like divide and conquer it splits the problem into two, solves them individually and then merge them. But we can’t apply meet in the middle like divide and conquer because we don’t have the same structure as the original problem. An easy (but I'm not sure if correct) way to distinguish them is that meet-in-the-middle is typically used to optimize a complete search. When you split the problem, ask yourself: "If the problem is the same for the two halves, and I can solve those halves by brute force, can I use those results to solve the full problem?". If the answer is yes, then it is DnC.       \
https://codeforces.com/contest/1006/problem/F

45. Dijkstra with negative weights - mora nesto sa potencijalnima da se gleda otprilike gledas da nema negativnih pa dodas nesto ili uocis na kraju koliko treba da dodas        \
https://atcoder.jp/contests/abc237/tasks/abc237_e

46. Boruvka's algorithm - mst algoritam veoma dobar stvar     \
(https://codeforces.com/problemset/problem/888/G)

47. O(n^(3/2)) ovaj zadatak bi trebao da bude common    \
https://codeforces.com/problemset/problem/425/D   \
https://codeforces.com/blog/entry/11998?#comment-167207

48. The ideas presented here are in two dimensions, but can be extended to further dimensions.  Each additional dimension requires double the amount of computations on each point.  For example, in 3-D space, the result is the maximum difference between the four extrema pairs computed from x+y+z, x+y-z, x-y+z, and x-y-z. (https://www.geeksforgeeks.org/maximum-manhattan-distance-between-a-distinct-pair-from-n-coordinates/#:~:text=Given%20an%20array%20arr%5B%5D,%2B%20%7CY1%20%E2%80%93%20Y2%7C)    https://codeforces.com/contest/1093/problem/G

49. Paziti na mod sa negativnim brojevima i njihovo sabiranje i oduzimanje     \
https://atcoder.jp/contests/abc151/tasks/abc151_e

50. Virtual edge     \
https://atcoder.jp/contests/abc184/tasks/abc184_e

51. Ako ti nekad treba longest distanc in weighted graph, mozes samo da negiras sve tezine na ivicama i radis shortest path  \  
https://atcoder.jp/contests/abc137/tasks/abc137_e

52. Distanca izmedju dva prosta broja je mala     \
https://codeforces.com/contest/584/problem/D

53. Primetiti kako izlgeda optimalni rezultat       \
https://codeforces.com/group/EO1Eu2qKmY/contest/370830/problem/C

54. Kad imam dva set-a i hocu da izracunam gcd svaka dva para. Najveci broj razlicith gcd-ova je sqrt(N) tako da samo cuvam count i radim sa tip po porovima    \
https://www.codechef.com/LTIME105A/problems/COOKPERM

55. Ima dosta zadataka sa Dirihleovim princip sa bitovima         \
https://www.codechef.com/problems/NANDXOR

56. Mozemo i segmente da drzimo kod upita i da ih brisem veoma dobar trik, veoma dobar dokaz za slozenost   \ 
https://codeforces.com/contest/1638/problem/E

57. Dodavanje segmenata razlicite boje kveriji (gledati samo see), moze se koristiti i kod online unije segmenata   \
https://codeforces.com/contest/1638/submission/149005412

58. Zadatke sa bojenjem uvek gledati otpozadi     \
https://codeforces.com/contest/1638/problem/D

59. Gledati nekad da li moze komplement resenju da izracuna lakse pa oduzeti od ukupno nacina   \
http://usaco.org/index.php?page=viewproblem2&cpid=791

60. Za bojenje UVEK mora da bude bar jedan segment K duzine koji je obojen, ostalo moze kako hoce    \
http://usaco.org/index.php?page=viewproblem2&cpid=791

61. Za svaki nivo segmentnog kada radimo lazy mozemo biti na najvise 4 cvora     \
https://codeforces.com/blog/entry/8864?#comment-145866

62. Maximalna duzina u graph-u izmedju dva cvora je N - 1    \
https://atcoder.jp/contests/abc218/tasks/abc218_f

63. Kad radimo walk na segmentnon ako hocemo da nadjemo najvecu poziciju za koju vazi, uveke cemo ispisivati tl - 1, e sad to znaci da moram da gledamo segmentnon na range-u [1, n + 1], kako bi n nekad moglo da bude resenj         \
https://codeforces.com/problemset/problem/1236/E

64. Kada gledamo neki shortest path sa bfs-om, na nekom layeru nam se mozda jave cvorovi u koje nikad necemo uci i njih mozemo da ignorisemo i samim tim smanjimo slozenost         \
https://codeforces.com/contest/1612/problem/F

65. Ako treba da vidimo da li C deli svaki element niza, dovoljno je samo da deli njihov gcd    \
https://codeforces.com/contest/1798/problem/C
