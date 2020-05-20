#ifndef BRAINFUCK2_H_
#define BRAINFUCK2_H_

//////////////////////// VAR ////////////////////////

// default
static uint const DEFAULT_TAPE_SIZE = 30000;

// struct
typedef struct script_s script_t;
typedef struct mem_s mem_t;

struct script_s
{
    unsigned char *ops;
    uint op_id;
};
struct mem_s
{
    script_t script;
    unsigned char *tape;
    uint tape_size;
    uint tape_ptr;
};

///////////////////// PROTOTYPE /////////////////////

// memory
mem_t *memory_create(uint tape_size);
void *memory_destroy(mem_t *memory);

// interpretor
int file_interpretor(char const *file_path);
unsigned char *read_file(const char *file_path);
int interpretor(unsigned char *instructions);

// console
int interactive_console(void);

#endif /* !BRAINFUCK2_H_ */