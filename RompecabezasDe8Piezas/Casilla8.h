#ifndef CASILLA8_H
#define CASILLA8_h
#include<iostream>

using namespace std;

template <class T> class Casilla8
{
public:
	Casilla8();
	~Casilla8();

	void Asignar(Casilla8<T>* Anterior, T Elemento, Casilla8<T>* Siguiente);

	Casilla8<T>* getAnterior() { return Anterior; }
	T getElemento() { return Elemento; }
	Casilla8<T>* getSiguiente() { return Siguiente; }

	void setAnterior(Casilla8<T>* Anterior) { this->Anterior = Anterior; }
	void setElemento(T Elemento) { this->Elemento = Elemento; }
	void setSiguiente(Casilla8<T>* Siguiente) { this->Siguiente = Siguiente; }

	void mostrar();

private:
	Casilla8<T>* Anterior;
	T Elemento;
	Casilla8<T>* Siguiente;
};

template <class T> Casilla8<T>::Casilla8()
{
	Anterior = Siguiente = NULL;
}

template <class T> Casilla8<T>::~Casilla8()
{
	//NO DELETE
}

template <class T> void Casilla8<T>::Asignar(Casilla8<T>* Anterior, T Elemento, Casilla8<T>* Siguiente)
{
	this->Anterior = Anterior;
	this->Elemento = Elemento;
	this->Siguiente = Siguiente;
}

template <class T> void Casilla8<T>::mostrar()
{
	cout << Elemento;
}

#endif