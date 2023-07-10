# General observations Excercise 2-6

The instructions DID NOT specify how x or y should be stored or provided. I interpreted the best thing would be to ask the user for a number. I find out the best way to do this is to use 'scanf' to ask for a value.

In this case, there might be bugs when entering non expected things in the input. That is why there is a clear explanation to the user on what it is expected to enter in the input.

<br> </br>

# Questions

- none

<br> </br>

---

<br> </br>

> Terminal output

```
8-bit byte called x
This has to be a byte of 8 characters only of 0 and 1
Enter value for x:
11110000

8-bit byte called y
This has to be a byte of 8 characters only of 0 and 1
Enter value for y:
00001111

p is a position in x, where a bit-by-bit exchange is initiated with bits from y and to the right.
This can only be a single digit number from 1 to 8
Enter value for p:
4

n is the number of bits that are switched to the right from position p
This can only be a single digit number from 1 to 8
Enter value for n:
4
The result of setbits(x, p, n, y) is: 00000000

Process returned 0 (0x0)   execution time : 18.961 s
Press any key to continue.

```
