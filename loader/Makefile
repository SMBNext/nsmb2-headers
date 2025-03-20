#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

GCC_ARM_NONE_EABI_LOCAL=$(realpath ../gcc-arm-none-eabi)

ifneq "$(wildcard $(GCC_ARM_NONE_EABI_LOCAL) )" ""
export GCC_ARM_NONE_EABI	:=	$(GCC_ARM_NONE_EABI_LOCAL)
endif

ifeq ($(strip $(GCC_ARM_NONE_EABI)),)
$(error gcc-arm-none-eabi was not found. Please set GCC_ARM_NONE_EABI in your \
environment or extract it into a directory called gcc-arm-none-eabi)
endif

export PATH		:=	$(GCC_ARM_NONE_EABI)/bin:$(PATH)

#---------------------------------------------------------------------------------
# the prefix on the compiler executables
#---------------------------------------------------------------------------------
PREFIX			:=	arm-none-eabi-

export CC		:=	$(PREFIX)gcc
export CXX		:=	$(PREFIX)g++
export AS		:=	$(PREFIX)gcc
export AR		:=	$(PREFIX)ar
export OBJCOPY	:=	$(PREFIX)objcopy
export OBJDUMP	:=	$(PREFIX)objdump


#---------------------------------------------------------------------------------
# TARGET is the name of the output
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing header files
#---------------------------------------------------------------------------------
TARGET		:=	loader
BUILD		:=	build
SOURCES		:=	source
INCLUDES	:=	include


#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
ARCH		:=	-march=armv6k+fp -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS		:=	-Wall -O3 -mword-relocations -fshort-wchar \
				-fomit-frame-pointer -ffunction-sections \
				$(ARCH) -nostdinc $(INCLUDE)

CXXFLAGS	:=	$(CFLAGS) -fno-exceptions -fno-rtti

ASFLAGS		:=	$(ARCH)

LDFLAGS		:=	-nodefaultlibs -nostartfiles $(ARCH) \
				-T $(LINKERSCRIPT) -T $(SYMBOLS) -Wl,-Map,$(notdir $(TARGET).map)


#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------

export LINKERSCRIPT	:=	$(CURDIR)/linker.ld

export SYMBOLS 		:=	$(CURDIR)/../symbols.ld

export OUTPUT		:=	$(CURDIR)/$(TARGET)

export VPATH		:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir))

export DEPSDIR		:=	$(CURDIR)/$(BUILD)

CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))

#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
	export LD	:=	$(CC)
else
	export LD	:=	$(CXX)
endif


export OFILES		:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)

export INCLUDE		:=	$(foreach dir,$(INCLUDES),-iquote $(CURDIR)/$(dir)) \
						-I$(CURDIR)/$(BUILD)


.PHONY: $(BUILD) clean
  
#---------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile
 
#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(BUILD) $(LINKERSCRIPT) $(TARGET).elf $(TARGET).bin $(TARGET).sym

#---------------------------------------------------------------------------------
else
 
#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------


ifeq ($(strip $(CODEADDR)),)
$(error "The code destination has to be defined. CODEADDR=<address>")
endif

ifeq ($(strip $(DATAADDR)),)
$(error "The data destination has to be defined. DATAADDR=<address>")
endif

#---------------------------------------------------------------------------------
# Linker Script Template
#---------------------------------------------------------------------------------

define LINKERSCRIPT_TEMPLATE
OUTPUT_ARCH(arm)

SECTIONS
{
    . = $(CODEADDR);
    .text : {
        __text_start = . ;
        *(.text)
        *(.text.*)
        __text_end  = . ;
    }
    
    . = $(DATAADDR);
    .data : {
        __data_start = . ;
        *(.rodata)
        *(.data)
        *(.bss)
        *(COMMON)
        __data_end  = . ;
    }
}
endef
export LINKERSCRIPT_TEMPLATE

#---------------------------------------------------------------------------------



all: $(OUTPUT).bin $(OUTPUT).sym

# Create binary file from elf
$(OUTPUT).bin : $(OUTPUT).elf
	$(OBJCOPY) -O binary $< $@
	@echo built ... $(notdir $@)

# Dump symbols from elf
$(OUTPUT).sym : $(OUTPUT).elf
	$(OBJDUMP) -t $< > $@
	@echo written the symbol table ... $(notdir $@)

# Link object files into elf
%.elf: $(OFILES)
	@echo generating linker script
	echo "$$LINKERSCRIPT_TEMPLATE" > $(LINKERSCRIPT)
	
	@echo linking $(notdir $@)
	$(LD)  $(LDFLAGS) $(OFILES) $(LIBPATHS) $(LIBS) -o $@

	rm $(LINKERSCRIPT)

# Compile C++ files
%.o: %.cpp
	@echo $(notdir $<)
	$(CXX) -MMD -MP -MF $(DEPSDIR)/$*.d $(CXXFLAGS) -c $< -o $@ $(ERROR_FILTER)
	
# Compile C files
%.o: %.c
	@echo $(notdir $<)
	$(CC) -MMD -MP -MF $(DEPSDIR)/$*.d $(CFLAGS) -c $< -o $@ $(ERROR_FILTER)
	
# Compile assembly files
%.o: %.s
	@echo $(notdir $<)
	$(AS) -MMD -MP -MF $(DEPSDIR)/$*.d -x assembler-with-cpp $(ASFLAGS) -c $< -o $@ $(ERROR_FILTER)

-include $(DEPSDIR)/*.d
 
#---------------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------------
