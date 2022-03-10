#include <iostream>
using namespace std;

struct item
{
	int value;
	int priority;
};

class Prq
{
private:
	// Pointer to the last index
	int size = -1;

public:
	item pr[100000];
	void enqueue(int value, int priority);
	int peek();
	void dequeue();
	void display();
};

void Prq ::enqueue(int value, int priority)
{
	// Increase the size
	size++;

	// Insert the element
	pr[size].value = value;
	pr[size].priority = priority;
}

int Prq ::peek()
{
	int highestPriority = -1;
	int ind = -1;

	// Check for the element with
	// highest priority
	for (int i = 0; i <= size; i++)
	{

		// If priority is same choose
		// the element with the
		// highest value
		if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
		{
			highestPriority = pr[i].priority;
			ind = i;
		}
		else if (highestPriority < pr[i].priority)
		{
			highestPriority = pr[i].priority;
			ind = i;
		}
	}

	// Return position of the element
	return ind;
}

void Prq ::dequeue()
{
	// Find the position of the element
	// with highest priority
	int ind = peek();

	// Shift the element one index before
	// from the position of the element
	// with highest priority is found
	for (int i = ind; i < size; i++)
	{
		pr[i] = pr[i + 1];
	}
	cout << "Dequeued element is : " << pr[ind].value << endl;

	// Decrease the size of the
	// priority queue by one
	size--;
}

void Prq ::display()
{
	for (int i = 0; i <= size; i++)
	{
		cout << pr[i].value << " ";
	}
	cout << endl;
	for (int i = 0; i <= size; i++)
	{
		cout << pr[i].priority << " ";
	}
}

int main()
{
	Prq pq;
	int choice, val, priority;
	while (true)
	{
		cout << "\nEnter 1 to enqueue\n";
		cout << "Enter 2 to dequeue\n";
		cout << "Enter 3 to peek\n";
		cout << "Enter 4 to display\n";
		cout << "Enter 5 to exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "enter value and priority\n";
			cin >> val >> priority;
			pq.enqueue(val, priority);
			break;
		case 2:
			pq.dequeue();
			break;
		case 3:
			cout << "Element with highest priority : " << pq.pr[pq.peek()].value << endl;
			break;
		case 4:
			pq.display();
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}