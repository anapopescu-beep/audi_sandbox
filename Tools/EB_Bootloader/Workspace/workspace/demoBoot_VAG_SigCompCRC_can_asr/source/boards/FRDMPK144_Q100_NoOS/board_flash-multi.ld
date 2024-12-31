/* board_flash-gnu.ldscript
 *
 * Linker script memory definitions for GNU binutils.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: board_flash-multi.ld 1.2.1.2 2022/09/01 06:53:04CEST Andrei Anca (andrei.anca) in_work  $
*/

/*    Memory types and sizes for S32K144:
 *    SRAM_L            = 0x8000;    32    KB    (Low-order, executable)
 *    SRAM_U            = 0x7000;    28    KB    (High-order, for data)
 *    FlexRAM            = 0x1000;    4    KB
 *    FLSH_PROG        = 0x80000;    512    KB
 *    FLSH_FlexNVM    = 0x10000;    64    KB
*/

/*    S32K144 memory is split into 2 regions:
 *    0x00000000 - 0x1FFFFFFF    :    Low-order addresses (access through the code bus)
 *    0x20000000 - 0xFFFFFFFF    :    High-order addresses (access through the system bus)
 *    All code should be placed to the low-order addresses
 *
 *    SRAM_L    lies in low-order address space (SRAM_L must end at 0x1FFFFFFF)
 *    SRAM_U    lies in high-order address space (SRAM_U must start at 0x20000000)
 *    SRAM_L and SRAM_U are contiguous!
*/

MEMORY
{
    /******************************************************************/
    /********************** ROM ***************************************/
    /******************************************************************/
    reset         : ORIGIN = 0x00000000, LENGTH = 0x100         /* reset-vector*/    
    startup         : ORIGIN = 0x00000100, LENGTH = 0x300         /* startup code*/
 
    /********** Gap: addresses at 0x00000400 are reserved and not writable *********/
    /**********            Ecu is locked if this area is changed           *********/
    reserved        : ORIGIN = 0x00000400, LENGTH = 0x10
    /**********                      End Gap                               *********/
    
    exctable        : ORIGIN = 0x00000800, LENGTH = 0x02800    /* exception (+interrupt) table */
    Flash_API_ROM_MEMORY  : ORIGIN = 0x00003000, LENGTH = 0x01000   /* Low-order RAM (code-bus)    reserved for RAM Flash code execution    */
  rom     : ORIGIN = 0x00004000, LENGTH = 0x7D000     /* the rest of FLASH memory   */
    
    /******************************************************************/
    /********************** RAM ***************************************/
    /******************************************************************/
    Flash_API_RAM_MEMORY  : ORIGIN = 0x1FFF8000, LENGTH = 0x01000 /* Low-order RAM (code-bus)  reserved for RAM Flash code execution  */
    ram           : ORIGIN = 0x1FFF9000, LENGTH = 0x0df00    /* High-order RAM (system-bus)    */
    mdatanoinit       : ORIGIN = 0x20006f00, LENGTH = 0x00100   
}

/* Definition of the 'reset_vector' section */
SECTIONS
{
    /*
     * Output section reset (Type RESET)
    */
    reset_vector :
    {
        . = ALIGN(256);
        "board_reset_vector.o*(.rodata)"
        "board_reset_vector.o*(.rodata.*)"
        "*/board_reset_vector.o(.rodata)"
        "*/board_reset_vector.o(.rodata.*)"
        "*\\board_reset_vector.o(.rodata)"
        "*\\board_reset_vector.o(.rodata.*)"
    } >reset

    /* Symbols for Memory Protection: Global RAM region */
  __GLBL_RAM_START    = 0x20000000;
  __GLBL_RAM_END      = 0x20006FFF;

  /* Symbols for Memory Protection: Global ROM region */
  __GLBL_ROM_START    = 0x00000000;
  __GLBL_ROM_END      = 0x0007FFFF;
}



SECTIONS
{
    /******************************************************************/
    /********************** ROM ***************************************/
    /******************************************************************/
    /*
     * Output section reset (Type RESET)
    */
    reset :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_reset = .;
        . = ALIGN(256);
        "*(.reset)"
    "*(.reset.*)"
        . = ALIGN(256);
        __EBDBGLD_ENDOF_RUN_reset = .;
    } >reset  
    
    startup :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_startup = .;
        . = ALIGN(256);
        "*(.startup)"
    "*(.startup.*)"
        . = ALIGN(256);
        __EBDBGLD_ENDOF_RUN_startup = .;
    } >startup  
    
    /*
     * Output section ExceptionTable (Type RESET)
    */
    ExceptionTable :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_ExceptionTable = .;
        . = ALIGN(256);
        __EXCTAB_START = .;
        "*(ExceptionTable)"
    "*(ExceptionTable.*)"
    "*(InterruptTable)"
    "*(InterruptTable.*)"
        . = ALIGN(256);
        __EBDBGLD_ENDOF_RUN_ExceptionTable = .;
        __EXCTAB_END = .;
    } >exctable
    
    /*
     * Output section text (Type TEXT)
    */
    text :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_text = .;
        . = ALIGN(32);
        __GLBL_TEXT_START = .;
    "*(.text)"
    "*(.text.*)"
    "*(.text)"
    "*(.text.*)"
    "*(i.*)"
    "*(i.*.*)"
        . = ALIGN(32);
        __EBDBGLD_ENDOF_RUN_text = .;
        __GLBL_TEXT_END = .;
    } >rom
    
    /*
     * Output section rodata (Type RODATA)
    */
    rodata :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_rodata = .;
        . = ALIGN(32);
        __GLBL_RODATA_START = .;
    "*(.rodata)"
    "*(.rodata.*)"
    "*(.constdata)"
    "*(.constdata.*)"
    "*(.const*)"
    "*(.const*.*)"
        . = ALIGN(32);
        __EBDBGLD_ENDOF_RUN_rodata = .;
        __GLBL_RODATA_END = .;
    } >rom
    
    Flash_API_ROM_SECTION :
    {
      /*Align on 4 bytes*/
      . = ALIGN(4);
      
      /*Retrieve the Low layer APIs flash start address*/
      __Flash_API_ROM_SECTION_START_ADDR = .;
      
      /*Store into this section the code which has been put into the dedicated section*/
      *(.fls_driver)
      
      /*Retrieve the Low layer APIs flash end address*/
      __Flash_API_ROM_SECTION_END_ADDR = .;
    } >Flash_API_ROM_MEMORY
    
    /******************************************************************/
    /********************** RAM ***************************************/
    /******************************************************************/
    /* Low layer APIs flash which will be stored in RAM */
    Flash_API_RAM_SECTION :
    {
      /*Align on 4 bytes*/
      . = ALIGN(4);
      
      /*Retrieve the Low layer APIs flash start address*/
      __Flash_API_RAM_SECTION_START_ADDR = .;
      
      /*Retrieve the Low layer APIs flash end address*/
          
    } >Flash_API_RAM_MEMORY
    __Flash_API_RAM_SECTION_END_ADDR = __Flash_API_RAM_SECTION_START_ADDR + 0x01000;
    
    ram = 0;
    /*
     * Output section BoardStack (Type STACK)
    */
    BoardStack ALIGN(32) :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_BoardStack = .;
        "*(*.bss.BoardStack)"
    "*(*.bss.BoardStack.*)"
        __EBDBGLD_ENDOF_RUN_BoardStack = .;
    } >ram 

    /*
     * Output section data_core0 (Type DATA)
    */
    data_core0 :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_data_core0 = .;
        . = ALIGN(32);
        __STARTDATA_C0 = .;
    "*(.data_core0)"
    "*(.data_core0.*)"
    "*(.data_shared_core0)"
    "*(.data_shared_core0.*)"
        . = ALIGN(32);
        __EBDBGLD_ENDOF_RUN_data_core0 = .;
        __ENDDATA_C0 = .;
    } >ram
  .ROM.data_core0 ROM(data_core0) : > rom
  
    __INITDATA_C0 = addr(.ROM.data_core0);
    __EBDBGLD_ENDOF_LOAD_data_core0 = __INITDATA_C0 + SIZEOF(data_core0) - (((ADDR(data_core0) + 31) & (~ 31)) - ADDR(data_core0));
    
    /*
     * Output section DATA (Type DATA)
    */
    DATA :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_DATA = .;
        . = ALIGN(32);
        __STARTDATA = .;
    "*(.data)"
    "*(.data.*)"
        . = ALIGN(32);
        __EBDBGLD_ENDOF_RUN_DATA = .;
        __ENDDATA = .;
    } >ram 
  .ROM.DATA ROM(DATA) : > rom
    __INITDATA = addr(.ROM.DATA);
    __EBDBGLD_ENDOF_LOAD_DATA = __INITDATA + SIZEOF(DATA) - (((ADDR(DATA) + 31) & (~ 31)) - ADDR(DATA));
    
    /*
     * Output section BSS (Type BSS)
    */
    BSS (NOLOAD) :
    {
        __EBDBGLD_BEFOREBEGINOF_RUN_BSS = .;
        . = ALIGN(32);
        __STARTBSS = .;
        "*(.bss)"
        "*(.bss.*)"
        . = ALIGN(32);
        __EBDBGLD_ENDOF_RUN_BSS = .;
        __ENDBSS = .;
    } >ram  
    
    NoInit (NOLOAD) :
    {
        . = ALIGN(8);
        __STARTNOINIT = .;
        "*(.section_noinit)"
        "*(.section_noinit.*)"
		"*(.ram_no_init)"
		"*(.ram_no_init.*)"
		"*(.prog_sig)"
		"*(.prog_sig.*)"
        . = ALIGN(8);
        __ENDNOINIT  = .;
    } >mdatanoinit
    
    __FLASH_DRIVER_ROM_START_ADDRESS = __Flash_API_ROM_SECTION_START_ADDR;
    __FLASH_DRIVER_ROM_END_ADDRESS = __Flash_API_ROM_SECTION_END_ADDR;
    __FLASH_DRIVER_RAM_START_ADDRESS = __Flash_API_RAM_SECTION_START_ADDR;
    __FLASH_DRIVER_RAM_END_ADDRESS = __Flash_API_RAM_SECTION_END_ADDR;
}