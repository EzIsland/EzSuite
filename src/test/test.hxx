///
/// \file test.hxx
/// \brief Module interface file for export of ezs::test namespace.
///
export module ezs.test;

export import ezs.test.Test;
export import ezs.test.TestPoint;
export import ezs.test.TestName;
export import ezs.test.TestResult;
export import ezs.test.TestSingleton;
export import ezs.test.TestFailure;
export import ezs.test.TestRunner;

///
/// \brief EzSuite Testing Framework
///
/// This namespace contains all code for the EzSuite testing framework.
///
namespace ezs::test { } // namespace ezs::test
