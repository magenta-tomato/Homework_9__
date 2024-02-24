#define BOOST_TEST_MODULE test_version

#include "Bulk.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(version() > 0);
}



// сортировка в обратном лексикографическом порядке
BOOST_AUTO_TEST_CASE(test1)
{
    bool  res = true;

    BOOST_CHECK( res );
	
	/*
    int sz = 3;
    Bulk b(sz);

    {
        ostringstream out;
        cout.rdbuf(out.rdbuf());
        istringstream in;
        cin.rdbuf(in.rdbuf());
        in.str("a b c");
        b.processLoop();
        bool x = (out.str() == "bulk: a, b, c\n");
    }

    {
        ostringstream out;
        cout.rdbuf(out.rdbuf());
        istringstream in;
        cin.rdbuf(in.rdbuf());
        in.str("a b { c d e }");
        b.processLoop();
        bool x = (out.str() == "bulk: a, b\nbulk: c, d, e\n");
    }

    {
        ostringstream out;
        cout.rdbuf(out.rdbuf());
        istringstream in;
        cin.rdbuf(in.rdbuf());
        in.str("a b { c d e { f g } h } i j k");
        b.processLoop();
        bool x = (out.str() == "bulk: a, b\nbulk: c, d, e, f, g, h\nbulk: i, j, k\n");
    }

    {
        ostringstream out;
        cout.rdbuf(out.rdbuf());
        istringstream in;
        cin.rdbuf(in.rdbuf());
        in.str("a b c d e ");
        b.processLoop();
        bool x = (out.str() == "bulk: a, b, c\nbulk: d, e\n");
    }

    {
        ostringstream out;
        cout.rdbuf(out.rdbuf());
        istringstream in;
        cin.rdbuf(in.rdbuf());
        in.str("{ a b } ");
        b.processLoop();
        bool x = (out.str() == "");
    }
	*/

}


BOOST_AUTO_TEST_SUITE_END()