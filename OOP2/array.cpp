#include "array.h"

Array::Array() 
{
	size = 0;
	capacity = 2;
	array = new number[capacity];
}

Array::Array(int initCapacity) 
{
	size = 0;
	capacity = initCapacity;
	array = new number[capacity];
}

Array::~Array() {
	delete[] array;
};

void Array::clear()
{
	resize(2);
	size = 0;
}

void Array::resize(int newCapacity)
{
	if (newCapacity < 0) return;

	size = min(size, newCapacity);
	number* temp = new number[newCapacity];
	for (int i = 0; i < size; i++) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
	capacity = newCapacity;
}

void Array::add(number value)
{
	if (size >= capacity) {
		resize(capacity * 2);
	}
	array[size] = value;
	size++;
}

void Array::remove()
{
	if (size > 0) {
		size--;
		if (size <= capacity / 4 && capacity > 2) {
			resize(capacity / 2);
		}
	}
}

void Array::fill(string& input)
{
	stringstream ss(input);
	number value;
	while (ss >> value) {
		add(value);
	}
}

void Array::show(ostream& output)
{
	output << "Массив: ";
	for (int i = 0; i < size; i++) {
		output << array[i] << ' ';
	}
	output << '\n';
}

number& Array::operator[](int index) {
	if (index < 0 || index >= size) {
		throw out_of_range("Index out of range");
	}
	return array[index];
}

number Array::average()
{
	number res = 0;
	for (int i = 0; i < size; i++) {
		res += array[i];
	}
	res /= size;

	return res;
}

number Array::MSD()
{
	number avg = average();
	number res = 0;
	for (int i = 0; i < size; i++) {
		res += pow((array[i] - avg), 2);
	}
	res = sqrt((1.0 / (size - 1)) * res);

	return res;
}

int Array::partition(int low, int high)
{
	number pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[high]);

	return (i + 1);
}

void Array::quickSort(int low, int high)
{
	if (low < high) {
		int pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

void Array::reverse()
{
	for (int i = 0; i < size / 2; i++) {
		swap(array[i], array[size - i - 1]);
	}
}

void Array::sort(bool isReversed)
{
	quickSort(0, size - 1);

	if (isReversed) {
		reverse();
	}
}