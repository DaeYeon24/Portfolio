#pragma once
#include <iostream>
#include<crtdbg.h>
using namespace std; 

template <typename T>
struct Node
{
	T data;
	Node* Left;
	Node* Right;
	Node(T input)
	{
		data = input;
		Left = NULL;
		Right = NULL;
	}
};

template <typename T>
class Tree
{
private:
	Node<T>* m_Root;
public:
	Tree();
	~Tree();
	void Insert(T data);
	void FindEmpty(Node<T>* node, T data);
	void Print(Node<T>* node);
	void PreOrder();
	void InOrder();
	void PostOrder();
	void PreOrder(Node<T>* node);
	void InOrder(Node<T>* node);
	void PostOrder(Node<T>* node);
	void Delete(T data);
	void Delete(Node<T>** node, T data);
	void Release();
	void Release(Node<T>* node);
};

template <typename T>
Tree<T>::Tree()
{
	m_Root = NULL;
}

template <typename T>
void Tree<T>::Insert(T data)
{
	if (m_Root == NULL)
		m_Root = new Node<T>(data);
	else
		FindEmpty(m_Root, data);
}

template <typename T>
void Tree<T>::FindEmpty(Node<T>* node, T data)
{
	if (data > node->data)
	{
		if (node->Right == NULL)
			node->Right = new Node<T>(data);
		else
			FindEmpty(node->Right, data);
	}
	else if (data < node->data)
	{
		if (node->Left == NULL)
			node->Left = new Node<T>(data);
		else
			FindEmpty(node->Left, data);
	}
}

template <typename T>
void Tree<T>::Print(Node<T>* node)
{
	cout << node->data << " > ";
}

template <typename T>
void Tree<T>::PreOrder()
{
	cout << "전위 : ";
	if (m_Root != NULL)
		PreOrder(m_Root);
	cout << endl << endl;
}

template <typename T>
void Tree<T>::PreOrder(Node<T>* node)
{
	if (node != NULL)
	{
		Print(node);
		PreOrder(node->Left);
		PreOrder(node->Right);
	}
}

template <typename T>
void Tree<T>::InOrder()
{
	cout << "중위 : ";
	if (m_Root != NULL)
		InOrder(m_Root);
	cout << endl << endl;
}

template <typename T>
void Tree<T>::InOrder(Node<T>* node)
{
	if (node != NULL)
	{
		InOrder(node->Left);
		Print(node);
		InOrder(node->Right);
	}
}

template <typename T>
void Tree<T>::PostOrder()
{
	cout << "후위 : ";
	if (m_Root != NULL)
		PostOrder(m_Root);
	cout << endl << endl;
}

template <typename T>
void Tree<T>::PostOrder(Node<T>* node)
{
	if (node != NULL)
	{
		PostOrder(node->Left);
		PostOrder(node->Right);
		Print(node);
	}
}

template <typename T>
void Tree<T>::Delete(T data)
{
	Delete(&m_Root, data);
}

template <typename T>
void Tree<T>::Delete(Node<T>** node, T data)
{
	Node<T>* tmp, * find_null, * find_null_above;
	if (node != NULL)
	{
		if (data > (*node)->data)
			Delete(&(*node)->Right, data);
		else if (data < (*node)->data)
			Delete(&(*node)->Left, data);
		else if (data == (*node)->data)
		{
			if ((*node)->Left == NULL && (*node)->Right == NULL) // 자식 노드가 없을때
			{																			//
				delete* node;														//
				*node = NULL;														//
				return;																//
			}																			//
			tmp = *node;
			if ((*node)->Left != NULL && (*node)->Right == NULL) // 왼쪽자식만 있을때
				*node = (*node)->Left;											//
			else if ((*node)->Right != NULL && (*node)->Left == NULL) // 오른쪽 자식만 있을때
				*node = (*node)->Right;											//
			else if ((*node)->Left != NULL && (*node)->Right != NULL) // 자식 둘 다 있을때
			{
				if ((*node)->Right->Left != NULL)
				{
					find_null_above = (*node)->Right;
					find_null = (*node)->Right->Left;
					while (find_null->Left != NULL)
					{
						find_null_above = find_null;
						find_null = find_null->Left;
					}
					find_null_above->Left = find_null->Right;
					*node = find_null;
					(*node)->Left = tmp->Left;
					(*node)->Right = tmp->Right;
				}
				else
				{
					(*node) = (*node)->Right;
					(*node)->Left = tmp->Left;
				}
			}
			delete tmp;
			return;
		}
	}
}

template <typename T>
void Tree<T>::Release()
{
	if (m_Root != NULL)
		Release(m_Root);
}

template <typename T>
void Tree<T>::Release(Node<T>* node)
{
	if (node == NULL)
		return;
	Release(node->Left);
	Release(node->Right);
	delete node;
}

template <typename T>
Tree<T>::~Tree()
{}