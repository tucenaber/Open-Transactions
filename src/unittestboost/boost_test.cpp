#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test_suite.hpp>
#include <boost/test/utils/basic_cstring/basic_cstring.hpp>
#include <stddef.h>

#include "OTLog.h"
#include "OTString.h"
#include "OpenTransactions.h"



class TestAPI
{
public:
  OT_API *ot;
  TestAPI()
  {
    OT_API::InitOTAPI();
    ot = &(OT_API::It());
    ot->Init();
    BOOST_WARN(ot->LoadWallet());
  }
  ~TestAPI()
  {
    OT_API::CleanupOTAPI();
    delete ot;
  }
};


BOOST_AUTO_TEST_CASE(testPassword)
{
  BOOST_IS_DEFINED(OT_TEST_PASSWORD);
}

BOOST_AUTO_TEST_CASE(createAPI)
{
  TestAPI api;
}

BOOST_AUTO_TEST_CASE(configPath)
{
  OTString strConfigPath;
  bool bConfigPathFound = OTLog::Path_GetConfigFolder(strConfigPath);
  BOOST_REQUIRE(bConfigPathFound);
  BOOST_REQUIRE(strConfigPath.Compare("/home/eyvind/.ot"));
  // BOOST_FAIL("Just checking");
}

BOOST_AUTO_TEST_CASE(createNym)
{
  TestAPI api;
  BOOST_REQUIRE(NULL != api.ot->CreateNym(1024));
}


