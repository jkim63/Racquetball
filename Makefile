CMP = g++
MAIN = project
CLASS = Racquetball
EXEC = Racquetball

$(EXEC): $(MAIN).o $(CLASS).o
		$(CMP) $(MAIN).o $(CLASS).o -o $(EXEC)

$(MAIN).o: $(CLASS).h $(MAIN).cpp
		$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).h $(CLASS).cpp
		$(CMP) -c $(CLASS).cpp

clean:
		rm $(MAIN).o $(CLASS).o
		rm $(EXEC)
