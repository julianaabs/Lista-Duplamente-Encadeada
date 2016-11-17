#include <iostream>
#include "header.h"

template <class object>
Lista<object>::Lista(){
	fsize = 0;
	head = NULL;
	tail = NULL;
}

template <class object>
void Lista<object>::InserirInicio(object h){
	if(fsize!=0){
		Node<object> *tmp = new Node<object>();
		tmp->setData(h);
		tmp->setNext(head);
		head->setBack(tmp);
		head = tmp;
		fsize++;
	}else{
		Node<object> *tmp = new Node<object>();
		tmp->setData(h);
		head = tmp;
		tail = tmp;
		tail->setNext(NULL);
		tail->setBack(NULL);
		fsize=1;
	}
}


template <class object>
void Lista<object>::InserirPosicao(object h, int pos){
	if(pos==0){
		InserirInicio(h);
		return;
	}
	if(pos>fsize){
		std::cout << "Posição inválida" << std::endl;
		return;
	}
	Node<object> *tmp = new Node<object>();
	Node<object> *cont = head;	
	for(int i=1; i<=fsize; i++){
		if(i==pos){
			tmp->setData(h);
			tmp->setNext(cont->getNext());
			Node<object> *next = cont->getNext();
			next->setBack(tmp);
			cont->setNext(tmp);
			tmp->setBack(cont);
			fsize++;
			break;
		}else{
			cont = cont->getNext();
		}
	}
}

template <class object>
void Lista<object>::InserirFinal(object h){
	if(fsize!=0){
		Node<object> *tmp = new Node<object>();
		tmp->setData(h);
		tail->setNext(tmp);
		tmp->setBack(tail);
		tail = tmp;
		tail->setNext(NULL);
		tail->setBack(tmp->getBack());
		fsize++;
	}
}

template <class object>
void Lista<object>::RemoverInicio(){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	else if(fsize==1){
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}else{
		Node<object> *tmp;
		tmp = head;
		head = head->getNext();
		head->setBack(NULL);
		delete tmp;
		fsize--;
	}
}

template <class object>
void Lista<object>::RemoverPosicao(int pos){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	if(pos>fsize){
		std::cout << "Operação inválida" << std::endl;
		return;
	}
	if(pos == 0){
		RemoverInicio();
		return;
	}
	Node<object> *cont = head;
	for(int i=1; i<=fsize; i++){
		if(i==pos){
			Node<object> *tmp = cont->getNext();
			tmp->setBack(cont);
			cont->setNext(tmp->getNext());
			cont->setBack(tmp->getBack());
			delete tmp;
			fsize--;
			break;
		}else{
			cont = cont->getNext();
		}
	}
}


template <class object>
void Lista<object>::RemoverFinal(){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	if(fsize==1){
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}
	Node<object> *cont = head;
	while(cont->getNext()!=tail) {
		cont = cont->getNext();	
	}
	tail = cont;
	delete cont->getNext();
	tail->setNext(NULL);
	fsize--;
}

template <class object>
void Lista<object>::NumeroElementos(){
	std::cout << "Tamanho da lista: " << fsize << std::endl;
}

template <class object>
void Lista<object>::BuscarElemento(object x){
	Node<object> *cont;
	int pos = 0;
	for(cont = head; cont!=NULL; cont = cont->getNext()) {
		if(x==cont->getData()){
			std::cout << "Elemento encontrado na posicao " << pos << std::endl;
			return;
		}
		pos++;
	}
	std::cout << "Elemento nao esta na lista" << std::endl;
}


template <class object>
void Lista<object>::DeletarLista(){
	Node<object> *cont = head; 
	while(cont!=NULL){
		Node<object> *tmp = cont;
		cont = tmp->getNext();
		delete tmp;
	}
	fsize=0;
	head = NULL;
	tail = NULL;
}

template <class object>
void Lista<object>::ImprimirLista(){
	Node<object> *cont = head;
	while(cont!=NULL){
		std::cout << cont->getData() << std::endl;
		cont = cont->getNext();
	}
} 