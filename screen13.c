#include <stdio.h>

int main() {
    asm volatile (
        "mov $0x13, %%ax\n"   // Definir a função de serviço 0x13 em AX
        "int $0x10\n"         // Chamar a interrupção 0x10
        :
        :
        : "ax"                // Registrador AX é usado, então é necessário informar isso ao compilador
    );

    return 0;
}

