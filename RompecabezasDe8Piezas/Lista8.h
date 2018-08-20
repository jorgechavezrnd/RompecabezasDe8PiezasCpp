#ifndef LISTA8_H
#define LISTA8_H
#include <string>
#include <fstream>
#include "Casilla8.h"

template <class T> class Lista8
{
public:
	Lista8();
	~Lista8();

	void Insertar_Principio(T Elemento);
	void Insertar_Final(T Elemento);
	void Eliminar_Principio();
	void Eliminar_Final();

	template <class U> friend ostream& operator<<(ostream&, Lista8<U>&);

	Casilla8<T>* getPrimero() { return Primero; }
	Casilla8<T>* getUltimo() { return Ultimo; }

	bool Buscar_Recursivo(T Elemento, Casilla8<T>* casilla);
	bool Buscar_Iterativo(T Elemento);
	void Insertar_En_Su_Lugar(T Elemento);

	T Buscar_Mayor_Recursivo(T Elemento, Casilla8<T>* casilla);
	T Buscar_Mayor_Iterativo();

	void Invertir_Lista();

	void Mostrar_Lista();

	void Llenar_Desde_Archivo(string nomArch);

	void Eliminar_Elemento(T Elemento);

	void Unir_Con(Lista8<T>& lista, Lista8<T>& resp);

	void Merge(Lista8<T>& l2);

	Casilla8<T>* getElemento(int i);

	bool Vacia() { return Primero == NULL; }

private:
	Casilla8<T>* Primero;
	Casilla8<T>* Ultimo;
};

template <class T> Lista8<T>::Lista8()
{
	Primero = NULL;
	Ultimo = NULL;
}

template <class T> Lista8<T>::~Lista8()
{
	while (Primero != NULL)
	{
		Eliminar_Final();
	}
}

template <class T> void Lista8<T>::Insertar_Principio(T Elemento)
{
	if (Primero == NULL) //LISTA VACIA
	{
		Primero = new Casilla8<T>;
		Primero->Asignar(NULL, Elemento, NULL);
		Ultimo = Primero;
	}
	else
	{
		Casilla8<T>* aux = new Casilla8<T>;
		aux->Asignar(NULL, Elemento, Primero);
		Primero->setAnterior(aux);
		Primero = aux;
	}
}

template <class T> void Lista8<T>::Insertar_Final(T Elemento)
{
	if (Primero == NULL) //LISTA VACIA
	{
		Primero = new Casilla8<T>;
		Primero->Asignar(NULL, Elemento, NULL);
		Ultimo = Primero;
	}
	else
	{
		Casilla8<T>* aux = new Casilla8<T>;
		aux->Asignar(Ultimo, Elemento, NULL);
		Ultimo->setSiguiente(aux);
		Ultimo = aux;
	}
}

template <class T> void Lista8<T>::Eliminar_Principio()
{
	if (Primero != NULL)
	{
		if (Primero == Ultimo)
		{
			delete Primero;
			Primero = NULL;
			Ultimo = NULL;
		}
		else
		{
			Casilla8<T>* aux = Primero->getSiguiente();
			aux->setAnterior(NULL);
			delete Primero;
			Primero = aux;
		}
	}
}

template <class T> void Lista8<T>::Eliminar_Final()
{
	if (Primero != NULL)
	{
		if (Primero == Ultimo)
		{
			delete Primero;
			Primero = NULL;
			Ultimo = NULL;
		}
		else
		{
			Casilla8<T>* aux = Ultimo->getAnterior();
			aux->setSiguiente(NULL);
			delete Ultimo;
			Ultimo = aux;
		}
	}
}

template <class U> ostream& operator<<(ostream& o, Lista8<U>& lista)
{
	if (lista.Primero == NULL)
		o << "[]";
	else
	{
		Casilla8<U>* Pos = lista.Primero;
		o << "[";
		while (Pos->getSiguiente() != NULL)
		{
			o << Pos->getElemento() << ",";
			Pos = Pos->getSiguiente();
		}
		o << lista.Ultimo->getElemento() << "]";
	}
	return o;
}

template <class T> bool Lista8<T>::Buscar_Recursivo(T Elemento, Casilla8<T>* casilla)
{
	bool resp = false;

	if (casilla != NULL)
	{
		if (casilla->getElemento() == Elemento)
		{
			resp = true;
		}
		else
		{
			resp = Buscar_Recursivo(Elemento, casilla->getSiguiente());
		}
	}

	return resp;
}

template <class T> bool Lista8<T>::Buscar_Iterativo(T Elemento)
{
	bool resp = false;
	Casilla8<T>* aux = Primero;

	while (aux != NULL)
	{
		if (aux->getElemento() == Elemento)
		{
			resp = true;
			break;
		}
		else
		{
			aux = aux->getSiguiente();
		}
	}

	return resp;
}

template <class T> void Lista8<T>::Insertar_En_Su_Lugar(T Elemento)
{
	if (Primero == NULL)
	{
		Insertar_Principio(Elemento);
	}
	else
	{
		if (Elemento < Primero->getElemento())
		{
			Insertar_Principio(Elemento);
		}
		else
		{
			if (Elemento > Ultimo->getElemento())
			{
				Insertar_Final(Elemento);
			}
			else
			{
				Casilla8<T>* aux = Primero->getSiguiente();

				while (Elemento > aux->getElemento())
				{
					aux = aux->getSiguiente();
				}

				Casilla8<T>* Nuevo = new Casilla8<T>;
				Nuevo->setElemento(Elemento);
				Nuevo->setSiguiente(aux);
				Nuevo->setAnterior(aux->getAnterior());
				aux->getAnterior()->setSiguiente(Nuevo);
				aux->setAnterior(Nuevo);
			}
		}
	}
}

template <class T> T Lista8<T>::Buscar_Mayor_Recursivo(T Elemento, Casilla8<T>* casilla)
{
	if (casilla != NULL)
	{
		if (Elemento < casilla->getElemento())
		{
			Elemento = Buscar_Mayor_Recursivo(casilla->getElemento(), casilla->getSiguiente());
		}
		else
		{
			Elemento = Buscar_Mayor_Recursivo(Elemento, casilla->getSiguiente());
		}
	}

	return Elemento;
}

template <class T> T Lista8<T>::Buscar_Mayor_Iterativo()
{
	T resp = Primero->getElemento();

	if (Primero != NULL)
	{
		Casilla8<T>* aux = Primero->getSiguiente();

		while (aux != NULL)
		{
			if (resp < aux->getElemento())
			{
				resp = aux->getElemento();
			}

			aux = aux->getSiguiente();
		}
	}

	return resp;
}

template <class T> void Lista8<T>::Invertir_Lista()
{
	if (Primero != NULL)
	{
		Casilla8<T>* ant = Primero->getAnterior();
		Primero->setAnterior(Primero->getSiguiente());
		Primero->setSiguiente(ant);

		Casilla8<T>* aux = Primero->getAnterior();

		while (aux != NULL)
		{
			ant = aux->getAnterior();
			aux->setAnterior(aux->getSiguiente());
			aux->setSiguiente(ant);
			aux = aux->getAnterior();
		}

		aux = Primero;
		Primero = Ultimo;
		Ultimo = aux;
	}
}

template <class T> void Lista8<T>::Mostrar_Lista()
{
	if (Primero == NULL)
		cout << "[]";
	else
	{
		Casilla8<T>* Pos = Primero;
		cout << "[";
		while (Pos->getSiguiente() != NULL)
		{
			cout << Pos->getElemento() << ",";
			Pos = Pos->getSiguiente();
		}
		cout << Ultimo->getElemento() << "]";
	}
}

template <class T> void Lista8<T>::Llenar_Desde_Archivo(string nomArch)
{
	T Elemento;
	ifstream arch;

	arch.open(nomArch);

	while (arch >> Elemento)
	{
		Insertar_Final(Elemento);
	}

	arch.close();
}

template <class T> void Lista8<T>::Eliminar_Elemento(T Elemento)
{
	if (Primero != NULL)
	{
		Casilla8<T>* aux = Primero;

		while (aux != NULL)
		{
			if (aux->getElemento() == Elemento)
			{
				if (aux == Primero)
				{
					Eliminar_Principio();
					break;
				}
				else
				{
					if (aux == Ultimo)
					{
						Eliminar_Final();
						break;
					}
					else
					{
						aux->getAnterior()->setSiguiente(aux->getSiguiente());
						aux->getSiguiente()->setAnterior(aux->getAnterior());
						delete aux;
						break;
					}
				}
			}
			aux = aux->getSiguiente();
		}
	}
}

template <class T> void Lista8<T>::Unir_Con(Lista8<T>& lista, Lista8<T>& resp)
{
	Casilla8<T>* pos = Primero;

	while (pos != NULL)
	{
		resp.Insertar_Final(pos->getElemento());
		pos = pos->getSiguiente();
	}

	pos = lista.getPrimero();

	while (pos != NULL)
	{
		resp.Insertar_Final(pos->getElemento());
		pos = pos->getSiguiente();
	}
}

template <class T> void Lista8<T>::Merge(Lista8<T>& l2)
{
	Casilla8<T>* pos = l2.getPrimero();

	while (pos != NULL)
	{
		Insertar_En_Su_Lugar(pos->getElemento());
		pos = pos->getSiguiente();
		l2.Eliminar_Principio();
	}
}

template <class T> Casilla8<T>* Lista8<T>::getElemento(int i)
{
	int pos = 1;
	Casilla8<T>* aux = Primero;

	while ((pos <= i) && (aux != NULL))
	{
		if (pos == i)
		{
			return aux;
		}
		aux = aux->getSiguiente();
		pos++;
	}

	return NULL;
}

#endif