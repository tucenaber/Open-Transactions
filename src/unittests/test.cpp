#define YAFFUT_MAIN
//#include <gtest/gtest.h>
#include <HippoMocks/hippomocks.h>
#include <injector/yaffut.h>

#include "OTStorage.h"
#include "OTContract.h"
#include "OTBasket.h"
#include "OTASCIIArmor.h"
#include "OTLog.h"
#include "OTString.h"
#include "OpenTransactions.h"
#include "OTWallet.h"


// class TestAPI : public ::testing::Test
// {
// public:
// 	OT_API *ot;
// 	virtual void SetUp()
// 	{
// 		OT_API::InitOTAPI();
// 		ot = &(OT_API::It());
// 		ot->Init();
// 		ASSERT_TRUE(ot->LoadWallet());
// 	}
// 	virtual void TearDown()
// 	{
// 		OT_API::CleanupOTAPI();
// 		delete ot;
// 	}
// };

// TEST(TestInclude, testPassword)
// {
// #ifdef OT_TEST_PASSWORD
// 	SUCCEED();
// #else
// 	FAIL();
// #endif
// }



// TEST_F(TestAPI, configPath)
// {
// 	OTString strConfigPath;
// 	bool bConfigPathFound = OTLog::Path_GetConfigFolder(strConfigPath);
// 	ASSERT_TRUE(bConfigPathFound);
// 	EXPECT_STREQ("/home/eyvind/.ot", strConfigPath.Get());
// }

// TEST_F(TestAPI, createNym)
// {
// 	OTString strConfigPath;
// 	bool bConfigPathFound = OTLog::Path_GetConfigFolder(strConfigPath);
// 	ASSERT_TRUE(bConfigPathFound);
// 	ASSERT_TRUE(NULL != ot->CreateNym(1024));
// }

#if (defined(_MSC_VER) && defined(_M_IX86)) || (defined(__GNUC__) && defined(__i386__))
int a()
{
	return 1;
}

FUNC (checkFunctionReplacedAndChecked)
{
	EQUAL(a(), 1);
	MockRepository mocks;
	mocks.ExpectCallFunc(a).Return(2);
	EQUAL(a(), 2);
}
#endif

FUNC(checkMock)
{
	MockRepository mocks;
	IWallet* m = mocks.Mock<IWallet>();
	mocks.ExpectCall(m, IWallet::LoadWallet).Return(true);
	bool res = m->LoadWallet("");
}

class IA {
public:
		virtual ~IA() {}
		virtual void f() {}
		virtual void g() = 0;
};

FUNC (checkBaseCase)
{
		MockRepository mocks;
		IA *iamock = mocks.Mock<IA>();
		mocks.ExpectCall(iamock, IA::f);
		mocks.ExpectCall(iamock, IA::g);
		iamock->f();
		iamock->g();
}
