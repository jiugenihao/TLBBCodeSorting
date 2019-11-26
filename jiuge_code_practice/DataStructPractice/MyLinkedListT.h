/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyLinkedList.h
//������������������ʵ�ֵ����Ա�
//   MySinglyLinkedListT ������
//   �����ٶ���������ɾ������Ҫ�ƶ����ر��
//   �ʺ������룬���ʺ���ǰ
//ע�⣺
//   ��pos����������������ʱ�����ص���β���
//   Insert(int pos, T value)
//   ������������۵���������˫��������Ҫ�ҵ�pos-1λ�õĽ��
//ջʹ�ã�
//   Insert(0, value),Remove(0, &value)
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

// ������-����ͷ���
template <class T>
class MySinglyLinkedListT
{
public:
	MySinglyLinkedListT();
	MySinglyLinkedListT(T value[], int n);
	~MySinglyLinkedListT();

public:
	LinkListNode<T>* GetRoot() 
	{
		return this->m_pHead;
	}
	void SetRoot(LinkListNode<T>* node)
	{
		this->m_pHead = node;
	}
public:
	bool IsEmpty();
	int	 Size();
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	LinkListNode<T>* GetNode(int pos);	// �޷�����ͷ����ĳЩ����
	LinkListNode<T>* Insert(int pos, T value);	// posλ�ò����½ڵ�
	bool Remove(int pos, T& old);
	void Clear();
	void Concat(MySinglyLinkedListT<T>& list);
	void Visit();
	LinkListNode<T>* Search(T value);
	LinkListNode<T>* Search(T value, MySinglyLinkedListT<T>* node);
	bool Contain(T value);
	bool Remove(T value);

	friend ostream& operator << (ostream& out, const MySinglyLinkedListT<T>& list)
	{
		//out << "output all elements:" << endl;
		LinkListNode<T>* p = list.m_pHead;
		while (nullptr != p)
		{
			out << p->m_Data;
			p = p->m_pNext;
			if (nullptr != p)
				out << " ";
		}
		out << endl;
		return out;
	}

private:
	LinkListNode<T>* m_pHead;
	//int m_Len;

};


// ��ͷ���ĵ�����
