export module ezs.tfl.RemoveConst;


namespace ezs::tfl {

template <typename T>  struct RemoveConstImpl {
  using Type = T;
};

template<typename T> struct RemoveConstImpl<const T> {
  using Type = T;
};

export template<typename T> using RemoveConst = typename RemoveConstImpl<T>::Type;
} // namespace 
