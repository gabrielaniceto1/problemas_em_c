/*
beecrowd | 2253
Validador de Senhas
Por Gustavo Marmentini, URIBR Brazil

Rolien e Naej são os desenvolvedores de um grande portal de programação. 
Para ajudar no novo sistema de cadastro do site, eles requisitaram a sua ajuda. Seu trabalho é fazer um código que valide as senhas que são 
cadastradas no portal, para isso você deve atentar aos requisitos a seguir:

A senha deve conter, no mínimo, uma letra maiúscula, uma letra minúscula e um número;
A mesma não pode ter nenhum caractere de pontuação, acentuação ou espaço;
Além disso, a senha pode ter de 6 a 32 caracteres.

Entrada
A entrada contém vários casos de teste e termina com final de arquivo. Cada linha tem uma string S, correspondente a senha que é inserida pelo usuário 
no momento do cadastro.

Saída
A saída contém uma linha, que pode ser “Senha valida.”, 
caso a senha tenha cada item dos requisitos solicitados anteriormente, ou “Senha invalida.”, se um ou mais requisitos não forem atendidos.

*/

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