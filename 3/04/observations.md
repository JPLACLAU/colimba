# General observations Excercise 3-4

When representing signed numbers using binary code, the representation of negative numbers is not exactly simatrical to the positive numbers because the 0 occupies a space in the binary list of possible spaces.

For example, a bit represinging "signed numbers can only represent from -128 to 0, and to +127. The 0 occupies a space, and the space of the negative numbers are not symetrical to the positive numbers.

the itoa function from the book, assumes that all -n can be turned into an +n . And that is not correct. It cannot handle the -128.

In the limitedItoa.c program the maximum value by the itoa function is -2147483648 , 0 and 2147483647.
(That is because int values in C occupies 32bits). When executing the itoa function with a positive number that exceeds the limit, you have as a result a wrong number, and a overflow problem (see Terminal output #2).

The solution I found.. Is not really a solution, but a "band-aid" type of solution. I simply added "long long int " modifier, so that the int values are way bigger than 32 bits.

<br> </br>

# Questions

- Are there any other " nicer ways " to fix this problem?
- I found somwhere that adding " s[i] = '\0';" at the end is good practice for progfunctions that will be printed with printf. I understand what it does, it ads an end line to the program, but I do not understand really why is this a good practice..

---

<br> </br>

> Terminal output #1: limitedItoa.c

```
2147483647
0
-2147483648

Process returned 0 (0x0)   execution time : 0.028 s
Press any key to continue.

```

> Terminal output #2: limitedItoa.c breaking the limit: overflow and wrong result.

```
-2147483648
0
-2147483648

Process returned 0 (0x0)   execution time : 0.032 s
Press any key to continue.


```

<br> </br>

> Terminal output #3: main.c Problem "solved"

```
2147483648
0
-2147483648

Process returned 0 (0x0)   execution time : 0.029 s
Press any key to continue.


```
