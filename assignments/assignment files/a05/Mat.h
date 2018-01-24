#ifndef MAT_H
#define MAT_H
#include <iomanip>


class IndexError{};


class SizeError{};


class Undefined{};


template<class D>
class Mat
{
public:
    Mat(const Mat< D > & num)
        : _rowsize(num.rowsize()), _colsize(num.colsize())
    {
        allocate_arrays();

        for (int i = 0; i < _rowsize; i++)
        {
            for (int j = 0; j < _colsize; j++)
            {
                _p[i][j] = num(i, j);
            }
        }
    }
    Mat(int rowsize=1, int colsize=1)
        :_rowsize(rowsize), _colsize(colsize)
    {
        allocate_arrays();

        for (int i = 0; i < _rowsize; i++)
        {
            for (int j = 0; j < _colsize; j++)
            {
                _p[i][j] = 0;
            }
        }
    }
    Mat(int rowsize, int colsize, D x[])
    {
        _rowsize = rowsize;
        _colsize = colsize;

        allocate_arrays();

        int i = 0, j = 0;
        while (i < _rowsize)
        {
            for (int k = 0; k < _colsize; k++, j++)
            {
                _p[i][k] = x[j];
            }
            i++;
        }
    }
    ~Mat()
    {
        for (int i = 0; i < _rowsize; i++)
            delete [] _p[i];

        delete [] _p;
    }
    Mat & operator=(const Mat< D > &);
    D & operator()(const int, const int) const;
    Mat & operator+=(const Mat< D > &);
    Mat operator+(const Mat< D > &) const;
    Mat & operator-=(const Mat< D > &);
    Mat operator-(const Mat< D > &) const;
    Mat operator*(const Mat< D > &) const;
    Mat operator*(const D &) const;
    void insert(int, int, D) const;
    int rowsize() const { return _rowsize; }
    int colsize() const { return _colsize; }
    //D get_value(const int, const int) const;
    Mat inv() const;
private:
    D ** _p;
    int _rowsize;
    int _colsize;
    void allocate_arrays()
    {
        _p = new D*[_rowsize];
        for (int i = 0; i < _rowsize; i++)
            _p[i] = new D[_colsize];
    }
};




template< class D >
std::ostream & operator<<(std::ostream & cout, const Mat< D > & matrix)
{
    for (int i = 0; i < matrix.rowsize(); i++)
    {
        cout << '[';
        for (int j = 0; j < matrix.colsize(); j++)
        {
            cout << matrix(i, j);
            if (j != matrix.colsize() - 1) cout << ' ';
        }
        cout << ']'; if (i != matrix.rowsize() - 1) cout << '\n';
    }
    return cout;
}

template< class D >
Mat< D > operator*(int a, const Mat< D > & b)
{
    Mat< D > prod(b);

    for (int i = 0; i < prod.rowsize(); i++)
    {
        for (int j = 0; j < b.colsize(); j++)
        {
            prod(i, j) = (prod(i, j) * a);
        }
    }

    return prod;
}

template< class D >
int len(const Mat< D > & num)
{
    if (num.rowsize() == 1 || num.colsize() == 1)
    {
        if (num.rowsize() == 1) return num.colsize();
        return num.rowsize();
    }
    else
        std::cout << "Error. _rowsize isn't 0 and _columnsize isn't 1" << std::endl;
}

template< class D >
D & Mat<D>::operator()(const int row_index, const int col_index) const
{
    if (row_index >= _rowsize || col_index >= _colsize) { std::cout << "I FOUND IT" << std::endl; throw IndexError(); }

    return (_p[row_index][col_index]);
}

template< class D >
Mat< D > & Mat<D>::operator=(const Mat< D > & num)
{
    /*if (_rowsize != num.rowsize()) { std::cout << "here4" << std::endl;throw SizeError();}*/
    this->~Mat();
    _rowsize = num.rowsize();
    _colsize = num.colsize();

    allocate_arrays();

    for (int i = 0; i < _rowsize; i++)
    {
        for (int j = 0; j < _colsize; j++)
            _p[i][j] = num(i, j);
    }

    return *this;
}

template< class D >
Mat< D > & Mat<D>::operator+=(const Mat< D > & num)
{
    if (_rowsize != num.rowsize()) throw SizeError();
    for (int i = 0; i < _rowsize; i++)
    {
        for (int j = 0; j < _colsize; j++)
            this->_p[i][j] += num(i, j);
    }

    return *this;
}

template< class D >
Mat< D > Mat<D>::operator+(const Mat< D > & num) const
{
    if (_rowsize != num.rowsize()) throw SizeError();
    Mat sum(_rowsize, _colsize);
    
    return(sum += num);
}

template< class D >
Mat< D > & Mat<D>::operator-=(const Mat< D > & num)
{
    if (_rowsize != num.rowsize()) throw SizeError();
    for (int i = 0; i < _rowsize; i++)
    {
        for (int j = 0; j < _colsize; j++)
            this->_p[i][j] = this->_p[i][j] - num(i, j);
    }

    return *this;
}

template< class D >
Mat< D > Mat<D>::operator-(const Mat< D > & num) const
{
    if (_rowsize != num.rowsize()) throw SizeError();
    Mat sum(_rowsize, _colsize);
    
    return (sum -= num);
}

template< class D >
Mat< D > Mat<D>::operator*(const Mat< D > & num) const
{
    if (_colsize != num.rowsize()) throw SizeError();
    
    Mat prod(_rowsize, num.colsize());

    for (int i = 0; i < prod.rowsize(); i++)
    {
        for (int j = 0; j < prod.colsize(); j++)
        {
            for (int k = 0; k < _colsize; k++)
            {
                prod(i, j) += _p[i][k] * num(k, j);
            }
        }
    }

    return prod;
}

template< class D >
Mat< D > Mat<D>::operator*(const D & num) const
{
    for (int i = 0; i < _rowsize; i++)
    {
        for (int j = 0; j < _colsize; j++)
            _p[i][j] *= num;
    }

    return *this;
}

template< class D >
void Mat< D >::insert(int row_index, int col_index, D value) const
{
    if (row_index >= _rowsize || col_index >= col_index) throw IndexError();
    _p[row_index][col_index] = value;
}

template< class D >
Mat< D > Mat<D>::inv() const
{
    Mat< D > inverse(_rowsize, _colsize);
    int order = this->rowsize();
    double det = 1.0 / CalcDeterminant(*this, order);
    
    Mat< D > minor(order - 1, order - 1);
    
    for (int j = 0; j < order; j++)
    {
        for (int i = 0; i < order; i++)
        {
            GetMinor(*this, minor, j, i, order);
            inverse(i, j) = det * CalcDeterminant(minor, order - 1);
            if ((i + j) % 2 == 1)
            {
                inverse(i, j) = -inverse(i, j);
            }
        }
    }
 
    return inverse;
}

template< class D >
double det(const Mat< D > & mat)
{
    // order must be >= 0
    // stop the recursion when matrix is a single element
    int order = mat.rowsize();
    
    if( order == 1 )
        return mat(0, 0);
    
    // the determinant value
    double detr = 0;
    
    // allocate the cofactor matrix
    Mat< D > minor(order - 1, order - 1);
    
    for(int i = 0; i < order; i++ )
    {
        // get minor of element (0,i)
        GetMinor(mat, minor, 0, i, order);
        
        // the recusion is here!
        detr += (i % 2 == 1 ? -1.0 : 1.0) * mat(0, i) * CalcDeterminant(minor, order-1);
    }
    
    return detr;
}


// matrix inversioon
// the result is put in Y
template< class D >
void MatrixInversion(Mat< D > A, int order, Mat< D > Y)
{
    // get the determinant of a
    double det = 1.0 / CalcDeterminant(A,order);
    
    // memory allocation
    int * temp = new int[(order - 1) * (order - 1)];
    Mat< D > minor(order - 1, order - 1);
    
    for(int j = 0; j < order; j++)
    {
        for(int i = 0; i < order; i++)
        {
            // get the co-factor (matrix) of A(j,i)
            GetMinor(A, minor, j, i, order);
            Y(i, j) = det * CalcDeterminant(minor, order - 1);
            
            if((i + j) % 2 == 1)
                Y(i, j) = -Y(i, j);
        }
    }
    
    // release memory

    delete [] temp;
}


// calculate the cofactor of element (row,col)
template< class D >
int GetMinor(Mat< D > src, Mat< D > & dest, int row, int col, int order)
{
    // indicate which col and row is being copied to dest
    int colCount = 0, rowCount = 0;
    
    for(int i = 0; i < order; i++ )
    {
        if( i != row )
        {
            colCount = 0;
            
            for(int j = 0; j < order; j++ )
            {
                // when j is not the element
                if( j != col )
                {
                    dest(rowCount, colCount) = src(i, j);
                    colCount++;
                }
            }
            rowCount++;
        }
    }
    return 1;
}


// Calculate the determinant recursively.
template< class D >
double CalcDeterminant(Mat< D > mat, int order)
{
    // order must be >= 0
    // stop the recursion when matrix is a single element
    if( order == 1 )
        return mat(0, 0);

    // the determinant value
    double det = 0;
    
    // allocate the cofactor matrix
    Mat< D > minor(order - 1, order - 1);

    for(int i = 0; i < order; i++ )
    {
        // get minor of element (0,i)
        GetMinor(mat, minor, 0, i, order);
        
        // the recusion is here!
        det += (i % 2 == 1 ? -1.0 : 1.0) * mat(0, i) * CalcDeterminant(minor, order-1);
    }

    if (det == 0) throw Undefined();

    return det;
}




#endif
