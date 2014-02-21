/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#include <boost/align/align.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/detail/lightweight_test.hpp>

int main()
{
    enum {
        N = 128
    };

    char s[N + N - 1] = { 0 };

    for (std::size_t i = 1; i <= N; i *= 2) {
        for (std::size_t j = 0; j < N; j++) {
            std::size_t n = i - 1;
            void* p = s + j;
            void* q = boost::align(i, 0, p, n);
            BOOST_TEST(q != 0);
            BOOST_TEST(p == q);
            BOOST_TEST(boost::is_aligned(i, p));
            BOOST_TEST(n < i);
            BOOST_TEST(p < s + j + i);
        }
    }

    return boost::report_errors();
}
