#include <iostream>
#include <string>

using namespace std;

int N, M;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* addr[1000001];

Node* new_node(int x) {
	Node* node = new Node;
	node->data = x;
	addr[x] = node;
	return node;
}

void insert(Node* A, Node* B, Node* X) {
	A->next = X;
	X->prev = A;
	B->prev = X;
	X->next = B;
}

void erase(Node* X) {
	X->prev->next = X->next;
	X->next->prev = X->prev;

	addr[X->data] = nullptr;
	delete X;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int x;
	cin >> x;
	Node* st = new_node(x);
	addr[st->data] = st;
	Node* tail = st;
	for (int i = 1; i < N - 1; ++i)
	{
		cin >> x;
		Node* n = new_node(x);
		tail->next = n;
		n->prev = tail;
		tail = n;
		addr[n->data] = n;
	}
	if (N >= 2) {
		cin >> x;
		Node* en = new_node(x);
		tail->next = en;
		en->prev = tail;
		tail = en;
		en->next = st;
		st->prev = en;
		addr[en->data] = en;
	}
	while (M--) {
		string cmd;
		cin >> cmd;

		int i, j;

		if (cmd == "BN") {
			cin >> i >> j;
			cout << addr[i]->next->data << "\n";
			Node* n = new_node(j);
			insert(addr[i], addr[i]->next, n);
		}
		else if (cmd == "BP") {
			cin >> i >> j;
			cout << addr[i]->prev->data << "\n";
			Node* n = new_node(j);
			insert(addr[i]->prev, addr[i], n);
		}
		else if (cmd == "CN") {
			cin >> i;
			cout << addr[i]->next->data << "\n";
			erase(addr[i]->next);
		}
		else if (cmd == "CP") {
			cin >> i;
			cout << addr[i]->prev->data << "\n";
			erase(addr[i]->prev);
		}
	}

	return 0;
}

