#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL; // Adicionado ponteiro para o último elemento

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL; // Resetando o ponteiro ultimo
	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		cout << "Erro de alocacao de memoria!\n";
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		// procura o final da lista

		ultimo->prox = novo;
		ultimo = novo;
	}

	cout << "Elemento inserido com sucesso!\n";
}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia, nao ha elementos para excluir!\n";
		return;
	}

	int valor;
	cout << "Digite o elemento a ser excluido: ";
	cin >> valor;

	NO* atual = primeiro;
	NO* anterior = NULL;

	while (atual != NULL && atual->valor != valor) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual == NULL) {
		cout << "Elemento nao encontrado!\n";
		return;
	}

	if (anterior == NULL) {
		primeiro = atual->prox;

		if (primeiro == NULL) {
			ultimo = NULL;
		}
	}
	else {
		anterior->prox = atual->prox;

		if (atual == ultimo) {
			ultimo = anterior;
		}
	}

	free(atual);
	cout << "Elemento excluido com sucesso!\n";
}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia!\n";
		return;
	}

	int valor;
	cout << "Digite o elemento a ser buscado: ";
	cin >> valor;

	NO* aux = primeiro;
	int posicao = 1;

	while (aux != NULL) {
		if (aux->valor == valor) {
			cout << "Elemento " << valor << " encontrado na posicao " << posicao << "!\n";
			return;
		}
		aux = aux->prox;
		posicao++;
	}

	cout << "Elemento " << valor << " nao encontrado na lista!\n";
}