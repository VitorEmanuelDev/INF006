#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#define VENDA 1
#define COMPRA 2

#define SIM 1
#define NAO 2

#define GOGL34 1
#define FBOK34 2
#define AMZO34 3
#define ARQUIVO 4


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


void menu();
void finalizar_sessao();
void inserir_ofertas();
void inserir_vendas();
void inserir_compra();
void listar_ofertas();
void listar_GOGL34();
void listar_FBOK34();
void listar_AMZO34();
void ordenar_vendas();
void ordenar_compras();
void persistir_compras();
void persistir_vendas();
void escolha_arquivos();
struct Compras listar_arquivos_compra();
struct Vendas listar_arquivos_venda();
struct Compras salvar_arquivos_compra();
struct Vendas salvar_arquivos_venda();
void negociar_ofertas();
void eliminar_ofertas(int posicao_venda, int valor_venda, int posicao_compra, int valor_compra);

#endif
