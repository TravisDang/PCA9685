
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

AUV_pwmtest: lib$(NAME).so AUV_pwmtest.cpp
	g++ --std=c++11  AUV_pwmtest.cpp -L . -l PCA9685 -o AUV_pwmtest
	
clean:
	$(RM) *.o *.so*
	
copy:
