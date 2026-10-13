#include "solver.h"
#include <cstdlib>
namespace queens {

static bool search(int &count, int limit ,int r, std::vector<int> &cols,
            std::vector<bool> &usedCol,
            std::vector<bool> &usedReg, const Board &board){
    if (r==board.size()){
        count++;
        return count>=limit;
    }
    for (int c=0;c<board.size();c++){
        if(!usedCol[c] && !usedReg[board.regionAt(r,c)] && !(r > 0 && std::abs(c - cols[r-1]) <= 1)){
            cols[r]=c;
            usedCol[c]=true;
            usedReg[board.regionAt(r,c)]=true;
            if (search(count,limit,r+1,cols,usedCol,usedReg,board)){
                return true;
            }
            usedCol[c]=false;
            usedReg[board.regionAt(r,c)]=false;
        }
    }
    return false;
}

std::optional<std::vector<int>> solve(const Board &board)
{
    //backtracking, one queen per row, track used columns/regions
    int count=0;
    std::vector<bool>usedCol(board.size(),false);
    std::vector<bool>usedReg(board.size(),false);
    std:: vector <int> cols(board.size());
    if(search(count,1,0,cols,usedCol,usedReg,board)){
        return cols;
    }
    return std::nullopt;

}

int countSolutions(const Board &board, int limit)
{
    // TODO: same search as solve(), but count and stop at `limit`
    int count=0;
    std::vector<bool>usedCol(board.size(),false);
    std::vector<bool>usedReg(board.size(),false);
    std:: vector <int> cols(board.size());
    search(count,limit,0,cols,usedCol,usedReg,board);
    return count;
}

} // namespace queens
