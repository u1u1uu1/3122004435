#include "pch.h"
#include "CppUnitTest.h"
#include "D:\VS2017data\DuplicateCheck\DuplicateCheck\compare.h"
#include "D:\VS2017data\DuplicateCheck\DuplicateCheck\message.h"
#include "D:\VS2017data\DuplicateCheck\DuplicateCheck\function.h"
#include "D:\VS2017data\DuplicateCheck\DuplicateCheck\output.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace compareTest
{
	TEST_CLASS(LCSTest)
	{
	public:
		
		TEST_METHOD(TestLCS_OneEmptyString_Return0)
		{
			string randomStr = "ä±Ñô½­Í·Ò¹ËÍ¿Í";
			string emptyStr = "";
			int result = LCS(emptyStr, randomStr);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(TestLCS_TwoEmptyString_Return0)
		{
			string emptyStr = "";
			int result = LCS(emptyStr, emptyStr);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(TestLCS_SameStr_Return7)
		{
			string firstStr = "·ãÒ¶Ý¶»¨ÇïÉªÉª";
			string secondStr = "·ãÒ¶Ý¶»¨ÇïÉªÉª";
			int result = LCS(firstStr, secondStr);
			Assert::AreEqual(7, result);
		}

		TEST_METHOD(TestLCS_Normal0_Return5)
		{
			string firstStr = "·ãÒ¶ÇïÉªÉª";
			string secondStr = "·ãÒ¶Ý¶»¨ÇïÉªÉª";
			int result = LCS(firstStr, secondStr);
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(TestLCS_Normal1_Return4)
		{
			string firstStr = "Ý¶»¨ÇïÉª";
			string secondStr = "·ãÒ¶Ý¶»¨ÇïÉªÉª";
			int result = LCS(firstStr, secondStr);
			Assert::AreEqual(4, result);
		}
	};

	TEST_CLASS(isCopidTest)
	{
	public:
		TEST_METHOD(TestIsCopid_LeftEmptyStr_ReturnFalse)
		{
			string emptyStr = "";
			string randomStr = "·ãÒ¶Ý¶»¨ÇïÉªÉª";
			bool result = isCopied(emptyStr, randomStr);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(TestIsCopid_RightEmptyStr_ReturnFalse)
		{
			string emptyStr = "";
			string randomStr = "·ãÒ¶Ý¶»¨ÇïÉªÉª";
			bool result = isCopied(randomStr, emptyStr);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(TestIsCopid_ThreeSameInSeven_ReturnFalse)
		{
			string firstStr = "Ý¶»¨Çï";
			string secondStr = "·ãÒ¶Ý¶»¨ÇïÉªÉª";
			bool result = isCopied(firstStr, secondStr);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(TestIsCopid_FiveSameInSeven_ReturnTrue)
		{
			string firstStr = "·ãÒ¶ÇïÉªÉª";
			string secondStr = "·ãÒ¶Ý¶»¨ÇïÉªÉª";
			bool result = isCopied(firstStr, secondStr);
			Assert::AreEqual(true, result);
		}
	};
}
