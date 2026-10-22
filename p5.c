/* CS100 Fall 2026 - HW2 Problem 5: CPU emulator
 *
 * Emulate a toy CPU with registers x0..x5 (16-bit signed, x0 always 0)
 * executing add/sub/mul/div/let/print instructions read as hex words.
 * Do not use <math.h>. Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    /* TODO: your code here */
    short reg[6] = {0, 0, 0, 0, 0, 0}; // reg[0] = x0, always zero
    int n;
    scanf("%d", &n);
    for (int pc = 0; pc < n; pc++)
    {
        unsigned short inst;
        scanf("%hx", &inst);
        unsigned int opcode = (inst >> 13) & 0b111;
        int r1 = (inst >> 10) & 0b111;
        int r2 = (inst >> 7) & 0b111;
        int imm = inst & 0b000001111111; // 7-bit immediate

        if (opcode == 0b000) // add r1, r2
        {
            if (r1 != 0) reg[r1] += reg[r2];
        }
        else if (opcode == 0b001) // sub r1, r2
        {
            if (r1 != 0) reg[r1] -= reg[r2];
        }
        else if (opcode == 0b010) // mul r1, r2
        {
            if (r1 != 0) reg[r1] *= reg[r2];
        }
        else if (opcode == 0b011) // div r1, r2, truncate towards zero
        {
            if (r1 != 0) reg[r1] = reg[r1] / reg[r2];
        }
        else if (opcode == 0b100) // let r1, imm
        {
            if (r1 != 0) reg[r1] = imm;
        }
        else if (opcode == 0b101) // print r1
        {
            printf("x%d = %d\n", r1, reg[r1]);
        }
    }
    return 0;
}
