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
#include <boost/assert.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <cstdlib>

namespace boost {
    namespace detail {
        namespace align {
            inline void* aligned_alloc(std::size_t alignment,
                std::size_t size)
            {
                BOOST_ASSERT((alignment & (alignment - 1)) == 0);
                enum {
                    N = boost::alignment_of<void*>::value
                };
                if (alignment < N) {
                    alignment = N;
                }
                std::size_t n1 = size + alignment - 1;
                void* p1 = 0;
                void* p2 = std::malloc(n1 + sizeof p2);
                if (p2) {
                    p1 = (char*)p2 + sizeof p2;
                    boost::align(alignment, size, p1, n1);
                    *((void**)p1 - 1) = p2;
                }
                return p1;
            }

            inline void aligned_free(void* ptr)
            {
                if (ptr) {
                    void* p1 = *((void**)ptr - 1);
                    std::free(p1);
                }
            }
        }
    }
}

#endif
