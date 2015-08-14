// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_EMPTY_HPP
#define METAL_SEQUENCE_EMPTY_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename seq>
    struct empty
    {};

    /// \ingroup sequence
    /// \brief Eager adaptor for \ref empty.
    template<typename seq>
    using empty_t = typename metal::empty<seq>::type;

    template<template<typename...> class list, typename... vals>
    struct empty<list<vals...>> :
            boolean<false>
    {};

    template<template<typename...> class list>
    struct empty<list<>> :
            boolean<true>
    {};
}

#endif