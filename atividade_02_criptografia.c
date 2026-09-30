#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 16

int sequencia(int tipo, int i) {
    int a, b, c, j;

    if (tipo == 1) {
        return i + 1;
    }

    if (tipo == 2) {
        int valor = 1;
        for (j = 0; j < i; j++)
            valor *= 2;
        return valor;
    }

    if (tipo == 3) {
        a = 1;
        b = 1;

        if (i == 0 || i == 1)
            return 1;

        for (j = 2; j <= i; j++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    if (tipo == 4) {
        int numero = 2;
        int contador = 0;
        int primo;

        while (1) {
            primo = 1;

            for (j = 2; j * j <= numero; j++) {
                if (numero % j == 0) {
                    primo = 0;
                    break;
                }
            }

            if (primo) {
                if (contador == i)
                    return numero;
                contador++;
            }

            numero++;
        }
    }

    return 0;
}

void criptografar(char palavra[], char resultado[], int shift, int tipo) {
    int i;
    int deslocamento;
    char letra;

    for (i = 0; palavra[i] != '\0'; i++) {
        letra = palavra[i];

        deslocamento = shift + sequencia(tipo, i);

        resultado[i] =
            ((letra - 'a' + deslocamento) % 26) + 'a';
    }

    resultado[i] = '\0';
}

void salvarArquivo(char palavra[], char resultado[],
                  int shift, int tipo) {
    FILE *arquivo;
    const char *nomeSequencia;

    if (tipo == 1)
        nomeSequencia = "PA";
    else if (tipo == 2)
        nomeSequencia = "PG";
    else if (tipo == 3)
        nomeSequencia = "Fibonacci";
    else
        nomeSequencia = "Primos";

    arquivo = fopen("resultado_criptografia.txt", "w");

    if (arquivo == NULL) {
        printf("\nErro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "===== RESULTADO DA CRIPTOGRAFIA =====\n");
    fprintf(arquivo, "Palavra original: %s\n", palavra);
    fprintf(arquivo, "Palavra codificada: %s\n", resultado);
    fprintf(arquivo, "SHIFT: %d\n", shift);
    fprintf(arquivo, "Tipo de sequencia: %s\n", nomeSequencia);
    fprintf(arquivo, "Letras: %d\n", (int)strlen(palavra));
    fprintf(arquivo, "Metodo: Cesar + deslocamento dinamico\n");
    fprintf(arquivo, "=====================================\n");

    fclose(arquivo);

    printf("\nArquivo 'resultado_criptografia.txt' gerado com sucesso!\n");
}

int main() {
    char palavra[MAX];
    char resultado[MAX];
    int shift;
    int tipo;

    printf("========================================\n");
    printf("   SISTEMA DE CRIPTOGRAFIA SIMPLES\n");
    printf("========================================\n");

    printf("\nDigite a palavra secreta (ate 15 letras): ");
    scanf("%15s", palavra);

    for (int i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = tolower((unsigned char)palavra[i]);

        if (palavra[i] < 'a' || palavra[i] > 'z') {
            printf("\nErro: use somente letras de A a Z, sem acentos.\n");
            return 1;
        }
    }

    do {
        printf("\nDigite o valor do SHIFT (0 a 25): ");
        scanf("%d", &shift);

        if (shift < 0 || shift > 25)
            printf("SHIFT invalido. Digite um valor entre 0 e 25.\n");

    } while (shift < 0 || shift > 25);

    printf("\nEscolha a sequencia numerica:\n");
    printf("1 - PA\n");
    printf("2 - PG\n");
    printf("3 - Fibonacci\n");
    printf("4 - Primos\n");
    printf("Opcao: ");
    scanf("%d", &tipo);

    if (tipo < 1 || tipo > 4) {
        printf("\nOpcao de sequencia invalida.\n");
        return 1;
    }

    criptografar(palavra, resultado, shift, tipo);

    printf("\n----------------------------------------\n");
    printf("Palavra original: %s\n", palavra);
    printf("Palavra criptografada: %s\n", resultado);
    printf("SHIFT: %d\n", shift);

    if (tipo == 1)
        printf("Sequencia: PA\n");
    else if (tipo == 2)
        printf("Sequencia: PG\n");
    else if (tipo == 3)
        printf("Sequencia: Fibonacci\n");
    else
        printf("Sequencia: Primos\n");

    printf("----------------------------------------\n");

    salvarArquivo(palavra, resultado, shift, tipo);

    return 0;
}