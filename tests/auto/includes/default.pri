QT += testlib

# Location of autotests project dir
TESTS_DIR = $$_PRO_FILE_PWD_/..

DESTDIR = $$TESTS_DIR

COMMAND = $${TESTS_DIR}/$${TARGET}
win32 {
    tests.commands = $$replace(COMMAND, /, \\)
} else {
    tests.commands = $$COMMAND
}
QMAKE_EXTRA_TARGETS += tests