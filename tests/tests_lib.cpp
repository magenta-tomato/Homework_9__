#define BOOST_TEST_MODULE test_version

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

// сортировка в обратном лексикографическом порядке
BOOST_AUTO_TEST_CASE(test1)
{
    bool  res = true;
    BOOST_CHECK( res );
}

BOOST_AUTO_TEST_SUITE_END()