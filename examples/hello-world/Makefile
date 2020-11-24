CONTIKI_PROJECT = hello-world
all: $(CONTIKI_PROJECT)


TARGET=vesna
AT86RF2XX_BOARD = ISMTV_v1.1

VESNA= ../../arch/platform/vesna/vesna-drivers/

MAKE_MAC = MAKE_MAC_TSCH
MODULES += os/services/shell


CONTIKI = ../..
include $(CONTIKI)/Makefile.include
