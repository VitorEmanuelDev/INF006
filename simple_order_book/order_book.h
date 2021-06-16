#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#define VENDA 1
#define COMPRA 2

#define SIM 1
#define NAO 2

#define GOGL34 1
#define FBOK34 2
#define AMZO34 3


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
void negociar_ofertas();
void eliminar_compra(int posicao);
void eliminar_venda(int posicao);

#endif
