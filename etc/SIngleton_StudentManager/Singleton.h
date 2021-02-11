#pragma once
#include "���.h"

template <typename T>
class Singleton
{
private:
	static T* m_pSingleton;
protected:
	Singleton() {};
	//SIngleton(const Singleton& other) {};
public:
	static T* GetInstance()
	{
		if (m_pSingleton == NULL)
			m_pSingleton = new T;
		return m_pSingleton;
	}
	static void DestroyInstance()
	{
		if (m_pSingleton != NULL)
			delete m_pSingleton;
	}
};
template <typename T>
T* Singleton<T>::m_pSingleton = NULL;