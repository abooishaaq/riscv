#include "cpu.h"
#include "file.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute(cpu_t *cpu, uint32_t inst) {
    int opcode = inst & 0x7f;
    int rd = (inst >> 7) & 0x1f;
    int rs1 = (inst >> 15) & 0x1f;
    int rs2 = (inst >> 20) & 0x1f;
    switch (opcode) {
    case 0x13: {
        uint64_t imm = ((int64_t)(inst & 0xfff00000)) >> 20;
        cpu->regs[rd] = cpu->regs[rs1] + imm;
        break;
    }
    case 0x33: {
        cpu->regs[rd] = cpu->regs[rs1] + cpu->regs[rs2];
    }
    }
}

void dump_registers(cpu_t *cpu) {
    char *abi[] = {"zero", " ra ", " sp ", " gp ", " tp ", " t0 ", " t1 ",
                   " t2 ", " s0 ", " s1 ", " a0 ", " a1 ", " a2 ", " a3 ",
                   " a4 ", " a5 ", " a6 ", " a7 ", " s2 ", " s3 ", " s4 ",
                   " s5 ", " s6 ", " s7 ", " s8 ", " s9 ", " s10", " s11",
                   " t3 ", " t4 ", " t5 ", " t6 "};

    char output[1024] = "";

    for (int i = 0; i < 32; i += 4) {
        sprintf(output + strlen(output),
                "\n%02d %s = %#018lx %02d %s = %#018lx %02d %s = %#018lx %02d "
                "%s = %#018lx",
                i, abi[i], cpu->regs[i], i + 1, abi[i + 1], cpu->regs[i + 1],
                i + 2, abi[i + 2], cpu->regs[i + 2], i + 3, abi[i + 3],
                cpu->regs[i + 3]);
    }

    printf("%s\n", output);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        exit(1);
    }

    cpu_t *cpu = malloc(sizeof(cpu_t));
    file_buffer_t *code = read_file(argv[1]);
    cpu_init(cpu, code);

    while (cpu->pc < cpu->code.len) {
        // dump_registers(cpu);
        uint32_t inst = fetch_instr(cpu);
        execute(cpu, inst);
        dump_registers(cpu);
        puts("\n\n");
        cpu->pc += 4;
    }
}
