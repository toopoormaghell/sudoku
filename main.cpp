#include <iostream>
#include <vector>

// Type for an item in the grid
typedef int ItemType;
// Default value for an item of the grid
static const ItemType d = -12;

int main()
{
    // Example:
    //  0 1 2 3 4 5 6 7 8
    //  ----- ----- -----
    // |9    |  2  |7 1  | 0
    // |6    |5    |4   2| 1
    // |    1|  4  |6    | 2
    //  ----- ----- -----
    // |3   2|  6  |9    | 3
    // |  5 9|3   2|1 4  | 4
    // |    8|  9  |5   3| 5
    //  ----- ----- -----
    // |    6|  7  |2    | 6
    // |8   7|    6|    1| 7
    // |  9 5|  3  |    7| 8
    //  ----- ----- -----
    const std::vector<ItemType> gridContent
    {
            9, d, d, d, 2, d, 7, 1, d,
            6, d, d, 5, d, d, 4, d, 2,
            d, d, 1, d, 4, d, 6, d, d,
            3, d, 2, d, 6, d, 9, d, d,
            d, 5, 9, 3, d, 2, 1, 4, d,
            d, d, 8, d, 9, d, 5, d, 3,
            d, d, 6, d, 7, d, 2, d, d,
            8, d, 7, d, d, 6, d, d, 1,
            d, 9, 5, d, 3, d, d, d, 7
    };

    std::cout << "Hello World!" << std::endl;
    return 0;
}
