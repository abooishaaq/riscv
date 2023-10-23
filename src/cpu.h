#ifndef CPU_H

#define CPU_H

#include "file.h"
#include <stdint.h>


struct cpu_t {
    uint64_t regs[32];
    uint64_t pc;
    struct code {
        uint8_t *bytes;
        uint64_t len;
        uint64_t cap;
    } code;
};

typedef struct cpu_t cpu_t;

void cpu_init(cpu_t *cpu, file_buffer_t *code_file);

uint32_t fetch_instr(cpu_t *cpu);

#endif