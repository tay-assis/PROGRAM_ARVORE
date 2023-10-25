/*
    * Arvore.h
    * TAD que implementa uma árvore binária de busca.
    *
    * The MIT License (MIT)
    *
*/
#ifndef Arvore_H_INCLUDED
#define Arvore_H_INCLUDED

//BIBLIOTECAS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//ESTRUTURAS
struct No{
    int info;
    struct No *esq;
    struct No *dir;
};
typedef struct No No;

struct Arvore
{
    No *raiz;
};
typedef struct Arvore Arv;

/**
 * @brief Cria uma nova árvore vazia.
 * 
 * @return Arv* Ponteiro para a nova árvore criada.
 */
Arv *criaArvore();

/**
 * @brief Insere um novo nó com o valor especificado na árvore.
 * 
 * @param arvore Ponteiro para a árvore onde o valor será inserido.
 * @param valor Valor a ser inserido na árvore.
 * @return Arv* Ponteiro para a árvore atualizada.
 */
Arv *Inserir(Arv *arvore, int valor);

/**
 * @brief Verifica se a árvore está vazia.
 * 
 * @param arvore Ponteiro para a árvore a ser verificada.
 * @return int 1 se a árvore estiver vazia, 0 caso contrário.
 */
int VerificarVazia(Arv *arvore);

/**
 * @brief Busca um valor na árvore.
 * 
 * @param arvore Ponteiro para a árvore onde o valor será buscado.
 * @param valor Valor a ser buscado na árvore.
 * @return int 1 se o valor for encontrado na árvore, 0 caso contrário.
 */
int BuscaArvore(Arv *arvore, int valor);

/**
 * @brief Imprime a árvore em pré-ordem.
 * 
 * @param pai Ponteiro para o nó raiz da árvore a ser impressa.
 */
void ImprimirArvore(No *pai);

/**
 * @brief Conta a quantidade de nós internos da árvore.
 * 
 * @param pai Ponteiro para o nó raiz da árvore.
 * @param cont Contador de nós internos.
 * @return int Quantidade de nós internos da árvore.
 */
int QuantNoInt(No *pai, int cont);

/**
 * @brief Retorna o menor valor da árvore.
 * 
 * @param pai Ponteiro para o nó raiz da árvore.
 * @param valor Valor a ser comparado.
 * @return int Menor valor da árvore.
 */
int MenorValor(No *pai, int valor);

Arv *criaArvore(){
    Arv *Arvore = (Arv*)malloc(sizeof(Arv));
    Arvore->raiz = NULL;
    return Arvore;
}

int VerificarVazia(Arv *arvore){
    if (arvore->raiz == NULL){
        return 1;
    }
    return 0;
}

Arv *Inserir(Arv *arvore, int valor){
    No *aux = arvore->raiz;
    No *pai = (No*)malloc(sizeof(No));
    int flag = 0;

    // Inicializa a nova raiz da árvore
    pai->info = valor;
    pai->dir = NULL;
    pai->esq = NULL;

    // Se a árvore tiver vazia, o valor será a raiz da árvore
    if (aux == NULL){
        arvore->raiz = pai; //Atualize a raiz da árvore aqui
    }else{
        while(!flag){
            if(valor > aux->info){
                if(aux->dir != NULL){
                    aux = aux->dir;
                }
                else{
                    aux->dir = pai;
                    flag = 1;
                }
            }else{
                if(aux->esq != NULL){
                    aux = aux->esq;
                }else{
                    aux->esq = pai;
                    flag = 1;
                }
            }
        }
    }
    return arvore;
}

void ImprimirArvore(No *pai){
    printf("%d,", pai->info);
    if(pai->dir != NULL){
        ImprimirArvore(pai->dir);
    }
    if(pai->esq != NULL){
        ImprimirArvore(pai->esq);
    }
}

int BuscaArvore(Arv *arvore, int valor){
    No *macaco = arvore->raiz;
    int flag = 0;

    if(VerificarVazia(arvore)){
        printf("A arvore esta vazia!");
    }else{
        while(!flag){
            if(macaco->info < valor){
                if(macaco->dir != NULL){
                    macaco = macaco->dir;
                }
                else{
                    return 0;
                }
            }else if(macaco->info > valor){
                if(macaco->esq != NULL){
                    macaco = macaco->esq;
                }else{
                    return 0;
                }
            }else{
                if(macaco->info == valor){
                    return 1;
                }else{
                    return 0;
                }
            }
        }
    }
}

int QuantNoInt(No *pai, int cont){
    if(pai == NULL){
        return 0;
    }else{
        if(pai->dir != NULL){
            cont++;
            cont = QuantNoInt(pai->dir, cont);
        }
        if(pai->esq != NULL){
            cont++;
            cont = QuantNoInt(pai->esq, cont);
        }
        if(pai->dir == NULL && pai->esq == NULL){
            cont--;
        }
    }
        return cont;
}

int MenorValor(No *pai, int valor){
    if(pai == NULL){
        return 0;
    }else{
        if(pai->esq != NULL){
            valor = MenorValor(pai->esq, valor);
        }else{
            valor = pai->info;
            return valor;
        }
    }
}

#endif