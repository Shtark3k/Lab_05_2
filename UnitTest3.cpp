#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_2/Lab_05_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double x = 0.6;
			double n = 2;
			double a = 0.92896;
			double expected = acos(x);
			double result = A(x, n, a);
			Assert::AreEqual(expected, result, 0.92730);
		}
	};
}
