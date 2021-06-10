
typedef struct No {
	int identificador;//cotação por empresa
	int operacao;//1 == venda; 2 == compra;
    int acoes;
    float preco;
    struct No *proximo;
    struct No *anterior;
} No;

struct No *cabecote, *cauda = NULL;

void finalizar_sessao();
void inserir_ofertas();
void listar_ofertas(int identificador);
void ordenar_lista();
void persistir_lista();
