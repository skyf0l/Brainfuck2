#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

// dept struct
typedef struct mem_s mem_t;

// nothing
int nothing(mem_t *);

// brainfuck
int add(mem_t *);
int sub(mem_t *);
int move_ptr_right(mem_t *);
int move_ptr_left(mem_t *);
int print_char(mem_t *);
int while_in(mem_t *);
int while_out(mem_t *);

// conditional statement
int conditional_in(mem_t *);
int conditional_mid(mem_t *);
int conditional_out(mem_t *);

static int (* const INSTRUCTIONS[128])() = {
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing,
    nothing, // space
    conditional_out, // !
    nothing, // "
    nothing, // #
    nothing, // $
    nothing, // %
    nothing, // &
    nothing, // '
    nothing, // (
    nothing, // )
    nothing, // *
    add,     // +
    nothing, // ,
    sub,     // -
    print_char, // .
    nothing, // /
    nothing, // 0
    nothing, // 1
    nothing, // 2
    nothing, // 3
    nothing, // 4
    nothing, // 5
    nothing, // 6
    nothing, // 7
    nothing, // 8
    nothing, // 9
    conditional_mid, // :
    nothing, // ;
    move_ptr_left, // <
    nothing, // =
    move_ptr_right, // >
    conditional_in, // ?
    nothing, // @
    nothing, // A
    nothing, // B
    nothing, // C
    nothing, // D
    nothing, // E
    nothing, // F
    nothing, // G
    nothing, // H
    nothing, // I
    nothing, // J
    nothing, // K
    nothing, // L
    nothing, // M
    nothing, // N
    nothing, // O
    nothing, // P
    nothing, // Q
    nothing, // R
    nothing, // S
    nothing, // T
    nothing, // U
    nothing, // V
    nothing, // W
    nothing, // X
    nothing, // Y
    nothing, // Z
    while_in, // [
    nothing, // \\/
    while_out, // ]
    nothing, // ^
    nothing, // _
    nothing, // `
    nothing, // a
    nothing, // b
    nothing, // c
    nothing, // d
    nothing, // e
    nothing, // f
    nothing, // g
    nothing, // h
    nothing, // i
    nothing, // j
    nothing, // k
    nothing, // l
    nothing, // m
    nothing, // n
    nothing, // o
    nothing, // p
    nothing, // q
    nothing, // r
    nothing, // s
    nothing, // t
    nothing, // u
    nothing, // v
    nothing, // w
    nothing, // x
    nothing, // y
    nothing, // z
    nothing, // {
    nothing, // |
    nothing, // }
    nothing, // ~
    nothing
};

#endif /* !INSTRUCTIONS_H_ */