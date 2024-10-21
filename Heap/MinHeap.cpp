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
class MinHeap
{
private:
	int size; /// marimea movilei
	int capacity; /// marimea maxima
	vector<int>heap; /// salvam elementele intr-un vector
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }
public:
	///Constructor
	MinHeap(int capacity);
	void insert(int k);
	int ExtractMin();
	void heapify(int i);
	void printHeap();
};
/// Constructor care seteaza dimensiunea movilei si capacitatea
MinHeap::MinHeap(int capacity) {
	size = 0;
	this->capacity = capacity;
	heap.resize(capacity);
}
void MinHeap::insert(int k)
{
	if (size == capacity)
	{
		cout << "MinHeap-ul este PLIN!" << endl;
		return;
	}
	///crestem numarul de elemente din movila
	size++;
	// Inseram cheia noua la sfarsit
	int i = size - 1;
	heap[i] = k;
	
	// Fixam proprietatea min heap-ului
	// Mutam elementele pana cand i >= parent sau root
	while (i != 0 && heap[parent(i)] > heap[i])
	{
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}
void MinHeap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	/// Cautam cel mai mic element din tree
	if ((l < size) && (heap[l] < heap[smallest]))
		smallest = l;
		if ((r < size) && (heap[r] < heap[smallest]))
			smallest = r;
		if (smallest != i)
		{
			swap(heap[i], heap[smallest]);
			heapify(smallest);
		}
}
int MinHeap::ExtractMin(){
	if (size == 0)
	{
		cout << "Empty Heap" << endl;
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
void MinHeap::printHeap()
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
	/*
		Exemplul din curs:
		n=4
		heap[1]=12
		heap[2]=7
		heap[3]=29
		heap[4]=25

		ExtractMin -> 7
	*/
	cout << "Cat de lung vreti sa fie heap-ul?\n";
	cin >> n;
	MinHeap heap(n);
	for (int i = 0; i < n; i++)
	{
		cout << "Inserting element " << i + 1 << ":";
		int value_to_be_inserted;
		cin >> value_to_be_inserted;
		heap.insert(value_to_be_inserted);
		cout << endl;
	}
	cout << "Heap-ul arata momentan asa:\n";
	heap.printHeap();
	cout << "Cea mai mica valoare din Heap este egala cu: ";
	cout << heap.ExtractMin() << endl;
	cout << "Dupa extragere heap-ul arata asa:\n";
	heap.printHeap();
	return 0;
}
