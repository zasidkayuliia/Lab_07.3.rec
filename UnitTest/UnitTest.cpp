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
		{// ��������� ������� ������� 3x3
			const int n = 3;
			int** matrix = new int* [n];
			for (int i = 0; i < n; ++i)
				matrix[i] = new int[n];

			// ���������� �������� �������� �������
			// �������:
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

			// ����������� ���������� ���������: | -2 | + | 3 | + | -6 | = 2 + 3 + 6 = 11
			int expectedSum = 11;

			// ��������� ������� SumAboveMainDiag
			int result = SumAboveMainDiag(matrix, n);

			// ����������, �� �������� ��������� � ����������
			Assert::AreEqual(expectedSum, result);

			// ��������� ���'���
			for (int i = 0; i < n; ++i)
				delete[] matrix[i];
			delete[] matrix;
		}
	};
}
	