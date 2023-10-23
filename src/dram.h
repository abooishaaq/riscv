#ifndef DRAM_H

#define DRAM_H

#include <stdint.h>
#include <string.h>

#define DRAM_BASE 0x80000000
const int DRAM_SIZE = 1024 * 1024 * 128;

struct dram_t {
    uint8_t *dram;
    int size;
};

typedef struct dram_t dram_t;


void dram_store64(dram_t *dram, uint64_t addr, uint64_t value);
void dram_store32(dram_t *dram, uint64_t addr, uint32_t value);
void dram_store16(dram_t *dram, uint64_t addr, uint16_t value);
void dram_store8(dram_t *dram, uint64_t addr, uint8_t value);

uint64_t dram_load64(dram_t *dram, uint64_t addr);
uint32_t dram_load32(dram_t *dram, uint64_t addr);
uint16_t dram_load16(dram_t *dram, uint64_t addr);
uint8_t dram_load8(dram_t *dram, uint64_t addr);

#endif
