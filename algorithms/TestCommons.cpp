#include"Commons.hpp"
#include<string>

// the boost minimal testing framework.
#include<boost/test/minimal.hpp>

int test_main(int argc, char *argv[]) {
  // gcd and mcm. 
  BOOST_CHECK(gcd(-1, 8) == -1); 
  BOOST_CHECK(gcd(6, 8) == 2);
  BOOST_CHECK(gcd(15, 18) == 3); 
  BOOST_CHECK(mcm(6, 3) == 6); 
  BOOST_CHECK(mcm(12, 18) == 36); 

  // isLeapYear.
  //BOOST_ERROR(isLeapYear(2000) == true); 
  //BOOST_CHECK(isLeapYear(2001) == false); 

  // reverse string. 

  return isLeapYear(2000) ? 0 : 1;

}

/*int main(int argc, char** argv) {
  // gcd and mcm. 
  std::cout << gcd(-1, 8) << std::endl; 
  std::cout << mcm(12, 18) << std::endl; 

  std::cout << "Is leap year: " << isLeapYear(2001) << std::endl; 

  // reverse string. 
  char str[100] = "Hello world.";
  std::cout << str << std::endl; 

  reverseStr(str); 
  std::cout << str << std::endl; 

  // google test.
  // ::testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS(); 
}
*/
