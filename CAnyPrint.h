#ifndef CANYPRINT_H
#define CANYPRINT_H

#include "AnyObject.h"
#include <iostream>
#include <vector>

namespace NSDetail {

// Interface of a printable object.
// We are going to support a print() method on all CAnyPrint objects here.
// Note, that you have to implement these methods for each particular
// class TObject in CAnyPrintImpl class template.
// This could be simply calling to a method print() of TObject
// or anything else you need.
// See the example below.
template<class TBase>
class IAnyPrint : public TBase {
public:
  virtual void print() const = 0;
};

// For any object of type TObject, we must implement the print() method
// This is the generic case for any type supporting the operator<<
// Access to the TObject stored in CAnyObject is done via CBase::Object() method
// of the base class TBase. Note that CBase is an alias for TBase.
template<class TBase, class TObject>
class CAnyPrintImpl : public TBase {
  // This using is for convenience only
  using CBase = TBase;
public:
  // We need to open all constructors of the base class
  using CBase::CBase;
  void print() const override {
    std::cout << "data = " << CBase::Object() << std::endl;
  }
};

// This is an example of the specialization for TObject = std::vector<T>
// where T supports the operator<<
// Now we can print any std::vector containing elements supporing
// the operator<<
template<class TBase, class TData>
class CAnyPrintImpl<TBase, std::vector<TData>> : public TBase {
  // This using is for convenience only
  using CBase = TBase;
public:
  // We need to open all constructors of the base class
  using CBase::CBase;
  void print() const override {
    std::cout << "vec data" << std::endl;
    for (const auto& element : CBase::Object())
      std::cout << "data = " << element << std::endl;
  }
};

// A using for convenience
using CAnyPrintT = CAnyObject<IAnyPrint, CAnyPrintImpl>;
}

class CAnyPrint : public NSDetail::CAnyPrintT {
  // This using is for convenience only
  using CBase = NSDetail::CAnyPrintT;
public:
  // We only need to open all constructors of the base class
  using CBase::CBase;
  // You could provide any additional methods of CAnyPrint here
};


#endif // CANYPRINT_H
