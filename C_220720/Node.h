#pragma once

struct Node
{
	int data = 0;
	Node* next = nullptr;

	Node()
	{
	}

	Node(int data) : data(data)
	{}
};