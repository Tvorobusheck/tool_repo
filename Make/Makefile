.PHONY: compile test install uninstall filelist dist documentation clean help
.DEFAULT: help
BIN_PATH = /home/alex/
BIN = bin/test_work 
INFO_DEPS = doc/test_work.info
DIST_DEP = release/1.0-test_work.tar.gz
targets = @grep "^*: " Makefile | tr ':' ' '
RUN_ARGS := $(firstword $(MAKECMDGOALS))

# Модификация makefile
ifneq (targets,$(firstword $(MAKECMDGOALS)))
$(eval $(RUN_ARGS):; @echo Цель \"$(RUN_ARGS)\" не обнаружена! Введите \"make help\" для показа справки)
endif

#! all - сборка программы установки и создание документации
all: compile install dist documentation

# Для запуска make введите: make OPTION [PATH]
# OPTIONS:
#! help - справка по правилам
help:
	@grep "^# " Makefile | tr '#' ' '
	@grep "^#!" Makefile | tr '#!' '\t\t'

compile:
	@cd src && make

#! test - тестовый запуск программы
test: compile
	$(if $(wildcard bin/test_work),,$(error "Программа не собрана! Введите \"make compile\" для компиляции проекта."))
	@cd bin && ./test_work

#! install [BIN_PATH=] - установка программы
install:
	$(if $(wildcard bin/test_work),,$(error "Программа не собрана! Введите \"make compile\" для компиляции проекта."))
	@cp -f $(BIN) $(BIN_PATH) && echo "Программа установлена в: $(BIN_PATH)"

#! uninstall - полная очистка проекта
uninstall:
	rm -f $(BIN_PATH)/test_work
	make clean
	rm -f $(DIST_DEP)

#! filelist - запуск внешенго скрипта
filelist:
	@tree

#! dist [DIST_DEP=] - создание дистрибутива проекта
dist:
	tar -cvf $(DIST_DEP) ../Make

#! documentation - создание документации
documentation:
	@doxygen

#! clean - очистка временных файлов проекта
clean:
	cd src && make clean
	cd bin && rm -f test_work
