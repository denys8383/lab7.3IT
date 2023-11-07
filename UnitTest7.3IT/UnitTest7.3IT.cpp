	#include "pch.h"
	#include "CppUnitTest.h"
#include "../Project7.3IT/Source.cpp"

	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	namespace UnitTest73IT
	{
		TEST_CLASS(UnitTest73IT)
		{
		public:
		
			TEST_METHOD(TestMethod1)
			{
				int rowCount = 3;
				int colCount = 4;
				int** a = new int* [rowCount];
				for (int i = 0; i < rowCount; i++)
				{
					a[i] = new int[colCount];
				}
				int result = Zero(a, rowCount, colCount);
				Assert::AreEqual(4, result); 
				for (int i = 0; i < rowCount; i++)
				{
					delete[] a[i];
				}
				delete[] a;
			}
		};
	}
