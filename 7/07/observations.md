# General observations Excercise 7-7

This program will look for a pattern either in user entered files (see text1.txt and text2.txt), or in manually entered text.

<br> </br>

# Questions

- none

---

<br> </br>

> Terminal output case 1: look in the files.

```
Enter the pattern to search for: this line
Enter the names of files separated by commas (or just press enter to input text manually): text1.txt,text2.txt
In file text1.txt - Line #2: blabla 2 this line will differ
In file text2.txt - Line #2: blabla 2 this line is different

Process returned 0 (0x0)   execution time : 11.751 s
Press any key to continue.

```

<br> </br>

> Terminal output case 2: there are no files, manually entered text.

```
Enter the pattern to search for: hola que tal
Enter the names of files separated by commas (or just press enter to input text manually):

No files provided or file not found. Enter your text manually.
Write your text. When done, press Ctrl-D (or Ctrl-Z on Windows):
buenos dias
hola que tal
como le va
todo en orden?
hola

The pattern was found in the following lines:

Line #2: hola que tal

Process returned 0 (0x0)   execution time : 24.247 s
Press any key to continue.


```
