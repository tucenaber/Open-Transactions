#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/auto_unit_test.hpp>
#include <turtle/mock.hpp>
#include <stddef.h>

#include "OTStorage.h"
#include "OTContract.h"
#include "OTBasket.h"
#include "OTASCIIArmor.h"
#include "OTLog.h"
#include "OTString.h"
#include "OpenTransactions.h"
#include "OTWallet.h"



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


BOOST_AUTO_TEST_CASE( testPassword )
{
  BOOST_IS_DEFINED( OT_TEST_PASSWORD );
}

struct view
{
    virtual void display( int result ) = 0;
};

struct calculator
{
    view& m;
    calculator( view& v ): m(v) {}
    void add( int a, int b ) { return m.display(a+b); }
};

MOCK_BASE_CLASS( mock_view, view ) // declare a 'mock_view' class implementing 'view'
{
    MOCK_METHOD( display, 1 )      // implement the 'display' method from 'view' (taking 1 argument)
};

BOOST_AUTO_TEST_CASE( zero_plus_zero_is_zero )
{
    mock_view v;
    calculator c( v );
    MOCK_EXPECT( v.display ).once().with( 1 ); // expect the 'display' method to be called once (and only once) with a parameter value equal to 0
    c.add( 0, 0 );
}

// BOOST_AUTO_TEST_CASE(createAPI)
// {
//   TestAPI api;
// }

// BOOST_AUTO_TEST_CASE(configPath)
// {
//   OTString strConfigPath;
//   bool bConfigPathFound = OTLog::Path_GetConfigFolder(strConfigPath);
//   BOOST_REQUIRE(bConfigPathFound);
//   BOOST_REQUIRE(strConfigPath.Compare("/home/eyvind/.ot"));
//   // BOOST_FAIL("Just checking");
// }

// BOOST_AUTO_TEST_CASE(createNym)
// {
//   TestAPI api;
//   BOOST_REQUIRE(NULL != api.ot->CreateNym(1024));
// }


