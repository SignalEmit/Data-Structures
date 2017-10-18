#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node
{
private:
	Node *left;
	Node *right;
	T data;
public:
	Node(T data_,Node *left_=NULL, Node *right_=NULL):data(data_),left(left_),right(right_){}			//���캯����ֵ
	T Data()const { return data; }
	Node *&Left() { return left; }
	Node *&Right(){ return right; }
	void AddPointer(Node left_, Node right_) { left = left_; right = right_; }
	~Node(){}
};

template<class T>
class Tree
{
protected:
	Node<T> *root;							//ͷ���
public:
	Tree(T data_){ root = new Node<T>(data_, NULL,NULL); }//��ʼ��ͷ���
	void clearTree(Node<T> *root_)
	{
		if (root_ != NULL)
		{
			clearTree(root_->Right());
			clearTree(root_->Left());
			delete root_;
		}
	}
	void show(Node<T> *root_)
	{
		if (root_ != NULL)
		{
			cout << root_->Data();
			show(root->Left());
			show(root->Right());
		}
	}
	/*
	void Head_Add(Node<T> *left_, Node<T> *right_) 
	{
		root->left = left_;
		root->right = right_;
	}*/
	Node<T> *&Head() { return root; }
	void MakeTree();
	~Tree()
	{
		clearTree(root);
	}
	
};
