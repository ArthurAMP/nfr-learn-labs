//
// rascii
// Created by: Evan Bertis-Sample
// 
// A dependency free 3D rendering engine, that outputs to the terminal using ASCII characters
// Built purely for fun, and to learn more about 3D graphics
//

#define NATIVE // lets PlatformIO know that this is a native build

#include <iostream>
#include <signal.h>
#include "app.hpp"

App app;

int main() {
  std::cout << "Starting RASCII\n";
  // initialize the app
  app.init();   
  // run the app
  app.run();

  return 0;
}