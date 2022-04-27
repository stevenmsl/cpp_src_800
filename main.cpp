#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol800;

/*
Example 1:
Input: color = "#09f166"
Output: "#11ee66"
Explanation:
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
*/

tuple<string, string>
testFixture1()
{
  return make_tuple("#09f166", "#11ee66");
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.find(get<0>(f)) << endl;
}

main()
{
  test1();

  return 0;
}