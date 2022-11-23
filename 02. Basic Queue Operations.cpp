#include <iostream>
#include <queue>
#include <limits>
#include <string>

std::queue<int> readInput(int& remove, int& target) {
    std::queue<int> queue;
    int input = 0;

    std::cin >> input;
    std::cin >> remove;
    std::cin >> target;
    int currNumber = 0;
    for (int i = 0; i < input; i++)
    {
        std::cin >> currNumber;
        queue.push(currNumber);
    }
    return queue;
}

void removeNumbers(std::queue<int>& queue, int& remove) {

    for (int i = 0; i < remove; i++)
    {
        queue.pop();
    }

}

std::string findSolution(std::queue<int>& queue, int target) {
    if (queue.empty()) {
        return "0";
    }
    int currNumber = 0;
    int smallestNumber = std::numeric_limits<int>::max();
    while (!queue.empty())
    {
        currNumber = queue.front();
        if (target == currNumber) {
            return "true";
        }
        if (currNumber < smallestNumber) {
            smallestNumber = currNumber;
        }
        queue.pop();
    }
    return std::to_string(smallestNumber);
}

void printSolution(const std::string& answer) {
    std::cout << answer << std::endl;
}

int main()
{
    int remove = 0;
    int target = 0;
    std::queue<int> queue = readInput(remove, target);
    removeNumbers(queue, remove);
    const std::string answer = findSolution(queue, target);
    printSolution(answer);



    return 0;
}
