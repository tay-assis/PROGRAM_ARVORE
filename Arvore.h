/*
    * Arvore.h
    * TAD que implementa uma árvore binária com funções de inserção,
    * busca, impressão, quantidade de nós internos e menor valor da árvore.
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

//PROTÓTIPOS

/**
 * @brief Cria uma nova árvore vazia.
 * 
 * @return Arv* Ponteiro para a nova árvore criada.
 */
Arv *CriaArvore();

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

//IMPLEMENTAÇÃO
Arv *CriaArvore(){
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

    // Verifica se a árvore está vazia
    if (aux == NULL){
        arvore->raiz = pai; 
    }else{
        // Verifica se o valor já existe na árvore
        if(BuscaArvore(arvore, valor)){
            printf("\nValor ja existe na arvore!\n");
            flag = 1;
            system("pause");
        }
        // Percorre a árvore até encontrar um nó folha
        while(!flag){
            // Verifica se o valor é maior ou menor que o nó atual
            if(valor > aux->info){
                // Verifica se o nó atual possui um filho à direita
                if(aux->dir != NULL){
                    aux = aux->dir;
                }
                else{
                    // Insere o novo nó à direita do nó atual
                    aux->dir = pai;
                    flag = 1;
                }
            }else{
                if(aux->esq != NULL){
                    aux = aux->esq;
                }else{
                    // Insere o novo nó à esquerda do nó atual
                    aux->esq = pai;
                    flag = 1;
                }
            }
        }
    }
    // Retorna a árvore atualizada
    return arvore;
}

void ImprimirArvore(No *pai){
    // Imprime o valor do nó atual
    printf("%d,", pai->info);
    // Verifica se o nó atual possui filhos na direita
    if(pai->dir != NULL){
        ImprimirArvore(pai->dir); // Chama a função para o filho à direita
    }
    // Verifica se o nó atual possui filhos na esquerda
    if(pai->esq != NULL){
        ImprimirArvore(pai->esq); // Chama a função para o filho à esquerda
    }
}

int BuscaArvore(Arv *arvore, int valor){
    No *aux = arvore->raiz;
    int flag = 0;

    // Verifica se a árvore está vazia
    if(VerificarVazia(arvore)){
        printf("A arvore esta vazia!");
    }else{
        // Percorre a árvore até encontrar o valor ou um nó folha
        while(!flag){
            // Verifica se o valor é maior
            if(aux->info < valor){
                if(aux->dir != NULL){
                    aux = aux->dir;
                }
                else{
                    // Se o valor não for encontrado, retorna 0
                    return 0;
                }
            // Verifica se o valor é menor
            }else if(aux->info > valor){
                if(aux->esq != NULL){
                    aux = aux->esq;
                }else{
                    return 0;
                }
            // Verifica se o valor é igual
            }else{
                if(aux->info == valor){
                    // Se o valor for encontrado, retorna 1
                    return 1;
                }else{
                    return 0;
                }
            }
        }
    }
}

int QuantNoInt(No *pai, int cont){
    // Verifica se a árvore está vazia
    if(pai == NULL){
        return 0;
    }else{
        // Verifica se o nó atual possui filhos
        if(pai->dir != NULL){
            cont++; // Incrementa o contador
            cont = QuantNoInt(pai->dir, cont); // Chama a função para o filho à direita
        }
        if(pai->esq != NULL){
            cont++; // Incrementa o contador
            cont = QuantNoInt(pai->esq, cont); // Chama a função para o filho à esquerda
        }
        // Verifica se o nó atual é uma folha
        if(pai->dir == NULL && pai->esq == NULL){
            cont--; // Decrementa o contador
        }
    }
    // Retorna o valor do contador
    return cont;
}

int MenorValor(No *pai, int valor){
    // Verifica se a árvore está vazia
    if(pai == NULL){
        return 0;
    }else{
        // Verifica se o nó atual possui filhos
        if(pai->esq != NULL){ // Se o nó atual possuir um filho à esquerda
            valor = MenorValor(pai->esq, valor); // Chama a função para o filho à esquerda
        }else{ // Se o nó atual não possuir um filho à esquerda
            valor = pai->info; // O valor do nó atual é o menor valor da árvore
            return valor; // Retorna o valor
        }
    }
}

#endif