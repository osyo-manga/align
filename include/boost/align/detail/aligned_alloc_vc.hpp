/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_VC_HPP
#define BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_VC_HPP

#include <boost/assert.hpp>
#include <cstddef>
#include <malloc.h>

namespace boost {
    namespace detail {
        namespace align {
            inline void* aligned_alloc(std::size_t alignment,
                std::size_t size)
            {
                BOOST_ASSERT((alignment & (alignment - 1)) == 0);
                return _aligned_malloc(size, alignment);
            }

            inline void aligned_free(void* ptr)
            {
                _aligned_free(ptr);
            }
        }
    }
}

#endif
