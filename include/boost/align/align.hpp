/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_ALIGN_ALIGN_HPP
#define BOOST_ALIGN_ALIGN_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_CXX11_STD_ALIGN)
#include <boost/align/detail/align_std.hpp>
#else
#include <boost/align/detail/align_any.hpp>
#endif

namespace boost {
    using boost::detail::align::align;
}

#endif
