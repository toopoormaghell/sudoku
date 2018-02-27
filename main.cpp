#include <iostream>
#include <vector>

// Type for an item in the grid
typedef int ItemType;
// Default value for an item of the grid
static const ItemType d = -12;
// Type for a grid of items
typedef std::vector<ItemType> GridType;


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
    const GridType gridContent
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

    // Solution:
    //  0 1 2 3 4 5 6 7 8
    //  ----- ----- -----
    // |9 8 4|6 2 3|7 1 5| 0
    // |6 7 3|5 1 9|4 8 2| 1
    // |5 2 1|8 4 7|6 3 9| 2
    //  ----- ----- -----
    // |3 1 2|4 6 5|9 7 8| 3
    // |7 5 9|3 8 2|1 4 6| 4
    // |4 6 8|7 9 1|5 2 3| 5
    //  ----- ----- -----
    // |1 3 6|9 7 8|2 5 4| 6
    // |8 4 7|2 5 6|3 9 1| 7
    // |2 9 5|1 3 4|8 6 7| 8
    //  ----- ----- -----
    const GridType gridSolution
    {
            9, 8, 4, 6, 2, 3, 7, 1, 5,
            6, 7, 3, 5, 1, 9, 4, 8, 2,
            5, 2, 1, 8, 4, 7, 6, 3, 9,
            3, 1, 2, 4, 6, 5, 9, 7, 8,
            7, 5, 9, 3, 8, 2, 1, 4, 6,
            4, 6, 8, 7, 9, 1, 5, 2, 3,
            1, 3, 6, 9, 7, 8, 2, 5, 4,
            8, 4, 7, 2, 5, 6, 3, 9, 1,
            2, 9, 5, 1, 3, 4, 8, 6, 7
    };

    std::cout << "Hello World!" << std::endl;
    return 0;
}
