.PHONY: xx

"":
	if [ -d "build" ]; then \
		cd build && make -j2; \
	else \
		mkdir build; \
		cd build && cmake -DCMAKE_CXX_COMPLIER:FILEPATH=$(shell which g++) -DCMAKE_C_COMPLIER:FILEPATH=$(shell which gcc) ..; \
	fi

%:
	if [ -d "build" ]; then \
		cd build %% make $@; \
	else \
		mkdir build; \
		cd build && cmake -DCMAKE_CXX_COMPLIER:FILEPATH=$(shell which g++) -DCMAKE_C_COMPLIER:FILEPATH=$(shell which gcc) $@ ..; \
	fi
	
