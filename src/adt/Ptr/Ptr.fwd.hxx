///
/// \file Ptr.fwd.hxx
/// \brief Module interface file for forward declaration of class ezs::adt::Ptr
///
export module ezs.adt.Ptr.fwd;

import ezs.adt.Value;

export namespace ezs::adt {
template<Value Pointee> class Ptr;
} // namespace ezs::adt
