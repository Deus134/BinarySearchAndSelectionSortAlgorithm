#include <iostream>
#include <ctime>
using namespace std;


void FillArray(int nums[], const int sizeOfNums) // заполнение массива случайными числами
{
	for (int index = 0; index < sizeOfNums; index++)
	{
		nums[index] = rand() % 100;
	}
}

void ShowArray(int nums[], const int sizeOfNums) // вывод массива 
{
	cout << "[";
	for (int index = 0; index < sizeOfNums; index++)
	{
		cout << *(nums + index) << ", ";
	}
	cout << "\b\b]" << endl;
}

void SelectionSort(int nums[], const int sizeOfNums) // функция отвечающая за сортировку данных
{
	for (int lap = 0; lap < sizeOfNums; lap++)
	{	
		int maxNum = nums[0];
		int indexOfMaxNum = 0;
		int index = 0;
		int temp = *(nums + sizeOfNums - 1 - lap);
		for ( ; index < sizeOfNums - lap; index++)
		{
			if (nums[index] > maxNum)
			{
				maxNum = nums[index];
				indexOfMaxNum = index;
			}
		}
		*(nums + sizeOfNums - 1 - lap) = *(nums + indexOfMaxNum);
		*(nums + indexOfMaxNum) = temp;
	}

}

void binarySearch(int nums[], const int sizeOfNums, int item) // функция отвечающая за бинарный поиск
{
	int counter = 0, guess, mid, low = 0, high = sizeOfNums - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		guess = nums[mid];

		counter++;

		if (guess == item)
		{
			cout << "Ваше число найдено, оно находится в списке на позиции " << mid + 1 << endl;
			return;
		}
		if (guess > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << "Введенное вами число не найдено в списке";
}

int main()
{
	setlocale(LC_ALL, "ru");

	srand(time(NULL));

	const int SIZEofArray = 10;

	int nums[SIZEofArray];

	FillArray(nums, SIZEofArray); // заполнение массива случайными числами

	ShowArray(nums, SIZEofArray); // вывод неотсортированного массива

	SelectionSort(nums, SIZEofArray); // сортировка массива

	ShowArray(nums, SIZEofArray); // вывод отсортированного массива

	int requiredNumber;

	cout << "Введите любое число и программа проверит, присутствует ли оно в списке: ";
	cin >> requiredNumber;

	binarySearch(nums, SIZEofArray, requiredNumber); // поиск числа при помощи бинарного поиска в уже отсортированном массиве
}