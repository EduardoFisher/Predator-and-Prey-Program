#include "location.h"

Location::Location()
{
    _i = -1;
    _j = -1;
}

Location::Location(int i, int j)
{
    _i = i;
    _j = j;
}

//insertion operator for this struct
std::istream& operator >>(std::istream& is, Location& input)
{
    is >> input._i >> input._j;
    return is;
}
