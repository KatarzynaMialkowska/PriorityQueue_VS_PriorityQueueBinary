
.SUFFIXES: .cxx .o .x .hxx
NAME1 = priorityQueue
NAME2 = priorityQueueBinary
NAME3 = tester

CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x

CO=g++
FLAGS= -std=c++17

.PHONY: all
all: $(EXEC1)  $(EXEC2)  $(EXEC3)


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS) 

$(EXEC2):
	$(CO) -o $@ $(CXX2) $(FLAGS) 

$(EXEC3):
	$(CO) -o $@ $(CXX3) $(FLAGS) 


#priority queue#

A: $(EXEC1)

.PHONY: PriorityQueue
PriorityQueue: A
	@echo "priority queue\n"
	@./$(EXEC1)

#priority queue binary#

B: $(EXEC2)
.PHONY: PriorityQueueBinary
PriorityQueueBinary: B
	@echo "priority queue binary\n"
	@./$(EXEC2)


test: $(EXEC3)
.PHONY: tester
tester: test
	@echo "priority queue vs priority queue binary\n"
	@./$(EXEC3)



.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x *.txt *.dat *.pdf core core* a.out; rm -rf ${LIB_DIR}