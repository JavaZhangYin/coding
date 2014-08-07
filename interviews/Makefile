SRC=MinkowskiDistance.java TopTen.java
CLASSES=$(SRC:.java=.class)

all:$(CLASSES)

.SUFFIX: .java .class

all: $(CLASSES)

%.class: %.java
	@echo "Compiling source file --> " $<
	@javac $<

clean:
	@rm -v -rf $(CLASSES)
