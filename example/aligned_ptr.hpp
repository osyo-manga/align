/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_ALIGN_EXAMPLE_ALIGNED_PTR_HPP
#define BOOST_ALIGN_EXAMPLE_ALIGNED_PTR_HPP

#include <boost/align.hpp>
#include <memory>

template<class T>
struct aligned_delete {
    void operator()(void* ptr) {
        boost::aligned_free(ptr);
    }
};

template<class T>
using aligned_ptr = std::unique_ptr<T,
    aligned_delete<T> >;

#endif
