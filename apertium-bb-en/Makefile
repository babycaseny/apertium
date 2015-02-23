all:
	lt-comp lr apertium-bb-en.en.dix en-bb.automorf.bin

	if [ ! -d .deps ]; then mkdir .deps; fi
	xsltproc lexchoicebil.xsl apertium-bb-en.bb-en.dix > .deps/apertium-bb-en.bb-en.dix
	lt-comp rl .deps/apertium-bb-en.bb-en.dix en-bb.autobil.bin

	apertium-validate-transfer apertium-bb-en.en-bb.t1x
	apertium-preprocess-transfer apertium-bb-en.en-bb.t1x en-bb.t1x.bin
	apertium-validate-transfer apertium-bb-en.en-bb.t2x
	apertium-preprocess-transfer apertium-bb-en.en-bb.t2x en-bb.t2x.bin

	apertium-gen-modes modes.xml
compile-bb:
	lt-comp lr apertium-bb-en.bb.dix bb-en.automorf.bin 
	lt-comp rl apertium-bb-en.bb.dix bb-en.autogen.bin 
compile-en:
	lt-comp lr apertium-bb-en.en.dix en-bb.automorf.bin 
	lt-comp rl apertium-bb-en.en.dix en-bb.autogen.bin 
compile-bil:
	lt-comp lr apertium-bb-en.bb-en.dix bb-en.autobil.bin 
	lt-comp rl apertium-bb-en.bb-en.dix en-bb.autobil.bin 
compile-rules:
	apertium-preprocess-transfer apertium-bb-en.en-bb.t1x en-bb.t1x.bin

compile-all: compile-bb compile-en compile-bil compile-rules

test:
	echo "walk" | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin
	echo "walks" | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin
	echo "chair" | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin
	echo "chairs" | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin
test-input:
	cat input | lt-proc en-tr.automorf.bin | gawk 'BEGIN{RS="$$"; FS="/";}{nf=split($$1,COMPONENTS,"^"); for(i = 1; i<nf; i++) printf COMPONENTS[i]; if($$2 != "") printf("^%s$$",$$2);}' |  apertium-transfer apertium-tr-en.en-tr.t1x en-tr.t1x.bin en-tr.autobil.bin | lt-proc -g tr-en.autogen.bin | tr -d '[:punct:]' > tmp

