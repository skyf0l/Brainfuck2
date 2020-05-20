#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

// nothing
int nothing(mem_t *);

// brainfuck
int add(mem_t *);
int sub(mem_t *);

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
    nothing, // !
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
    nothing, // .
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
    nothing, // :
    nothing, // ;
    nothing, // <
    nothing, // =
    nothing, // >
    nothing, // ?
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
    nothing, // [
    nothing, // \\/
    nothing, // ]
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