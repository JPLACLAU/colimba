# General observations Excercise 7-9

We compare two ways of solving this problem:

- isupper_memory_optimized [-memory]: It directly checks if a character is uppercase, while being memory-efficient.
- isupper_time_optimized [-time]: It uses more memory (using a lookup table) for faster a check.

The returned line will show a 1 if the corresponding character is an Upper case or a 0 if it is not.

<br> </br>

# Questions

- none

---

<br> </br>

> Terminal output [-memory]

```
Using the memory optimized version of isupper
Enter a sentence: Hola que Tal PROBANDO UPPERCASES test
1000000001000111111110111111111100000

Process returned 0 (0x0)   execution time : 2.081 s
Press any key to continue.

```

<br> </br>

> Terminal output [-time]

```
Using the time optimized version of isupper
Enter a sentence: Hola que Tal PROBANDO UPPERCASES test
1000000001000111111110111111111100000

Process returned 0 (0x0)   execution time : 1.996 s
Press any key to continue.






```
