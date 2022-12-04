#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void gravar_historico(nome, vitoria_jogador, vitoria_computador){
	//funcao que salva no historico as partidas, contendo nome, rodadas ganhas e rodadas perdidas
	char vitoria_jogador_string[40], vitoria_computador_string[40];
	itoa(vitoria_jogador,vitoria_jogador_string,10);
    	itoa(vitoria_computador,vitoria_computador_string,10);
    
	FILE * file;
	file = fopen("historico.txt", "a");
	if(file == NULL){
		printf("Arquivo nao pode ser aberto");
		getchar();
		exit(1);
	}
	fprintf(file, "\nNick: %s", nome);
	fprintf(file, "Venceu: ");
	fputs(vitoria_jogador_string, file);
	fprintf(file, "------Perdeu: ");
	fputs(vitoria_computador_string, file);
	fprintf(file, "\n");
}

void mostrar_historico(void){
	//funcao que abre o arquivo onde esta o historico de todas as partidas
	FILE *file;
	file = fopen("historico.txt", "r");
	if(file==NULL){
		printf("Nao foi possivel abrir o arquivo\n");
		getchar();
		exit(0);
	}
	
	char historico[5000];
	while(fgets(historico, 5000, file) != NULL){
		printf("%s", historico);
	}

}

int computador() {     //funcao para aleatorizar a jogada feita pelo computador
    int jogada_computador;
    srand(time(NULL));
    jogada_computador = rand() % 100;
    if (jogada_computador < 33) {
        jogada_computador = 1;
    }
    else if (jogada_computador > 33 && jogada_computador < 66) {
        jogada_computador = 2;
    }
    else {
        jogada_computador = 3;
    }
    return jogada_computador; //1 pedra,2 papel,3 tesoura
}

int main () {
    int loop=0,rodadas,opcao,i=0,jogada_computador,vitoria_jogador=0,vitoria_computador=0;
    char jogada[10],pedra[]="Pedra",papel[]="Papel",tesoura[]="Tesoura",nome[100];
    printf("Digite o seu nickname: ");
    fgets(nome, 99, stdin);
    while (loop!=1) { //laco de repeticao para o jogo so acabar quando o usuario escolher sair
        printf("=_=_=_=_=_=_=_=_=_=_ Escolha a opcao abaixo _=_=_=_=_=_=_=_=_=_\n1. Iniciar o jogo\n2. Mostrar o historico\n3. Sair do jogo\n=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=\nTodos os direitos reservados a Joao Victor, Dimas, Victor e Joao Pedro\nDigite a sua opcao: ");
        scanf("%i", &opcao);
        if(opcao==1) { //opcao para iniciar o jogo
            system("cls"); //funcao para limpar o terminal
            printf("Digite quantas rodadas voce quer jogar, (O numero de rodadas deve ser impar): ");
            scanf("%i", &rodadas);
            if(rodadas>0 && rodadas%2!=0) { //comparar se o usuario escolhe um numero impar e maior que 0
                while(i<rodadas) { //laco para decidir quem ganhou
                    printf("Digite a sua jogada(Pedra, Papel ou Tesoura): ");
                    scanf("%s", jogada);
                    if(strcmp(jogada, pedra)==0) { //checar se o jogador digitou corretamente
                        system("cls");
                        jogada_computador=computador(); //funcao para aleatorizar a jogada do computador: 1 pedra,2 papel,3 tesoura
                        if(jogada_computador==1) { //condicao para checar a jogada o computador e comparar com a sua
                            printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- PEDRA X PEDRA -Computador: Empate!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                        }
                        else if(jogada_computador==2) {
                            printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- PEDRA X PAPEL -Computador: Derrota!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                            vitoria_computador+=1;
                            i++;
                        }
                        else {
                            printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- PEDRA X TESOURA -Computador: Vitoria!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                            vitoria_jogador+=1;
                            i++;
                        }
                        system("pause");
                    }    
                    else if(strcmp(jogada, tesoura)==0) {
                            system("cls");
                            jogada_computador=computador(); //1 pedra,2 papel,3 tesoura
                            if(jogada_computador==1) {
                                printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- TESOURA X PEDRA -Computador: Derrota!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                                vitoria_computador+=1;   
                                i++;                         
                            }
                            else if(jogada_computador==2) {
                                printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- TESOURA X PAPEL -Computador: Vitoria!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                                vitoria_jogador+=1;    
                                i++;                        
                            }
                            else {
                                printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- TESOURA X TESOURA -Computador: Empate!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                            }
                            system("pause");                       
                    }    
                    else if(strcmp(jogada, papel)==0) {
                            system("cls");
                            jogada_computador=computador(); //1 pedra,2 papel,3 tesoura
                            if(jogada_computador==1) {
                                printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- PAPEL X PEDRA -Computador: Vitoria!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                                vitoria_jogador+=1;
                                i++;
                            }
                            else if(jogada_computador==2) {
                                printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- PAPEL X PAPEL -Computador: Empate!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                            }
                            else {
                                printf("_=_=_=_=_=_=_=_=_=JO KEN PO=_=_=_=_=_=_=_=_=_=_\nJogador- PAPEL X TESOURA -Computador: Derrota!\n_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
                                vitoria_computador+=1;
                                i++;
                            }
                            system("pause");                     
                    } 
                    else { //mensagem de tratamento de erro caso o usuario digite errado
                        printf("Jogada invalida, digite corretamente(Pedra, Papel ou Tesoura): \n"); 
                        system("pause");
                        system("cls");
                    }
            } 
            
            gravar_historico(nome, vitoria_jogador, vitoria_computador);
            
            i=0;//zerar o indice para poder entrar novamente no laco, caso o usuario queira jogar novamente
            
            } else { //mensagem de tratamento de erro caso o usuario digite um numero par ou menor que 0
                system("cls");
                printf("Digite um numero valido de rodadas\n");
                system("pause");
            }
        }
        else if(opcao==2) { //mostrar o historico do jogo
            system("cls");
	    mostrar_historico();
            system("pause");
        }
        else if(opcao==3) { //sair do jogo
            system("cls");
            loop = 0;
            
        }
        else { //mensagem de tratamento de erro caso o usuario digite uma opcao invalida
            printf("Opcao invalida, digite uma opcao valida.");
        }
        
    system("cls");
    }
    
    return 0;
}

