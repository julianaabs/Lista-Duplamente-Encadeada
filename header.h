#ifndef _HEADER_H_
#define _HEADER_H_

template <class object>

class Node{

private:
	object data;
	Node *next;
	Node *back;
public:
	Node(void){}
	object getData(){
		return data;
	}
	void setData(object d){
		data = d;
	}
	Node *getNext(){
		return next;
	}
	void setNext(Node *p){
		next = p;
	}
	Node *getBack(){
		return back;
	}
	void setBack(Node *b){
		back = b;
	}

};

template <class object>
class Lista{

private:
	Node<object> *head;
	Node<object> *tail;
	int fsize;
public:
	Lista(void);
	//Lista(object);
	void InserirInicio(object h);
	void InserirPosicao(object h, int pos);
	void InserirFinal(object h);
	void RemoverInicio();
	void RemoverPosicao(int pos);
	void RemoverFinal();
	void NumeroElementos();
	void BuscarElemento(object x);
	void DeletarLista();
	void ImprimirLista();
};

#include "class.inl"

#endif