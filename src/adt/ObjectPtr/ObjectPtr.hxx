export module ezs.adt.ObjectPtr;

import ezs.tfl.Object;

export
namespace ezs::adt {
// template<class T>
// concept ObjectPtrLike = requires (const T& pPtrLike) {
//   { std::declval<typename T::PointeeType>() } -> Object;
//   { std::declval<typename T::PointerType>() } -> SameAs<typename T::PointeeType*>;
//   { *pPtrLike } -> SameAs<typename T::PointeeType>;
//   { pPtrLike.operator->() } -> SameAs<typename T::PointerType>;
// };
template<typename T> concept ObjectPtr = true;

} // namespace ezs::adt
