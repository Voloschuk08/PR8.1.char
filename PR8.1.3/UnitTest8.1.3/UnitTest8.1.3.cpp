#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1.3/PR8.1.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest813
{
	TEST_CLASS(UnitTest813)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* testStr1 = "no way";
			const char* expected1 = "*** way";
			
			// Перевірка заміни пар "no" на "***"
			char* result1 = ReplaceNoWithStars(testStr1);
			
			Assert::AreEqual(expected1, result1, "Failed on testStr1");
			
			// Звільняємо пам'ять
			delete[] result1;
		}
	};
}
