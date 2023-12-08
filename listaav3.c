#include <stdio.h>
#include <stdlib.h>

typedef struct Produto{
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
    struct Produto *prox;
}Produto;

Produto *inicializaLista(){
    return NULL;
}

Produto *adicionaProduto(Produto *lista){
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));

    printf("Digite o código do produto: ");
    scanf("%d", &novoProduto->codigo);
    printf("Digite a descrição do produto: ");
    scanf("%s", novoProduto->descricao);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto->quantidade);
    printf("Digite o valor do produto: ");
    scanf("%f", &novoProduto->valor);

    novoProduto->prox = lista;
    return novoProduto;
}

void relatorioProdutos(Produto *lista){
    printf("\nRelatório de Produtos:\n");
    while(lista != NULL){
        printf("Código: %d\n", lista->codigo);
        printf("Descrição: %s\n", lista->descricao);
        printf("Quantidade: %d\n", lista->quantidade);
        printf("Valor: %.2f\n", lista->valor);
        lista = lista->prox;
    }
}

Produto *pesquisaProduto(Produto *lista, int codigo){
    while(lista != NULL){
    if(lista->codigo == codigo){
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}

Produto *removeProduto(Produto *lista, int codigo){
    Produto *atual = lista;
    Produto *anterior = NULL;

    while(atual != NULL && atual->codigo != codigo){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual != NULL){
      if(anterior != NULL){
            anterior->prox = atual->prox;
        }else{
          lista = atual->prox;
        }
        free(atual);
        printf("Produto removido com sucesso\n");
    }else{
        printf("Produto não encontrado\n");
    }
    return lista;
}

int main(){
    Produto *estoque = inicializaLista();
    int escolha, codigo;

    do{
        printf("\nMenu:\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Consultar produtos\n");
        printf("3 - Pesquisar produto\n");
        printf("4 - Remover produto\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção acima: ");
        scanf("%d", &escolha);

        switch (escolha){
            case 1:
              estoque = adicionaProduto(estoque);
              break;
            case 2:
              relatorioProdutos(estoque);
              break;
            case 3:
              printf("Digite o código do produto: ");
              scanf("%d", &codigo);
              Produto *pesquisado = pesquisaProduto(estoque, codigo);
                if(pesquisado != NULL){
                    printf("\nProduto encontrado:\n");
                    printf("Código: %d\n", pesquisado->codigo);
                    printf("Descrição: %s\n", pesquisado->descricao);
                    printf("Quantidade: %d\n", pesquisado->quantidade);
                    printf("Valor: %.2f\n", pesquisado->valor);
                }else{
                    printf("Produto não encontrado.\n");
                }
                break;
            case 4:
              printf("Digite o código do produto a ser removido: ");
              scanf("%d", &codigo);
              estoque = removeProduto(estoque, codigo);
              break;
            case 0:
              printf("Saindo do programa.\n");
              break;
            default:
              printf("Opção inválida.\n");
        }
    }while(escolha != 0);

     while(estoque != NULL){
        Produto *temp = estoque;
        estoque = estoque->prox;
        free(temp);
    }
}
