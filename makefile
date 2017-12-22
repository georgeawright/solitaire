OBJ = main.o SolitaireBoard.o Point.o
EXE = solitaire
CXX = g++
CXXFLAGS = -Wall -g -MMD -std=c++11

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJ:.o=.d)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)
