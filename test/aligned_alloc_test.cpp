/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#include <boost/align/aligned_alloc.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/detail/lightweight_test.hpp>

int main()
{
    enum {
        N = 128
    };

    for (std::size_t i = 1; i <= N; i *= 2) {
        void* p = boost::aligned_alloc(i, i);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(i, p));
        boost::aligned_free(p);
    }

    return boost::report_errors();
}
