#include <iostream>
#include <vector>

// A value is between 1 and 9 or uninitialized.
class GridValue
{
public:
    enum class AllowedValue
    {
        ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, UNINITIALIZED
    };
    AllowedValue m_value;
};


// A region is a collection of values from a grid.
class Region
{
public:
    std::vector<Value*> m_values;
};

// A line is a special region with specific rules.



// A game grid is a collection of values organized in a 2D array.
template<typename ValueType>
class GameGrid
{
public:
    GameGrid() = delete;
    GameGrid(const GameGrid& that);
    GameGrid(GameGrid&& rv);
    GameGrid(const int nbLines, const int nbColumns);
    ~GameGrid();
    const ValueType& value(const int i, const int j);
    void setValue(const int line, const int column, const ValueType& value);
private:
    std::vector<ValueType> m_values;
    friend void swap(GameGrid& value1, GameGrid& value2);
};
// A specialization of a GameGrid for classic sudoku.
class ClassicSudokuGrid
{
public:

};
// A specialization of GameGrid for demoniac sudoku.
class DemoniacSudokuGrid
{
public:
};




// Type for an item in the grid
typedef int ItemType;
// Default value for an item of the grid
static const ItemType d = -12;
// Type for a grid of items
typedef std::vector<ItemType> GridType;

struct validityInformation
{
    int line;
    int column;
    std::string message;
    bool isValid;
};

struct validityInformation makeResult(const int line, const int column, const std::string& message, const bool isValid)
{
    struct validityInformation tmp;
    tmp.line = line;
    tmp.column = column;
    tmp.message = message;
    tmp.isValid = isValid;
    return tmp;
}

struct validityInformation isGridValid(const GridType& grid)
{
    // Create the result of the function
    struct validityInformation retVal = makeResult(d, d, "", false);
    int& i = retVal.line;
    int& j = retVal.column;

    // Create an array of boolean values to test if a value is found in the region
    std::vector<bool> testArray(9);

    // Check for lines
    for (i = 0; i < 9; ++i)
    {
        std::fill(testArray.begin(), testArray.end(), false);
        for (j = 0; j < 9; ++j)
        {
            const ItemType& val = grid[j+i*9];
            if ((val < 1) || (val > 9))
            {
                retVal.message = "value is out of bound";
                return retVal;
            }
            else
            {
                if (testArray[val-1] == true)
                {
                    retVal.message = "same value repeated several times";
                    return retVal;
                }
                else
                {
                    testArray[val-1] = true;
                }
            }
        }
    }
    // Check for columns
    for (j = 0; j < 9; ++j)
    {
        std::fill(testArray.begin(), testArray.end(), false);
        for (i = 0; i < 9; ++i)
        {
            const ItemType& val = grid[j+i*9];
            if ((val < 1) || (val > 9))
            {
                retVal.message = "value is out of bound";
                return retVal;
            }
            else
            {
                if (testArray[val-1] == true)
                {
                    retVal.message = "same value repeated several times";
                    return retVal;
                }
                else
                {
                    testArray[val-1] = true;
                }
            }
        }
    }
    // Check for squares
    for (int l = 0; l < 3; ++l)
    {
        const int offsetY = 3 * l;
        for (int k = 0; k < 3; ++k)
        {
            const int offsetX = 3 * k;
            for (i = 0; i < 3; ++i)
            {
                std::fill(testArray.begin(), testArray.end(), false);
                for (j = 0; j < 3; ++j)
                {
                    const ItemType& val = grid[(j+offsetY)+(i+offsetX)*9];
                    if ((val < 1) || (val > 9))
                    {
                        retVal.message = "value is out of bound";
                        return retVal;
                    }
                    else
                    {
                        if (testArray[val-1] == true)
                        {
                            retVal.message = "same value repeated several times";
                            return retVal;
                        }
                        else
                        {
                            testArray[val-1] = true;
                        }
                    }
                }
            }
        }
    }

    retVal.isValid = true;
    return retVal;
}

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
//    const GridType gridSolution
//    {
//            9, 8, 4, 6, 2, 3, 7, 1, 5,
//            6, 7, 3, 5, 1, 9, 4, 8, 2,
//            5, 2, 1, 8, 4, 7, 6, 3, 9,
//            3, 1, 2, 4, 6, 5, 9, 7, 8,
//            7, 5, 9, 3, 8, 2, 1, 4, 6,
//            4, 6, 8, 7, 9, 1, 5, 2, 3,
//            1, 3, 6, 9, 7, 8, 2, 5, 4,
//            8, 4, 7, 2, 5, 6, 3, 9, 1,
//            2, 9, 5, 1, 3, 4, 8, 6, 7
//    };
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



    const struct validityInformation testContent(isGridValid(gridContent));
    std::string message("grid is ");
    if (testContent.isValid)
        message += "valid";
    else
        message += "not valid: " + testContent.message + " - line: " + std::to_string(testContent.line) + " - column: " + std::to_string(testContent.column);
    std::cout << message << std::endl;

    const struct validityInformation testSolution(isGridValid(gridSolution));
    message = "grid is ";
    if (testSolution.isValid)
        message += "valid";
    else
        message += "not valid: " + testSolution.message + " - line: " + std::to_string(testSolution.line) + " - column: " + std::to_string(testSolution.column);
    std::cout << message << std::endl;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
