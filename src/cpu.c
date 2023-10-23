#include "cpu.h"
#include <stdint.h>
#include <string.h>

uint32_t fetch_instr(cpu_t *cpu) {
    union {
        uint8_t *restrict u8;
        uint32_t *restrict u32;
    } conv = {cpu->code.bytes + cpu->pc};
    return *conv.u32;
}

void cpu_init(cpu_t *cpu, file_buffer_t *code_file) {
    memset(cpu->regs, 0, sizeof(uint64_t) * 32);
    cpu->pc = 0;
    cpu->code.bytes = malloc(code_file->len);
    memcpy(cpu->code.bytes, code_file->buffer, code_file->len);
    cpu->code.cap = cpu->code.len = code_file->len;
}
