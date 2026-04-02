# Compiler
GPP = g++

# Compilation flags
GPPFlags = -Wall -Wextra -Werror -Wfatal-errors -std=c++20

# Source and output names
SRC = HW4.cpp ErrorCheck.cpp GOLApp.cpp 
HEADER = GameOfLife.h ErrorCheck.h

HWNUM = HW4
TARNAME = Marytheresa_Ifediba

# Target name
TARGET = GOLApp

# Compile
$(TARGET): $(SRC) $(HEADER)
	$(GPP) $(GPPFlags) $(SRC) -o $(TARGET)

$(HWNUM).a: $(SRC)
	ar -rcs $(HWNUM).a $^
	rm $^

# Clean
clean:
	rm -f $(TARGET)
	@echo "Removed all object files."

package:
	tar -c Makefile $(filter-out GOLApp.cpp, $(SRC)) $(HEADER) -f $(HWNUM)_$(TARNAME).tar
