/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_ALIGN_DETAIL_CSTDINT_HPP
#define BOOST_ALIGN_DETAIL_CSTDINT_HPP

#include <boost/cstdint.hpp>

namespace boost {
    namespace detail {
        namespace align {
#if defined(BOOST_HAS_INTPTR_T)
            typedef boost::uintptr_t uintptr_t;
#else
            typedef std::size_t uintptr_t;
#endif
        }
    }
}

#endif
