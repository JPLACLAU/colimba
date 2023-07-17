# General observations Excercise 2-6: CORRECTION

## (Still wrong)

The program uses the number 12, which is 0000000110010010 in binary.

This is what I expect the program to do:

1. The program starts ("p=4")at the position "4" counting from the right, which corresponds to a "0".
2. Then as "n = 3", it will replace the 3 digits to the right of the 4th position.
3. The digits 100 should be replaced by 010, making the number "00001100" into "00001010" (which is 10 in decimal).

<br> </br>

# Questions

However, after making those operations, the new number is 00001000, which is 8. I don't see why I got it wrong.

> "12": 00001100

> "18": 00010010

> "8": 00001000

---

<br> </br>

> Terminal output

```
The result is: 8

Process returned 0 (0x0)   execution time : 0.029 s
Press any key to continue.


```
