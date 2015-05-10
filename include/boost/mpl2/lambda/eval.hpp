// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_EVAL_HPP
#define BOOST_MPL2_LAMBDA_EVAL_HPP

#include <boost/mpl2/lambda/evaluator.hpp>
#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/unpack.hpp>
#include <boost/mpl2/lambda/traits.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr, typename... args>
        using eval = unpack<evaluator<expr>::template call, pack<args...> >;

        template<template<typename...> class expr, typename... args>
        using is_evaluable = detail::has_type<eval<expr, args...> >;
    }
}

#endif