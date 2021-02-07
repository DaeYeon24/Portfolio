#pragma once

template <typename T>
class Singleton
{
private:
	static T* m_pThis;
protected:
	Singleton() {};
	virtual ~Singleton() {};
	Singleton(const T& other) {};
public:
	static T* GetInstance()
	{
		if (m_pThis == NULL)
			m_pThis = new T;
		return m_pThis;
	}
	static void DestroyInstance()
	{
		if (m_pThis != NULL)
			delete m_pThis;
	}
};

template <typename T>
T* Singleton<T>::m_pThis = NULL;