#include "stdafx.h"
#include "CppUnitTest.h"
#include "Header.h"
#include "ТехПрога№1(ч.2).cpp"
#include "Functions.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(InShot)
		{
			ifstream ReadFile("C:\\Users\\Антоха\\Documents\\Visual Studio 2015\\Projects\\ТехПрога№1(ч.2)\\UnitTest1\\InShot.txt");

			type * test = new shot;
			test->InData(ReadFile);
			double expected = test->Count();
			double actual = 0.5;

			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(InSComplex)
		{
			ifstream ReadFile("C:\\Users\\Антоха\\Documents\\Visual Studio 2015\\Projects\\ТехПрога№1(ч.2)\\UnitTest1\\InComplex.txt");

			type * test = new complex;
			test->InData(ReadFile);
			float expected = test->Count();
			float actual = 7.07;

			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(InPolar)
		{
			ifstream ReadFile("C:\\Users\\Антоха\\Documents\\Visual Studio 2015\\Projects\\ТехПрога№1(ч.2)\\UnitTest1\\InPolar.txt");

			type * test = new polar;
			test->InData(ReadFile);
			float expected = test->Count();
			float actual = 6.2;

			Assert::AreEqual(actual, expected);
		}
	};
}