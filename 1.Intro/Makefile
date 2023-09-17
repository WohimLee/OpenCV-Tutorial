
MAIN   := Examples/main.cpp
MAIN.o := objs/main.o

cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))


include_dirs := /home/nerf/datav/3rdParty/opencv-3.4.15/include

linking_libs := opencv_core opencv_imgcodecs opencv_highgui 

library_dirs := /home/nerf/datav/3rdParty/opencv-3.4.15/lib

I_options := $(include_dirs:%=-I%)
l_options := $(linking_libs:%=-l%)
L_options := $(library_dirs:%=-L%)
r_options := $(library_dirs:%=-Wl,-rpath=%)

dynamic_options := -fPIC
compile_options := -g -O3 -w -std=c++14 $(I_options)
linking_options := $(l_options) $(L_options) $(r_options)

$(MAIN.o) : $(MAIN)
	@echo [INFO]: Compile $< to $@
	@mkdir -p $(dir $@)
	@g++ -c $< -o $@ $(compile_options) 

objs/%.o : src/%.cpp
	@echo [INFO]: Compile $^ to $@
	@mkdir -p $(dir $@)
	@g++ -c $^ -o $@ $(compile_options) $(dynamic_options)

lib/libtest.so : $(cpp_objs)
	@echo [INFO]: Generate $@, including: $^
	@mkdir -p $(dir $@)
	@g++ -shared $^ -o $@


dynamic : lib/libtest.so


workspace/exec : $(MAIN.o) 
	@echo [INFO]: Link $< to $@
	@mkdir -p $(dir $@)
	@g++ $< -o $@ $(linking_options)

run : workspace/exec
	@./$< aaa bbb ccc


clean :
	@rm -rf objs lib workspace/exec


debug :
	@echo $(MAIN)
	@echo $(linking_options)


.PHONY : run clean debug dynamic