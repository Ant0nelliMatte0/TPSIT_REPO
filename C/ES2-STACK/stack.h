/*
 * stack.h
 * 
 * Implementazione di uno stack in C
 *
 * Autore:   Nicolò Maffi
 * Data:     16/05/2020
 * Versione: 1.2
*/

#include <stdio.h> //Per size_t
#include <stdlib.h> //Per calloc

#ifndef _STACK_H_
#define _STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node_t //Tipo node -> rappresenta una cella dello stack
{
    int value; //Valore del nodo
    struct node_t *prev; //Puntatore del nodo precedente
}node;

typedef struct stack_t //Tipo stack
{
    size_t dim; //Dimensione dello stack
    node *top; //Puntatore alla cima dello stack
}stack;

//Funzionne che inizializza lo stack
//VALORE DI RITORNO: stack inizializzato
stack initstack();

//Funzione di push -> inserimento di un dato nello stack
//PARAMETRI: s = puntatore allo stack su cui si vuole effettuare la push
//           value = valore che si vuole far assumere al nodo
//VALORE DI RITORNO: 1 se loperazione è riuscita, 0 altrimenti
short push(stack *s, int value);

//Funzione di pop -> rimozione di un dato dallo stack
//PARAMETRI: s = puntatore allo stack su cui si vuole effettuare la push
//           value = valore del nodo che ritornerà la push
//VALORE DI RITORNO: 1 se loperazione è riuscita, 0 altrimenti
short pop(stack *s, int *value);

#ifdef __cplusplus
}
#endif

#endif //_STACK_H_
