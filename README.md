# 1. 42_projects

## 1.1. Overview
---

All projects that I have finished while I'm studying in 42

---

## 1.2. Libft

---

libft is the first project at 42 that demands us to re-create some standard C library function.
At 42, all students are not allowed to use some standard libraries for finishing projects, therefore, we have to keep updating this library to go further in the 42 program.


### 1.2.1. Features

| Lib.Function |  Additional   |   Personal    |
| :----------: | :-----------: | :-----------: |
|    memset    |   ft_memdel   |   ft_lstadd   |
|    bzero     |  ft_memalloc  | ft_lstdelone  |
|    memcpy    |   ft_strnew   |   ft_lstnew   |
|   memccpy    |   ft_strdel   |   ft_lstdel   |
|   memmove    |   ft_strier   | get_next_line |
|    memchr    |   ft_srteqp   |   ft_printf   |
|    memcmp    |   ft_strmap   |  ft_absolute  |
|    strlne    |   ft_strsub   |
|    strdup    |  ft_strjoin   |
|    strchr    |    ft_itoa    |
|    strstr    |  ft_putchar   |
|   strrchr    |  ft_strsplit  |
|   strnstr    |   ft_putstr   |
|   isalpha    |  ft_putendl   |
|   isdigit    |   ft_putnbr   |
|   isascii    | ft_puthcar_fd |
|   toupper    | ft_putstr_fd  |
|   tolower    | ft_putendl_fd |
|     atoi     |  ft_strjoin   |
|    strcat    |  ft_strmapi   |
|   strncpy    |  ft_strmerge  |
|   isascii    |  ft_strtrim   |

---

<br />

## 1.3. Get Next Line
---

<p>Get Next Line is a function that reads a file and allows user to read a line ending with a new line character '\n' 

This project deals with memory allocation and free allocated memory to prevent leaks.
</p>
 
### 1.3.1. Return value
    -1 : Error occcured
     0 : Finishing to read a file
     1 : the line was read

---

<br />

## 1.4. fillit
---
<p>The purpose of this project is to make the smallest possible "square" with a given tetriminos
</p>

### 1.4.1. Usage
    $> make
    $> ./fillit [file]
#### 1.4.1.1. example
    $> ./fillit smaples/test7

    ABBBB.
    ACCC..
    AGGCDD
    A.GDD.
    EEGFF.
    EE..FF

