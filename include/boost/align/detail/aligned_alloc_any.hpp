/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_ANY_HPP
#define BOOST_ALIGN_DETAIL_ALIGNED_ALLOC_ANY_HPP

#include <boost/align/align.hpp>
#include <cstdlib>
#include <cstring>

namespace boost {
    namespace detail {
        namespace align {
            inline void* aligned_alloc(std::size_t alignment,
                std::size_t size)
            {
                std::size_t n1 = alignment - 1 + size;
                void* p1 = 0;
                void* p2 = std::malloc(sizeof p2 + n1);
                if (p2) {
                    p1 = (char*)p2 + sizeof p2;
                    boost::align(alignment, size, p1, n1);
                    std::memcpy((void**)p1 - 1, &p2, sizeof p2);
                }
                return p1;
            }

            inline void aligned_free(void* ptr)
            {
                if (ptr) {
                    void* p1;
                    std::memcpy(&p1, (void**)ptr - 1, sizeof p1);
                    std::free(p1);
                }
            }
        }
    }
}

#endif
