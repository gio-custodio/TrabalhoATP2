#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { feminino, masculino, outro } GENERO;
typedef enum { solteiro, casado, divorciado, viuvo } ESTADO_CIVIL;
typedef enum { janeiro, fevereiro, marco, abril, maio, junho, julho, agosto, setembro, outubro, novembro, dezembro } MESES;

typedef struct Data {
    int dia;
    MESES mes;
    int ano;
} DATA;

typedef struct Equipe {
    char nome[50];
    char nickname[50];
    int numSeguidores;
} EQUIPE;

typedef struct Equipamento {
    char modelo[50];
    char Processador[50];
    char PlacaDeVideo[50];
    char MemoriaRAM[50];
} EQUIPAMENTO;

typedef struct CadastroJogador {
    char nome[50];
    int cpf;
    DATA data;
    GENERO genero;
    ESTADO_CIVIL estadoCivil;
    EQUIPE equipe;
    EQUIPAMENTO Equipamento;
    char patrocinador[50];
    char nickname[50];
    int seguidores;
    int pontuacao;
    int vitorias;
    int derrotas;
    int empates;
    int titulosGanhos;
    int rankingM;
} CADASTROJOGADOR;

void inserirJogador(CADASTROJOGADOR CadastroJogador[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nDigite o nome do jogador: ");
        fflush(stdin);
        fgets(CadastroJogador[i].nome, 50, stdin);

        printf("Digite o CPF do jogador: ");
        scanf("%d", &CadastroJogador[i].cpf);

        printf("Digite a data de nascimento do jogador: ");
        scanf("%d", &CadastroJogador[i].data);

        printf("Digite o genero do jogador: ");
        fflush(stdin);
        scanf("%d", &CadastroJogador[i].genero);

        printf("Digite o estado civil do jogador: ");
        scanf("%d", &CadastroJogador[i].estadoCivil);

        printf("Digite a equipe do jogador: ");
        scanf("%d", &CadastroJogador[i].equipe);

        printf("Digite o Equipamento do jogador: ");
        scanf("%d", &CadastroJogador[i].Equipamento);

        printf("Digite o(s) patrocinador(es) do jogador: ");
        scanf("%d", &CadastroJogador[i].patrocinador);

        printf("Digite o nickname do jogador: ");
        scanf("%d", &CadastroJogador[i].nickname);

        printf("Digite a quantidade de seguidores do jogador: ");
        scanf("%d", &CadastroJogador[i].seguidores);

        // Adicione a leitura para os outros membros da estrutura CadastroJogador
    }
}

void imprimirJogador(CADASTROJOGADOR jogadorImprimir[], int numJogadores) {
    printf("\n===== JOGADORES ====\n\n");
    for (int i = 0; i < numJogadores; i++) {
        printf("Nome: %s\n", jogadorImprimir[i].nome);
        printf("CPF: %d\n", jogadorImprimir[i].cpf);
        // Adicione a impressão para os outros membros da estrutura CadastroJogador
    }
}


void escreverJogadoresArquivo(CADASTROJOGADOR jogadoresEscrever[], int jogadoresNum) {
    FILE *file;
    file = fopen("jogadores.dat", "wb");

    if (file != NULL) {
        int qtsRegEscritos = fwrite(jogadoresNum, sizeof(CADASTROJOGADOR), jogadoresNum, file);
        printf("\nForam escritos %d registro(s) de jogador(es)!\n", qtsRegEscritos);

        fclose(file);
    } else {
        printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
    }
    return;
}

void lerJogadorArquivo(CADASTROJOGADOR jogadoresLidos[], int n) {
    FILE *file;
    file = fopen("jogadores.dat", "rb");

    if (file != NULL) {
        int qtdRegLidos = fread(jogadoresLidos, sizeof(CADASTROJOGADOR), n, file);
        printf("\nForam lidos %d registro(s) de jogador(es)!\n", qtdRegLidos);

        fclose(file);
    } else {
        printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
    }
    return;
}


int main() {


    int jogadoresNum;
    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &jogadoresNum);

    CADASTROJOGADOR jogadoresEscrever[jogadoresNum];
    inserirJogador(jogadoresEscrever, jogadoresNum);
    escreverJogadoresArquivo(jogadoresEscrever, jogadoresNum);

    CADASTROJOGADOR jogadoresLidos[jogadoresNum];
    lerJogadorArquivo(jogadoresLidos, jogadoresNum);
    imprimirJogador(jogadoresLidos,jogadoresNum);

    system("pause");
    return 0;
}
