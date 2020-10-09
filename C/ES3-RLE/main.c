#include <stdio.h>
#include <string.h>
#include <ctype.h> //Per toupper();

#define NO_ERR 0 //Valore che indica nessun errore
#define PARAM_ERR 1 //Valore che indica un errore sulla chiamata del programma
#define PARSE_ERR 2 //Valore che indica un errore sull'interpretazione dei parametri

#define LETT_NUM 26 //Numero di lettere dell'alfabeto
#define OFFSET 'A' //Offset tra 0 ed il valore di A (65)

void encoding(const char *str, size_t size);
void decoding(const char *str, size_t size);

int main(int argc, const char **argv, const char **envp) //Entry point
{
    short cmd = 0; //Scelta tra decoding o encoding

    if(argc != 3) //La chiamata al programma deve avvenire con tre parametri
    {
        printf("\nErrore 0x%08x: Numero invalido di argomenti.\n\n");

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

    if(cmd == 1)
        encoding(argv[2], strlen(argv[2]));
    else
        decoding(argv[2], strlen(argv[2]));

    return NO_ERR;
}

void encoding(const char *str, size_t size)
{
    unsigned long occ = 1;

    printf("\n");

    for(int k = 0; k < size; k++)
    {
        if(str[k] == str[k + 1])
        {
            occ++;
        }
        else
        {
            if(occ > 1)
                printf("%d", occ);

            printf("%c", toupper(str[k]));
            occ = 1;
        }        
    }

    printf("\n\n");

    return;
}

void decoding(const char *str, size_t size)
{
    const char *let_del = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *num_tok = NULL;
    unsigned long occ = 0;

    printf("\n");

    num_tok = strtok((char *)str, let_del);
    while(num_tok != NULL)
    {
        sscanf(num_tok, "%lu", &occ);

        for(int k = 0; k < occ; k++)
            printf("%c", str[strlen(num_tok)]);

        num_tok = strtok(NULL, let_del);
    }

    printf("\n\n");

    return;
}