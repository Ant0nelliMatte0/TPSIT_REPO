#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NO_ERR 0
#define INPUT_ERR 1
#define ALLOC_ERR 2

int main(int argc, const char **argv, const char **envp)
{
    float r = 0.0;
    float *contagi_gior = NULL;
    unsigned giorni = 0;
    unsigned n_alunni = 0;

    printf("Numero di soggetti contagiati da un singolo: ");
    if(scanf("%f", &r) == 0)
    {
        printf("Error 0x08%x: Non e' stato inserito un numero.\n\n", INPUT_ERR);
        return INPUT_ERR;
    }

    printf("Numero di alunni: ");
    if(scanf("%u", &n_alunni) == 0)
    {
        printf("Errore 0x%08x: Non e' stato inserito un numero.\n\n", INPUT_ERR);
        return INPUT_ERR;
    }

    giorni = log(n_alunni)/log(r) + 1;

    if(giorni <= 0)
    {
        printf("Error 0x%08x: Impossibile eseguire la procedura.\n\n", ALLOC_ERR);
        return ALLOC_ERR;
    }

    contagi_gior = (float *)calloc(giorni, sizeof(float));

    contagi_gior[0] = 1;
    for(int k = 1; k < giorni; k++)
        contagi_gior[k] = contagi_gior[k - 1] * r;

    printf("\nLa classe verra' contagiata in %u giorni.\n\n", giorni);
    printf("Tabella dei contagi durante i giorni:\n");
    for(int k = 0; k < giorni; k++)
        printf("giorno %d: %.0f persone contagiate\n", k + 1, contagi_gior[k]);

    free(contagi_gior);

    fflush(stdin);
    printf("\nPremere un tasto per continuare. ");
    getchar();

    return NO_ERR;
}
