# garbage_malloc
Garbage collector to manage malloc allocation.

Functions which allow the override of C malloc and free functions. Will store each allocated pointer in chained list and manage this list whenever a pointer if freed.

You can use macro `MALLOC` and `FREE` defined in the header to malloc and free like the exemple below.

A destructor attribute is set to `free_g_garbage_lst(void)` to destroy our chained list at the end of the programm execution. With this ability, you can leave a programm with `exit` and each allocated element is gonna be free properly.

### Exemple 1
```c
#include "garbage.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
  char	*str;

  str = MALLOC(sizeof(char) * 5);
  strcpy(str, "test");
  printf("str : %s\n", str);
  FREE(str);
  return (0);
}
```

### Exemple 2
```c
#include "garbage.h"
#include <string.h>
#include <stdio.h>

#define malloc	garbage_malloc
#define free	garbage_free

int		main(int argc, char **argv)
{
  char	*str;
  char	*str2;

  str = MALLOC(sizeof(char) * 5);
  str2 = MALLOC(sizeof(char) * 9);
  
  if (!str || !str2)
    exit(-1);    // Will exit without any leaks with a destructor
}
```
