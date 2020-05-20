# Brainfuck2
From useless to almost useful !

## How it work

Originaly, brainfuck operates on an array of memory cells, also referred to as the tape, each initially set to zero and there is a pointer, initially pointing to the first memory cell.

Each instruction is executed one by one and can modify the state of tape.

## Basic Brainfuck Commands:

Initialisation (C equivalent)

tape_size, cell_size and cell_signed can be defined in command line or in file header **(Not implemented)**
``` C
cell_type mem[tape_size];
cell_type *ptr = mem;
memset(mem, 0, tape_size);
```
| Brainfuck | C equivalent        | Meaning                                                                                    |
|-----------|---------------------|--------------------------------------------------------------------------------------------|
| >         | ptr++;              | Increment the pointer (to point to the next cell to the right).                            |
| <         | ptr--;              | Decrement the pointer (to point to the next cell to the left).                             |
| +         | (*ptr)++;           | Increment (increase by one) the cell at the pointer.                                       |
| -         | (*ptr)--;           | Decrement (decrease by one) the cell at the pointer.                                       |
| .         | putchar(*ptr);      | Output the current cell value in current output (in ASCII).                                                  |
| ,         | (*ptr) = getchar(); | Accept one value from current input and storing it in the current cell                                   |
| [         | while(*ptr) {       | Jump forward to the command after the corresponding ] if the cell value is zero.               |
| ]         | }                   | Jump back to the command after the corresponding [ if the cell value is non-zero. |


## Brainfunk2 Features:
### Header:
| Name | Value | Default | Meaning                                     |
|-----------|----------|--------------|---------------------------------------------|
| tape_size  | greater or equal to 1 | 30000 | Set tape size in cell **(Not implemented)** |
| cell_size  | greater or equal to 1 | 8 | Set cell size in bit **(Not implemented)** |
| cell_signed  | true or false | false | Set if cell is signed (if cell_size is 8 bits, cell value is between 0 and 255) or unsigned (between -128 and 127) **(Not implemented)** |

Format: `@name=value@`

All header value must be write at begin of file (if header is malformed, already defined or define after instructions, exit the program)

### Data:
| Brainfunk | C equivalent        | Meaning                                     |
|-----------|---------------------|---------------------------------------------|
| c         | *ptr = 0; | Clear cell (equivalent of '\[0\]' but more optimized) **(Not implemented)** |
| x\[0-9A-F\] | *ptr = hex_value;      | Fast cell initializer, store value from hex **(Not implemented)** |
| s"some string" | strcpy(ptr, str);      | Fast cell initializer, store value from string **(Not implemented)** |
| ' | printf("%d, *ptr);      | Output the current cell value in current output (in decimal). **(Not implemented)** |

### Data stack:
| Brainfunk | Meaning                                     |
|-----------|---------------------------------------------|
| )         | Push current cell value on the stack **(Not implemented)** |
| (         | Pop the value on the stack into the current cell (an empty stack pop zero into cell) **(Not implemented)** |
| %         | Copy the value on the stack into the current cell (an empty stack copy zero into cell) **(Not implemented)** |
| $         | Pop the value of the stack without writing it **(Not implemented)** |

### Conditional Statements:
| Brainfunk | C equivalent        | Meaning                                     |
|-----------|---------------------|---------------------------------------------|
| ? \[code1\] : \[code2\] ! | if (*ptr) {code1}<br>else {code2} | Execute code1 if cell value is not 0 and code2 else **(Not implemented)** |

If you want just if statement you can simplify as `? [code] !`

### Functions:
Functions can be loaded from library files at execution
| Brainfunk | C equivalent        | Meaning                                     |
|-----------|---------------------|---------------------------------------------|
| Flabel{code} | void label(){code}; | Declare function 'label', if function is malformed or already defined, exit the program **(Not implemented)** |
| flabel{N}      | label() \/\*N times\*\/ | Execute code in function 'label' N times, if it's not defined does nothing, if function is malformed, exit the program</br>If a while loop or an if statement is open in the function, at each exit it's forceful closed **(Not implemented)** |
| ;      | return; | Exit function and close all while loop and if statements openned **(Not implemented)** |

Labels can contains `abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789`

### System:
| Brainfunk | C equivalent        | Meaning                                     |
|-----------|---------------------|---------------------------------------------|
| w         | usleep(*ptr * 10000) | Wait cell value mult by 10ms **(Not implemented)** |
| &         | exit(*ptr) | Exit program with cell value **(Not implemented)** |
| Y         | fork(); | Fork program and store in current cell 0 if program is child and `child_id` else</br> Both are asynchronized **(Not implemented)** |
| y         | *fork();* | Fork program and store in current cell 0 if program is child and `child_id` else</br> Both execute each instruction in same cicle (parent and child after) **(Not implemented)** |

For fork instruction, child tape is a copy independent of parent tape

### Other:
| Brainfunk | C equivalent        | Meaning                                     |
|-----------|---------------------|---------------------------------------------|
| ##...       | //  |  All following characters between ## and the next new line are ignored **(Not implemented)** |
| #...#        | /\* ... \*/  | All following characters between this and the next # are ignored **(Not implemented)** |
| d        | printf("Cell %d (%d)\n", cell_id, *ptr);  | Debug instruction **(Not implemented)** |

### Writing optimisation:
`10+` is same that `++++++++++` **(Not implemented)**

`3[3@func@]2]` is same that `[[[@function@@function@@function@]]]` **(Not implemented)**
