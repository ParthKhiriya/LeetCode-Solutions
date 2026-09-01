class Solution {
public:
    int minMoves(vector<string>& classroom, int maxEnergy) {
        int numRows = classroom.size();
        int numCols = classroom[0].size();
        
        int litterIds[20][20];
        memset(litterIds, -1, sizeof(litterIds));
        
        int totalLitter = 0;
        int startRow = -1;
        int startCol = -1;
        
        for(int row = 0; row < numRows; row++) {
            for(int col = 0; col < numCols; col++) {
                if(classroom[row][col] == 'S') {
                    startRow = row;
                    startCol = col;
                } else if(classroom[row][col] == 'L') {
                    litterIds[row][col] = totalLitter++;
                }
            }
        }
        
        int allLitterCollectedMask = (1 << totalLitter) - 1;
        
        int maxEnergyAtState[20][20][1024];
        memset(maxEnergyAtState, -1, sizeof(maxEnergyAtState));
        
        queue<tuple<int, int, int, int>> bfsQueue;
        bfsQueue.push({startRow, startCol, 0, maxEnergy});
        maxEnergyAtState[startRow][startCol][0] = maxEnergy;
        
        int movesTaken = 0;
        int rowOffsets[4] = {-1, 0, 1, 0};
        int colOffsets[4] = {0, 1, 0, -1};
        
        while(!bfsQueue.empty()) {
            int currentLevelSize = bfsQueue.size();
            
            for(int i = 0; i < currentLevelSize; i++) {
                auto [currentRow, currentCol, currentMask, currentEnergy] = bfsQueue.front();
                bfsQueue.pop();
                
                if(currentMask == allLitterCollectedMask) {
                    return movesTaken;
                }
                
                if(currentEnergy == 0) continue;
                
                for(int directionIndex = 0; directionIndex < 4; directionIndex++) {
                    int nextRow = currentRow + rowOffsets[directionIndex];
                    int nextCol = currentCol + colOffsets[directionIndex];
                    
                    if(nextRow >= 0 && nextRow < numRows && nextCol >= 0 && nextCol < numCols && classroom[nextRow][nextCol] != 'X') {
                        int nextEnergy = currentEnergy - 1;
                        
                        if (classroom[nextRow][nextCol] == 'R') {
                            nextEnergy = maxEnergy;
                        }
                        
                        if (nextEnergy >= 0) { 
                            int nextMask = currentMask;
                            
                            if (classroom[nextRow][nextCol] == 'L') {
                                nextMask |= (1 << litterIds[nextRow][nextCol]);
                            }
                            
                            if (nextEnergy > maxEnergyAtState[nextRow][nextCol][nextMask]) {
                                maxEnergyAtState[nextRow][nextCol][nextMask] = nextEnergy;
                                bfsQueue.push({nextRow, nextCol, nextMask, nextEnergy});
                            }
                        }
                    }
                }
            }
            movesTaken++;
        }
        
        return -1;
    }
};