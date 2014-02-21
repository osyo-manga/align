/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#include <boost/config.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/type_traits/aligned_storage.hpp>
#include <boost/type_traits/alignment_of.hpp>

enum {
    N1 = 1,
    N2 = 2,
    N3 = 4,
    N4 = 8,
    N5 = 16,
    N6 = 32,
    N7 = 64,
    N8 = 128
};

typedef boost::aligned_storage<N1, N1> T1;
typedef boost::aligned_storage<N2, N2> T2;
typedef boost::aligned_storage<N3, N3> T3;
typedef boost::aligned_storage<N4, N4> T4;
typedef boost::aligned_storage<N5, N5> T5;
typedef boost::aligned_storage<N6, N6> T6;
typedef boost::aligned_storage<N7, N7> T7;
typedef boost::aligned_storage<N8, N8> T8;

int main()
{
    {
        boost::aligned_allocator<T1> a;
        T1* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(boost::alignment_of<T1>::value, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<T2> a;
        T2* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(boost::alignment_of<T2>::value, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<T3> a;
        T3* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(boost::alignment_of<T3>::value, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<T4> a;
        T4* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(boost::alignment_of<T4>::value, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<T5> a;
        T5* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(boost::alignment_of<T5>::value, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<T6> a;
        T6* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(boost::alignment_of<T6>::value, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<T7> a;
        T7* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(boost::alignment_of<T7>::value, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<T8> a;
        T8* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(boost::alignment_of<T8>::value, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<int, N5> a;
        int* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(N5, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<int, N6> a;
        int* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(N6, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<int, N7> a;
        int* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(N7, p));
        a.deallocate(p, 1);
    }
    {
        boost::aligned_allocator<int, N8> a;
        int* p = a.allocate(1);
        BOOST_TEST(p != 0);
        BOOST_TEST(boost::is_aligned(N8, p));
        a.deallocate(p, 1);
    }

    return boost::report_errors();
}
