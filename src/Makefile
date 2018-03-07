
CXXFLAGS := -O3 -fPIC -g -Wall -Werror 
#CXX := g++
CXX := g++
MAJOR := 0
MINOR := 1
NAME := PCA9685
VERSION := $(MAJOR).$(MINOR)
RM := rm -rf

all: lib copy
lib: lib$(NAME).so.$(VERSION) lib$(NAME).so

lib$(NAME).so: lib$(NAME).so.$(VERSION)
	ldconfig -v -n .
	ln -s lib$(NAME).so.$(MAJOR) lib$(NAME).so

lib$(NAME).so.$(VERSION): $(NAME).o I2C.o
	$(CXX) -pg -shared -Wl,-soname,lib$(NAME).so.$(MAJOR) $^ -o $@
	
clean:
	$(RM) *.o *.so*
	
copy: