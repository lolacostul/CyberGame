// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "catch.hpp"
//include your classes here
#include "Player.hpp"

TEST_CASE("1: Atoms toString")
{
  // Atom a(U),b,d(F);
  // Atom c(b);
  // REQUIRE(a.toString() == "(a_0 = U)");
  // REQUIRE(b.toString() == "(a_1 = U)");
  // REQUIRE(c.toString() == "(a_3 = U)");
  // REQUIRE(d.toString() == "(a_2 = F)");
}


// TEST_CASE("2: Create Atoms and evaluate Atoms"){
//   Atom a(U),b,c(T),d(F);
//   REQUIRE(a.evaluate() == U);
//   REQUIRE(b.evaluate() == U);
//   REQUIRE(c.evaluate() == T);
//   REQUIRE(d.evaluate() == F);
//   Atom e(a);
//   REQUIRE(e.evaluate() == U);
//   // REQUIRE((a.id() != e.id() && b.id() != a.id() && a.id() != c.id()));
// }
