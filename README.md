# MyStringUtility
Lib that contain C functions to handle strings

## `void fget_string(FILE* Stream, char Str[], char lastChar)`
Function that read the content of data stream _Stream_ into the string _Str[]_ until the char _lastChar_
is reached.


## `void get_string(char Str[], char lastChar)`
Same as `void fget_string(FILE* Stream, char Str[], char lastChar)` but reads directly from the stream of **_stdin_** from the _<stdio.h>_ standard lib.
> Reads the console input until _lastChar_ char is reached.

## `unsigned int find_replace(char StrIn[], char ToFind[], char ToReplaceWith[], unsigned int max)`
Find the all strings _ToFind[]_ into string _StrIn[]_ and replaces it with _ToReplaceWith[]_.
The _max_ parameter limits the _StrIn[]_ string expansion as the function doesn't handle dynamic memory allocation.
> example : The StrIn[] has been declared as 100 units array and the string is actually 90 char's long. If the string that replaces the previous ones is bigger then an array overflow could occur. _max_ parameter check that the final string won't be longer than its own limit.

## Todo : same as the previous one but with dynamic memory allocation/reallocation
