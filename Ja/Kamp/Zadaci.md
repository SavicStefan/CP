1. COI 16 Dijamant, resio sam ga, ali moze bolje sa bitset-om nisam video, kad god treba nesto da se gleda da li neko 
ima i da se uporedjuje sa drugima, vrv je bitset. \
https://oj.uz/problem/view/COI16_dijament

2. Ako bi treba gcd razlike $\gcd{\lvert A[i] - A[j]\rvert }$ za $1 \le i, j \le n$, izgleda da mogu ne moram da ih sortiram pa da gledam susedne, nego mogu samo susedne ne zavisno u kom su odnosnu $\implies$ $\gcd{\lvert A[i] - A[i + 1]\rvert }$ za $1 \le i \le n$ 

3. Ovde trebalo da hesujem stablo da vidim da li su dva pod stabla jednaka, to cemo da radimo tako sto koristimo duzinu do leaf-a, odnsono leaf ce da ima vrednost p, a onda cemo svaki put da dizemo to na q, kad dodamo je na predak,
i tako dobijamo: hsh[v] = p, hsh[v] += hsh[u]^q    \
https://codeforces.com/contest/1800/problem/G
