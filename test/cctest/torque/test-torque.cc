// Copyright 2015 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <cmath>

#include "src/api.h"
#include "src/base/utils/random-number-generator.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/char-predicates.h"
#include "src/code-factory.h"
#include "src/code-stub-assembler.h"
#include "src/compiler/node.h"
#include "src/debug/debug.h"
#include "src/elements-kind.h"
#include "src/isolate.h"
#include "src/objects-inl.h"
#include "src/objects/promise-inl.h"
#include "test/cctest/compiler/code-assembler-tester.h"
#include "test/cctest/compiler/function-tester.h"
#include "torque-generated/builtins-test-from-dsl-gen.h"

namespace v8 {
namespace internal {
namespace compiler {

namespace {

typedef CodeAssemblerLabel Label;
typedef CodeAssemblerVariable Variable;

}  // namespace

TEST(TestConstexpr1) {
  Isolate* isolate(CcTest::InitIsolateOnce());
  CodeAssemblerTester asm_tester(isolate, 0);
  TestBuiltinsFromDSLAssembler m(asm_tester.state());
  {
    m.TestConstexpr1();
    m.Return(m.UndefinedConstant());
  }
  FunctionTester ft(asm_tester.GenerateCode(), 0);
}

TEST(TestConstexprIf) {
  Isolate* isolate(CcTest::InitIsolateOnce());
  CodeAssemblerTester asm_tester(isolate, 0);
  TestBuiltinsFromDSLAssembler m(asm_tester.state());
  {
    m.TestConstexprIf();
    m.Return(m.UndefinedConstant());
  }
  FunctionTester ft(asm_tester.GenerateCode(), 0);
}

TEST(TestConstexprReturn) {
  Isolate* isolate(CcTest::InitIsolateOnce());
  CodeAssemblerTester asm_tester(isolate, 0);
  TestBuiltinsFromDSLAssembler m(asm_tester.state());
  {
    m.TestConstexprReturn();
    m.Return(m.UndefinedConstant());
  }
  FunctionTester ft(asm_tester.GenerateCode(), 0);
}

}  // namespace compiler
}  // namespace internal
}  // namespace v8
