# General observations Excercise 4-4

To print the top of the stack (TOS), I introduced the pint_top() function. It must be executed after some number was entered throught the input into the stack. Other commands were added as well.

This is the list of the commands added on this excercise:

| Command | Calculator case | Functionality                     |
| ------- | --------------- | --------------------------------- |
| top     | OP_TOP          | Print the top of the stack (TOS)  |
| dup     | OP_DUP          | Duplicate the top of the stack    |
| swp     | OP_SWP          | Swap the two numbers of the stack |
| clr     | OP_CLR          | Clear the stack                   |

Note: the other operators are also already written down but will be fully implemented in the following excercises.

<br> </br>

# Questions

- I am not sure the clr command is working as it is suposed to work.

---

<br> </br>

> Terminal output: testing top

```
1 5 top
        5
        5
4 8 top
        8
        8

Process returned 0 (0x0)   execution time : 64.995 s
Press any key to continue.
```

> Terminal output: testing dup

```
4 8 dup
        8
        8

Process returned 0 (0x0)   execution time : 10.320 s
Press any key to continue.
```

> Terminal output: testing swp

```
1 7 top
        7
        7
1 7 swp
        1

Process returned 0 (0x0)   execution time : 20.201 s
Press any key to continue.
```
