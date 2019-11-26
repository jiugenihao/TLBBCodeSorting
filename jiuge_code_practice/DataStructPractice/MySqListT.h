/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MySqListT.h
//����������˳���ʵ�ֵ����Ա�
//   �����ȡ������ɾ����
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

template <class T>
class MySqListT
{
public:
	MySqListT(int size = MAX_SQLIST_SIZE);
	MySqListT(T value[], int len);
	~MySqListT();

	// immutable function
	bool IsEmpty();
	int  Len();
	int  Capacity();

	// mutable
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	void Insert(int pos, T value);
	void Insert(T value);				// β������
	bool Remove(int pos, T& value);
	void Clear();
	int	 Index(T value);
	bool Contain(T value);
	bool Remove(T value);				// ɾ���״γ��ֵ�valueԪ��
	void RemoveAll(T value);			// ɾ������valueԪ��
	bool Replace(T v1, T v2);			// ���״γ���Ԫ��v1�滻Ϊv2
	void ReplaceAll(T v1, T v2);		// �����Ա�������Ԫ��v1�滻Ϊv2

	// ���ҪΪ�����ز��������������������Ϊ��һ���������������ʹ����Ԫ����ת��������˳��
	// ͨ���ú�����Ϊ�����Ԫ�����Ը���ú��������Ա������ͬ�ķ���Ȩ��
	// C++���Թ涨���������������ƣ�ֻ��ʹ������
	// ���MySqListT<T>���ﲻʹ�����ã���ô�ͻᷢ���������ƣ�����ִ����󣬸��Ƴ����Ĳ�����Ҫ����
	// ������������õĻ���������������ƣ���ͬһ������Ĳ���
	friend ostream& operator << (ostream& out, const MySqListT<T>& list)
	{
		//out << "output all elements:" << endl;
		if (list.m_Len > 0)
		{
			out << list.m_pData[0];
			for (int i = 1; i < list.m_Len; ++i)
			{
				out << "," << list.m_pData[i];
			}
			out << endl;
		}
		return out;
	}

private:
	T*	m_pData;
	int	m_Len;
	int m_Size;
};
