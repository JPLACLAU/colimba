# General observations Excercise 8-2

The program will open a text.txt file, read the amount of lines, words and characters of that file.

(words are everything that has a blank space or tabs before and after some characters. So it will count many things as words even if they are not de facto "words")

The Explicit Bit Operations (EBO) version of the program is named main_EBO.c . The fields version of the program is named main_F.c . Both version of the program are compared using the windows time measurment operator on the windows powershell.

It seams main_F.c is faster than main_EBO.c.

<br> </br>

# Questions

- none

---

<br> </br>

> TermWindows Powershell Terminal: output main_EBO.c

```
PS E:\Github\colimba_gimnasio\8\02\8-2> gcc main_EBO.c
PS E:\Github\colimba_gimnasio\8\02\8-2> Measure-Command {./a}

Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 0
Milliseconds      : 38
Ticks             : 383836
TotalDays         : 4,4425462962963E-07
TotalHours        : 1,06621111111111E-05
TotalMinutes      : 0,000639726666666667
TotalSeconds      : 0,0383836
TotalMilliseconds : 38,3836

```

<br> </br>

> TermWindows Powershell Terminal: output main_F.c

```
PS E:\Github\colimba_gimnasio\8\02\8-2> gcc main_F.c
PS E:\Github\colimba_gimnasio\8\02\8-2> Measure-Command {./a}

Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 0
Milliseconds      : 26
Ticks             : 262352
TotalDays         : 3,03648148148148E-07
TotalHours        : 7,28755555555556E-06
TotalMinutes      : 0,000437253333333333
TotalSeconds      : 0,0262352
TotalMilliseconds : 26,2352

```

There is also a main_F_debug.c file wich corresponds to the main_F.c modified in order to understand some overflow errors and debugging it correctly. I saved it as a reminder of some debugging ideas i had to do to solve those errors.
