XBE_TITLE = tetris

SRCS += $(CURDIR)/graphics.c $(CURDIR)/input.c $(CURDIR)/logsys.c $(CURDIR)/tetris.c

NXDK_DIR = $(CURDIR)/../nxdk
NXDK_SDL = y
GEN_XISO = ${XBE_TITLE}.iso

new_all: copy_font all

include $(NXDK_DIR)/Makefile

copy_font:
	@mkdir -p $(OUTPUT_DIR)/data
	@cp $(CURDIR)/data/DejaVuSerif.ttf $(OUTPUT_DIR)/data/DejaVuSerif.ttf
