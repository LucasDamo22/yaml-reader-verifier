all:
	cd Random-tasks-generator && make
	cd Cpu-usage-calculator && make
cleanAll:
	cd Random-tasks-generator && make clean
	cd Cpu-usage-calculator && make clean
cleanDataFiles:
	rm Cpu-usage-calculator/data/*.yaml
docs:
	mkdir docs
	mkdir docs/doxygen
	doxygen
cleanDocs:
	rm -r docs
	