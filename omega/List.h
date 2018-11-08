#pragma once
#include "pch.h"
#include <iostream>
#include <string>

template<typename T>
class Node
{
public:
	Node * pNext;
	T data;

	Node(T data = T(), Node *pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};

template<typename T>
class List
{
public:
	List();
	~List();
	int Size;
	Node<T> *head;

	void add_end(T data);//добавить в конец//
	int GetSize();        // узнать размер//
	T& find(const int index);// переход к элементу//
	void delete_first();//удаление первого//
	void delete_all();// очистить список//
	void add_first(T data);//добавление элемента в начало списка//
	void add_index(T data, int index);//добавление элемента в список по указанному индексу//
	void delete_index(int index);   //удаление элемента в списке по указанному индексу//
	void delete_end();//удаление последнего элемента в списке//

};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}



template<typename T>
void List<T>::add_end(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;


		while (current->pNext != nullptr)
		{
			current = current->pNext;

		}
		current->pNext = new Node<T>(data);


	}

	Size++;
}

template<typename T>
int List<T>::GetSize() {
	return Size;
}

template<typename T>
T & List<T>::find(const int index)
{
	int counter = 0;

	Node<T> *current = this->head;

	while (counter != Size)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::delete_first()
{
	Node<T> *tmp = head;

	head = head->pNext;

	delete tmp;

	Size--;

}


template<typename T>
void List<T>::delete_all()
{
	while (Size != 0)
	{
		delete_first();
	}
}

template<typename T>
List<T>::~List()
{

	delete_all();
}


template<typename T>
void List<T>::add_first(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::add_index(T data, int index)
{

	if (index == 0)
	{
		add_first(data);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newData = new Node<T>(data, previous->pNext);

		previous->pNext = newData;

		Size++;
	}





}

template<typename T>
void List<T>::delete_index(int index)
{
	if (index == 0)
	{
		delete_first();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *rubbish = previous->pNext;
		previous->pNext = rubbish->pNext;
		delete rubbish;
		Size--;
	}

}


template<typename T>
void List<T>::delete_end()
{
	delete_index(Size - 1);
}



