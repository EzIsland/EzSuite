#define TEST(...) class MyClass final : public ezs::adt::Test { \
 public:                                                        \
 MyClass() : ezs::adt::Test(__VA_ARGS__) { }                    \
  void run() {                                                  \
  __VA_ARGS__                                                              \
  }


TEST("A", "B", "C", "D", [](){
  int hello = 0;
});


ezs::test::Test t1("A", "B", "C", "D", [](const TestRef& test) {
    test.assertEqual();
    test.assert
  });
