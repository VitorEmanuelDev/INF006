#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#define VENDA 1
#define COMPRA 2

#define SIM 1
#define NAO 2

#define GOGL34 1
#define FBOK34 2
#define AMZO34 3
#define VOLTAR 4
#define ARQUIVO 5


typedef struct Compra {
	int papel_compra;//cotação por empresa
    int acoes_compra;//quantas ações
    float preco_compra;
    struct Compra *proxima_compra;
} Compra;

typedef struct Venda {
	int papel_venda;//cotação por empresa
    int acoes_venda;//quantas ações
    float preco_venda;
    struct Venda *proxima_venda;
} Venda;


int menu();
void carregar_arquivo_compras();
void carregar_arquivo_vendas();
void popular_lista_compras(int papel, int acoes, float preco);
void popular_lista_vendas(int papel, int acoes, float preco);
void finalizar_sessao();
void inserir_ofertas();
void inserir_venda();
void inserir_compra();
void listar_ofertas();
void listar_GOGL34();
void listar_FBOK34();
void listar_AMZO34();
void ordenar_vendas();
void ordenar_compras();
void escolher_arquivos();
void buscar_arquivos_compra();
void buscar_arquivos_venda();
void salvar_arquivos_compra();
void salvar_arquivos_venda();
void negociar_ofertas();
void eliminar_ofertas(int posicao_venda, int valor_venda, int posicao_compra, int valor_compra);

#endif
