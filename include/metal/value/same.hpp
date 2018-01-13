// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_SAME_HPP
#define METAL_VALUE_SAME_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename... vals>
        struct _same;
    }
    /// \endcond

    /// \ingroup value
    ///
    /// ### Description
    /// Checks whether all \values are identical.
    ///
    /// ### Usage
    /// For any \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::same<val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If at least two \values in `val_0, ..., val_n-1` are not identical
    ///     to each other, then
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet value.cpp same
    ///
    /// ### See Also
    /// \see distinct
    template<typename... vals>
    using same = typename detail::_same<vals...>::type;
}

#include "../number/number.hpp"
#include "../value/value.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename...>
        struct _same_impl : false_ {};

        template<template<typename> class... _, typename val>
        struct _same_impl<_<val>...> : true_ {};

        template<typename... vals>
        struct _same : _same_impl<value<vals>...> {};

        template<typename x, typename y>
        struct _same<x, y> : false_ {};

        template<typename x>
        struct _same<x, x> : true_ {};

        template<typename x>
        struct _same<x> : true_ {};

        template<>
        struct _same<> : true_ {};
    }
    /// \endcond
}

#endif
