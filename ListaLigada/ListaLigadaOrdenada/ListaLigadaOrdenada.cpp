#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

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
	// aloca memória dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		
		primeiro = novo;
	}
	else
	{
		NO* anterior = NULL;

		NO* aux = primeiro;
		while (aux != NULL && aux->valor < novo->valor)
		{
			anterior = aux;
			aux = aux->prox;
		}
		if (aux->valor == novo->valor) {
			cout << "Elemento " << novo->valor << " ja existe na lista.\n";
				free(novo);  // Liberar a memória alocada, pois não vai inserir
				return;
			}
			aux = aux->prox;


		// Inserir no início (antes de 'primeiro')
		if (anterior == NULL)
		{
			novo->prox = primeiro;
			primeiro = novo;
		}
		else
		{
			// Inserir no meio ou no final
			anterior->prox = novo;
			novo->prox = aux;
		}
	}
}

void excluirElemento()
{
	int numero;
	cout << "Insira um numero para excluir: ";
	cin >> numero;

	
	if (primeiro == NULL) {
		cout << "A lista está vazia!" << endl;
		return;
	}

	NO* aux = primeiro;
	NO* anterior = NULL;

	// Busca o elemento a ser excluído
	while (aux != NULL && aux->valor != numero) {
		anterior = aux;          // Salva o nó anterior
		aux = aux->prox;         // Avança para o próximo nó
	}


	if (aux == NULL) {
		cout << "Elemento não encontrado." << endl;
		return;
	}

	// Excluir o primeiro elemento (caso o elemento seja o primeiro da lista)
	if (aux == primeiro) {
		primeiro = aux->prox;
	}
	else {
		// Excluir o elemento no meio ou no final
		anterior->prox = aux->prox;
	}

	
	free(aux);

	cout << "Elemento excluido com sucesso." << endl;

}

void buscarElemento()
{
	int buscar;

	cout << "Busque o elemento: ";
	cin >> buscar;

	NO* elemento = primeiro;

	if (elemento == NULL) {
		cout << "Lista Vazia";
		return;
	}
	while (elemento != NULL) {
		if (elemento->valor == buscar) {
			cout << "Elemento: " << buscar << " Encontrado." << endl;
			return;


		}
		elemento = elemento->prox;


	}

	cout << "Elemento nao encontrado. \n";


}



