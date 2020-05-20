#ifndef BRAINFUCK2_H_
#define BRAINFUCK2_H_

//////////////////////// VAR ////////////////////////

// default
static size_t const DEFAULT_TAPE_SIZE = 30000;

// struct
typedef struct mem_s mem_t;
struct mem_s
{
    unsigned char *tape;
    size_t tape_size;
    int tape_ptr;
};

///////////////////// PROTOTYPE /////////////////////

// interpretor
int file_interpretor(char const *file_path);
int interpretor(unsigned char const *instructions);

// console
int interactive_console(void);

#endif /* !BRAINFUCK2_H_ */