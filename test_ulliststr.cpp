#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "ulliststr.h"
#include <cassert>
int main() {
  // Your ULListStr class and methods should be declared and defined here

  ULListStr myLinkedList;

  // Add and remove an element 5 times
  for (int i = 0; i < 5; ++i) {
    std::string elementToAdd = "Element" + std::to_string(i);

    // Add element to the back of the list
    myLinkedList.push_back(elementToAdd);
    std::cout << "Added: " << elementToAdd << std::endl;

    // Remove element from the front of the list
    if (!myLinkedList.empty()) {
      std::string removedElement = myLinkedList.front();
      myLinkedList.pop_front();
      std::cout << "Removed: " << removedElement << std::endl;
    } else {
      std::cout << "List is empty. Cannot remove." << std::endl;
    }
  }

  return 0;
}