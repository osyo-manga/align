/*
 * Copyright (c) 2014 Glen Joseph Fernandes
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_ALIGN_ALIGNED_ALLOCATOR_HPP
#define BOOST_ALIGN_ALIGNED_ALLOCATOR_HPP

#include <boost/config.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <boost/utility/addressof.hpp>
#include <new>

namespace boost {
    template<class T,
        std::size_t minimum_alignment = 1>
    class aligned_allocator;

    template<std::size_t A>
    class aligned_allocator<void, A> {
        BOOST_STATIC_ASSERT((A & (A - 1)) == 0);

    public:
        typedef void value_type;
        typedef void* pointer;
        typedef const void* const_pointer;

        template<class U>
        struct rebind {
            typedef aligned_allocator<U, A> other;
        };
    };

    template<class T, std::size_t A>
    class aligned_allocator {
        BOOST_STATIC_ASSERT((A & (A - 1)) == 0);

    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef T& reference;
        typedef const T& const_reference;

        template<class U>
        struct rebind {
            typedef aligned_allocator<U, A> other;
        };

        aligned_allocator() {
        }

        template<class U>
        aligned_allocator(const aligned_allocator<U, A>&) {
        }

        pointer address(reference value) const {
            return boost::addressof(value);
        }

        const_pointer address(const_reference value) const {
            return boost::addressof(value);
        }

        pointer allocate(size_type size,
            aligned_allocator<void>::const_pointer = 0) {
            enum {
                N = boost::alignment_of<value_type>::value
            };
            enum {
                M = (A > N) ? A : N
            };
            void* p1 = boost::aligned_alloc(M, sizeof(value_type) * size);
            if (!p1) {
                throw std::bad_alloc();
            }
            return static_cast<pointer>(p1);
        }

        void deallocate(pointer memory, size_type) {
            boost::aligned_free(memory);
        }

        size_type max_size() const {
            enum {
                N = static_cast<size_type>(-1) / sizeof(value_type)
            };
            return N;
        }

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && \
    !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
        template<class U, class... Args>
        void construct(U* memory, Args&&... args) {
            void* p1 = memory;
            ::new(p1) U(std::forward<Args>(args)...);
        }
#else
        void construct(pointer memory) {
            void* p1 = memory;
            ::new(p1) value_type();
        }

        void construct(pointer memory, const_reference value) {
            void* p1 = memory;
            ::new(p1) value_type(value);
        }
#endif

        template<class U>
        void destroy(U* memory) {
            memory->~U();
        }
    };

    template<class T1, class T2, std::size_t A>
    inline bool operator==(const aligned_allocator<T1, A>&,
        const aligned_allocator<T2, A>&) {
        return true;
    }

    template<class T1, class T2, std::size_t A>
    inline bool operator!=(const aligned_allocator<T1, A>&,
        const aligned_allocator<T2, A>&) {
        return false;
    }
}

#endif
