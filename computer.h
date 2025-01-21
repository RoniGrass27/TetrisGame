#include "gameConfig.h"
#include "point.h"
#include "shape.h"
#include "player.h"



class Computer : public Player {
private:
	int stepsToSides;
	int maxY;
	int maxRowsToDelete;

public:

	// Default constructor
	Computer() : stepsToSides(0), maxY(0), maxRowsToDelete(0) {}
	~Computer() override{};

	// Getter for stepsToSides
	int getStepsToSides() const {
		return stepsToSides;
	}

	// Setter for stepsToSides
	void setStepsToSides(int steps) {
		stepsToSides = steps;
	}

	// Getter for maxY
	int getMaxY() const {
		return maxY;
	}

	// Setter for maxY
	void setMaxY(int value) {
		maxY = value;
	}

    // Getter for maxRowsToDelete
    int getMaxRowsToDelete() const {
	return maxRowsToDelete;
    }

    // Setter for maxRowsToDelete
    void setMaxRowsToDelete(int value) {
	maxRowsToDelete = value;
    }

	void calculateMove(Shape& shape, int* MaxRowsToDelete, int* maxY, int* StepsToSides);
	int updateAndCheck(Point tempBody[]);
	bool MoveSides(Point tempBody[], int minX, int j);
	int checkRows() const;
	void run(Shape& currentShape, char key, int num, bool* over, bool* turnFinish, bool* firstShape) override;
	void computerRotate(int direction,int num);
	void moveSidesComp(int num);
	

};

