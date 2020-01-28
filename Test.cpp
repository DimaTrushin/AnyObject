#include "Test.h"
#include "Echo.h"

#include "CAny.h"
#include "CAnyPrint.h"

#include <vector>
#include <algorithm>
#include <string>

void test1() {
  std::cout << "test()" << std::endl;

  std::cout << std::endl << "Echo data1;" << std::endl;
  Echo data1;

  std::cout << std::endl << "const Echo const_data1;" << std::endl;
  const Echo const_data1;

  std::cout << std::endl << "Echo arr[2];" << std::endl;
  Echo arr[2];
  std::cout << std::endl << "const Echo carr[2];" << std::endl;
  const Echo carr[2];

  std::cout << std::endl << "CAny value1 = data1;" << std::endl;
  CAny value1 = data1;
  std::cout << std::endl << "CAny value2 = const_data1;" << std::endl;
  CAny value2 = const_data1;

  std::cout << std::endl << "CAny value1m = std::move(data1);" << std::endl;
  CAny value1m = std::move(data1);
  std::cout << std::endl << "CAny value2m = std::move(const_data1);" << std::endl;
  CAny value2m = std::move(const_data1);


  std::cout << std::endl << "CAny value3 = arr;" << std::endl;
  CAny value3 = arr;
  std::cout << std::endl << "CAny value4 = carr;" << std::endl;
  CAny value4 = carr;

  std::cout << std::endl << "CAny value3m = std::move(arr);" << std::endl;
  CAny value3m = std::move(arr);
  std::cout << std::endl << "CAny value4m = std::move(carr);" << std::endl;
  CAny value4m = std::move(carr);

  std::cout << std::endl << "CAny value5;" << std::endl;
  CAny value5;
  std::cout << std::endl << "value5 = value1;" << std::endl;
  value5 = value1;
  std::cout << std::endl << "value5 = value2;" << std::endl;
  value5 = value2;
  std::cout << std::endl << "value5 = std::move(value2);" << std::endl;
  value5 = std::move(value2);


  std::cout << std::endl << "CAny value6;" << std::endl;
  CAny value6;
  std::cout << std::endl << "value6 = std::move(value1);" << std::endl;
  value6 = std::move(value1);

  std::cout << std::endl << "value6 = std::move(value1);" << std::endl;
  value6 = std::move(value1);

  std::cout << std::endl << "value7 = Echo();" << std::endl;
  CAny value7 = Echo();
  // I do not know how to avoid creation and destruction of
  // the temporary object here
  // The only option I know is to provide the emplace method


  std::cout << std::endl;
}


void test2() {
  std::cout << "test2()" << std::endl;

  std::cout << std::endl << "std::vector<CAny> vec;" << std::endl;
  std::vector<CAny> vec;

  std::cout << std::endl << "Echo data;" << std::endl;
  Echo data;

  std::cout << std::endl << "vec.push_back(Echo());" << std::endl;
  vec.push_back(Echo());

  std::cout << std::endl << "vec.push_back(data);" << std::endl;
  vec.push_back(data);

  std::cout << std::endl << "vec.push_back(std::move(data));" << std::endl;
  vec.push_back(std::move(data));

  std::cout << std::endl << "vec.push_back(CAny());" << std::endl;
  vec.push_back(CAny());

  std::cout << std::endl << "vec.back() = Echo();" << std::endl;
  vec.back() = Echo();

  std::cout << std::endl << "std::reverse(vec.begin(), vec.end());" << std::endl;
  std::reverse(vec.begin(), vec.end());


  std::cout << std::endl;
}

class A {
public:
  A(Echo data) : data_(std::move(data)) {
//    std::cout << "A" << std::endl;
  }
private:
  Echo data_;
};

class B {
public:
  B(const Echo& data) : data_(data) {
//    std::cout << "B&" << std::endl;
  }
  B(Echo&& data) : data_(std::move(data)) {
//    std::cout << "B&&" << std::endl;
  }
private:
  Echo data_;
};

void test3() {

  std::cout << "test3()" << std::endl;

  std::cout << std::endl << "Echo data;" << std::endl;
  Echo data;

  std::cout << std::endl << "A a(data);" << std::endl;
  A a(data);

  std::cout << std::endl << "B b(data);" << std::endl;
  B b(data);

  std::cout << std::endl << "A am(std::move(data));" << std::endl;
  A am(std::move(data));

  std::cout << std::endl << "B bm(std::move(data));" << std::endl;
  B bm(std::move(data));

  std::cout << std::endl << "A am1(Echo{});" << std::endl;
  A am1(Echo{});

  std::cout << std::endl << "B bm1(Echo{});" << std::endl;
  B bm1(Echo{});

  std::cout << std::endl << "am1 = Echo{};" << std::endl;
  am1 = Echo{};

  std::cout << std::endl << "bm1 = Echo{};" << std::endl;
  bm1 = Echo{};

  std::cout << std::endl << "am1 = std::move(data);" << std::endl;
  am1 = std::move(data);

  std::cout << std::endl << "bm1 = std::move(data);" << std::endl;
  bm1 = std::move(data);


  std::cout << std::endl;
}


void test4() {
  std::cout << "test4()" << std::endl;

  std::cout << std::endl << "CAny x;" << std::endl;
  CAny x;
  std::cout << std::endl << "x.emplace<int>();" << std::endl;
  x.emplace<int>();

  std::cout << std::endl << "x.emplace<Echo>();" << std::endl;
  x.emplace<Echo>();

  std::cout << std::endl << "x.emplace<Echo>(1);" << std::endl;
  x.emplace<Echo>(1);

  std::cout << std::endl << "CAny y = Echo();" << std::endl;
  CAny y = Echo();

  std::cout << std::endl << "CAny z;" << std::endl;
  CAny z;

  std::cout << std::endl << "z.emplace<Echo>(1);" << std::endl;
  z.emplace<Echo>(1);

  std::cout << std::endl;
}

void test5() {
  std::cout << "test5()" << std::endl;

  std::cout << std::endl << "CAnyPrint x;" << std::endl;
  CAnyPrint x;
  if (x.isDefined())
    x->print();

  x = 4;
  x->print();

  x = "123";
  x->print();

  x.emplace<std::string>("abc");
  x->print();

  std::vector<std::string> vec;
  vec.push_back("ggg");
  vec.push_back("aaa");

  x = std::move(vec);
  x->print();

  std::cout << "vec.size() = " << vec.size() << std::endl;
}


void test_all() {
  test1();
  test2();
  test3();
  test4();
  test5();
}
