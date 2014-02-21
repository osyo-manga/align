/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_ALIGN_DETAIL_IS_ALIGNED_ANY_HPP
#define BOOST_ALIGN_DETAIL_IS_ALIGNED_ANY_HPP

#include <boost/align/detail/cstdint.hpp>
#include <boost/assert.hpp>

namespace boost {
    namespace detail {
        namespace align {
            inline bool is_aligned(std::size_t alignment, const void* ptr)
            {
                BOOST_ASSERT((alignment & (alignment - 1)) == 0);
                return ((uintptr_t)ptr & (alignment - 1)) == 0;
            }
        }
    }
}

#endif
