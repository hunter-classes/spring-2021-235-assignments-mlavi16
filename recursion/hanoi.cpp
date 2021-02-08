#include <iostream>

void hanoi(int disc, char origin, char destination, char temp);

int main() {
    std::cout << "----------------\nNumber of discs: 1" << std::endl;
    hanoi(1, 'a', 'b', 'c');
    std::cout << "----------------\nNumber of discs: 2" << std::endl;
    hanoi(2, 'a', 'b', 'c');
    std::cout << "----------------\nNumber of discs: 3" << std::endl;
    hanoi(3, 'a', 'b', 'c');
    std::cout << "----------------\nNumber of discs: 4" << std::endl;
    hanoi(4, 'a', 'b', 'c');
}

void hanoi(int disc, char origin, char destination, char temp) {
    // base case- one disc on origin
    if (disc == 1) {
        std::cout << "Moving disc " << disc << " from " << origin << " to " << destination << std::endl;
    } else {
        hanoi(disc-1, origin, temp, destination);
        std::cout << "Moving disc " << disc << " from " << origin << " to " << destination << std::endl;
        hanoi(disc-1, temp, destination, origin);
    }
}