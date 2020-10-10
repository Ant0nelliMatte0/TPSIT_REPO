/*
 * Esercizio COVID-19
 * 
 * Programma che calcola il numero di contagiati da COVID-19
 *
 * Autore:   Nicolò Maffi
 * Data:     01/10/2020
 * Versione: 1.1
*/

#include <stdio.h> //Per funzioni di input output
#include <stdlib.h> //Per calloc
#include <math.h> //Per log

#define NO_ERR 0 //Costante che nessun errore
#define INPUT_ERR 1 //Costante che indica un errore di input
#define ALLOC_ERR 2 //Costante che indica un errore di allocazione

int main(int argc, const char **argv, const char **envp)
{
    float r = 0.0; //Costante che indica il contagio esponenziale
    float *contagi_gior = NULL; //Array che conterrà il numero di contagiati in ogni giorno
    unsigned giorni = 0; //Numero di giorni di contagio
    unsigned n_alunni = 0; //Numero di alunni contagiati

    printf("Costante di contagi: "); //Input costante di contagio
    if(scanf("%f", &r) == 0) //Controllo validità dell'input
    {
        printf("Errore %d: Non e' stato inserito un numero.\n\n", INPUT_ERR);
        return INPUT_ERR;
    }

    printf("Numero di alunni: "); //Input numero di alunni
    if(scanf("%u", &n_alunni) == 0) //Controllo validità dell'input
    {
        printf("Errore %d: Non e' stato inserito un numero.\n\n", INPUT_ERR);
        return INPUT_ERR;
    }

    //Formula del cambiamento di base dei logaritmi -> calcolo numero di giorni
    //Viene aggiunto 1 perchè il primo giorno vi è già un contagiato
    giorni = log(n_alunni) / log(r) + 1;

    if(giorni <= 0) //Se il numero di giorni è <= 0 non si può allocare il vettore
    {
        printf("Errore %d: Impossibile eseguire la procedura.\n\n", ALLOC_ERR);
        return ALLOC_ERR;
    }

    contagi_gior = (float *)calloc(giorni, sizeof(float)); //Allocazione dell'array

    contagi_gior[0] = 1; //Un contagiato dal primo girno
    for(int k = 1; k < giorni; k++)
        contagi_gior[k] = contagi_gior[k - 1] * r; //Calcolo dei contagiati in ogni giorno

    printf("\nLa classe verra' contagiata in %u giorni.\n\n", giorni);
    printf("Tabella dei contagi durante i giorni:\n");
    for(int k = 0; k < giorni; k++)
        printf("giorno %3d: %.0f persone contagiate\n", k + 1, contagi_gior[k]); //Stampa dell'array

    free(contagi_gior); //Deallocazione array

    fflush(stdin);
    printf("\nPremere un tasto per continuare. ");
    getchar();

    return NO_ERR;
}