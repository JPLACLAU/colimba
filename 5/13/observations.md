# General observations Excercise 5-13

The program works however when printing back the saved lines it does not show them in propper order if I reach the maximum allowed of lines to be stored and I surpass it. If i write less lines than 10 if no argument, or less lines than n if there is an n argument, it works fine.

<br> </br>

# Questions

- none

---

<br> </br>

> Terminal output: with -n = -5

```
line 1
line 2
line 3
line 4
line 5
line 6
line 7 (by the way this program was run with -n = -5, so it will save the last 5 lines)
line 8 (this is the last line before ctrl+z)
line 6
line 7 (by the way this program was run with -n = -5, so it will save the last 5 lines)
line 8 (this is the last line before ctrl+z)
line 4
line 5

Process returned 0 (0x0)   execution time : 69.358 s
Press any key to continue.



```

<br> </br>

> Terminal output: with no argument (default n=10)

```
line 1
line 2
line 3
line 4
line 5
line 6
line 7
line 8
line 9
line 10
line 11
line 12 i ll ctrlz here
line 11
line 12 i ll ctrlz here
line 3
line 4
line 5
line 6
line 7
line 8
line 9
line 10

Process returned 0 (0x0)   execution time : 38.867 s
Press any key to continue.


```

<br> </br>

> Terminal output: with no argument (default n=10), less than 10 lines.

```
line 1
line 2
line 3
line 4
line 5 ctrlz here
line 1
line 2
line 3
line 4
line 5 ctrlz here

Process returned 0 (0x0)   execution time : 21.200 s
Press any key to continue.



```
