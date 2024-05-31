#pragma once
#include <iostream>

class DynArray {
	int* arr;
	int size;
public :
	DynArray(int size) : arr{ new int[size] {} }, size{ size } {
		std::cout << "DynArray constructed for " << size
			<< " elements, for " << this << "\n";
	}
	DynArray(): DynArray(5){}
	DynArray(const DynArray& obj) : arr{ new int[obj.size] }, size{ obj.size } {
		for (int i{ 0 }; i < size; i++) {
			arr[i] = obj.arr[i];
		}

		std::cout << "DynArray copy contructed for " << size
			<< " elements, for " << this << "\n";
	}

	DynArray(DynArray&& obj): size{ obj.size } {
		arr = obj.arr;
		obj.arr = nullptr;
		obj.size = 0;

		std::cout << "DynArray move contructed for " << size
			<< " elements, for " << this << "\n";
	}

	DynArray& operator=(const DynArray& obj) {
		if (!(this == &obj)) {
			if (size != obj.size) {
				delete[] arr;
				arr = new int[obj.size];
			}
			size = obj.size;

			int* dest{ arr };
			int* src{ obj.arr };

			int* const end{ arr + size };

			while (dest < end) {
				*dest++ = *src++;
			}	
		}
		std::cout << "DyArray copy assigned for " << size
			<< " elements, for " << this << "\n";

		return *this;
	}
	DynArray& operator=(DynArray&& obj) {
		if (!(this == &obj)) {
			delete[] arr;
			arr = obj.arr;
			size = obj.size;
			obj.arr = nullptr;
			obj.size = 0;
		}
		std::cout << "DynArray move assigned for " << size
			<< " elements, for " << this << "\n";
		return *this;
	}

	int getElem(int index) { return arr[index]; }
	void setElem(int index, int val) { arr[index] = val; }
	void print() {
		for (int i{ 0 }; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	void randomize() {
		for (int i{ 0 }; i < size; i++) {
			arr[i] = rand() % 10;
		}
	}

	~DynArray() {
		std::cout << "Try to free memory from DyArray for "
			<< arr << " pointer\n";
		delete[] arr;
		std::cout << "DynArray destructed for " << size
			<< " elements, for " << this << "\n";
	}
};
