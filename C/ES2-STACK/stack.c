#include "stack.h"

stack initstack()
{
    stack s;

    s.dim = 0; //Inizializzazione della dimensione
    s.top = NULL; //La cima punta a NULL -> lo stack è vuoto

    return s;
}

short push(stack *s, int value)
{
    node *tmp = NULL; //Puntatore di supporto

    if(s == NULL) //Controllo della validità del puntatore allo stack
        return 0;

    tmp = s->top;
    s->top = (node *)calloc(1, sizeof(node)); //Creazione di un nuovo nodo, puntato da top
    s->top->value = value; //Impostazione del valore del nodo
    s->top->prev = tmp; //Collegamento tra il nodo appena creato e quello precedente

    return 1;
}

short pop(stack *s, int *value)
{
    node *tmp = NULL; //Puntatore di supporto

    //Controllo validità dei puntatori passati come parametri
    //Se il il puntatore top è nullo lo stack e vuoto -> non si può effettuare la push
    if(s == NULL || value == NULL || s->top == NULL)
        return 0;

    tmp = s->top;
    *value = s->top->value; //Impostazione del valore che restituirà la push
    s->top = s->top->prev; //Il puntatore top ora punta al nodo precedente
    free(tmp); //Deallocazione del nodo in cima allo stack

    return 1;
}