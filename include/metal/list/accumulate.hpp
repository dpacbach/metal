// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_ACCUMULATE_HPP
#define METAL_LIST_ACCUMULATE_HPP

#include <metal/config.hpp>

#include <metal/detail/sfinae.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd>
        struct _accumulate;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Computes the recursive invocation of a binary \lambda with the result of
    /// the previous invocation and each element of one or more \lists traversed
    /// in parallel from the beginning to the end.
    ///
    /// ### Usage
    /// For any \lambda `lbd`, \value `val` and \lists `l_0, ..., l_n-1`
    /// \code
    ///     using result = metal::accumulate<lbd, val, l_0, ..., l_n-1>;
    /// \endcode
    ///
    /// \pre: `metal::size<l_0>{} == metal::size<>{}... == metal::size<l_n-1>{}`
    /// \returns: \value
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result =
    ///             lbd(... lbd(lbd(val, l[0]...), l[1]...), ..., l[m-1]...)
    ///     \endcode
    ///     where `l[N]...` stands for `l_0[N], ...[N], l_n-1[N]` and
    ///     `lbd(x, y)` stands for `metal::invoke<lbd, x, y>`.
    ///
    /// ### Example
    /// \snippet list.cpp accumulate
    ///
    /// ### See Also
    /// \see list, transform, fold_left
    template<typename lbd, typename state, typename... seqs>
    using accumulate =
        detail::call<detail::_accumulate<lbd>::template type, state, seqs...>;
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/indices.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/if.hpp>
#include <metal/value/same.hpp>
#include <metal/value/fold_left.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename state, typename num, typename... seqs>
        struct accumulator_impl
        {
            template<template<typename...> class expr>
            using type = expr<state, at<seqs, num>...>;
        };

        template<template<typename...> class expr, typename... seqs>
        struct accumulator
        {
            template<typename state, typename num>
            using type = forward<
                accumulator_impl<state, num, seqs...>::template type,
                expr
            >;
        };

        template<typename state, typename head, typename... tail>
        struct _accumulate_impl
        {
            template<template<typename...> class expr>
            using type = forward<
                _accumulate_impl<state, indices<head>>::template type,
                accumulator<expr, head, tail...>::template type
            >;
        };

        template<typename state, typename... vals>
        struct _accumulate_impl<state, list<vals...>>
        {
            template<template<typename...> class expr>
            using type = fold_left<lambda<expr>, state, vals...>;
        };

        template<typename lbd>
        struct _accumulate
        {};

        template<template<typename...> class expr>
        struct _accumulate<lambda<expr>>
        {
            template<typename state, typename... seqs>
            using type = forward<
                if_<same<size<seqs>...>, _accumulate_impl<state, seqs...>>
                    ::template type,
                expr
            >;
        };
    }
    /// \endcond
}

#endif
