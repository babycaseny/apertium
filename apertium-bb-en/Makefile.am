VERSION=0.0.1
LANG1=bb
LANG2=en
PREFIX1=$(LANG1)-$(LANG2)
PREFIX2=$(LANG2)-$(LANG1)

BASENAME=apertium-$(PREFIX1)

TARGETS_COMMON = \
	$(PREFIX1).automorf.bin $(PREFIX2).automorf.bin \
        $(PREFIX1).autopgen.bin $(PREFIX2).autopgen.bin \
	$(PREFIX1).autobil.bin \
	$(PREFIX1).autogen.bin \
	$(PREFIX1).alpha.bin \
	$(PREFIX1).t1x.bin \
	$(PREFIX1).t2x.bin \
	$(PREFIX1).t3x.bin \
	$(PREFIX1).rlx.bin $(PREFIX1).lex.bin \
	$(PREFIX1).mode \
	modes 

$(PREFIX1).autogen.bin: $(BASENAME).$(LANG2).dix
	apertium-validate-dictionary $(BASENAME).$(LANG2).dix
	lt-comp rl $(BASENAME).$(LANG2).dix $@

$(PREFIX1).automorf.bin: $(BASENAME).$(LANG1).dix
	apertium-validate-dictionary $(BASENAME).$(LANG1).dix
	lt-comp lr $(BASENAME).$(LANG1).dix $@ $(BASENAME).$(LANG1).acx

$(PREFIX2).automorf.bin: $(BASENAME).$(LANG2).dix
	apertium-validate-dictionary $(BASENAME).$(LANG2).dix
	lt-comp lr $(BASENAME).$(LANG2).dix $@ 

.deps/$(BASENAME).$(PREFIX1).dix: $(BASENAME).$(PREFIX1).dix lexchoicebil.xsl
	if [ ! -d .deps ]; then mkdir .deps; fi
	xsltproc lexchoicebil.xsl $(BASENAME).$(PREFIX1).dix > $@

$(PREFIX1).autobil.bin: .deps/$(BASENAME).$(PREFIX1).dix
	apertium-validate-dictionary .deps/$(BASENAME).$(PREFIX1).dix
	lt-comp lr .deps/$(BASENAME).$(PREFIX1).dix $@

$(PREFIX1).autopgen.bin: $(BASENAME).post-$(LANG2).dix
	apertium-validate-dictionary $(BASENAME).post-$(LANG2).dix
	lt-comp lr $(BASENAME).post-$(LANG2).dix $@

$(PREFIX1).alpha.bin: $(BASENAME).$(PREFIX1).alpha.dix
	apertium-validate-dictionary $(BASENAME).$(PREFIX1).alpha.dix
	lt-comp rl $(BASENAME).$(PREFIX1).alpha.dix $@

$(PREFIX1).rlx.bin: $(BASENAME).$(PREFIX1).rlx
	cg-comp $(BASENAME).$(PREFIX1).rlx $@

$(PREFIX1).lex.bin: $(BASENAME).$(PREFIX1).lex
	cg-comp $(BASENAME).$(PREFIX1).lex $@

$(PREFIX1).t1x.bin: $(BASENAME).$(PREFIX1).t1x
	apertium-validate-transfer $(BASENAME).$(PREFIX1).t1x
	apertium-preprocess-transfer $(BASENAME).$(PREFIX1).t1x $@

$(PREFIX1).t2x.bin: $(BASENAME).$(PREFIX1).t2x
	apertium-validate-interchunk $(BASENAME).$(PREFIX1).t2x
	apertium-preprocess-transfer $(BASENAME).$(PREFIX1).t2x $@

$(PREFIX1).t3x.bin: $(BASENAME).$(PREFIX1).t3x
	apertium-validate-postchunk $(BASENAME).$(PREFIX1).t3x
	apertium-preprocess-transfer $(BASENAME).$(PREFIX1).t3x $@

EXTRA_DIST=$(BASENAME).$(LANG1).dix $(BASENAME).$(PREFIX1).dix \
           $(BASENAME).$(LANG2).dix \
           $(BASENAME).$(LANG1).acx \
           $(BASENAME).post-$(LANG2).dix \
           $(BASENAME).$(PREFIX1).alpha.dix \
           $(PREFIX1).prob \
           $(BASENAME).$(PREFIX1).t1x \
           $(BASENAME).$(PREFIX1).t2x \
           $(BASENAME).$(PREFIX1).t3x \
           $(BASENAME).$(PREFIX1).rlx \
           $(BASENAME).$(PREFIX1).lex \
           modes.xml

$(PREFIX1).mode: modes.xml
	apertium-gen-modes modes.xml
	cp *.mode modes/

$(PREFIX2).mode: modes.xml
	apertium-gen-modes modes.xml
	cp *.mode modes/

clean-dicts:
	touch $(BASENAME).$(LANG1).dix $(BASENAME).$(LANG2).dix $(BASENAME).$(PREFIX1).dix
	rm $(BASENAME).$(LANG1).dix
	
apertium_bb_en_modesdir=$(prefix)/share/apertium/modes/
apertium_bb_en_dir=$(prefix)/share/apertium/apertium-$(PREFIX1)/
apertium_bb_en_DATA=$(PREFIX1).automorf.bin $(PREFIX2).automorf.bin \
                    $(PREFIX1).autobil.bin \
                    $(PREFIX1).autogen.bin \
                    $(PREFIX1).prob \
		    $(PREFIX1).t1x.bin  \
		    $(PREFIX1).t2x.bin  \
		    $(PREFIX1).t3x.bin  \
		    $(PREFIX1).rlx.bin  \
		    $(PREFIX1).lex.bin  \
		    lexchoicebil.xsl  \
		    $(PREFIX1).alpha.bin  \
		    $(BASENAME).$(PREFIX1).t1x \
		    $(BASENAME).$(PREFIX1).t2x \
		    $(BASENAME).$(PREFIX1).t3x \
		    $(PREFIX1).autopgen.bin \
		    $(PREFIX1).mode 
		  
install-data-local:
	apertium-gen-modes modes.xml apertium-$(PREFIX1)
	$(INSTALL_DATA) $(PREFIX1).mode $(apertium_bb_en_modesdir)
	$(INSTALL_DATA) $(PREFIX2).mode $(apertium_bb_en_modesdir)
	$(INSTALL_DATA) $(BASENAME).$(PREFIX1).t1x $(apertium_bb_en_dir)
	$(INSTALL_DATA) $(BASENAME).$(PREFIX1).t2x $(apertium_bb_en_dir)
	$(INSTALL_DATA) $(BASENAME).$(PREFIX1).t3x $(apertium_bb_en_dir)

CLEANFILES = -r $(TARGETS_COMMON) 
