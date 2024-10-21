/*
    Author: Stoian Cristian-Georgian
	Github: https://github.com/bibozisbibogel/
	College: University of Craiova, F.A.C.E, 2nd year in Computer Science
	~ Cristiano Ronaldo Best Player Alive ~
	~ Real Madrid ~
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <cmath>
#include <cstring>
#include <time.h>
#include <set>
#include <queue>
#include <stdlib.h>
#include <math.h>
#define  ll  long long
#define  endl  '\n'
#define DIM 200005
#define RANDOM_PRIME 7230859
#define dbg(...)
#define  yn(f)  f? cout<<"YES\n":cout<<"NO\n"
#define INF 1e9
using namespace std;
class MaxHeap {
private:
	int size; /// marimea heap-ului
	int capacity; /// valoarea maxima de elemente pe care le putem salva in heap
	vector<int>heap; /// salvam toate elementele intr-un vector
	int parent(int i) {
		return(i - 1) / 2;
	}
	int left(int i)
	{
		return 2 * i + 1;
	}
	int right(int i)
	{
		return 2 * i + 2;
	}
	public:
		/// Constructor
		MaxHeap(int capacity);
		void insert(int k);
		int ExtractMax();
		void heapify(int i);
		void printHeap();
};
MaxHeap::MaxHeap(int capacity)
{
	size = 0;
	this->capacity = capacity;
	heap.resize(capacity);
}
void MaxHeap::insert(int k)
{
	if (size == capacity)
	{
		cout << "NU MAI ESTE LOC IN HEAP PENTRU A ADAUGA ELEMENTE NOI!" << endl;
		return;
	}
	size++;
	/// inseram la sfarsit cheia
	int i = size - 1;
	heap[i] = k;
	/// fixam proprietatea max heap-ului
	/// Mutam elementele pana cand i>=parent sau root
	while (i != 0 && heap[parent(i)] < heap[i])
	{
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}
void MaxHeap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	/// Gasim cel mai mare element din tree
	if ((l < size) && (heap[l] > heap[largest]))
		largest = l;
	if ((r < size) && (heap[r] > heap[largest]))
		largest = r;
	// Daca cel mai mare dintre l si r, continuam heapify-ul
	if (largest != i)
	{
		swap(heap[i], heap[largest]);
		heapify(largest);
	}
}
int MaxHeap::ExtractMax() {
	if (size == 0)
	{
		cout << "Heap-ul este gol!" << endl;
		return -1;
	}
	else
		if (size == 1)
		{
			size--;
			return heap[0];
		}
		else
		{
			int root = heap[0];
			heap[0] = heap[size - 1];
			size--;
			heapify(0);
			return root;
		}
}
void MaxHeap::printHeap()
{
	int power = 0;
	int value = 1;
	for (int i = 0; i < size; i++)
	{
		if (i == value)
		{
			cout << endl;
			power += 1;
			value += (1 << power);
		}
		cout << heap[i] << " ";
	}
	cout << endl;
}
int main() {
	int n;
	cout << "Introduceti numarul de elemente din heap:";
	cin >> n;
	MaxHeap heap(n);
	for (int i = 0; i < n; i++)
	{
		int value_to_be_inserted;
		cout << "Inserting element " << i + 1 << ":" << endl;
		cin >> value_to_be_inserted;
		heap.insert(value_to_be_inserted);
	}
	cout << "Momentan heap-ul arata asa:\n";
	heap.printHeap();
	cout << "Valoarea maxima din heap este egala cu: ";
	cout << heap.ExtractMax() << endl;
	cout << "Dupa extragerea numarului maxim, heap-ul arata asa: \n";
	heap.printHeap();
	return 0;
}
