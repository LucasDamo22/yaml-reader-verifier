OUTPUTDIR :=./bin
SOURCEDIR :=./src
HEADERDIR :=./include
PROGRAM_NAME = cpuUsage


CXXFLAGS  +=-Iinclude

#link with other libraries
LD_FLAGS :=-lm

#source files for the platform
SOURCE_FILES := $(wildcard $(SOURCEDIR)/*.cpp)

# include headers in the dependecy check
HEADER_FILES := $(wildcard $(HEADERDIR)/*.h)

#compiler an instance of the simulator
$(OUTPUTDIR)/$(PROGRAM_NAME): $(SOURCE_FILES) $(HEADER_FILES)
	g++ $(SOURCE_FILES) -o $(OUTPUTDIR)/$(PROGRAM_NAME) $(LD_FLAGS) $(CXXFLAGS)

docs:
	cd .. && pwd && mkdir docs && mkdir docs/doxygen && doxygen
	
remdocs:
	cd .. && rm -r docs

#remove previously generated files
clean:
	$(Q)rm -rf $(OUTPUTDIR)/$(PROGRAM_NAME)
cleanDataFiles:
	cd .. && rm ./data/*.yaml
	

