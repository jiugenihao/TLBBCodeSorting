#include "pch.h"
#include "MyBinaryTreeT.h"
#include "MyLinkStackT.h"

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT()
{
	m_pRoot = nullptr;
}

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT(T prelist[], int n)
{
	int i = 0;
	m_pRoot = Create(prelist, n, i);
}

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT(T prelist[], T inlist[], int n)
{
	
}

template <class T>
MyBinaryTreeT<T>::~MyBinaryTreeT()
{
	Destroy(m_pRoot);
}

template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::GetRoot()
{
	return m_pRoot;
}

template <class T>
void MyBinaryTreeT<T>::SetRoot(BinaryNode<T>* node)
{
	m_pRoot = node;
}

// 后序遍历来删除，先删左右结点再删自身
template <class T>
void MyBinaryTreeT<T>::Destroy(BinaryNode<T>* node)
{
	if (node)
	{
		Destroy(node->m_pLeft);
		Destroy(node->m_pRight);
		delete node;
	}
}

template <class T>
bool MyBinaryTreeT<T>::IsEmpty()
{
	return (m_pRoot == nullptr);
}

template <class T>
void MyBinaryTreeT<T>::PreOrder()
{
	cout << "先序遍历二叉树：";
	PreOrder(m_pRoot);
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::PreOrder(BinaryNode<T>* node)
{
	if (node)
	{
		cout << node->m_Data;
		PreOrder(node->m_pLeft);
		PreOrder(node->m_pRight);
	}
}

template <class T>
void MyBinaryTreeT<T>::InOrder()
{
	cout << "中序遍历二叉树：";
	InOrder(m_pRoot);
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::InOrder(BinaryNode<T>* node)
{
	if (node)
	{
		InOrder(node->m_pLeft);
		cout << node->m_Data;
		InOrder(node->m_pRight);
	}
}

template <class T>
void MyBinaryTreeT<T>::PostOrder()
{
	cout << "后序遍历二叉树：";
	PostOrder(m_pRoot);
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::PostOrder(BinaryNode<T>* node)
{
	if (node)
	{
		PostOrder(node->m_pLeft);
		PostOrder(node->m_pRight);
		cout << node->m_Data;
	}
}

template <class T>
int MyBinaryTreeT<T>::Count()
{
	return Count(m_pRoot);
}

template <class T>
int MyBinaryTreeT<T>::Count(BinaryNode<T>* node)
{
	if (node)
	{
		return 1 + Count(node->m_pLeft) + Count(node->m_pRight);
	}
	return 0;
}

template <class T>
int MyBinaryTreeT<T>::Height()
{
	return Height(m_pRoot);
}

// 采用后序层次遍历
template <class T>
int MyBinaryTreeT<T>::Height(BinaryNode<T>* node)
{
	if (node)
	{
		int lh = Height(node->m_pLeft);
		int rh = Height(node->m_pRight);
		
		return (lh >= rh) ? lh+1 : rh+1;
	}
	return 0;
}

template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::Search(T value)
{
	return Search(m_pRoot, value);
}

// 采用先序遍历查找
template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::Search(BinaryNode<T>* node, T value)
{
	BinaryNode<T>* pFind = nullptr;

	if (!node)
		return nullptr;
	
	if (node->m_Data == value)
	{
		return node;
	}
	pFind = Search(node->m_pLeft, value);
	if (!pFind)
	{
		pFind = Search(node->m_pRight, value);
	}

	return pFind;
}

template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::GetParent(BinaryNode<T>* node)
{
	if (!m_pRoot || !node || node == m_pRoot)
	{
		return nullptr;
	}
	return GetParent(m_pRoot, node);
}

// 采用先序遍历获取
template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::GetParent(BinaryNode<T>* parent, BinaryNode<T>* node)
{
	BinaryNode<T>* pFind = nullptr;

	if (parent)
	{
		if (parent->m_pLeft == node || parent->m_pRight == node)
			return parent;
		pFind = GetParent(parent->m_pLeft, node);
		if (!pFind)
		{
			pFind = GetParent(parent->m_pRight, node);
		}
	}

	return pFind;
}

template <class T>
void MyBinaryTreeT<T>::GetAllAncestorNode(T value)
{
	BinaryNode<T>* find = Search(value);
	if (find)
	{
		cout << value << "的祖先结点是：";
		BinaryNode<T>* parent = GetParent(find);
		while (parent)
		{
			cout << parent->m_Data << " ";
			parent = GetParent(parent);
		}
		cout << endl;
	}
	else
		cout << "没有找到该结点" << endl;
}

// 用标明空子树的先序序列创建二叉树，先构造左子树，再构造右子树
template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::Create(T preList[], int n, int& i)
{
	BinaryNode<T>* p = nullptr;

	if (i < n)
	{
		T elem = preList[i];
		i++;
		if (NULL != elem)
		{
			p = new BinaryNode<T>(elem);
			p->m_pLeft = Create(preList, n, i);
			p->m_pRight = Create(preList, n, i);
		}
	}

	return p;
}


template <class T>
void MyBinaryTreeT<T>::PreOrderTraverse()
{
	MyLinkStackT<BinaryNode<T>*> stack;
	BinaryNode<T>* p = m_pRoot;

	cout << "非递归先序遍历二叉树：";
	while (p || !stack.IsEmpty())
	{
		// 遍历左子树
		while (p) 
		{
			cout << p->m_Data;
			stack.Push(p);
			p = p->m_pLeft;
		}//endwhile

		// 通过下一次循环中的内嵌while实现右子树遍历
		if (!stack.IsEmpty()) 
		{
			p = stack.Pop();
			p = p->m_pRight;
		}//endif
	}
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::InOrderTraverse()
{
	MyLinkStackT<BinaryNode<T>*> stack;
	BinaryNode<T>* p = m_pRoot;

	cout << "非递归中序遍历二叉树：";
	while (p || !stack.IsEmpty())
	{
		// 遍历左子树
		while (p) 
		{
			stack.Push(p);
			p = p->m_pLeft;
		}//endwhile

		if (!stack.IsEmpty())
		{
			p = stack.Pop();
			cout << p->m_Data;
			p = p->m_pRight;		//通过下一次循环实现右子树遍历
		}//endif 

	}//endwhile
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::PostOrderTraverse()
{
	MyLinkStackT<BinaryNode<T>*> stack;
	BinaryNode<T>* p = m_pRoot;

	cout << "非递归后续遍历二叉树";

	int  Tag[20];       // 栈，用于标识从左（0）或右（1）返回  
	//while (p || !stack.IsEmpty())
	//{
	//	while (p)
	//	{
	//		stack.Push(p);
	//		Tag[stack.top] = 0;
	//		p = p->m_pLeft;
	//	}
	//	while (!isempty(st) && Tag[st->top] == 1)
	//	{
	//		p = pop(st);
	//		cout << p->data << "    ";
	//	}
	//	if (!isempty(st))
	//	{
	//		Tag[st->top] = 1;    // 设置标记右子树已经访问  
	//		p = gettop(st);
	//		p = p->rchild;
	//	}
	//	else   
	//		break;
	//}
	//do
	//{
	//	while (p) //遍历左子树
	//	{
	//		x.ptr = p;
	//		x.tag = L; //标记为左子树
	//		push(s, x);
	//		p = p->lchild;
	//	}

	//	while (!StackEmpty(s) && s.Elem[s.top].tag == R)
	//	{
	//		x = pop(s);
	//		p = x.ptr;
	//		visite(p->data); //tag为R，表示右子树访问完毕，故访问根结点 
	//	}

	//	if (!StackEmpty(s))
	//	{
	//		s.Elem[s.top].tag = R; //遍历右子树
	//		p = s.Elem[s.top].ptr->rchild;
	//	}
	//} while (!StackEmpty(s));
}