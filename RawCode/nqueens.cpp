/**
 * markUnmarkable() takes the newly occupied position co-ordinates as arguments - coordX and coordY
 *   and marks unoccupiable positions into the canPlace vector and return the modified Vector/ the
 *   chess board
 * canPlace is a 2D vector represents the chess board, indicating the currently unoccupiable positions
 *   i.e the places occupied either by the Queens or the positions, i.e where new queens can or can't
 *   be placed
 * sizeB is a size_t type argument representing the size of the 2D Square vector or the chess board
 */
std::vector<std::vector<bool>> markUnmarkable(std::vector<std::vector<bool>> canPlace, size_t sizeB, int coordX, int coordY) {
    // Move in 8 Dimensions
    // Move top
    //canPlace[coordX][coordY] = false;
    for(int i = 0; i < coordX; i++) {
        canPlace[i][coordY] = false;
    }
    // Move right
    for(int j = coordY; j < sizeB; j++) {
        canPlace[coordX][j] = false;
    }
    // Move bottom
    for(int i = coordX; i < sizeB; i++) {
        canPlace[i][coordY] = false;
    }
    // Move left
    for(int j = 0; j < coordY; j++) {
        canPlace[coordX][j] = false;
    }
    // Move diag-top-left
    for(int i = coordX, j = coordY; i >= 0 && j >= 0; i--, j--) {
        canPlace[i][j] = false;
    }
    // Move diag-top-right
    for(int i = coordX, j = coordY; i >= 0 && j < sizeB; i--, j++) {
        canPlace[i][j] = false;
    }
    // Move diag-bottom-right
    for(int i = coordX, j = coordY; i < sizeB && j < sizeB; i++, j++) {
        canPlace[i][j] = false;
    }
    // Move diag-bottom-left
    for(int i = coordX, j = coordY; i < sizeB && j >= 0; i++, j--) {
        canPlace[i][j] = false;
    }
    return canPlace;
}

/**
 * nQueens recursively iterates through the chess board represented by queens vector til one possible
 * combination can be found such that all queens can be placed so that no queen can cut any other queen
 * placed on the board diagonally, vertically or horizontally.
 */
bool nQueens(std::vector<std::vector<bool>> queens, std::vector<std::vector<bool>> canPlace,
             int queensLeft, size_t sizeB) {
    if(queensLeft == 0) {
        for(uint i = 0; i < sizeB; i++) {
            for(uint j = 0; j < sizeB; j++) {
                std::cout << queens[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return true;
    }
    else {
        for(int i = 0; i < sizeB; i++) {
            for(int j = 0; j < sizeB; j++) {
                // Mark cur as queen
                if(canPlace[i][j]) {
                    queens[i][j] = true;
                    //canPlace[i][j] = false;
                    bool foundFlag = nQueens(queens, markUnmarkable(canPlace, sizeB, i, j), queensLeft - 1, sizeB);
                    if(foundFlag) {
                        return true;
                    }
                    queens[i][j] = false;
                    //canPlace[i][j] = true;
                }
            }
        }
    }
}

void nQueens(size_t sizeB) {
    std::vector<std::vector<bool>> queens(sizeB, std::vector<bool>(sizeB, false));
    std::vector<std::vector<bool>> canPlace(sizeB, std::vector<bool>(sizeB, true));
    // Total Number of Queens to place
    int total = sizeB;
    nQueens(queens, canPlace, total, sizeB);
}
