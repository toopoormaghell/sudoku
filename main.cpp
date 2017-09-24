#include <iostream>
#include <vector>

class SudokuGrid
{
public:
    SudokuGrid():
        m_cells(81, 0)
    {
    }

    void setInitialValues(const std::vector<int>& content)
    {
        int i = 0;
        for (auto& item : content)
        {
            m_cells[i] = item;
            i++;
        }
    }
private:
    std::vector<int> m_cells;
};

int main()
{
    SudokuGrid grid;
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
    std::vector<int> gridContent(81, 0);
    gridContent[0+0*9] = 9;
    gridContent[4+0*9] = 2;
    gridContent[6+0*9] = 7;
    gridContent[7+0*9] = 1;
    gridContent[0+1*9] = 6;
    gridContent[3+1*9] = 5;
    gridContent[6+1*9] = 4;
    gridContent[8+1*9] = 2;
    gridContent[2+2*9] = 1;
    gridContent[4+2*9] = 4;
    gridContent[6+2*9] = 6;
    gridContent[0+3*9] = 3;
    gridContent[2+3*9] = 2;
    gridContent[4+3*9] = 6;
    gridContent[6+3*9] = 9;
    gridContent[1+4*9] = 5;
    gridContent[2+4*9] = 9;
    gridContent[3+4*9] = 3;
    gridContent[5+4*9] = 2;
    gridContent[6+4*9] = 1;
    gridContent[7+4*9] = 4;
    gridContent[2+5*9] = 8;
    gridContent[4+5*9] = 9;
    gridContent[6+5*9] = 5;
    gridContent[8+5*9] = 3;
    gridContent[2+6*9] = 6;
    gridContent[4+6*9] = 7;
    gridContent[6+6*9] = 2;
    gridContent[0+7*9] = 8;
    gridContent[2+7*9] = 7;
    gridContent[5+7*9] = 6;
    gridContent[8+7*9] = 1;
    gridContent[1+8*9] = 9;
    gridContent[2+8*9] = 5;
    gridContent[4+8*9] = 3;
    gridContent[8+8*9] = 7;
    grid.setInitialValues(gridContent);

    std::cout << "Hello World!" << std::endl;
    return 0;
}
