// 182 ms, 09/08/2017
// Time  : O((kn)^2), k is 3 in this problem
// Space : O(1)
class Solution {
public:
    typedef vector<vector<int>> matrix;
    
    matrix imageSmoother(matrix& M)
    {
        matrix smooth_m(M);
        
        int rows = M.size(), cols;
        if (rows >= 0)
            cols = M[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int count = 0;
                double sum = 0;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if ((r + i) >= 0 && (r + i) < rows && (c + j) >= 0 && (c + j) < cols) { 
                            sum += M[r + i][c + j];
                            ++count;
                        }
                    }
                }
                smooth_m[r][c] = sum / count;
            }
        }
        
        return smooth_m;
    }
};
/*--------------------------------------------------------------------------*/
// TODO: Incomplete - sliding window approach for better performance
class Solution {
public:
    typedef vector<vector<int>> matrix;
    matrix imageSmoother(matrix& M)
    {
        int rows = M.size(), cols;
        if (rows >= 0)
            cols = M[0].size();
        if (rows > 5 && cols > 5)
            return image_smoother_large(M, rows, cols);
        else
            return image_smoother_small(M, rows, cols);
    }
    
private:    
    matrix image_smoother_small(matrix& M, int rows, int, cols)
    {
        matrix smooth_m(M);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int count = 0;
                double sum = 0;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if ((r + i) >= 0 && (r + i) < rows && (c + j) >= 0 && (c + j) < cols) { 
                            sum += M[r + i][c + j];
                            ++count;
                        }
                    }
                }
                smooth_m[r][c] = sum / count;
            }
        }
        return smooth_m;
    }
    class window3x3 {
      private:
        struct pos {
            int r, c;
        };
      public:
        window3x3(matrix& M) : _m(M), _c({1,1}), _sum(0)
        {
            _row_sum.resize(3, 0), _col_sum.resize(3, 0);
            // Sum the rows and also the total
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j)
                    _row_sum[i + 1] += _m[_c.r + i][_c.c + j];
                _sum += _row_sum[i + 1];
            }
            // Sum the columns
            for (int j = -1; j <= 1; ++j)
                for (int i = -1; i <= 1; ++i)
                    _col_sum[j + 1] += _m[_c.r + i][_c.c + j];
        }
        
        // int avg() { return floor(_sum / 9); }
        int avg() { return _sum; }
        void move_right() {
            for (int i = -1; i <= 1; ++i)
                _row_sum[i + 1] += _m[_c.r + i][_c.c + 2] - _m[_c.r + i][_c.c - 1];
            _col_sum.push_back(0);
            for (int i = -1; i <= 1; ++i)
                _col_sum.back() += _m[_c.r + i][_c.c + 2];
            _sum += _col_sum.back() - _col_sum.front();
            _col_sum.pop_front();
            ++_c.c;
        }
        void move_down() {
            for (int i = -1; i <= 1; ++i)
                _col_sum[i + 1] += _m[_c.r + 2][_c.c + i] - _m[_c.r - 1][_c.c + i];
            _row_sum.push_back(0);
            for (int i = -1; i <= 1; ++i)
                _row_sum.back() += _m[_c.r + 2][_c.c + i];
            _sum += _row_sum.back() - _row_sum.front();
            _row_sum.pop_front();
            ++_c.r;
        }
      public:
        // double _sum;
        int _sum;
        pos _c;
        const matrix& _m;
        deque<int> _row_sum, _col_sum;        
    };
    matrix image_smoother_large(matrix& M)
    {
        matrix smooth_m(M);
        
        int rows = M.size(), cols;
        if (rows >= 0)
            cols = M[0].size();
        
        // 4 corners
        smooth_m[0][0] = floor(M[0][0] + M[0][1] + M[1][0] + M[1][1] / 4.0);
        smooth_m[rows-1][cols-1] = floor(M[rows-2][cols-2] + M[rows-2][cols-1] + M[rows-1][cols-2] + M[rows-1][cols-1] / 4.0);
        smooth_m[rows-1][0] = floor(M[rows-2][0] + M[rows-2][1] + M[rows-1][0] + M[rows-1][1] / 4.0);
        smooth_m[0][cols-1] = floor(M[0][cols-2] + M[0][cols-1] + M[1][cols-2] + M[1][cols-1] / 4.0);
        
        window3x3 left_window(M);
        for (int r = 1; r < rows - 1; ) {
            window3x3 window(left_window);
            for (int c = 1; c < cols - 1; ) {
                smooth_m[r][c] = window.avg();
                if (++c < cols - 1)
                    window.move_right();
            }
            if (++r < rows - 1)
                left_window.move_down();
        }
        
        return smooth_m;
    }
};
