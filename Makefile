

.PHONY: all clean

all: monteCarlos pi_proc.pdf

pi_proc: pi_proc.c
	gcc monteCarlos.c -o monteCarlos -Wall -std=c99

pi_proc.pdf: pi_proc.tex
	pdflatex pi_proc.tex
	@rm -f pi_proc.aux
	@rm -f pi_proc.log

clean:
	@rm -f pi_proc
	@rm -f pi_proc.pdf
	@rm -f pi_proc.aux
	@rm -f pi_proc.log
