#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char senha[100];
    char *resultado;

    while (1) {
        resultado = fgets(senha, 100, stdin);
        if(resultado == NULL){
            break;
        }

        int cont1 = 0, cont2 = 0, cont3 = 0, invalida = 0;
        
        senha[strcspn(senha, "\n")] = '\0';
        
        size_t tamanho = strlen(senha);
        
        if (tamanho > 32 || tamanho < 6) {
            printf("Senha invalida.\n");
            continue;
        }
        
        for (int i = 0; i < tamanho; i++) {
            int valor = senha[i];
            // número
            if (valor >= 48 && valor <= 57) {
                cont1++;
            }
            // maiúscula
            else if (valor >= 65 && valor <= 90) {
                cont2++;
            }
            // minúscula
            else if (valor >= 97 && valor <= 122) {
                cont3++;
            }
            else {
                invalida++;
                break;
            }
        }
        
        if (invalida > 0) {
            printf("Senha invalida.\n");
        }
        else if (cont1 > 0 && cont2 > 0 && cont3 > 0) {
            printf("Senha valida.\n");
        }
        else {
            printf("Senha invalida.\n");
        }
    }
    return 0;
}