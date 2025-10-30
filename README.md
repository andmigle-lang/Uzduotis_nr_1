<pre>
Testavimo sistemos parametrai: 
  Processor:	11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz 2.42 GHz
  Installed RAM:	8.00 GB (7.73 GB usable)
  Storage:	238 GB SSD NVMe PC SN530 NVMe WDC 256GB
  System Type:	64-bit operating system, x64-based processor

1 Lentelė. Vector ir list efektyvumo tyrimas - vidutinis duomenų skaitymo iš failų greitis (vidurkiai iš 3 iteracijų)
------------------------------------------------------------------------------------------------------------
|                               |                                  Failo dydis                             |
|                               |--------------------------------------------------------------------------|
|                               |     1000     |     10000    |    100000    |    1000000   |   10000000   |
|-------------------------------|--------------|--------------|--------------|--------------|--------------|
|    Duomenų    |    Vector     | 0.00706697 s |  0.0349166 s |  0.230066 s  |   1.99499 s  |   19.5969 s  |
|    tipas      |---------------|--------------|--------------|--------------|--------------|--------------|
|               |     List      | 0.00658363 s |  0.0314788 s |  0.196846 s  |   1.97507 s  |   18.7698 s  |
------------------------------------------------------------------------------------------------------------

2 Lentelė. Vector ir list efektyvumo tyrimas - vidutinis duomenų rūšiavimo sort funkcija greitis (vidurkiai iš 3 iteracijų)
------------------------------------------------------------------------------------------------------------
|                               |                                  Failo dydis                             |
|                               |--------------------------------------------------------------------------|
|                               |     1000     |     10000    |    100000    |    1000000   |   10000000   |
|-------------------------------|--------------|--------------|--------------|--------------|--------------|
|    Duomenų    |    Vector     | 0.000223433 s| 0.00242663 s |  0.0286921 s |  0.169811 s  |    1.6163 s  |
|    tipas      |---------------|--------------|--------------|--------------|--------------|--------------|
|               |     List      | 0.0001681 s  | 0.0018494 s  |  0.0368933 s |  0.809427 s  |   13.6655 s  |
------------------------------------------------------------------------------------------------------------

3 Lentelė. Vector ir list efektyvumo tyrimas - vidutinis duomenų dalijimo (rūšiavimo) į dvi kategorijas greitis (vidurkiai iš 3 iteracijų)
------------------------------------------------------------------------------------------------------------
|                               |                                  Failo dydis                             |
|                               |--------------------------------------------------------------------------|
|                               |     1000     |     10000    |    100000    |    1000000   |   10000000   |
|-------------------------------|--------------|--------------|--------------|--------------|--------------|
|    Duomenų    |    Vector     | 0.000562267 s| 0.004866 s   |  0.050564 s  |  0.395736 s  |   5.13189 s  |
|    tipas      |---------------|--------------|--------------|--------------|--------------|--------------|
|               |     List      | 0.000684233 s| 0.00390743 s |  0.0463096 s |  0.470163 s  |   5.26054 s  |
------------------------------------------------------------------------------------------------------------

4 Lentelė. Vector ir list efektyvumo tyrimas - vidutinis duomenų įrašymo į vargšiukų failą greitis (vidurkiai iš 3 iteracijų)
------------------------------------------------------------------------------------------------------------
|                               |                                  Failo dydis                             |
|                               |--------------------------------------------------------------------------|
|                               |     1000     |     10000    |    100000    |    1000000   |   10000000   |
|-------------------------------|--------------|--------------|--------------|--------------|--------------|
|    Duomenų    |    Vector     |  0.0025461 s | 0.00862267 s |  0.0761669 s |   0.4879 s   |   5.12591 s  |
|    tipas      |---------------|--------------|--------------|--------------|--------------|--------------|
|               |     List      |  0.00281183 s| 0.00700453 s |  0.0635964 s |   0.570951 s |   5.04984 s  |
------------------------------------------------------------------------------------------------------------

5 Lentelė. Vector ir list efektyvumo tyrimas - vidutinis duomenų įrašymo į kietiakų failą greitis (vidurkiai iš 3 iteracijų)
------------------------------------------------------------------------------------------------------------
|                               |                                  Failo dydis                             |
|                               |--------------------------------------------------------------------------|
|                               |     1000     |     10000    |    100000    |    1000000   |   10000000   |
|-------------------------------|--------------|--------------|--------------|--------------|--------------|
|    Duomenų    |    Vector     | 0.00244277 s |  0.0147428 s |  0.0856534 s |  0.749151 s  |   7.61867 s  |
|    tipas      |---------------|--------------|--------------|--------------|--------------|--------------|
|               |     List      | 0.0029309 s  |  0.0103041 s |  0.100202 s  |  0.781466 s  |   7.66964 s  |
------------------------------------------------------------------------------------------------------------

Išvada: 
  
//Bandymas (išvestis konsolėje):
Ar norite dirbti su studentai.txt failais/rasyti duomenis rankomis/generuoti (rasyti 1), ar su generuotais failais (5 failai su nuo 1000 iki 10000000 studentu) (rasyti 2): 2
Jei failai jau sukurti, rasykite 1, o jei ne, tai rasykite 2: 1

Pasirinkite, pagal kuri parametra rusiuosite
(1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini pazymi): 3

Testavimas su vektoriais:

1 iteracija:

Failo is 1000 irasu nuskaitymo laikas: 0.0065757 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000
1000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0002098 s
1000 irasu dalijimo i dvi grupes laikas: 0.0002836 s
1000 irasu irasymo i vargsiuku faila laikas: 0.0027422 s
1000 irasu irasymo i kietiaku faila laikas: 0.0014856 s
Surusiuota studentu:
Vargsai (< 5.0): 415 studentai
Kietiakai (>= 5.0): 585 studentai
1000 irasu testo laikas: 0.0112969 s

Failo is 10000 irasu nuskaitymo laikas: 0.031842 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000
10000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0014353 s
10000 irasu dalijimo i dvi grupes laikas: 0.0027069 s
10000 irasu irasymo i vargsiuku faila laikas: 0.0073085 s
10000 irasu irasymo i kietiaku faila laikas: 0.0084108 s
Surusiuota studentu:
Vargsai (< 5.0): 4111 studentai
Kietiakai (>= 5.0): 5889 studentai
10000 irasu testo laikas: 0.0517035 s

Failo is 100000 irasu nuskaitymo laikas: 0.221974 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 100000
100000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0214443 s
100000 irasu dalijimo i dvi grupes laikas: 0.0476972 s
100000 irasu irasymo i vargsiuku faila laikas: 0.075648 s
100000 irasu irasymo i kietiaku faila laikas: 0.0880994 s
Surusiuota studentu:
Vargsai (< 5.0): 40881 studentai
Kietiakai (>= 5.0): 59119 studentai
100000 irasu testo laikas: 0.454863 s

Failo is 1000000 irasu nuskaitymo laikas: 2.01701 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000000
1000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.155534 s
1000000 irasu dalijimo i dvi grupes laikas: 0.392052 s
1000000 irasu irasymo i vargsiuku faila laikas: 0.516771 s
1000000 irasu irasymo i kietiaku faila laikas: 0.74773 s
Surusiuota studentu:
Vargsai (< 5.0): 411101 studentai
Kietiakai (>= 5.0): 588899 studentai
1000000 irasu testo laikas: 3.82909 s

Failo is 10000000 irasu nuskaitymo laikas: 19.6958 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000000
10000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 1.58807 s
10000000 irasu dalijimo i dvi grupes laikas: 5.03682 s
10000000 irasu irasymo i vargsiuku faila laikas: 4.86858 s
10000000 irasu irasymo i kietiaku faila laikas: 7.60622 s
Surusiuota studentu:
Vargsai (< 5.0): 4108815 studentai
Kietiakai (>= 5.0): 5891185 studentai
10000000 irasu testo laikas: 38.7954 s

2 iteracija:

Failo is 1000 irasu nuskaitymo laikas: 0.0054533 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000
1000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0002541 s
1000 irasu dalijimo i dvi grupes laikas: 0.0005705 s
1000 irasu irasymo i vargsiuku faila laikas: 0.0023734 s
1000 irasu irasymo i kietiaku faila laikas: 0.0041135 s
Surusiuota studentu:
Vargsai (< 5.0): 415 studentai
Kietiakai (>= 5.0): 585 studentai
1000 irasu testo laikas: 0.0127648 s

Failo is 10000 irasu nuskaitymo laikas: 0.0476898 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000
10000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0033544 s
10000 irasu dalijimo i dvi grupes laikas: 0.0073104 s
10000 irasu irasymo i vargsiuku faila laikas: 0.0115675 s
10000 irasu irasymo i kietiaku faila laikas: 0.0201785 s
Surusiuota studentu:
Vargsai (< 5.0): 4111 studentai
Kietiakai (>= 5.0): 5889 studentai
10000 irasu testo laikas: 0.0901006 s

Failo is 100000 irasu nuskaitymo laikas: 0.266863 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 100000
100000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0484311 s
100000 irasu dalijimo i dvi grupes laikas: 0.0654774 s
100000 irasu irasymo i vargsiuku faila laikas: 0.0692983 s
100000 irasu irasymo i kietiaku faila laikas: 0.0737623 s
Surusiuota studentu:
Vargsai (< 5.0): 40881 studentai
Kietiakai (>= 5.0): 59119 studentai
100000 irasu testo laikas: 0.523832 s

Failo is 1000000 irasu nuskaitymo laikas: 2.04068 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000000
1000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.180111 s
1000000 irasu dalijimo i dvi grupes laikas: 0.400046 s
1000000 irasu irasymo i vargsiuku faila laikas: 0.461353 s
1000000 irasu irasymo i kietiaku faila laikas: 0.736066 s
Surusiuota studentu:
Vargsai (< 5.0): 411101 studentai
Kietiakai (>= 5.0): 588899 studentai
1000000 irasu testo laikas: 3.81826 s

Failo is 10000000 irasu nuskaitymo laikas: 19.4937 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000000
10000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 1.6368 s
10000000 irasu dalijimo i dvi grupes laikas: 5.38956 s
10000000 irasu irasymo i vargsiuku faila laikas: 5.14903 s
10000000 irasu irasymo i kietiaku faila laikas: 7.30839 s
Surusiuota studentu:
Vargsai (< 5.0): 4108815 studentai
Kietiakai (>= 5.0): 5891185 studentai
10000000 irasu testo laikas: 38.9775 s

3 iteracija:

Failo is 1000 irasu nuskaitymo laikas: 0.0091719 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000
1000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0002064 s
1000 irasu dalijimo i dvi grupes laikas: 0.0008327 s
1000 irasu irasymo i vargsiuku faila laikas: 0.0025227 s
1000 irasu irasymo i kietiaku faila laikas: 0.0017292 s
Surusiuota studentu:
Vargsai (< 5.0): 415 studentai
Kietiakai (>= 5.0): 585 studentai
1000 irasu testo laikas: 0.0144629 s

Failo is 10000 irasu nuskaitymo laikas: 0.025218 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000
10000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0024902 s
10000 irasu dalijimo i dvi grupes laikas: 0.0045807 s
10000 irasu irasymo i vargsiuku faila laikas: 0.006992 s
10000 irasu irasymo i kietiaku faila laikas: 0.0156391 s
Surusiuota studentu:
Vargsai (< 5.0): 4111 studentai
Kietiakai (>= 5.0): 5889 studentai
10000 irasu testo laikas: 0.05492 s

Failo is 100000 irasu nuskaitymo laikas: 0.20136 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 100000
100000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.016201 s
100000 irasu dalijimo i dvi grupes laikas: 0.0385175 s
100000 irasu irasymo i vargsiuku faila laikas: 0.0835544 s
100000 irasu irasymo i kietiaku faila laikas: 0.0950984 s
Surusiuota studentu:
Vargsai (< 5.0): 40881 studentai
Kietiakai (>= 5.0): 59119 studentai
100000 irasu testo laikas: 0.434731 s

Failo is 1000000 irasu nuskaitymo laikas: 1.92728 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000000
1000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.17379 s
1000000 irasu dalijimo i dvi grupes laikas: 0.395109 s
1000000 irasu irasymo i vargsiuku faila laikas: 0.485576 s
1000000 irasu irasymo i kietiaku faila laikas: 0.763656 s
Surusiuota studentu:
Vargsai (< 5.0): 411101 studentai
Kietiakai (>= 5.0): 588899 studentai
1000000 irasu testo laikas: 3.74541 s

Failo is 10000000 irasu nuskaitymo laikas: 19.6012 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000000
10000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 1.62402 s
10000000 irasu dalijimo i dvi grupes laikas: 4.9693 s
10000000 irasu irasymo i vargsiuku faila laikas: 5.36013 s
10000000 irasu irasymo i kietiaku faila laikas: 7.9414 s
Surusiuota studentu:
Vargsai (< 5.0): 4108815 studentai
Kietiakai (>= 5.0): 5891185 studentai
10000000 irasu testo laikas: 39.4961 s

VIDURKIAI IS 3 ITERACIJU:

Failo dydis: 1000
Skaitymo vidurkis: 0.00706697 s
Rusiavimo vidurkis: 0.000223433 s
Dalijimo vidurkis: 0.000562267 s
Vargsiuku irasymo vidurkis: 0.0025461 s
Kietiaku irasymo vidurkis: 0.00244277 s

Failo dydis: 10000
Skaitymo vidurkis: 0.0349166 s
Rusiavimo vidurkis: 0.00242663 s
Dalijimo vidurkis: 0.004866 s
Vargsiuku irasymo vidurkis: 0.00862267 s
Kietiaku irasymo vidurkis: 0.0147428 s

Failo dydis: 100000
Skaitymo vidurkis: 0.230066 s
Rusiavimo vidurkis: 0.0286921 s
Dalijimo vidurkis: 0.050564 s
Vargsiuku irasymo vidurkis: 0.0761669 s
Kietiaku irasymo vidurkis: 0.0856534 s

Failo dydis: 1000000
Skaitymo vidurkis: 1.99499 s
Rusiavimo vidurkis: 0.169811 s
Dalijimo vidurkis: 0.395736 s
Vargsiuku irasymo vidurkis: 0.4879 s
Kietiaku irasymo vidurkis: 0.749151 s

Failo dydis: 10000000
Skaitymo vidurkis: 19.5969 s
Rusiavimo vidurkis: 1.6163 s
Dalijimo vidurkis: 5.13189 s
Vargsiuku irasymo vidurkis: 5.12591 s
Kietiaku irasymo vidurkis: 7.61867 s

Testavimas su list'ais:

1 iteracija:

Failo is 1000 irasu nuskaitymo laikas: 0.0069963 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000
1000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0001575 s
1000 irasu dalijimo i dvi grupes laikas: 0.0007131 s
1000 irasu irasymo i vargsiuku faila laikas: 0.0022892 s
1000 irasu irasymo i kietiaku faila laikas: 0.0024992 s
Surusiuota studentu:
Vargsai (< 5.0): 415 studentai
Kietiakai (>= 5.0): 585 studentai
1000 irasu testo laikas: 0.0126553 s

Failo is 10000 irasu nuskaitymo laikas: 0.0327439 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000
10000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0024916 s
10000 irasu dalijimo i dvi grupes laikas: 0.004813 s
10000 irasu irasymo i vargsiuku faila laikas: 0.0066683 s
10000 irasu irasymo i kietiaku faila laikas: 0.0079985 s
Surusiuota studentu:
Vargsai (< 5.0): 4111 studentai
Kietiakai (>= 5.0): 5889 studentai
10000 irasu testo laikas: 0.0547153 s

Failo is 100000 irasu nuskaitymo laikas: 0.204956 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 100000
100000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0367995 s
100000 irasu dalijimo i dvi grupes laikas: 0.0498191 s
100000 irasu irasymo i vargsiuku faila laikas: 0.0541914 s
100000 irasu irasymo i kietiaku faila laikas: 0.0807393 s
Surusiuota studentu:
Vargsai (< 5.0): 40881 studentai
Kietiakai (>= 5.0): 59119 studentai
100000 irasu testo laikas: 0.426505 s

Failo is 1000000 irasu nuskaitymo laikas: 1.9106 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000000
1000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.825012 s
1000000 irasu dalijimo i dvi grupes laikas: 0.456503 s
1000000 irasu irasymo i vargsiuku faila laikas: 0.576782 s
1000000 irasu irasymo i kietiaku faila laikas: 0.823745 s
Surusiuota studentu:
Vargsai (< 5.0): 411101 studentai
Kietiakai (>= 5.0): 588899 studentai
1000000 irasu testo laikas: 4.59264 s

Failo is 10000000 irasu nuskaitymo laikas: 18.5736 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000000
10000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 13.917 s
10000000 irasu dalijimo i dvi grupes laikas: 5.19583 s
10000000 irasu irasymo i vargsiuku faila laikas: 5.13281 s
10000000 irasu irasymo i kietiaku faila laikas: 7.80566 s
Surusiuota studentu:
Vargsai (< 5.0): 4108815 studentai
Kietiakai (>= 5.0): 5891185 studentai
10000000 irasu testo laikas: 50.6249 s

2 iteracija:

Failo is 1000 irasu nuskaitymo laikas: 0.0058613 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000
1000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0001349 s
1000 irasu dalijimo i dvi grupes laikas: 0.0007417 s
1000 irasu irasymo i vargsiuku faila laikas: 0.0024742 s
1000 irasu irasymo i kietiaku faila laikas: 0.0022456 s
Surusiuota studentu:
Vargsai (< 5.0): 415 studentai
Kietiakai (>= 5.0): 585 studentai
1000 irasu testo laikas: 0.0114577 s

Failo is 10000 irasu nuskaitymo laikas: 0.0231192 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000
10000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.001391 s
10000 irasu dalijimo i dvi grupes laikas: 0.0031088 s
10000 irasu irasymo i vargsiuku faila laikas: 0.0076988 s
10000 irasu irasymo i kietiaku faila laikas: 0.0124708 s
Surusiuota studentu:
Vargsai (< 5.0): 4111 studentai
Kietiakai (>= 5.0): 5889 studentai
10000 irasu testo laikas: 0.0477886 s

Failo is 100000 irasu nuskaitymo laikas: 0.195041 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 100000
100000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.035106 s
100000 irasu dalijimo i dvi grupes laikas: 0.04566 s
100000 irasu irasymo i vargsiuku faila laikas: 0.0806467 s
100000 irasu irasymo i kietiaku faila laikas: 0.118041 s
Surusiuota studentu:
Vargsai (< 5.0): 40881 studentai
Kietiakai (>= 5.0): 59119 studentai
100000 irasu testo laikas: 0.474495 s

Failo is 1000000 irasu nuskaitymo laikas: 1.88186 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000000
1000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.795224 s
1000000 irasu dalijimo i dvi grupes laikas: 0.476743 s
1000000 irasu irasymo i vargsiuku faila laikas: 0.600546 s
1000000 irasu irasymo i kietiaku faila laikas: 0.745513 s
Surusiuota studentu:
Vargsai (< 5.0): 411101 studentai
Kietiakai (>= 5.0): 588899 studentai
1000000 irasu testo laikas: 4.49989 s

Failo is 10000000 irasu nuskaitymo laikas: 18.561 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000000
10000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 13.3429 s
10000000 irasu dalijimo i dvi grupes laikas: 5.24301 s
10000000 irasu irasymo i vargsiuku faila laikas: 4.9628 s
10000000 irasu irasymo i kietiaku faila laikas: 7.50954 s
Surusiuota studentu:
Vargsai (< 5.0): 4108815 studentai
Kietiakai (>= 5.0): 5891185 studentai
10000000 irasu testo laikas: 49.6193 s

3 iteracija:

Failo is 1000 irasu nuskaitymo laikas: 0.0068933 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000
1000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0002119 s
1000 irasu dalijimo i dvi grupes laikas: 0.0005979 s
1000 irasu irasymo i vargsiuku faila laikas: 0.0036721 s
1000 irasu irasymo i kietiaku faila laikas: 0.0040479 s
Surusiuota studentu:
Vargsai (< 5.0): 415 studentai
Kietiakai (>= 5.0): 585 studentai
1000 irasu testo laikas: 0.0154231 s

Failo is 10000 irasu nuskaitymo laikas: 0.0385733 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000
10000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0016656 s
10000 irasu dalijimo i dvi grupes laikas: 0.0038005 s
10000 irasu irasymo i vargsiuku faila laikas: 0.0066465 s
10000 irasu irasymo i kietiaku faila laikas: 0.0104431 s
Surusiuota studentu:
Vargsai (< 5.0): 4111 studentai
Kietiakai (>= 5.0): 5889 studentai
10000 irasu testo laikas: 0.061129 s

Failo is 100000 irasu nuskaitymo laikas: 0.190542 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 100000
100000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.0387744 s
100000 irasu dalijimo i dvi grupes laikas: 0.0434498 s
100000 irasu irasymo i vargsiuku faila laikas: 0.0559512 s
100000 irasu irasymo i kietiaku faila laikas: 0.101827 s
Surusiuota studentu:
Vargsai (< 5.0): 40881 studentai
Kietiakai (>= 5.0): 59119 studentai
100000 irasu testo laikas: 0.430545 s

Failo is 1000000 irasu nuskaitymo laikas: 2.13275 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 1000000
1000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 0.808046 s
1000000 irasu dalijimo i dvi grupes laikas: 0.477243 s
1000000 irasu irasymo i vargsiuku faila laikas: 0.535523 s
1000000 irasu irasymo i kietiaku faila laikas: 0.775139 s
Surusiuota studentu:
Vargsai (< 5.0): 411101 studentai
Kietiakai (>= 5.0): 588899 studentai
1000000 irasu testo laikas: 4.7287 s

Failo is 10000000 irasu nuskaitymo laikas: 19.175 s
Duomenys nuskaityti is failo. Rastas studentu skaicius: 10000000
10000000 irasu rusiavimo didejimo tvarka laikas, su sort funkcija: 13.7366 s
10000000 irasu dalijimo i dvi grupes laikas: 5.34279 s
10000000 irasu irasymo i vargsiuku faila laikas: 5.05391 s
10000000 irasu irasymo i kietiaku faila laikas: 7.69372 s
Surusiuota studentu:
Vargsai (< 5.0): 4108815 studentai
Kietiakai (>= 5.0): 5891185 studentai
10000000 irasu testo laikas: 51.0019 s

VIDURKIAI IS 3 ITERACIJU:

Failo dydis: 1000
Skaitymo vidurkis: 0.00658363 s
Rusiavimo vidurkis: 0.0001681 s
Dalijimo vidurkis: 0.000684233 s
Vargsiuku irasymo vidurkis: 0.00281183 s
Kietiaku irasymo vidurkis: 0.0029309 s

Failo dydis: 10000
Skaitymo vidurkis: 0.0314788 s
Rusiavimo vidurkis: 0.0018494 s
Dalijimo vidurkis: 0.00390743 s
Vargsiuku irasymo vidurkis: 0.00700453 s
Kietiaku irasymo vidurkis: 0.0103041 s

Failo dydis: 100000
Skaitymo vidurkis: 0.196846 s
Rusiavimo vidurkis: 0.0368933 s
Dalijimo vidurkis: 0.0463096 s
Vargsiuku irasymo vidurkis: 0.0635964 s
Kietiaku irasymo vidurkis: 0.100202 s

Failo dydis: 1000000
Skaitymo vidurkis: 1.97507 s
Rusiavimo vidurkis: 0.809427 s
Dalijimo vidurkis: 0.470163 s
Vargsiuku irasymo vidurkis: 0.570951 s
Kietiaku irasymo vidurkis: 0.781466 s

Failo dydis: 10000000
Skaitymo vidurkis: 18.7698 s
Rusiavimo vidurkis: 13.6655 s
Dalijimo vidurkis: 5.26054 s
Vargsiuku irasymo vidurkis: 5.04984 s
Kietiaku irasymo vidurkis: 7.66964 s

(process 8204) exited with code 0 (0x0).
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
</pre>
