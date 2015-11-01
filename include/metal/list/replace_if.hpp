// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename lbd, typename val>
    struct replace_if;

    /// \ingroup list
    /// \brief Eager adaptor for \ref replace_if.
    template<typename list, typename lbd, typename val>
    using replace_if_t = typename replace_if<list, lbd, val>::type;
}

#include <metal/list/list.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    template<typename list, typename lbd, typename val>
    struct replace_if :
        invoke<
            lift_t<copy<quote_t<list>, apply<quote_t<lambda<join>>, _1>>>,
            transform<
                list,
                conditional<
                    bind_t<lbd, _1>,
                    metal::list<quote_t<val>>,
                    metal::list<_1>
                >
            >
        >
    {};
}

#endif
