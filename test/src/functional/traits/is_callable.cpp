// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_callable.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_callable<test::a0>>::value, "");
static_assert(not_<is_callable<test::a1>>::value, "");
static_assert(not_<is_callable<test::a2>>::value, "");
static_assert(not_<is_callable<test::a3>>::value, "");
static_assert(not_<is_callable<test::a4>>::value, "");
static_assert(not_<is_callable<test::a5>>::value, "");
static_assert(not_<is_callable<test::a6>>::value, "");
static_assert(not_<is_callable<test::a7>>::value, "");
static_assert(not_<is_callable<test::a9>>::value, "");
static_assert(not_<is_callable<test::a9>>::value, "");

static_assert(not_<is_callable<test::a0, void>>::value, "");
static_assert(not_<is_callable<test::a1, void>>::value, "");
static_assert(not_<is_callable<test::a2, void>>::value, "");
static_assert(not_<is_callable<test::a3, void>>::value, "");
static_assert(not_<is_callable<test::a4, void>>::value, "");
static_assert(not_<is_callable<test::a5, void>>::value, "");
static_assert(not_<is_callable<test::a6, void>>::value, "");
static_assert(not_<is_callable<test::a7, void>>::value, "");
static_assert(not_<is_callable<test::a9, void>>::value, "");
static_assert(not_<is_callable<test::a9, void>>::value, "");

static_assert(not_<is_callable<test::a0, void, void*>>::value, "");
static_assert(not_<is_callable<test::a1, void, void*>>::value, "");
static_assert(not_<is_callable<test::a2, void, void*>>::value, "");
static_assert(not_<is_callable<test::a3, void, void*>>::value, "");
static_assert(not_<is_callable<test::a4, void, void*>>::value, "");
static_assert(not_<is_callable<test::a5, void, void*>>::value, "");
static_assert(not_<is_callable<test::a6, void, void*>>::value, "");
static_assert(not_<is_callable<test::a7, void, void*>>::value, "");
static_assert(not_<is_callable<test::a9, void, void*>>::value, "");
static_assert(not_<is_callable<test::a9, void, void*>>::value, "");

static_assert(not_<is_callable<test::unary<test::alias>>>::value, "");
static_assert(not_<is_callable<test::unary<test::empty>>>::value, "");
static_assert(not_<is_callable<test::unary<test::call>>>::value, "");
static_assert(not_<is_callable<test::unary<test::union_>>>::value, "");
static_assert(not_<is_callable<test::unary<test::evaluable>>>::value, "");

static_assert(not_<is_callable<test::unary<test::alias>, void>>::value, "");
static_assert(not_<is_callable<test::unary<test::empty>, void>>::value, "");
static_assert(not_<is_callable<test::unary<test::call>, void>>::value, "");
static_assert(not_<is_callable<test::unary<test::union_>, void>>::value, "");
static_assert(is_callable<test::unary<test::evaluable>, void>::value, "");

static_assert(not_<is_callable<test::unary<test::alias>, void, void*>>::value, "");
static_assert(not_<is_callable<test::unary<test::empty>, void, void*>>::value, "");
static_assert(not_<is_callable<test::unary<test::call>, void, void*>>::value, "");
static_assert(not_<is_callable<test::unary<test::union_>, void, void*>>::value, "");
static_assert(not_<is_callable<test::unary<test::evaluable>, void, void*>>::value, "");

static_assert(not_<is_callable<test::binary<test::alias>>>::value, "");
static_assert(not_<is_callable<test::binary<test::empty>>>::value, "");
static_assert(not_<is_callable<test::binary<test::call>>>::value, "");
static_assert(not_<is_callable<test::binary<test::union_>>>::value, "");
static_assert(not_<is_callable<test::binary<test::evaluable>>>::value, "");

static_assert(not_<is_callable<test::binary<test::alias>, void>>::value, "");
static_assert(not_<is_callable<test::binary<test::empty>, void>>::value, "");
static_assert(not_<is_callable<test::binary<test::call>, void>>::value, "");
static_assert(not_<is_callable<test::binary<test::union_>, void>>::value, "");
static_assert(not_<is_callable<test::binary<test::evaluable>, void>>::value, "");

static_assert(not_<is_callable<test::binary<test::alias>, void, void*>>::value, "");
static_assert(not_<is_callable<test::binary<test::empty>, void, void*>>::value, "");
static_assert(not_<is_callable<test::binary<test::call>, void, void*>>::value, "");
static_assert(not_<is_callable<test::binary<test::union_>, void, void*>>::value, "");
static_assert(is_callable<test::binary<test::evaluable>, void, void*>::value, "");

static_assert(not_<is_callable<test::n_ary<test::alias>>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::empty>>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::call>>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::union_>>>::value, "");
static_assert(is_callable<test::n_ary<test::evaluable>>::value, "");

static_assert(not_<is_callable<test::n_ary<test::alias>, void>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::empty>, void>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::call>, void>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::union_>, void>>::value, "");
static_assert(is_callable<test::n_ary<test::evaluable>, void>::value, "");

static_assert(not_<is_callable<test::n_ary<test::alias>, void, void*>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::empty>, void, void*>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::call>, void, void*>>::value, "");
static_assert(not_<is_callable<test::n_ary<test::union_>, void, void*>>::value, "");
static_assert(is_callable<test::n_ary<test::evaluable>, void, void*>::value, "");
