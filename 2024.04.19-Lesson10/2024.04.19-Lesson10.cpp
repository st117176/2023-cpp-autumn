﻿#include <iostream>

struct Node {
	int data;
	Node* next;
	Node(int data, Node* next) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node() { data = 0; next = nullptr; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList {
public:
	LinkedList() : head(nullptr) {};
	~LinkedList() { dispose(); }

	int Length();
	bool IsEmpty();
	void Insert(int index, int data);
	int Extract(int index);

	void PushHead(int data);
	void PushTail(int data);
	int PopHead();
	int PopTail();

	int Data(int index);
	void swap(int ia, int ib);
	void sort();
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
	{
		if (list.head == nullptr)
		{
			stream << "list empty";
			return stream;
		}
		Node* tmp = list.head;
		while (tmp != nullptr)
		{
			stream << tmp << " ";
			tmp = tmp->next;
		}
		return stream;
	}

private:
	void dispose();
	int PopData(Node* node); //!
	void InsertNode(int index, Node* node); //!
	bool IndexValid(int index);
	Node* ExtractNode(int index); //!
	Node* head;
};

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return 0;
}

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

bool LinkedList::IsEmpty()
{
	return head == nullptr;
}

void LinkedList::Insert(int index, int data)
{
	if (index == 0)
	{
		return PushHead(data);
	}
	if (index == Length())
	{
		return PushTail(data);
	}
	if (IndexValid(index))
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(data, tmp->next);
	}
}

int LinkedList::Extract(int index)
{
	if (!IndexValid(index) || head == nullptr)
	{
		return -1;
	}
	Node* node = ExtractNode(index);
	return PopData(node);
}

void LinkedList::PushHead(int data)
{
	Insert(0, data);
}

void LinkedList::PushTail(int data)
{
	Insert(Length(), data);
}

int LinkedList::PopHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* node = ExtractNode(0);
	return PopData(node);
}

int LinkedList::PopTail()
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* node = ExtractNode(Length() - 1);
	return PopData(node);
}

int LinkedList::Data(int index)
{
	if (!IndexValid(index) || head == nullptr)
	{
		return -1;
	}
	Node* tmp = head;
	while (index > 0)
	{
		tmp = tmp->next;
		--index;
	}
	return tmp->data;
}

void LinkedList::swap(int ia, int ib)
{
	if (head == nullptr || !IndexValid(ia) || !IndexValid(ib))
	{
		return;
	}
	if (ia > ib)
	{
		return swap(ib, ia);
	}
	Node* nodeb = ExtractNode(ib);
	Node* nodea = ExtractNode(ia);
	InsertNode(ia, nodeb);
	InsertNode(ib, nodea);
}

void LinkedList::sort()
{
	if (head == nullptr || Length() == 1)
	{
		return;
	}
	for (int i = 0; i < Length(); ++i)
	{
		for (int j = 0; j < Length() - 1 - i; ++j)
		{
			if (Data(j) > Data(j + 1))
			{
				swap(j, j + 1);
			}
		}
	}
}

void LinkedList::dispose()
{
	while (head != nullptr)
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

int LinkedList::PopData(Node* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	int res = node->data;
	delete node;
	return res;
}

void LinkedList::InsertNode(int index, Node* node)
{
	if ((head == nullptr || !IndexValid(index)) && index != Length() && index != 0)
	{
		return;
	}
	if (index == 0)
	{
		if (head != nullptr)
		{
			node->next = head;
		}
		head = node;
		return;
	}
	if (index == Length())
	{
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
		return;
	}
	Node* tmp = head;
	while (index > 1)
	{
		tmp = tmp->next;
		--index;
	}
	node->next = tmp->next;
	tmp->next = node;
}

bool LinkedList::IndexValid(int index)
{
	return (index >= 0 && index < Length());
}

Node* LinkedList::ExtractNode(int index)
{
	if (!IndexValid(index) || head == nullptr)
	{
		return nullptr;
	}
	Node* tmp = head;
	if (index == 0)
	{
		Node* res = head;
		head = head->next;
		return res;
	}
	while (index > 1)
	{
		tmp = tmp->next;
		--index;
	}
	Node* res = tmp->next;
	tmp->next = tmp->next->next;
	return res;
}