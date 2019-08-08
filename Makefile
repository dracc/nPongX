DEBUG = y
XBE_TITLE = nPongX
INCDIR = $(CURDIR)/Includes
RESOURCEDIR = $(CURDIR)/Resources

SRCS += $(CURDIR)/main.cpp \
	$(INCDIR)/init.cpp $(INCDIR)/player.cpp $(INCDIR)/rendering.cpp \
	$(INCDIR)/ball.cpp $(INCDIR)/smallMath.cpp

NXDK_DIR = $(CURDIR)/../nxdk
NXDK_SDL = y
GEN_XISO = ${XBE_TITLE}.iso

CXXFLAGS += -I$(INCDIR) -Wall -Wextra -std=gnu++11
CFLAGS   += -std=gnu11

new_all: copy_resources all

include $(NXDK_DIR)/Makefile

copy_resources:
	@mkdir -p $(OUTPUT_DIR)
#	@cp $(RESOURCEDIR)/480p.bmp $(OUTPUT_DIR)/480p.bmp
	@cp $(RESOURCEDIR)/vegur.ttf $(OUTPUT_DIR)/vegur.ttf
