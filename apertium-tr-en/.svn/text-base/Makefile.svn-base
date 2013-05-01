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
