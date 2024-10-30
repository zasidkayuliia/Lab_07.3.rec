#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3.rec/Lab_07.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{// Створюємо тестову матрицю 3x3
			const int n = 3;
			int** matrix = new int* [n];
			for (int i = 0; i < n; ++i)
				matrix[i] = new int[n];

			// Ініціалізуємо значення елементів матриці
			// Матриця:
			// 1  -2  3
			// 4   5 -6
			// 7   8  9
			matrix[0][0] = 1;
			matrix[0][1] = -2;
			matrix[0][2] = 3;
			matrix[1][0] = 4;
			matrix[1][1] = 5;
			matrix[1][2] = -6;
			matrix[2][0] = 7;
			matrix[2][1] = 8;
			matrix[2][2] = 9;

			// Розраховуємо очікуваний результат: | -2 | + | 3 | + | -6 | = 2 + 3 + 6 = 11
			int expectedSum = 11;

			// Викликаємо функцію SumAboveMainDiag
			int result = SumAboveMainDiag(matrix, n);

			// Перевіряємо, чи збігається результат з очікуваним
			Assert::AreEqual(expectedSum, result);

			// Звільняємо пам'ять
			for (int i = 0; i < n; ++i)
				delete[] matrix[i];
			delete[] matrix;
		}
	};
}
	