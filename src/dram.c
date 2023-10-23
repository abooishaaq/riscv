#include "dram.h"

uint64_t dram_load64(dram_t *dram, uint64_t addr) {
    union {
        uint8_t *restrict u8;
        uint64_t *restrict u64;
    } conv = {dram->dram + addr - DRAM_BASE};
    return *conv.u64;
}


uint32_t dram_load32(dram_t *dram, uint64_t addr) {
    union {
        uint8_t *restrict u8;
        uint32_t *restrict u32;
    } conv = {dram->dram + addr - DRAM_BASE};
    return *conv.u32;
}

uint16_t dram_load16(dram_t *dram, uint64_t addr) {
    union {
        uint8_t *restrict u8;
        uint16_t *restrict u16;
    } conv = {dram->dram + addr - DRAM_BASE};
    return *conv.u16;
}

uint8_t dram_load8(dram_t *dram, uint64_t addr) {
    return *(dram->dram + addr - DRAM_BASE);
}


void dram_store64(dram_t *dram, uint64_t addr, uint64_t value) {
    memcpy(dram->dram + addr - DRAM_BASE, &value, sizeof(uint64_t));
}

void dram_store32(dram_t *dram, uint64_t addr, uint32_t value) {
    memcpy(dram->dram + addr - DRAM_BASE, &value, sizeof(uint32_t));
}


void dram_store16(dram_t *dram, uint64_t addr, uint16_t value) {
    memcpy(dram->dram + addr - DRAM_BASE, &value, sizeof(uint16_t));
}

void dram_store8(dram_t *dram, uint64_t addr, uint8_t value) {
    memcpy(dram->dram + addr - DRAM_BASE, &value, sizeof(uint8_t));
}
