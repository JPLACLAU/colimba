# General observations Excercise 5-5

1. strncpy(s, t, n)
   This function copies n characters from t to s. If t is less than n, the remainder of s is filled with null characters.

2. strncat(s, t, n)
   This function combine n characters of t to the end of s. The combined string is terminated with a null characters.

3. strncmp(s, t, n)
   This function compares the first n characters of s and t. It returns a negative, zero, or positive value based on the comparison (similar to strcmp).

<br> </br>

# Questions

- none

---

<br> </br>

> Terminal output

```
s+t: 123456
Does '456' occur at the end of '123456'? Yes
strncpy(s, u, 2): 453456
strncat(s, t, 2): 45345645
strncmp(s, u, 3): -3

Process returned 0 (0x0)   execution time : 0.013 s
Press any key to continue.



```
