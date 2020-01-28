#ifndef CANY_H
#define CANY_H

#include "AnyObject.h"

namespace NSDetail {

// This is an example of an object storing data but without any access to it

// Empty interface
template<class TBase>
class IAny : public TBase {
};

// Empty implementation
template<class TBase, class TObject>
class CAnyImpl : public TBase {
  using CBase = TBase;
public:
  using CBase::CBase;
};

// A using for convenience
using CAnyT = CAnyObject<IAny, CAnyImpl>;
}

// A class that stors anything and has no access to the data it has
class CAny : public NSDetail::CAnyT {
  using CBase = NSDetail::CAnyT;
public:
  using CBase::CBase;
};


#endif // CANY_H
