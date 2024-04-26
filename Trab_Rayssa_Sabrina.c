/****************************************************************************** 
 * TRABALHO 1 - Estrutura de dados
 * Programadoras Rayssa e Sabrina 
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>


void imprimindo_vetor (int *ovetor, bool *preenchido){   //funcao pra imprimir o vetor
    int i, elem_preenchidos=0;
    printf("\n");
    for (i=0;i<18;i++){
        if(preenchido[i] == true){
            printf("Pos [ %d ] = %d\n", i+1, ovetor[i]);
            elem_preenchidos++;
        }else{
            printf("Pos [ %d ] - esta vazia - \n", i+1);
        }
    }
    printf("\nTemos %d posicoes preenchidas no vetor.\n\n",elem_preenchidos);
}

void consulta_pos(int *ovetor, bool *preenchido) {    //função para consultar posições do vetor
    int pos;
    printf("\n");
    printf("Informe a posicao a ser consultada: ");
    printf("\n");
    scanf(" %d", &pos);                             //Leitura da posição dada pelo usuário
    
    if(pos >= 1 && pos <= 18) {                     //Condicional para averiguar se a posição existe no vetor
        
        if(preenchido[pos-1] == true) {             //Condicional para averiguar se a posição esta disponivel
            printf("\n");
            printf("Na posicao: %d , temos o valor: %d.", pos, ovetor[pos-1]);
            printf("\n");
            return;
        } else {
            printf("\n");
            printf(" --- A posicao esta vazia --- ");
            printf("\n");
            return;
        }

    } else {
        printf("\n");
        printf(" --- Posicao nao encontrada ---");
        printf("\n");
        return;
    }
}

void preenchendo (int *ovetor, bool *preenchido){ //função para adicionar elementos ao vetor
    int i,valor,pos;
        printf("\n");
        printf ("informe o valor da posicao a ser alterada: ");
        scanf("%d",&pos);
        for(i = 0; i < 18; i++) {
        if(preenchido[i] == false) {    //percorrendo o vetor e parando na primeira casa vazia afim de descobrir se o vetor esta cheio ou nao.
            break;
        }
    }
    if(i == 18) {                       //se o contador foi ate 18 eh pq o vetor estava cheio
        printf("\n");
        printf("Vetor cheio - selecione outra operacao");
        printf("\n");
        return;
    }
    if(pos >= 1 && pos <= 18) {                   //Condicional para garantir que o usuario entre com um valor de posicao valido.

        printf("\nInforme o valor a ser adicionado a posicao [%d] : \n",pos);
        scanf("%d", &valor);
        if(preenchido[pos-1] == false) {                //condicional de o vetor de preenchimento indicar que a posicao esta disponivel
                    
                    for(i = 0; i < 18; i++) {         //percorrendo o vetor até encontrar o primeiro espaço vazio  
                        if(preenchido[i] == false) {
                            ovetor[i] = valor;        //encontrado o espaço vazio, ele recebe o valor
                            preenchido[i] = true;
                            return;
                        }
                    }
                }else {                            //Caso da posição ocupada
            for(i = 17; i >= pos; i--) {    //percorrer o  vetor de tras pra frente para encontrar a posição inserida e ir rearranjando o lugar dos elementos para frente
                ovetor[i] = ovetor[i-1];     //empurrando adiante afim de acomodar o valor na posicao desejada ~o da frente recebe o de tras
                preenchido[i] = preenchido[i-1];
            }
            ovetor[pos-1] = valor;           //efetivamente inserindo o valor no local desejado
            printf("\n\tO valor foi adicionado com sucesso!\n");
            preenchido[pos-1] = true;
        }
    } else {
        printf("\n");
        printf(" --- Posicao nao encontrada, selecione outra operacao ---");
        printf("\n");
        return;
    }
    
}

void remove_elem (int *ovetor, bool *preenchido) {    //função para remover elementos do vetor
    int pos, i;
    printf("\n");
    printf("Informe a posicao da qual se deseja remover o conteudo: ");
    printf("\n");
    scanf(" %d", &pos); // Obtém a posição do usuário
    
    
    if(pos >= 1 && pos <= 18 && preenchido[pos-1] == true) {            //Condicional para verificar se a posição realmente está preenchida e se o vetor tem essa posição
        for(i = (pos - 1); i < 17 && preenchido[i+1] == true; i++) {    //Como na remoção os valores posteriores vao descer uma posição, percorremos o vetor
            ovetor[i] = ovetor[i+1];                                    //da posição removida em diante e para cada espaço ocupado, atribuimos o conteudo da memória posterior 
        }
        ovetor[i] = 0;              //Como um elemento foi removido, a ultima posicao que estava preenchida obrigatoriamente ficara vazia
        preenchido[i] = false;      
        printf("\n\tO valor foi removido com sucesso!\n");
    } else {
        printf("\n");
        printf(" --- Posicao nao encontrada ou vazia, selecione outra operacao ---");
        printf("\n");
        return;
    }
}



void menu_op (){ //função para imprimir o menu de opções
    printf("\n");
    printf("   ____________________________________________________  \n");
    printf("   --- Esse eh o humilde programa do vetor ---  \n");
    printf("   --- Escolha uma operacao para fazer: \n");
    printf("   ____________________________________________________  \n\n");
    printf("   --- Imprimir o vetor                     -- digite 1  \n");
    printf("   --- Consultar uma posicao no vetor       -- digite 2  \n");
    printf("   --- Inserir valor em uma dada posicao    -- digite 3  \n");
    printf("   --- Remover valor de uma dada posicao    -- digite 4 \n");
    printf("   --- Finalizar o programa                 -- digite 0  \n");
    printf("   ____________________________________________________  \n");
    printf("   Escolha:  ");

}


int main()
{
    int op, ovetor[18] = {0};
    bool preenchido[18] = {false};


    do {
        imprimindo_vetor(ovetor,preenchido);
        menu_op (); //chamada do menu de opcoes
        scanf("%d",&op); 
            switch (op)
            {
            case 1:
                ////////
                printf("\n   ______Imprimir o vetor______________________________________________  \n");
                imprimindo_vetor (ovetor, preenchido);
                break;
            case 2:
                ////////
                printf("\n   ______Consultar uma posicao no vetor________________________________  \n");
                consulta_pos(ovetor, preenchido);
                break;
            case 3:
                ////////
                printf("\n   ______Inserir valor em uma dada posicao_____________________________  \n");
                preenchendo(ovetor, preenchido);
                break;    
            case 4:
                ////////
                printf("\n   ______Remover valor de uma dada posicao_____________________________  \n");
                remove_elem(ovetor, preenchido);
                break;
            case 0:
                break;   

            default:
                printf("\n   ____________________________________________________  \n");
                printf("   |      --  Opcao invalida, digite novamente  --    |  \n");
                printf("   |__________________________________________________|  \n");
                break;
            }            
        

    } while(op != 0);

    printf("\n   ____________________________________________________  \n");
    printf("\n       Programa finalizado ... saindo ...\n");
    printf("   ____________________________________________________  \n");



    return 0;
}

