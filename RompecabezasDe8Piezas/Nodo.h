#ifndef NODO_H
#define NODO_H
#include "Lista8.h"

template <class T> class Nodo
{
public:
	Nodo();
	~Nodo() { }
	
	void agregarAdyacente(int adyacente) { Adyacentes.Insertar_Final(adyacente); }
	void setPadre(int Padre) { this->Padre = Padre; }
	void setMarca(bool Marca) { this->Marca = Marca; }

	Casilla8<T>* getSiguienteAdyacente(int i);
	int getPadre() { return Padre; }
	bool getMarca() { return Marca; }

	void Mostrar_Adyacentes();

private:
	Lista8<int> Adyacentes;
	int Padre;
	bool Marca;
};

template <class T> Nodo<T>::Nodo() : Adyacentes()
{
	Padre = -1;
	Marca = false;
}

template <class T> Casilla8<T>* Nodo<T>::getSiguienteAdyacente(int i)
{
	return Adyacentes.getElemento(i);
}

template <class T> void Nodo<T>::Mostrar_Adyacentes()
{
	cout << Adyacentes;
}

#endif