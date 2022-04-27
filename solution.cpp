#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <cstring>
using namespace sol800;
using namespace std;
/*takeaways
  - the definition of the similarity means you
    can look at rgb separately as we can calculate
    the total min distance by adding up each
    min distance
  - the distance between each colors than can be shorthanded
    is 17 (11 in hex):
    00...11...22...33.......ff
    so given a hex code, we need to find out which pair of those
    shorthanded colors the given code is falling in-between
  - for example 09 % 17 = 0, so it falls between 00...11,
    next you have to determine is it closer to 00 or 11
    9 is greater than (17/2) so it passes the mid-point and
    hence is closer to 11

*/

string Solution::find(string color)
{
  for (auto i = 1; i < 6; i += 2)
  {
    auto code = stoi(color.substr(i, 2), nullptr, 16);
    auto indx = code / 17 + (code % 17 > 8 ? 1 : 0);
    color[i] = color[i + 1] = indx > 9 ? indx - 10 + 'a' : indx + '0';
  }

  return color;
}