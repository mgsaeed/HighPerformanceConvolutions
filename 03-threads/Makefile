CXX=icpc
CXXFLAGS=-c -save-temps -qopenmp -qopt-report=5 -xMIC-AVX512
LDFLAGS=-qopenmp -lpng

OBJECTS=main.o image.o convolution.o

convolution: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o convolution $(OBJECTS)

all:	convolution

run:	all
	./convolution test-image.png

queue:	all
	echo 'cd $$PBS_O_WORKDIR ; ./convolution ../00-input/test-image.png' | qsub -l nodes=1:flat -N edgedetection

clean:
	rm -f *.optrpt *.o convolution *output.png *~ edgedetection.*
