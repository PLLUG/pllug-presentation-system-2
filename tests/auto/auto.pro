TEMPLATE = subdirs

SUBDIRS += presentation \
    slide \
    domdocumentdivider \
    htmlimport \
    importdivision

# Curtom make target for all running available tests
tests.CONFIG = recursive
QMAKE_EXTRA_TARGETS += tests
