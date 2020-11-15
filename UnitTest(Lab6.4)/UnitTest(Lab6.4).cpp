#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.4/Lab6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab64
{
	TEST_CLASS(UnitTestLab64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[4]{0,2,0,0};
			int t = NMAXI(a, 4);
			Assert::AreEqual(t, 2);
		}
	};
}
