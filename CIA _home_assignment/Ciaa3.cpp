#include <iostream>
#include <stdexcept> // For exception handling

using namespace std; // Use the standard namespace

class Matrix
{
private:
    int rows, cols;
    int **data;

    // Helper function to allocate memory for the matrix
    void allocateMemory()
    {
        if (rows > 0 && cols > 0)
        {
            data = new int *[rows];
            for (int i = 0; i < rows; ++i)
            {
                data[i] = new int[cols];
            }
        }
        else
        {
            data = nullptr;
        }
    }

    // Helper function to deallocate memory
    void deallocateMemory()
    {
        if (data)
        {
            for (int i = 0; i < rows; ++i)
            {
                delete[] data[i];
            }
            delete[] data;
        }
    }

public:
    // 1. Default constructor: Initializes an empty matrix (0x0)
    Matrix() : rows(0), cols(0), data(nullptr) {}

    // 2. Parameterized constructor: Initializes matrix with dimensions and fills with value
    Matrix(int r, int c, int value = 0) : rows(r), cols(c)
    {
        if (r < 0 || c < 0)
        {
            throw invalid_argument("Matrix dimensions must be non-negative.");
        }
        allocateMemory();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = value;
            }
        }
    }

    // 3. Copy constructor: Deep copy
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    {
        allocateMemory();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // 4. Move constructor: Transfer ownership from an rvalue
    Matrix(Matrix &&other) noexcept : rows(other.rows), cols(other.cols), data(other.data)
    {
        other.data = nullptr;
        other.rows = 0;
        other.cols = 0;
    }

    // 5. Copy assignment operator: Handle self-assignment and deep copy
    Matrix &operator=(const Matrix &other)
    {
        if (this != &other)
        {
            // Deallocate current memory
            deallocateMemory();

            // Copy dimensions
            rows = other.rows;
            cols = other.cols;

            // Allocate new memory and copy elements
            allocateMemory();
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    // 6. Move assignment operator: Handle self-assignment and transfer ownership
    Matrix &operator=(Matrix &&other) noexcept
    {
        if (this != &other)
        {
            // Deallocate current memory
            deallocateMemory();

            // Transfer ownership of data
            rows = other.rows;
            cols = other.cols;
            data = other.data;

            // Leave the source matrix in a valid empty state
            other.data = nullptr;
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    // 7. Destructor: Clean up allocated memory
    ~Matrix()
    {
        deallocateMemory();
    }

    // 8. Overload the << operator to print the matrix
    friend ostream &operator<<(ostream &os, const Matrix &matrix)
    {
        if (matrix.data == nullptr)
        {
            os << "Empty matrix" << endl;
            return os;
        }
        for (int i = 0; i < matrix.rows; ++i)
        {
            for (int j = 0; j < matrix.cols; ++j)
            {
                os << matrix.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    // Method to add two matrices
    Matrix operator+(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Method to multiply two matrices
    Matrix operator*(const Matrix &other) const
    {
        if (cols != other.rows)
        {
            throw invalid_argument("Matrix dimensions must be compatible for multiplication.");
        }
        Matrix result(rows, other.cols, 0);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                for (int k = 0; k < cols; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Method to check if matrix is empty
    bool isEmpty() const
    {
        return data == nullptr || rows == 0 || cols == 0;
    }
};

int main()
{
    // Example usage
    Matrix m1(3, 3, 1);  // 3x3 matrix filled with 1
    Matrix m2(m1);       // Copy constructor
    Matrix m3(move(m1)); // Move constructor

    m2 = Matrix(2, 2, 2); // Move assignment operator
    m3 = m2;              // Copy assignment operator

    Matrix result = m2 + m3;  // Matrix addition
    Matrix product = m2 * m3; // Matrix multiplication

    cout << "Result Matrix:\n"
         << result;
    cout << "Product Matrix:\n"
         << product;

    return 0;
}
