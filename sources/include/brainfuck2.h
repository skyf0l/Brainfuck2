#ifndef BRAINFUCK2_H_
#define BRAINFUCK2_H_

//////////////////////// VAR ////////////////////////

// default
static uint const DEFAULT_TAPE_SIZE = 30000;

// struct
typedef struct mem_s mem_t;
struct mem_s
{
    unsigned char *tape;
    uint tape_size;
    uint tape_ptr;
    int while_layer;
};

///////////////////// PROTOTYPE /////////////////////

// interpretor
int file_interpretor(char const *file_path);
int interpretor(unsigned char const *instructions);

// console
int interactive_console(void);

#endif /* !BRAINFUCK2_H_ */