//===-- is_rvalue_reference type_traits -------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIBC_SRC_SUPPORT_CPP_TYPE_TRAITS_IS_RVALUE_REFERENCE_H
#define LLVM_LIBC_SRC_SUPPORT_CPP_TYPE_TRAITS_IS_RVALUE_REFERENCE_H

#include "src/__support/CPP/type_traits/bool_constant.h"
#include "src/__support/CPP/type_traits/false_type.h"
#include "src/__support/CPP/type_traits/true_type.h"
#include "src/__support/macros/attributes.h"
#include "src/__support/macros/config.h"

namespace __llvm_libc::cpp {

// is_rvalue_reference
#if LIBC_HAS_BUILTIN(__is_rvalue_reference)
template <typename T>
struct is_rvalue_reference : bool_constant<__is_rvalue_reference(T)> {};
#else
template <typename T> struct is_rvalue_reference : public false_type {};
template <typename T> struct is_rvalue_reference<T &&> : public true_type {};
#endif
template <class T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

} // namespace __llvm_libc::cpp

#endif // LLVM_LIBC_SRC_SUPPORT_CPP_TYPE_TRAITS_IS_RVALUE_REFERENCE_H
