#
# $Id$
# 
dir := local/test

$(dir)_TEST_SOURCES :=  \
test_RigidObject3DTransformation.cxx \
	test_Quaternion.cxx

# rule to ignore registries
# note: has to be before include statement as that changes value of $(dir)
${DEST}$(dir)/test_Fourier: ${DEST}$(dir)/test_Fourier$(O_SUFFIX) $(STIR_LIB) 
	$(CXX) $(CFLAGS)  $(EXE_OUTFLAG)$@ $< $(STIR_LIB)  $(LINKFLAGS) $(SYS_LIBS)

${DEST}$(dir)/test_RigidObject3DTransformation: ${DEST}$(dir)/test_RigidObject3DTransformation$(O_SUFFIX) $(STIR_LIB) 
	$(CXX) $(CFLAGS)  $(EXE_OUTFLAG)$@ $< $(STIR_LIB)  $(LINKFLAGS) $(SYS_LIBS)

include $(WORKSPACE)/test.mk
