TEMPLATE = subdirs

SUBDIRS += presentation \
    slide

# Curtom make target for all running available tests
tests.CONFIG = recursive
QMAKE_EXTRA_TARGETS += tests