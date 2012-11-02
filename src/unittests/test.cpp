#include <gtest/gtest.h>
#include <stdbool.h>
#include <stddef.h>

#include "OTLog.h"
#include "OTString.h"
#include "OpenTransactions.h"




class TestAPI : public ::testing::Test
{
public:
	OT_API *ot;
	virtual void SetUp()
	{
		OT_API::InitOTAPI();
		ot = &(OT_API::It());
		ot->Init();
		ASSERT_TRUE(ot->LoadWallet());
	}
	virtual void TearDown()
	{
		OT_API::CleanupOTAPI();
		delete ot;
	}
};

TEST(TestInclude, testPassword)
{
#ifdef OT_TEST_PASSWORD
	SUCCEED();
#else
	FAIL();
#endif
}



TEST_F(TestAPI, configPath)
{
	OTString strConfigPath;
	bool bConfigPathFound = OTLog::Path_GetConfigFolder(strConfigPath);
	ASSERT_TRUE(bConfigPathFound);
	EXPECT_STREQ("/home/eyvind/.ot", strConfigPath.Get());
}

TEST_F(TestAPI, createNym)
{
	OTString strConfigPath;
	bool bConfigPathFound = OTLog::Path_GetConfigFolder(strConfigPath);
	ASSERT_TRUE(bConfigPathFound);
	ASSERT_TRUE(NULL != ot->CreateNym(1024));
}
