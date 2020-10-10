/*
 * Esercizio RLE (Run-length encoding)
 * 
 * Programma che comprime e decomprime stringhe
 *
 * Autore:   Nicolò Maffi
 * Data:     09/10/2020
 * Versione: 1.1
*/

#include <stdio.h> //Per funzioni di input output
#include <string.h> //Per gestione delle stringhe
#include <ctype.h> //Per toupper();

#define NO_ERR 0 //Valore che indica nessun errore
#define PARAM_ERR 1 //Valore che indica un errore sulla chiamata del programma
#define PARSE_ERR 2 //Valore che indica un errore sull'interpretazione dei parametri

void encoding(const char *str); //Funzione di codifica -> str = stringa da codificare
void decoding(const char *str); //Funzione di decodifica -> str = stringa da decodificare

int main(int argc, const char **argv, const char **envp)
{
    short cmd = 0; //Scelta tra decoding o encoding

    if(argc != 3) //La chiamata al programma deve avvenire con tre parametri
    {
        printf("\nErrore 0x%08x: Numero invalido di argomenti.\n\n", PARAM_ERR);

        printf("SYNOPSIS\n");
        printf("\t%s <ENC_DEC> <STRING>\n\n", argv[0]);

        printf("\t1 - Encoding\n");
        printf("\t2 - Decoding\n\n");

        return PARAM_ERR;
    }

    if(sscanf(argv[1], "%hd", &cmd) <= 0 || cmd > 2 || cmd < 0) //Viene controllata la validità del parametro di sceltra tra enc o dec
    {
        printf("\nErrore 0x%08x: %s non e' un' opzione valida.\n\n", PARSE_ERR, argv[1]);

        return PARSE_ERR;
    }

    if(cmd == 1) //Scelta tra encoding o decoding
        encoding(argv[2]);
    else
        decoding(argv[2]);

    return NO_ERR;
}

void encoding(const char *str)
{
    unsigned long occ = 1; //Numero di occorrenze -> parte da uno dato che ci sarà sempre una occorrenza

    printf("\n");
    for(size_t k = 0; k < strlen(str); k++)
    {
        if(str[k] == str[k + 1]) //Verifica del carattere successivo
        {
            occ++; //Se è uguale si incrementano le occorrenze
        }
        else
        {
            printf("%d%c", occ, toupper(str[k])); //Altrimenti viene stampata la sottostringa compressa
            occ = 1; //Reset delle occorrenze
        }        
    }
    printf("\n\n");

    return;
}

void decoding(const char *str)
{
    unsigned long occ = 0; //Numero di occorrenze

    printf("\n");
    for(int k = 0; k < strlen(str); k++)
    {
        if(str[k] >= '0' && str[k] <= '9') //Verifica del carattere
        {
            //Se è compreso tra 0 e 9 viene trasformato in cifra -> incremento occorrenze
            occ = occ * 10 + str[k] - '0';
        }
        else
        {
            //Altrimenti stampo il carattere occ volte
            for(int j = 0; j < occ; j++)
                printf("%c", str[k]);

            occ = 0; //Reset delle occorrenze
        }
    }
    printf("\n\n");

    return;
}