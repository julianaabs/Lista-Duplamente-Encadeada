#include "header.h"

//Lista<int> l;

int main(int argc, char const *argv[]){
	Lista<int> l;
	l.InserirInicio(2);
	l.InserirInicio(5);
	l.InserirInicio(1);
	l.InserirInicio(8);
	l.InserirFinal(10);
	l.RemoverInicio();
	l.InserirPosicao(4, 2);
	l.NumeroElementos();
	l.ImprimirLista();
	return 0;
}