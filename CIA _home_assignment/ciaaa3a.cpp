#include <iostream>
#include <vector>
#include <stdexcept> // For exceptions

class Matrix
{
private:
    int rows, cols;
    double **data;

    // Helper to allocate memory for matrix
    void allocateMemory(int r, int c)
    {
        rows = r;
        cols = c;
        data = new double *[rows];
        for (int i = 0; i < rows; ++i)
        {
            data[i] = new double[cols];
        }
    }

    // Helper to deallocate memory
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
    // 1. Default Constructor: Initializes an empty matrix (0x0 dimensions).
    Matrix() : rows(0), cols(0), data(nullptr) {}

    // 2. Parameterized Constructor: Initializes a matrix with given dimensions (rows, cols), optionally filled with a value.
    Matrix(int r, int c, double value = 0.0)
    {
        if (r < 0 || c < 0)
        {
            throw std::invalid_argument("Matrix dimensions cannot be negative.");
        }
        allocateMemory(r, c);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = value;
            }
        }
    }

    // 3. Copy Constructor: Creates a deep copy of an existing matrix.
    Matrix(const Matrix &other)
    {
        allocateMemory(other.rows, other.cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // 4. Move Constructor: Transfers ownership of the data from an rvalue matrix.
    Matrix(Matrix &&other) noexcept : rows(other.rows), cols(other.cols), data(other.data)
    {
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr; // Leave other matrix in a valid but empty state
    }

    // 5. Copy Assignment Operator: Handles self-assignment and performs deep copying.
    Matrix &operator=(const Matrix &other)
    {
        if (this != &other)
        {                       // Prevent self-assignment
            deallocateMemory(); // Deallocate current memory

            allocateMemory(other.rows, other.cols);
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

    // 6. Move Assignment Operator: Handles self-assignment and transfers ownership of the data.
    Matrix &operator=(Matrix &&other) noexcept
    {
        if (this != &other)
        {                       // Prevent self-assignment
            deallocateMemory(); // Deallocate current memory

            rows = other.rows;
            cols = other.cols;
            data = other.data;

            other.rows = 0;
            other.cols = 0;
            other.data = nullptr; // Leave other matrix in a valid but empty state
        }
        return *this;
    }

    // 7. Destructor: Properly deallocates all allocated memory.
    ~Matrix()
    {
        deallocateMemory();
    }

    // Overload the << operator to print the matrix.
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
    {
        for (int i = 0; i < matrix.rows; ++i)
        {
            for (int j = 0; j < matrix.cols; ++j)
            {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // Matrix addition
    Matrix operator+(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw std::invalid_argument("Matrix dimensions must match for addition.");
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

    // Matrix multiplication
    Matrix operator*(const Matrix &other) const
    {
        if (cols != other.rows)
        {
            throw std::invalid_argument("Matrix dimensions must be compatible for multiplication.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

// Example usage
int main()
{
    Matrix m1(3, 3, 1);       // 3x3 matrix filled with 1
    Matrix m2(m1);            // Copy constructor
    Matrix m3(std::move(m1)); // Move constructor
    m2 = Matrix(2, 2, 2);     // Move assignment operator
    m3 = m2;                  // Copy assignment operator
    Matrix result = m2 + m3;  // Matrix addition
    Matrix product = m2 * m3; // Matrix multiplication

    std::cout << "Result Matrix:\n"
              << result;
    std::cout << "Product Matrix:\n"
              << product;

    return 0;
}