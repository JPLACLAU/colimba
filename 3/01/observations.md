# General observations Excercise 3-1

Binary search with two test can be found in file 'main-ejemplo-del-libro.c'. Which is the closest to the book example. It takes 0,032s to execute.

Binary search with one test can be found on 'main.c'

The difference in run-time is 0.002s. The one test solution is faster

The "main-ejemplo-del-libro-UserPrompt.c" is just a version that prompts the user wich number to search. It was an early version of the program that I discarted since I need to compare execution times between the two versions.

I would like to try this with a bigger array, to have wider diferencies in execution times

<br> </br>

# Questions

- 'v[mid = (low + high) / 2]' Could I define mid somewhere else that is not inside these [] of the second argument of the while loop?

<br> </br>

---

<br> </br>

> Terminal output: Binary search with two test

```
Found 7 at index 6

Process returned 0 (0x0)   execution time : 0.032 s
Press any key to continue.

```

<br> </br>

> Terminal output: Binary search with one test

```
Found 7 at index 6

Process returned 0 (0x0)   execution time : 0.030 s
Press any key to continue.

```
