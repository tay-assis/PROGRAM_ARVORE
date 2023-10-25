#include "Arvore.h"

int main(){
    Arv *Arvore = criaArvore();
    int resposta = 0, valor = 0;

    do{
        printf("MANIPULACAO DE ARVORE\n");
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Imprimir\n");
        printf("4 - Quantidade de nos internos\n");
        printf("5 - Menor valor da arvore\n");
        printf("6 - Sair\n");

        printf("Escolha a opcao que deseja:\n");
        fflush(stdin);
        scanf("%d", &resposta);

        switch (resposta)
        {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                Arvore = Inserir(Arvore, valor);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                int flag = 0;
                scanf("%d", &valor);
                flag = BuscaArvore(Arvore, valor);
                if(flag){
                    printf("Valor existe na arvore! (:D)\n");
                }else{
                    printf("Valor nao existe na arvore! (:c)\n");
                }
                system("pause");
                break;
            case 3:
                printf("\n---------ARVORE--------- \n");
                printf("--> ");
                ImprimirArvore(Arvore->raiz);
                printf("\n-------------------------\n");
                system("pause");
                break;
            case 4:
                int quant = 1;
                quant = QuantNoInt(Arvore->raiz, quant);
                printf("A quantidade de nos internos na arvore e: %d\n", quant);
                break;
            case 5:
                int menor_valor = 0;
                menor_valor = MenorValor(Arvore->raiz, menor_valor);
                printf("O menor valor da arvore e: %d\n", menor_valor);
                break;
            case 6:
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
                break;
        }       
    }while(resposta != 6);

    return 0;
}