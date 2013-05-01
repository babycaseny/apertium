all:
	lt-comp lr apertium-tr-en.en.dix en-tr.automorf.bin

	if [ ! -d .deps ]; then mkdir .deps; fi
	xsltproc lexchoicebil.xsl apertium-tr-en.tr-en.dix > .deps/apertium-tr-en.tr-en.dix
	lt-comp rl .deps/apertium-tr-en.tr-en.dix en-tr.autobil.bin

	apertium-validate-transfer apertium-tr-en.en-tr.t1x
	apertium-preprocess-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin
	apertium-validate-transfer apertium-tr-en.en-tr.t2x
	apertium-preprocess-transfer apertium-tr-en.en-tr.t2x en-tr.t2x.bin

	apertium-gen-modes modes.xml
compile-tr:
	lt-comp lr apertium-tr-en.tr.dix tr-en.automorf.bin 
	lt-comp rl apertium-tr-en.tr.dix tr-en.autogen.bin 
compile-en:
	lt-comp lr apertium-tr-en.en.dix en-tr.automorf.bin 
	lt-comp rl apertium-tr-en.en.dix en-tr.autogen.bin 
compile-bil:
	lt-comp lr apertium-tr-en.tr-en.dix tr-en.autobil.bin 
	lt-comp rl apertium-tr-en.tr-en.dix en-tr.autobil.bin 
compile-rules:
	apertium-preprocess-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin

compile-all: compile-tr compile-en compile-bil compile-rules

test:
	echo "walk" | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin
	echo "walks" | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin
	echo "chair" | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin
	echo "chairs" | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin
test-input:
	cat input | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin | tr -d '[:punct:]' > tmp

