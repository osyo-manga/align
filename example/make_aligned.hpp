/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_ALIGN_EXAMPLE_MAKE_ALIGNED_HPP
#define BOOST_ALIGN_EXAMPLE_MAKE_ALIGNED_HPP

#include "aligned_ptr.hpp"

template<class T>
struct ptr_if {
    typedef aligned_ptr<T> scalar;
};

template<class T>
struct ptr_if<T[]> {
    typedef aligned_ptr<T> array;
};

template<class T, std::size_t N>
struct ptr_if<T[N]> {
    typedef aligned_ptr<T> disable;
};

template<class T, class... Args>
inline typename ptr_if<T>::scalar
make_aligned(Args&&... args)
{
    void* p = boost::aligned_alloc(alignof(T),
        sizeof(T));
    if (!p) {
        throw std::bad_alloc();
    }
    try {
        T* q = ::new(p) T(std::forward<Args>(args)...);
        return aligned_ptr<T>(q);
    } catch (...) {
        boost::aligned_free(p);
        throw;
    }
}

#endif
