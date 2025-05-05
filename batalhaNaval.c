#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição é válida para o navio (sem sair do tabuleiro ou sobreposição)
int podeColocarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : 0); // Direção vertical
        int c = coluna + (direcao == 0 ? i : 0); // Direção horizontal
        if (l >= TAM_TABULEIRO || c >= TAM_TABULEIRO || tabuleiro[l][c] != AGUA) {
            return 0; // Fora do tabuleiro ou posição já ocupada
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : 0);
        int c = coluna + (direcao == 0 ? i : 0);
        tabuleiro[l][c] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas definidas no código para os dois navios
    int linhaHorizontal = 2, colunaHorizontal = 4; // Começa na posição (2,4)
    int linhaVertical = 5, colunaVertical = 7;     // Começa na posição (5,7)

    // Direção: 0 = horizontal, 1 = vertical
    if (podeColocarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 0)) {
        posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 0);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    if (podeColocarNavio(tabuleiro, linhaVertical, colunaVertical, 1)) {
        posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 1);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    exibirTabuleiro(tabuleiro);
    return 0;
}
