#ifndef GRAFO_H
#define GRAFO_H
#include <fstream>
#include "Nodo.h"

template <class T> class Grafo
{
public:
	Grafo(int);
	~Grafo();

	void Insertar(T, T);
	void Resetear();

	void Busqueda_En_Amplitud(T, T, bool&);
	void Busqueda_En_Profundidad(T, T, bool&);

	void Mostrar_Camino(T, T);
	void Mostrar_Grafo();

	void Buscar_Camino_Amplitud(T, T);
	void Buscar_Camino_Profundidad(T, T);

	void Llenar_Desde_Archivo(string nomArch);

private:
	Nodo<T>* Array;
	int tam;
};

template <class T> Grafo<T>::Grafo(int tam)
{
	if (tam > 0)
	{
		Array = new Nodo<T>[tam];
		this->tam = tam;
	}
	else
	{
		Array = NULL;
	}
}

template <class T> Grafo<T>::~Grafo()
{
	if (Array != NULL)
	{
		delete[] Array;
	}
}

template <class T> void Grafo<T>::Insertar(T Elem1, T Elem2)
{
	if (Array)
	{
		if ((Elem1 >= 0) && (Elem2 >= 0))
		{
			Array[Elem1].agregarAdyacente(Elem2);
			Array[Elem2].agregarAdyacente(Elem1);
		}
	}
}

template <class T> void Grafo<T>::Resetear()
{
	if (Array)
	{
		for (int i = 0; i < tam; i++)
		{
			Array[i].setPadre(-1);
			Array[i].setMarca(false);
		}
	}
}

template <class T> void Grafo<T>::Busqueda_En_Amplitud(T Ori, T Dest, bool& Encontre)
{
	if (Array && (Ori >= 0) && (Dest >= 0))
	{
		Lista8<int> cola;
		int i_esimo, vert;
		Casilla8<T>* adya;
		Encontre = false;
		Array[Ori].setMarca(false);
		cola.Insertar_Final(Ori);

		while ((!cola.Vacia()) && (Encontre == false))
		{
			i_esimo = 1;
			vert = cola.getUltimo()->getElemento();
			cola.Eliminar_Final();
			adya = Array[vert].getSiguienteAdyacente(i_esimo);
			while ((adya != NULL) && (Encontre == false))
			{
				if (Array[adya->getElemento()].getMarca() == false)
				{
					Array[adya->getElemento()].setPadre(vert);

					if (adya->getElemento() == Dest)
					{
						Encontre = true;
					}
					else
					{
						Array[adya->getElemento()].setMarca(true);
						cola.Insertar_Final(adya->getElemento());
					}
				}
				i_esimo++;
				adya = Array[vert].getSiguienteAdyacente(i_esimo);
			}
		}
	}
	else
	{
		Encontre = false;
	}
}

template <class T> void Grafo<T>::Busqueda_En_Profundidad(T Ori, T Dest, bool& Encontre_cam)
{
	if (Array)
	{
		int i_esimo;
		Casilla8<T>* adya;
		Encontre_cam = false;
		Array[Ori].setMarca(true);
		i_esimo = 1;
		adya = Array[Ori].getSiguienteAdyacente(i_esimo);

		while (adya != NULL)
		{
			if ((Encontre_cam == false) && (Array[adya->getElemento()].getMarca() == false))
			{
				Array[adya->getElemento()].setPadre(Ori);
				if (adya->getElemento() == Dest)
				{
					Encontre_cam = true;
				}
				else
				{
					Busqueda_En_Profundidad(adya->getElemento(), Dest, Encontre_cam);
				}
			}
			i_esimo++;
			adya = Array[Ori].getSiguienteAdyacente(i_esimo);
		}
	}
	else
	{
		Encontre_cam = false;
	}
}

template <class T> void Grafo<T>::Mostrar_Camino(T Elem1, T Elem2)
{
	while (Elem2 != Elem1)
	{
		cout << Elem2 << " -> ";
		Elem2 = Array[Elem2].getPadre();
	}
	cout << Elem1;
}

template <class T> void Grafo<T>::Mostrar_Grafo()
{
	for (int i = 0; i < tam; i++)
	{
		cout << i << ": ";
		Array[i].Mostrar_Adyacentes();
		cout << endl;
	}
}

template <class T> void Grafo<T>::Buscar_Camino_Amplitud(T Elem1, T Elem2)
{
	if (Array)
	{
		bool encontrar = false;
		Busqueda_En_Amplitud(Elem1, Elem2, encontrar);
		if (encontrar)
		{
			cout << "Camino Desde " << Elem2 << " Hasta " << Elem1 << ":" << endl << endl;
			Mostrar_Camino(Elem1, Elem2);
			Resetear();
			cout << endl << endl;
		}
		else
		{
			cout << "Camino No Encontrado" << endl << endl;
		}
	}
}

template <class T> void Grafo<T>::Buscar_Camino_Profundidad(T Elem1, T Elem2)
{
	if (Array)
	{
		bool encontrar = false;
		Busqueda_En_Profundidad(Elem1, Elem2, encontrar);
		if (encontrar)
		{
			cout << "Camino Desde " << Elem2 << " Hasta " << Elem1 << ":" << endl << endl;
			Mostrar_Camino(Elem1, Elem2);
			Resetear();
		}
		else
		{
			cout << "Camino No Encontrado";
		}
	}
}

template <class T> void Grafo<T>::Llenar_Desde_Archivo(string nomArch)
{
	T Elemento1;
	T Elemento2;
	ifstream arch;

	arch.open(nomArch);

	while ((arch >> Elemento1) && (arch >> Elemento2))
	{
		Insertar(Elemento1, Elemento2);
	}

	arch.close();
}

#endif